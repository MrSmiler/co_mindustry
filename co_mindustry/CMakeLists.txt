# CMakeList.txt : CMake project for co_mindustry, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
Set(CMAKE_MODULE_PATH "$ENV{VCPKG_ROOT}/${VCPKG_TARGET_TRIPLET}/share/sfml")
find_package(SFML COMPONENTS system window graphics network audio)
find_package(Tweeny CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)
include_directories(co_mindustry PUBLIC "headers")
include_directories("$ENV{VCPKG_ROOT}/${VCPKG_TARGET_TRIPLET}/include")


# Add source to this project's executable.
add_executable (co_mindustry "main.cpp" "src/Game.cpp" "headers/components/InputComponent.h" "headers/components/SpriteComponent.h" "src/systems/DrawSystems.cpp" "src/systems/InputSystem.cpp" "headers/systems/InputSystem.h" "headers/components/AnimationComponent.h" "headers/components/MovementComponent.h")

set(CMAKE_CXX_FLAGS_DEBUG
  "/DWIN32 /D_WINDOWS /EHsc /WX /wd4355 /wd4251 /wd4250 /wd4996"
  CACHE STRING "Debug compiler flags" FORCE
)
# x64 libs only
target_link_libraries(co_mindustry PUBLIC sfml-graphics sfml-audio sfml-system sfml-network sfml-main sfml-window)

#C:\Users\Mr.Smiler\source\repos\co_mindustry\co_mindustry\third_parties\windows\SDL2\lib\x64\SDL2main.lib
#target_link_libraries(co_mindustry "sfml-window-s.lib" "sfml-system-s.lib" "opengl32.lib" "freetype.lib"
#								   "winmm.lib" "gdi32.lib" "ws2_32.lib" "winmm.lib"
#								   "openal32.lib" "flac.lib" "vorbisenc.lib" "vorbisfile.lib" "vorbis.lib" "ogg.lib"
#								   "sfml-graphics-s.lib" "sfml-audio-s.lib" "sfml-network-s.lib")

#file(COPY "third_parties/windows/SFML-2.5.1/bin/" DESTINATION ${CMAKE_BINARY_DIR}/co_mindustry)
file(COPY "assets-raw/" DESTINATION ${CMAKE_BINARY_DIR}/co_mindustry/assets-raw)


# TODO: Add tests and install targets if needed.
