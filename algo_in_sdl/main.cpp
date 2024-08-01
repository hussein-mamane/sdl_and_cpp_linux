#include<vector>
#include<memory>
#include <iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

/*textures loading, use logic to load what you need only
    SDL_Surface* surf = IMG_Load(groundImagePath);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(window.getRenderer(),surf);
    SDL_RenderCopy(

            )
    SDL_FreeSurface(surf);*/

#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 640

SDL_Window* window = SDL_CreateWindow("Dijkstra",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_SHOWN);
SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
bool quit = false;
bool play_simulation = false;
SDL_Event event;

SDL_Rect rect1 = {25,25,50,50};
SDL_Rect rect2 = {400,45,50,50};
SDL_Rect rect3 = {300,300,50,50};
SDL_Rect rect4 = {560,400,50,50};
SDL_Rect rect5 = {650,350,50,50};



SDL_Rect* selectedRect;//for the drag and drop
SDL_Point mousePosition;//mousePosition of mouse
SDL_Point clickOffset;//to avoid rectangle jumping to mouse
bool mouseLeftClicked;//to know if we start dragging


// returning values instead of addresses avoid memory leak easily, but here lets use delete
// unique_ptr is the best way 
SDL_Point* getRectCenter(const SDL_Rect& rect){
    auto* point =  new SDL_Point;//Allocated memory is leaked when called from function 'updateCenters'
    point->x = rect.x+rect.w/2;
    point->y = rect.y+rect.h/2;
    return point;
}

void updateCenters(const std::vector<SDL_Rect>& rects,std::vector<SDL_Point>& centers){
        centers.clear();
        for(auto& rect:rects){
            //centers.push_back(*getRectCenter(rect));//Allocated memory is leaked
            SDL_Point* p = getRectCenter(rect);
            centers.push_back(*p);
            delete p;//no more memory leak
        }
}

void linkTwoNodes(SDL_Renderer* p_renderer, const SDL_Point& p1, const SDL_Point& p2){
    SDL_RenderDrawLine(p_renderer,p1.x,p1.y,p2.x,p2.y);
}

int Init(){
     // init procedure
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER)>0)
    {
        std::cout << "INIT ERROR";
        return 1;
    }
    if(!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "INIT IMG ERROR";
        return 2;
    }
    return 0;
}

void getPath(const SDL_Point&  from, const SDL_Point& to){
    
}

void moveToPoint(const SDL_Renderer* renderer, const std::vector<SDL_Point>& path){
    
}
int main(int argc,char** argv) {
   
   if(Init()!=0)
        exit(1);
    SDL_Texture* car = IMG_LoadTexture(renderer,"car128.png");
    if(car == nullptr){
        std::cout << "Could not load texture" << "\n";
    }
    SDL_Rect src = {0,0,128,128};
    SDL_Rect dst = {0,0,128,128};


    // Entities Creation
    // this particular piece of code only works in main , why ?
    std::vector<SDL_Rect> my_rects {};
    my_rects.push_back(rect1);
    my_rects.push_back(rect2);
    my_rects.push_back(rect3);
    my_rects.push_back(rect4);
    my_rects.push_back(rect5);

    std::vector<SDL_Point> rects_centers {};
    // main loop 
    while(!quit)
    {
        SDL_PollEvent((&event));
        if(!play_simulation){
            switch(event.type) {

            case SDL_QUIT:
                quit = true;
                break;
            case SDL_MOUSEMOTION:
                mousePosition = {event.motion.x, event.motion.y};
                if (selectedRect != nullptr) {
                    selectedRect->x = event.motion.x - clickOffset.x;
                    selectedRect->y = event.motion.y - clickOffset.y;
                }
                break;
            case SDL_MOUSEBUTTONUP:
                if (mouseLeftClicked) {
                    mouseLeftClicked = false;
                    selectedRect = nullptr;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                    mouseLeftClicked = true;
                for (auto &rect: my_rects) {
                    if (SDL_PointInRect(&mousePosition, &rect)) {
                        selectedRect = &rect;
                        clickOffset.x = mousePosition.x - rect.x;
                        clickOffset.y = mousePosition.y - rect.y;
                        break;
                    }
                }
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.scancode == SDL_SCANCODE_F) {
                    play_simulation = true;
                    SDL_RenderClear(renderer);
                }
        }
        }//endif play_simulation
        switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.scancode == SDL_SCANCODE_G) {
                        play_simulation = false;
                    }
                    break;
        }

        // Redraw tree
        SDL_SetRenderDrawColor(renderer,125,148,94,1);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer,255,255,255,0);

        for(const SDL_Rect& rect: my_rects){
            if(&rect == selectedRect){
                SDL_SetRenderDrawColor(renderer,0,0,255,0);
                SDL_RenderFillRect(renderer,&rect);
            }
            else
            {
                SDL_SetRenderDrawColor(renderer,255,255,255,0);
                SDL_RenderFillRect(renderer,&rect);
            }
            SDL_SetRenderDrawColor(renderer,255,255,255,0);
            updateCenters(my_rects,rects_centers);
          

            linkTwoNodes(renderer,rects_centers[0],rects_centers[1]);
            linkTwoNodes(renderer,rects_centers[4],rects_centers[2]);
            linkTwoNodes(renderer,rects_centers[1],rects_centers[2]);
            linkTwoNodes(renderer,rects_centers[3],rects_centers[1]);
            linkTwoNodes(renderer,rects_centers[0],rects_centers[3]);
            linkTwoNodes(renderer,rects_centers[2],rects_centers[3]);

        }
		
		if(!play_simulation)
		{
			
		}
		else
		{
            //calculateDjikstra, set a path of Node orders, Nodes are rects in my_rects, Doing this only once


            //move from current SDL_Point to next SDL_Point

            //updatePath, remove the 

            

            //playAnimation
			
			SDL_Delay(16);
			
		}
		SDL_RenderCopy(renderer,car,&src,&dst);
        SDL_RenderPresent(renderer);
    }

    //Cleanup 
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
