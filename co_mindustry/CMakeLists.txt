# CMakeList.txt : CMake project for co_mindustry, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
Set(CMAKE_MODULE_PATH "$ENV{VCPKG_ROOT}/${VCPKG_TARGET_TRIPLET}/share/sfml")
find_package(SFML COMPONENTS system window graphics network audio)
find_package(Tweeny CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)
find_package(box2d CONFIG REQUIRED)
include_directories(co_mindustry PUBLIC "headers")
include_directories("$ENV{VCPKG_ROOT}/${VCPKG_TARGET_TRIPLET}/include")


# Add source to this project's executable.
add_executable (mindustry "main.cpp" "src/Game.cpp" "headers/components/InputComponent.h" "headers/components/SpriteComponent.h" "src/systems/DrawSystems.cpp" "src/systems/InputSystem.cpp" "headers/systems/InputSystem.h" "headers/components/AnimationComponent.h" "headers/components/MovementComponent.h" "headers/components/PhysicComponent.h")

# x64 libs only
target_link_libraries(mindustry PUBLIC sfml-graphics sfml-audio sfml-system sfml-network sfml-main sfml-window)
target_link_libraries(mindustry PRIVATE box2d::box2d)

file(COPY "assets-raw/" DESTINATION ${CMAKE_BINARY_DIR}/co_mindustry/assets-raw)


# TODO: Add tests and install targets if needed.
