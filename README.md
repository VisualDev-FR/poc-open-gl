# build GLFW

## Requirements

* download [GLFW source package](https://github.com/glfw/glfw/releases/download/3.4/glfw-3.4.zip) into `./lib/glfw-3.4`

* installing Cmake [windowsX64 Installer]( https://cmake.org/download/)

## [Compiling GLFW](https://www.glfw.org/docs/latest/compile_guide.html)

in [lib/glfw/CMakelists.txt](./lib/glfw-3.4/CMakelists.txt), add the following lines right after `cmake_minimum_required`:

```cmake
set(CMAKE_CXX_COMPILER "C:/mingw64/bin/g++.exe")
set(CMAKE_C_COMPILER "C:/mingw64/bin/gcc.exe")
```

or add them into env variables

then build GLFW

```cmd
cd ./lib/glfw-3.4
cmake.exe -S . -B .\build\ -G "MinGW Makefiles"
cd ./build
mingw32-make.exe
```

## [Building applications](https://www.glfw.org/docs/latest/build_guide.html)


# Resources:

* [Beginner's Guide to Linkers](https://www.lurklurk.org/linkers/linkers.html)
* [CMake guide](https://cmake.org/cmake/help/latest/guide/user-interaction)
* [How to include GLAD](https://rpxomi.github.io/)