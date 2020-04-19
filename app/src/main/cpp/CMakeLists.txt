# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

set(OBFUSCATED_BUILD "false")

if ( ${OBFUSCATED_BUILD} STREQUAL "true" )

    add_library( # Sets the name of the library.
            mrk

            # Sets the library as a shared library.
            SHARED

            # Provides a relative path to your source file(s).
            obf/mrkui/MRKUI.c

            obf/mrk/gui/MRKDisplay.cpp
            obf/mrk/gui/MRKGUI.cpp
            obf/mrk/gui/MRKGuiBaseButton.cpp
            obf/mrk/gui/MRKGuiBaseButtonEx.cpp
            obf/mrk/gui/MRKGuiBaseLabel.cpp
            obf/mrk/gui/MRKGuiBaseSlider.cpp
            obf/mrk/gui/MRKGuiBaseWidget.cpp
            obf/mrk/gui/MRKGuiBaseWindow.cpp
            obf/mrk/gui/MRKTheme.cpp

            obf/mrk/components/MRKGuiComponent.cpp
            obf/mrk/components/MRKGuiComponentDebugger.cpp
            obf/mrk/components/MRKGuiComponentLoader.cpp

            obf/mrk/utils/MRKUtils.cpp

            obf/mrk/math/MRKMath.cpp

            obf/mrk/MRKStringStore.cpp

            obf/mrk/MRKApplication.cpp
            obf/mrk/MRKColor.cpp
            obf/mrk/MRKLog.cpp
            mrk/MRKResources.cpp
            obf/mrk/MRKProxy.cpp
            obf/mrk/MRKNativeMain.cpp
            )
else()

add_library( # Sets the name of the library.
             mrk

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             mrkui/MRKUI.c

             mrk/gui/MRKDisplay.cpp
             mrk/gui/MRKGUI.cpp
             mrk/gui/MRKGuiBaseButton.cpp
             mrk/gui/MRKGuiBaseButtonEx.cpp
             mrk/gui/MRKGuiBaseLabel.cpp
             mrk/gui/MRKGuiBaseSlider.cpp
             mrk/gui/MRKGuiBaseWidget.cpp
             mrk/gui/MRKGuiBaseWindow.cpp
             mrk/gui/MRKTheme.cpp

             mrk/components/MRKGuiComponent.cpp
             mrk/components/MRKGuiComponentDebugger.cpp
             mrk/components/MRKGuiComponentLoader.cpp

             mrk/utils/MRKUtils.cpp

             mrk/math/MRKMath.cpp

             mrk/MRKApplication.cpp
             mrk/MRKColor.cpp
             mrk/MRKLog.cpp
             mrk/MRKResources.cpp
             mrk/MRKProxy.cpp
             mrk/MRKNativeMain.cpp
        )

ENDIF()

add_library(
        mrkproxy

        SHARED

        mrkproxy/MRKProxyDynamic.cpp
        mrkproxy/MRKUIExample2.cpp
)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries(
        mrk
        android
        log
        EGL
        GLESv2)