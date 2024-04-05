# MRK-Android-Dev

## Introduction
`MRK-Android-Dev` is an Android Low-Level/High-Level rendering API using OpenGL powered by [nanovg](https://github.com/memononen/nanovg). This project is designed to provide developers with a powerful tool for creating complex graphics and dynamic injectable user interfaces on the Android platform.

## Features
- **Low-Level Rendering**: Direct access to the rendering pipeline for maximum control over graphics output.
- **High-Level Abstractions**: Simplified interfaces for common rendering tasks, making it easier to develop complex applications.
- **Mono Piping**: Integration with Mono framework for cross-platform development.
- **Modified NanoVG**: Utilizes a customized version of the NanoVG library for vector graphics rendering.
- **UI Widgets**: A collection of pre-built widgets that can be easily customized and integrated into any app.
- **Focusable Elements**: UI components that support focus management, essential for navigation and accessibility.
- **Dynamic Component System**: Allows for the creation and management of UI components at runtime.

## Component Example
The [MRKGuiComponentBaseDT2_REF.cpp](https://github.com/MRKDaGods/MRK-Android-Dev/blob/master/app/src/main/cpp/mrk/components/DT2/MRKGuiComponentBaseDT2_REF.cpp) file serves as an example of a fully-fledged component that renders an extensive UI featuring my [Dead Trigger 2 cheat](https://github.com/MRKDaGods/LMSDT2) back in 2019.

The `MRKGuiComponentBaseDT2_REF` component utilizes the [Mono Pipe](https://github.com/MRKDaGods/MRK-Android-Dev/blob/master/app/src/main/cpp/mrk/mono/MRKMonoCore.cpp) to communicate dynamically with the [C# payload injected](https://github.com/MRKDaGods/LMSDT2/blob/master/LMSDT2/HackManager.cs) in the game.

## Demo
**MRKGuiComponentBaseDT2_REF** component dynamically running in DeadTrigger2 [video](https://www.youtube.com/watch?v=ulzrKuPOiMY)
<br /> <br />

The [MRKGuiComponentDebugger](https://github.com/MRKDaGods/MRK-Android-Dev/blob/master/app/src/main/cpp/mrk/components/MRKGuiComponentDebugger.cpp) component rendered in different android processes:

**Call Of Duty Mobile** <br/>
<img src="https://github.com/MRKDaGods/MRK-Android-Dev/assets/25166537/2ba078c3-9a74-4f42-b78c-83ef6247a835.jpg" width="600" />

**Critical Ops** <br/>
<img src="https://github.com/MRKDaGods/MRK-Android-Dev/assets/25166537/1bd7feed-26cf-488b-a70d-0b690024cd44.jpg" width="600" />

**Bullet Force** <br/>
<img src="https://github.com/MRKDaGods/MRK-Android-Dev/assets/25166537/a1aa3e17-8554-4870-89a6-8c260245c84c.jpg" width="600" />

**Dead Trigger 2** <br/>
<img src="https://github.com/MRKDaGods/MRK-Android-Dev/assets/25166537/a4236798-0e38-42c3-b9b4-24a3daba7c1a.jpg" width="600" />

**Shadowgun Legends** <br/>
<img src="https://github.com/MRKDaGods/MRK-Android-Dev/assets/25166537/a057b857-4fc3-41b2-ae2e-b2c28c7b8431.jpg" width="600" />

**Custom unity game** <br/>
<img src="https://github.com/MRKDaGods/MRK-Android-Dev/assets/25166537/05d1e575-14a4-4179-9d4c-3b2a026c9be4.jpg" width="600" />

**Standard android app** <br/>
<img src="https://github.com/MRKDaGods/MRK-Android-Dev/assets/25166537/34d8be54-698f-450d-aa86-c20a60aa2959.jpg" width="600" />

