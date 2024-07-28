# OpenGL Project
> Just a fun little project to learn the ins and outs of OpenGL using GLFW3

## Objective
Write a simple game from scratch using the minimum required libraries.

### Non-standard libraries used
- [**GLEW**](https://glew.sourceforge.net/): A cross-platform open-source extension loading library. In short, it loads the OpenGL extensions (funtions, variales) into our project. (_Note that OpenGL is not a library, but a specificacion that hardware drivers use_)
- [**GLFW**](https://www.glfw.org/): A cross-platform open-source API that handles the basics of windows, contexts, receiving input and OS events. Basically necesary for windows, since programs don't have low level access to the OS.


## SETUP
> Windows 10, AMD CPU, Nvidia GPU

### IDE
[VSCodium](https://vscodium.com/) with the following extensions:
- C/C++ Extension Pack (Microsoft)
- C/C++ (Microsoft)
- C/C++ Themes (Microsoft)
- CMake Tools (Microsoft)
- CMake (twxs)
- GitLens - Git supercharged (GitKreaken)
- Git History 
 
 ### [MSYS2](https://www.msys2.org/) Toolchain
> Install it in C:\\ and always use UCRT64. I say this to make it easier to link up the libraries with CMake down the line.

Packages installed:
- **CMake**: the tool that supposedly will make my life easier when builing my project ```pacman -S mingw-w64-ucrt-x86_64-cmake```
- **GCC**: C/C++ Compiler```pacman -S mingw-w64-ucrt-x86_64-gcc```
- **GBD**: C/C++ Debug tool (VSCodium uses it and works pretty well)```pacman -S mingw-w64-ucrt-x86_64-gdb```
- **GLEW**: ```pacman -S mingw-w64-ucrt-x86_64-glew```
- **GLFW**: ```pacman -S mingw-w64-ucrt-x86_64-glfw```



