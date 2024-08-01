cmake_minimum_required(VERSION 3.2)
project(UnhappyKnight)

set(CMAKE_CXX_STANDARD 11)

add_executable(UnhappyKnight src/main.cpp
        src/Animation.cpp
        src/Animation.h
        src/Window.cpp
        src/Window.h
        src/Entity.cpp
        src/Entity.h
        src/vec2.cpp
        src/vec2.h
        src/common.h
        src/MapHandler.cpp
        src/MapHandler.h
        src/DummyEntity.cpp)




set(SDL2_LIBRARIES "SDL2")
set(SDL2_IMAGE_LIBRARIES "SDL2_image")
set(SDL2_TTF_LIBRARIES "SDL2_ttf")
set(SDL2_MIXER_LIBRARIES "SDL2_mixer")


# Link SDL2 libraries
target_link_libraries(${PROJECT_NAME}  PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL2_MIXER_LIBRARIES})



