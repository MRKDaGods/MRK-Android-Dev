package io.github.mrkdagods.mrkandroidhaxexternal;

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.graphics.Color;
import android.graphics.PixelFormat;
import android.os.Build;
import android.os.IBinder;
import android.view.LayoutInflater;
import android.view.View;
import android.view.WindowManager;

import androidx.annotation.Nullable;
import androidx.core.app.NotificationCompat;

public class MRKOverlayService extends Service {
    private WindowManager m_WM;
    private MRKGLView m_View;
    private View m_RootView;

    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    private void StartForeground() {
        PendingIntent intent = PendingIntent.getActivity(this, 0,
                new Intent(this, MRKOverlayService.class), 0);

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            NotificationChannel channel = new NotificationChannel("overlay_channel_id", "overlay_channel_name", NotificationManager.IMPORTANCE_NONE);
            channel.setLightColor(Color.BLUE);
            channel.setLockscreenVisibility(Notification.VISIBILITY_PRIVATE);
            NotificationManager nm = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
            nm.createNotificationChannel(channel);
        }

        Notification notification = new NotificationCompat.Builder(this, "overlay_channel_id")
                .setContentTitle(getText(R.string.app_name))
                .setContentText(getText(R.string.app_name))
                .setSmallIcon(R.drawable.notification_template_icon_bg)
                .setContentIntent(intent)
                .setTicker(getText(R.string.app_name))
                .build();

        startForeground(6661, notification);
    }

    private void InitializeOverlay() {
        LayoutInflater li = (LayoutInflater) getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        m_RootView = li.inflate(R.layout.mrkoverlay, null);
        CheckView();

        int type = Build.VERSION.SDK_INT < Build.VERSION_CODES.O ? WindowManager.LayoutParams.TYPE_SYSTEM_OVERLAY
                : WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY;
        WindowManager.LayoutParams params = new WindowManager.LayoutParams(type,
                WindowManager.LayoutParams.FLAG_NOT_TOUCHABLE | WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE,
                PixelFormat.TRANSLUCENT);
        m_WM = (WindowManager) getSystemService(Context.WINDOW_SERVICE);
        m_WM.addView(m_RootView, params);
    }

    private void CheckView()
    {
        if (m_View == null)
            m_View = m_RootView.findViewById(R.id.MRKGLView);
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        StartForeground();

        return Service.START_STICKY;
    }

    @Override
    public void onCreate() {
        super.onCreate();

        InitializeOverlay();

        CheckView();
        if (m_View != null)
            m_View.onResume();
    }

    @Override
    public void onDestroy() {
        super.onDestroy();

        CheckView();
        if (m_View != null)
            m_View.onPause();

        m_WM.removeViewImmediate(m_RootView);

    }
}
