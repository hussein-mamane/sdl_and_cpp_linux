#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "common.h"
#include "Window.h"
#include "DummyEntity.h"

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) > 0) {
        LOG("SDL_Init has failed");
        LOG(SDL_GetError());
    }
    if (!(IMG_Init(IMG_INIT_PNG))) {
        LOG("IMG_Init has failed");
        LOG(SDL_GetError());
    }


    Window window("Game v1.0",640,480);
    //TODO fix warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings] on next line

    //TODO this should be in entity init method
    
    Entity entity = Entity(vec2(10, 10),"idle");
    window.loadTexture("../gfx/knight/Idle.png","idle",entity);
    window.loadTexture("../gfx/knight/Run.png","run",entity);
    entity.animations["idle"].makeFrameArray(0,4,0,2,128,64);
    entity.animations["run"].makeFrameArray(0,4,0,2,128,64);
    
    //end entity initialization

    //DummyEntity entity;
    bool gameRunning = true;
    SDL_Event event;
    const float timeStep = 0.01f;
    float currentTime = hireTimeInSeconds();
    float lag = 0.0f;
    int i = 0;
    short lastDirection = 0;
    bool entityMove = false;
    float frameTimeAnimate = 0.0f;
    while(gameRunning)
    {
        float newTime = hireTimeInSeconds();
        uint32_t startTicks = SDL_GetTicks();
        float elapsed = newTime - currentTime;

        frameTimeAnimate+=elapsed;
        /*
         * No speed or acceleration:
         * 8 images in the running animation, must take 1 seconds to go through the 8 images
         * everytime 1/8 of a second elapse, the animation increment to the next image
         * when stop running, this process stop
         * */
        currentTime = newTime;
        lag+=elapsed;

        //should reason on the timeStep instead of this
        if(entityMove){
            if(frameTimeAnimate > (float(window.getRefreshRate())*0.001)/8*10){
                //this should be in entity animate method
//                entity.setCurrentframeIndex(i);
//                i == 7 ? i = 0: ++i;
                /*
                for every entity :
                    update position
                for every entity :
                    update physics
                for every entity :
                    update animation state
                for every entity :
                    update audio
                for every entity:
                    update ai
                present current render state and present current audio by playing them
                */
                entity.updateFrameIndex();
                //end animate
                frameTimeAnimate = 0;
                //LOG(entity.animations[entity.getCurrentState()].frameArray.size());
            }
        }


        while (lag>=timeStep)
        {
            while(SDL_PollEvent(&event)){
                if(event.type == SDL_QUIT)
                    gameRunning = false;

                /** TODO Input handling should belong to its own function,  Handle Events, Call game loop callables*/
                 if(event.type == SDL_KEYDOWN){
                    entityMove = true;
                    if (event.key.keysym.scancode==SDL_SCANCODE_LEFT) {
                        entity.setPosition(vec2(entity.getPosition().getX() - 1, entity.getPosition().getY()));
                        entity.direction = 1;

                    }
//                  //another way of getting input
                    if (event.key.keysym.sym==SDLK_RIGHT) {
                        entity.direction = 0;
                        entity.setPosition(vec2(entity.getPosition().getX() + 1, entity.getPosition().getY()));
                    }
                    if (entity.direction != lastDirection){
                        entity.flip=!entity.flip;
                    }
                    lastDirection=entity.direction;
                    if (event.key.keysym.sym==SDLK_SPACE) {
                        entity.setCurrentState("run");
                    }
                }
                if(event.type == SDL_KEYUP){//bad to always think on one key at a time, now every keyup makes him idle
                    // even when there are some other keydown at the same time that should keep him going

                    if (event.key.keysym.sym==SDLK_SPACE) {
                        entity.setCurrentState("idle");
                    }
                    if (event.key.keysym.sym==SDLK_LEFT || event.key.keysym.sym==SDLK_RIGHT ) {
                        entity.setCurrentState("idle");
                        entityMove = false;
                    }
                }
                

            }
            lag-=timeStep  ;//fps varies according to speed of processing
        }

        //linear interpolation for physics state
        //const float alpha = lag/timeStep;// percentage of the timeStep that got realised, to guess physics movement between 2 updates

        window.clear();
        // Entity or Entity& or auto

      
        //render
        window.renderEntity(entity,2,entity.getCurrentState());
        //reset animation state
        
        window.display();

        uint32_t endTicks = SDL_GetTicks()-startTicks;
        if(endTicks<1000/window.getRefreshRate()){//faster than refresh rate
            SDL_Delay(1000/window.getRefreshRate()-endTicks);//wait
        }
    }
    window.CleanUp();
    SDL_Quit();
    return 0;
}
