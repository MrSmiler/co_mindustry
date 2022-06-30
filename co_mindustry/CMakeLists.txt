# CMakeList.txt : CMake project for co_mindustry, include source and define
# project specific logic here.
#
set(CMAKE_CXX_STANDARD 20)
# set(Python3_LIBRARIES "vcpkg_installed/${VCPKG_TARGET_TRIPLET}/lib")
#Set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "$ENV{VCPKG_ROOT}/${VCPKG_TARGET_TRIPLET}/share/sfml")
#Set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "vcpkg_installed/${VCPKG_TARGET_TRIPLET}/share/python3")
find_package(SFML COMPONENTS system window graphics network audio)
find_package(Tweeny CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)
find_package(box2d CONFIG REQUIRED)
find_package(Python3 COMPONENTS Development REQUIRED)

include_directories(co_mindustry PUBLIC "headers")
include_directories("vcpkg_installed/${VCPKG_TARGET_TRIPLET}/include")


# Add source to this project's executable.
add_executable (mindustry "main.cpp" "src/Game.cpp" "src/systems/DrawSystems.cpp" "src/systems/InputSystem.cpp" "headers/utils/vector2d.h" "headers/components/CameraComponent.h")

# x64 libs only
target_link_libraries(mindustry PRIVATE sfml-graphics sfml-audio sfml-system sfml-network sfml-main sfml-window)
target_link_libraries(mindustry PRIVATE box2d::box2d)
target_link_libraries(mindustry PRIVATE Python3::Python)

file(COPY "assets-raw/" DESTINATION ${CMAKE_BINARY_DIR}/co_mindustry/assets-raw)
file(COPY "${CMAKE_BINARY_DIR}/vcpkg_installed/${VCPKG_TARGET_TRIPLET}/tools/python3/lib" DESTINATION ${CMAKE_BINARY_DIR}/co_mindustry)


# TODO: Add tests and install targets if needed.
