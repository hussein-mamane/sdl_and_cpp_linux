//
// Created by Housseini on 08/05/2024.
//

#include "Window.h"
#include "common.h"
#include "Entity.h"
#include <SDL2/SDL_image.h>
#include <iostream>


void Window::CleanUp(){
    SDL_DestroyWindow(window);
}

void Window::clear(){
//    SDL_SetRenderDrawColor(renderer,255,255,255,0);//white
//    SDL_SetRenderDrawColor(Renderer,0,0,0,0);//black
    SDL_SetRenderDrawColor(Renderer,0,255,0,0);//green
    SDL_RenderClear(Renderer);
}

int Window::getRefreshRate() {
    int displayIndex= SDL_GetWindowDisplayIndex(window);
    SDL_DisplayMode  displayMode;
    SDL_GetDisplayMode(displayIndex,0,&displayMode);
    return displayMode.refresh_rate;
}

void Window::display() {
    SDL_RenderPresent(Renderer);
}

void Window::renderEntity(Entity& p_ent,int scale,const char* textureName){
    SDL_Rect src,dst;


    src.x = p_ent.getCurrentframe().x;
    src.y = p_ent.getCurrentframe().y;
    src.w = p_ent.getCurrentframe().w;
    src.h = p_ent.getCurrentframe().h;

    dst.x = p_ent.getPosition().getX() * scale;
    dst.y = p_ent.getPosition().getY() * scale;
    dst.w = p_ent.getCurrentframe().w*scale;
    dst.h = p_ent.getCurrentframe().h*scale;
    if(!p_ent.flip)
        SDL_RenderCopy(Renderer,p_ent.getTexture(textureName),&src,&dst);
    else
        SDL_RenderCopyEx(Renderer,p_ent.getTexture(textureName),&src,&dst,180,nullptr,SDL_FLIP_VERTICAL);

}
//Relevant Docs:
/*
 * *
 * Syntax

int SDL_RenderCopyEx(SDL_Renderer * renderer,
                   SDL_Texture * texture,
                   const SDL_Rect * srcrect,
                   const SDL_Rect * dstrect,
                   const double angle,
                   const SDL_Point *center,
                   const SDL_RendererFlip flip);

Function Parameters
renderer 	the rendering context
texture 	the source texture
srcrect 	the source SDL_Rect structure or NULL for the entire texture
dstrect 	the destination SDL_Rect structure or NULL for the entire rendering target
angle 	an angle in degrees that indicates the rotation that will be applied to dstrect, rotating it in a clockwise direction
center 	a pointer to a point indicating the point around which dstrect will be rotated (if NULL, rotation will be done around dstrect.w / 2, dstrect.h / 2)
flip 	a SDL_RendererFlip value stating which flipping actions should be performed on the texture
Return Value

Returns 0 on success or a negative error code on failure; call SDL_GetError() for more information.
 */


/**
 * @brief The window loads a texture and adds it to an entity, because the windows owns the renderer needed for loading
 * @param animationName of type const char* : animation slot to add the texture
 * @param path of type const char* : path of the texture in storage
 * @param e of type Entity& : entity that will receive the texture
 */
void Window::loadTexture(const char *path, const char *animationName, Entity &e) {
    SDL_Texture* texture = nullptr;
    texture = IMG_LoadTexture(Renderer,path);
    if(texture==nullptr){
        LOG("texture loading : SDL_GetError");
        LOG(SDL_GetError());
    }
    e.addTexture(texture,animationName);
}

Window::Window(const char *title, int width, int height) {
    window = SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
                              width,height,SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        LOG("Window initialisation failed");
        LOG(SDL_GetError());
    }
    Renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

}

void Window::renderBackgroundLayer(int width, int height, int h_offset, int w_offset, const char *textureName) {

}
