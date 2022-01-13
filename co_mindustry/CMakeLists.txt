# CMakeList.txt : CMake project for co_mindustry, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

include_directories(co_mindustry PUBLIC "third_parties/windows/SDL2/include"
										"third_parties/windows/SDL2_image/include"
										"headers")

# Add source to this project's executable.
add_executable (co_mindustry "main.cpp" "src/Game.cpp" "src/TextureManager.cpp" "headers/GameObject.h" "src/GameObject.cpp")

target_link_directories(co_mindustry PUBLIC "third_parties/windows/SDL2/lib/x64")
target_link_directories(co_mindustry PUBLIC "third_parties/windows/SDL2_image/lib/x64")

#C:\Users\Mr.Smiler\source\repos\co_mindustry\co_mindustry\third_parties\windows\SDL2\lib\x64\SDL2main.lib
target_link_libraries(co_mindustry "SDL2main" "SDL2" "SDL2_image")

message("mohsen:" ${CMAKE_BINARY_DIR})
file(COPY "third_parties/windows/SDL2/lib/x64/SDL2.dll" DESTINATION ${CMAKE_BINARY_DIR}/co_mindustry)
file(COPY "third_parties/windows/SDL2_image/lib/x64/libpng16-16.dll" DESTINATION ${CMAKE_BINARY_DIR}/co_mindustry)
file(COPY "third_parties/windows/SDL2_image/lib/x64/zlib1.dll" DESTINATION ${CMAKE_BINARY_DIR}/co_mindustry)
file(COPY "third_parties/windows/SDL2_image/lib/x64/SDL2_image.dll" DESTINATION ${CMAKE_BINARY_DIR}/co_mindustry)
file(COPY "assets-raw/" DESTINATION ${CMAKE_BINARY_DIR}/co_mindustry/assets-raw)


# TODO: Add tests and install targets if needed.
