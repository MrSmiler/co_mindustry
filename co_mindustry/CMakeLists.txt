# CMakeList.txt : CMake project for co_mindustry, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)

Set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/third_parties/windows/SFML-2.5.1/lib/cmake/SFML")
find_package (SFML COMPONENTS system window graphics network audio)
include_directories(co_mindustry PUBLIC "third_parties/windows/SFML-2.5.1/include" 
										"third_parties/entt-3.9.0/single_include"
										"third_parties/tweeny-3.2.0/include"
										"headers")


# Add source to this project's executable.
add_executable (co_mindustry "main.cpp" "src/Game.cpp" "headers/components/InputComponent.h" "headers/components/SpriteComponent.h" "src/systems/DrawSystems.cpp" "src/systems/InputSystem.cpp" "headers/systems/InputSystem.h" "headers/components/AnimationComponent.h")

# x64 libs only
target_link_libraries(co_mindustry PUBLIC sfml-graphics sfml-audio sfml-system sfml-network sfml-main sfml-window)

#C:\Users\Mr.Smiler\source\repos\co_mindustry\co_mindustry\third_parties\windows\SDL2\lib\x64\SDL2main.lib
#target_link_libraries(co_mindustry "sfml-window-s.lib" "sfml-system-s.lib" "opengl32.lib" "freetype.lib"
#								   "winmm.lib" "gdi32.lib" "ws2_32.lib" "winmm.lib"
#								   "openal32.lib" "flac.lib" "vorbisenc.lib" "vorbisfile.lib" "vorbis.lib" "ogg.lib"
#								   "sfml-graphics-s.lib" "sfml-audio-s.lib" "sfml-network-s.lib")

file(COPY "third_parties/windows/SFML-2.5.1/bin/" DESTINATION ${CMAKE_BINARY_DIR}/co_mindustry)
file(COPY "assets-raw/" DESTINATION ${CMAKE_BINARY_DIR}/co_mindustry/assets-raw)


# TODO: Add tests and install targets if needed.
