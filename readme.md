## Description
This is a basic side project of mine in which I intend to make
a relatively small game by building a basic framework using C++
and CMake.

## Libraries
- SDL2
- SDL2_image
- SDL2_mixer
- spdlog (header only)

## How to Compile
1. have the SDL libraries on your computer, and defined under `CMAKE_PREFIX_PATH` within the System environment variables
2. Build the project. The SDL2/SDL2main DLLs should install automatically, but you may have to manually install the DLLs for image and mixer
3. It *should* run fine after this, but I haven't tested it on any other machines, so I can't guarantee it.