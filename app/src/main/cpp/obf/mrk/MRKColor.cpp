#include "MRKColor.h"
#include "MRKApplication.h"
#include "math/MRKMath.h"
#include "MRKLog.h"

#include <cmath>

namespace MRK
{
    mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::mdSJ1AluedrHklRdbdUK4GtkHZNrfFXzA9b9pb5iK = mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(0, 255);
    mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::mVFxviKhn0pYE7O2WQsAqAQWPx8Q4rVF9chjhuZdb = mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(255, 255);
    mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::mJ7rYE5kTaqwuVQoAdFhnAoM7TIiT09Zp5JqC3hid = mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(true);
    mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD *mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::Rainbow = new mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD[MRK_COLOR_RAINBOW_COUNT]{
        mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(255, 0, 0, 255),
        mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(255, 255, 0, 255),
        mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(0, 255, 0, 255),
        mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(0, 255, 255, 255),
        mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(0, 0, 255, 255),
        mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(255, 0, 255, 255)
    };
    mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD *mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::InvRainbow = new mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD[MRK_COLOR_RAINBOW_COUNT]{
            mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(255, 255, 0, 255),
            mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(0, 255, 0, 255),
            mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(0, 255, 255, 255),
            mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(0, 0, 255, 255),
            mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(255, 0, 255, 255),
            mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(255, 0, 0, 255)
    };

    mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk mgd2KfMcnEss1adPmNnn8KkBGqKZjdCcf5OjmrlXc(mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD)
    {
        return m7Zf2FS4Dh1CgrFpZK03m8BlGiljoJpjMSOv2dxeN((unsigned char) mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD.muTbJumgqjGR21k8slwgaGmZcnSEvnnwczCnA5PIp(), (unsigned char) mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD.mVb1WkMKZgUsW1zFjVtgWuUUrNfLyy8zF4tDZ5X79(),
                       (unsigned char) mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD.mT6wtErdvs7jEoLzhB0oL9MYZvOZZUAE0vRCmh1ZG(), (unsigned char) mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD.mRDipnnKuYrGc2vMgk6OztGQ838M76i3aqj3idGel());
    }

    mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk operator&(mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD)
    {
        return mgd2KfMcnEss1adPmNnn8KkBGqKZjdCcf5OjmrlXc(mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD);
    }

    mTiE4g3CEyDaY5SRXutqTU6KzGYV0MRECWt1RDWPk operator!(mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD)
    {
        mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD._G() = true;
        return mgd2KfMcnEss1adPmNnn8KkBGqKZjdCcf5OjmrlXc(mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD);
    }

    bool operator==(mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD rhf, mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD lhf)
    {
        return rhf.muTbJumgqjGR21k8slwgaGmZcnSEvnnwczCnA5PIp() == lhf.muTbJumgqjGR21k8slwgaGmZcnSEvnnwczCnA5PIp() && rhf.mVb1WkMKZgUsW1zFjVtgWuUUrNfLyy8zF4tDZ5X79() == lhf.mVb1WkMKZgUsW1zFjVtgWuUUrNfLyy8zF4tDZ5X79() && rhf.mT6wtErdvs7jEoLzhB0oL9MYZvOZZUAE0vRCmh1ZG() == lhf.mT6wtErdvs7jEoLzhB0oL9MYZvOZZUAE0vRCmh1ZG() && rhf.mRDipnnKuYrGc2vMgk6OztGQ838M76i3aqj3idGel() == lhf.mRDipnnKuYrGc2vMgk6OztGQ838M76i3aqj3idGel();
    }

    mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(bool grad) : mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(0, 0, 0, 255)
    {
        m4AxiIE2mGllSVSM0zWsyWkwUfm8UlWlmW3od78W6 = grad;
    }

    mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(float mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC, float g, float b, float mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c)
    {
        mXLyCM8un8gwuAv0eumvDKafLA3IEdlo9qFUyabRV = mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC * 255.f;
        mMAJfDNPLk52b7cXrilb37zxB3mNLwaYUemWBUl5s = g * 255.f;
        mVFvGN0g7Z20C9gnmg3dQOi0WaxlG93rOq3qXwzvf = b * 255.f;
        me2s65RhANOyRsxhu1Yq03OyC3v3PScDahBJyzZ8H = mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c * 255.f;
    }

    mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(int mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC, int g, int b, int mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c)
    {
        mXLyCM8un8gwuAv0eumvDKafLA3IEdlo9qFUyabRV = mkfybIlpomk1YoOBUceufWK8BB5oKv4OOXyepbkKC;
        mMAJfDNPLk52b7cXrilb37zxB3mNLwaYUemWBUl5s = g;
        mVFvGN0g7Z20C9gnmg3dQOi0WaxlG93rOq3qXwzvf = b;
        me2s65RhANOyRsxhu1Yq03OyC3v3PScDahBJyzZ8H = mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c;
    }

    mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(int intensity, int mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c)
    {
        mXLyCM8un8gwuAv0eumvDKafLA3IEdlo9qFUyabRV = intensity;
        mMAJfDNPLk52b7cXrilb37zxB3mNLwaYUemWBUl5s = intensity;
        mVFvGN0g7Z20C9gnmg3dQOi0WaxlG93rOq3qXwzvf = intensity;
        me2s65RhANOyRsxhu1Yq03OyC3v3PScDahBJyzZ8H = mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c;
    }

    int mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::muTbJumgqjGR21k8slwgaGmZcnSEvnnwczCnA5PIp()
    {
        return mXLyCM8un8gwuAv0eumvDKafLA3IEdlo9qFUyabRV;
    }

    int mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::mVb1WkMKZgUsW1zFjVtgWuUUrNfLyy8zF4tDZ5X79()
    {
        return mMAJfDNPLk52b7cXrilb37zxB3mNLwaYUemWBUl5s;
    }

    int mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::mT6wtErdvs7jEoLzhB0oL9MYZvOZZUAE0vRCmh1ZG()
    {
        return mVFvGN0g7Z20C9gnmg3dQOi0WaxlG93rOq3qXwzvf;
    }

    int mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::mRDipnnKuYrGc2vMgk6OztGQ838M76i3aqj3idGel()
    {
        return me2s65RhANOyRsxhu1Yq03OyC3v3PScDahBJyzZ8H;
    }

    bool &mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::_G()
    {
        return m4AxiIE2mGllSVSM0zWsyWkwUfm8UlWlmW3od78W6;
    }

    float mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::mPMYKoXZRC7ymWW8UgTcNTur95tKM2322CoMkkcdD()
    {
        return mXLyCM8un8gwuAv0eumvDKafLA3IEdlo9qFUyabRV / 255.f;
    }

    float mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::mDeV1CTKL3MEg5f1RgZIVvmOZDaxvXPpicBZoexe7()
    {
        return mMAJfDNPLk52b7cXrilb37zxB3mNLwaYUemWBUl5s / 255.f;
    }

    float mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::m0s7hWs5qtVEXetyLRMrq3igk20vJiYYhfJaJXVUG()
    {
        return mVFvGN0g7Z20C9gnmg3dQOi0WaxlG93rOq3qXwzvf / 255.f;
    }

    float mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::mf0wBIvVQZgseGdCq4eaeMpxq6nGxZ5PeoXE8UfKt()
    {
        return me2s65RhANOyRsxhu1Yq03OyC3v3PScDahBJyzZ8H / 255.f;
    }

    mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::mp5U74kjDpwUC8aqSH2rBVtKXT1aGGBR0evWHHxOa()
    {
        return mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255);
    }

    mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::msF2aGJQNMFZo3RFxXPw8X0gaKixKbm05c009Ogy8(mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c, mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD b, float mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU)
    {
        mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU = _MATH mGf6g1mAx7GKo2kXqOz48f6dQIuLlUZhSoiDvWkJ5::mSJi5DgfL6Oz62AYnDMSAboOd6C8hZ64nKWNw0fpq(mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU, 0.f, 1.f);
        return mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD(mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c.mPMYKoXZRC7ymWW8UgTcNTur95tKM2322CoMkkcdD() + ((b.mPMYKoXZRC7ymWW8UgTcNTur95tKM2322CoMkkcdD() - mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c.mPMYKoXZRC7ymWW8UgTcNTur95tKM2322CoMkkcdD()) * mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU), mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c.mDeV1CTKL3MEg5f1RgZIVvmOZDaxvXPpicBZoexe7() + ((b.mDeV1CTKL3MEg5f1RgZIVvmOZDaxvXPpicBZoexe7() - mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c.mDeV1CTKL3MEg5f1RgZIVvmOZDaxvXPpicBZoexe7()) * mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU),
                        mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c.m0s7hWs5qtVEXetyLRMrq3igk20vJiYYhfJaJXVUG() + ((b.m0s7hWs5qtVEXetyLRMrq3igk20vJiYYhfJaJXVUG() - mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c.m0s7hWs5qtVEXetyLRMrq3igk20vJiYYhfJaJXVUG()) * mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU), mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c.mf0wBIvVQZgseGdCq4eaeMpxq6nGxZ5PeoXE8UfKt() + ((b.mf0wBIvVQZgseGdCq4eaeMpxq6nGxZ5PeoXE8UfKt() - mp1H22YpLDzAjuZjYuX8a2BsDkZrk8NfxLUIaJY9c.mf0wBIvVQZgseGdCq4eaeMpxq6nGxZ5PeoXE8UfKt()) * mZCXTMonaRZ1EKTBpNJXDtVFV8wuILMpmWRW3C4ZU));
    }

    mbuqdKwCpQnWXPw7KPC4wSMvwzm1KL047fubOnciu::mbuqdKwCpQnWXPw7KPC4wSMvwzm1KL047fubOnciu(unsigned int alloc)
    {
        m5dIQqZmwmizKmIJQTpxdLaH3sOlVfmLr8GAq6AE2 = alloc;
        mE9E41fYtvGvf7A7qZBPIShUJMmS6iJXKIBLVRMcb = new mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD*[alloc];
        for (unsigned int i = 0; i < alloc; i++)
            mE9E41fYtvGvf7A7qZBPIShUJMmS6iJXKIBLVRMcb[i] = new mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD[alloc / 2];
        myjo4gIlvfMn1aUKvYzgy1BdlSrjNjhd6hvXlHhK1 = new mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD*[alloc];
        for (unsigned int i = 0; i < alloc; i++)
            myjo4gIlvfMn1aUKvYzgy1BdlSrjNjhd6hvXlHhK1[i] = new mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD[alloc / 2];
        mEhPwfZDKkvGyD748Ci3zfiqyGrSmkL0sgsjTbWwd = new float*[alloc];
        for (unsigned int i = 0; i < alloc; i++)
        {
            mEhPwfZDKkvGyD748Ci3zfiqyGrSmkL0sgsjTbWwd[i] = new float[alloc / 2];
            for (unsigned int mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G = 0; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < alloc / 2; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G++)
                mEhPwfZDKkvGyD748Ci3zfiqyGrSmkL0sgsjTbWwd[i][mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G] = 0.f;
        }
        mouBDaQyAwel63fSy7v0BiGyKMqHnFJr4V3wlEgFd = mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::mdSJ1AluedrHklRdbdUK4GtkHZNrfFXzA9b9pb5iK;
        mqmiRFNRy3ZpnmsYFcTYGPSXizvQPvRrAuNSZDNBa = 0;
    }

    void mbuqdKwCpQnWXPw7KPC4wSMvwzm1KL047fubOnciu::mbBQQ8ZjGGb7I3F8fGa9qidkv5yrSsg9OPwC13uDV()
    {
        for (unsigned int i = 0; i < m5dIQqZmwmizKmIJQTpxdLaH3sOlVfmLr8GAq6AE2; i++)
        {
            for (unsigned int mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G = 0; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G < m5dIQqZmwmizKmIJQTpxdLaH3sOlVfmLr8GAq6AE2 / 2; mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G++)
            {
                mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD *current = _STD addressof(mE9E41fYtvGvf7A7qZBPIShUJMmS6iJXKIBLVRMcb[i][mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G]); //& is overloaded :(
                mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD *target = _STD addressof(myjo4gIlvfMn1aUKvYzgy1BdlSrjNjhd6hvXlHhK1[i][mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G]);
                float *delta = _STD addressof(mEhPwfZDKkvGyD748Ci3zfiqyGrSmkL0sgsjTbWwd[i][mHPUQAF8hFa1csxlgYdzl1bwDVuPQ4hXX6v7cas9G]);
                *delta = fmod((*delta + mP2kAlMiG3Kb8FzP6tM2QBI7DSS03c42Apgjk0lVK::GetUIFramerateInfo()->miy7yhGaxQOlTiWA5cHO2WCB0xnXinDnM6fn1arWA * 4.f),
                              (float) MRK_COLOR_RAINBOW_COUNT);
                int ilow = (int) floor(*delta);
                int ihigh = (ilow + 1) % MRK_COLOR_RAINBOW_COUNT;
                mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD *arr = i % 2 == 0 ? mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::Rainbow : mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::InvRainbow;
                *current = mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD::msF2aGJQNMFZo3RFxXPw8X0gaKixKbm05c009Ogy8(arr[ilow], arr[ihigh], fmod(*delta, 1.f));
            }
        }
    }

    mibXzhF8ooepNQMvjPyz9MjiLsij1Dzp493vbAeqD mbuqdKwCpQnWXPw7KPC4wSMvwzm1KL047fubOnciu::mZzZuEaeuyUfEKhvs2D5FrbimlU4B2682aisoCiTI(unsigned int _, unsigned int __)
    {
        return mE9E41fYtvGvf7A7qZBPIShUJMmS6iJXKIBLVRMcb[_][__];
    }
}