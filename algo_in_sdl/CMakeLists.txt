cmake_minimum_required(VERSION 3.2)
project(algo_in_sdl)


set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME} main.cpp)

# Set paths to SDL2 and its components
# set(SDL2_INCLUDE_DIRS "/usr/include/SDL2")


# set(SDL2_LIBRARIES "-L/usr/lib -lSDL2")
# set(SDL2_IMAGE_LIBRARIES "-lSDL2_image")
# set(SDL2_TTF_LIBRARIES "-lSDL2_ttf")
# set(SDL2_MIXER_LIBRARIES "-lSDL2_mixer")


set(SDL2_LIBRARIES "SDL2")
set(SDL2_IMAGE_LIBRARIES "SDL2_image")
set(SDL2_TTF_LIBRARIES "SDL2_ttf")
set(SDL2_MIXER_LIBRARIES "SDL2_mixer")


# Link SDL2 libraries
target_link_libraries(${PROJECT_NAME}  PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL2_MIXER_LIBRARIES})
  



