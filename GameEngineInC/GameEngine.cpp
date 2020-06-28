//
//  GameEngine.cpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud on 2020-06-19.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.
//

#include "GameEngine.h"


SDL_Texture *playerTex;

SDL_Rect srcR, destR;
PlayerSprite sprite(NULL,0,0);

GameEngine::GameEngine(){}

GameEngine::~GameEngine(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

}


//INITIALIZE
void GameEngine::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    
    int flag = 0;
    if(fullscreen){
        flag = SDL_WINDOW_FULLSCREEN;
    }
    
    if( SDL_Init(SDL_INIT_EVERYTHING) == 0 ) {
        std::cout << "Subsystems Initialized!...." << std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        
        if(renderer){
               SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
               std::cout << "Renderer Initialized!...." << std::endl;
           }
        
        
        screen = SDL_GetWindowSurface(window);//This "canvas" is where we gonna append our bmp picture to!
        
        //TriangleSprite sprite(NULL,0,0);
        playerTex = sprite.set_image("/Users/moslehmahamud/Documents/GameEngineInC/GameEngineInC/triangle-clipart-triangle-shape-1-original.png", renderer);
        
        sprite.set_position(100, 100);
        
        //destR = &sprite.getRect();
        srcR = sprite.getRect();
       // SDL_RectEquals(&destR, &sprite.getRect());
        
        SDL_RenderClear(renderer);
        
        /* Up until now everything was drawn behind the scenes.
         This will show the new contents of the window. */
        
        
//        SDL_Surface* tmpSurface = IMG_Load("/Users/moslehmahamud/Downloads/triangle-clipart-triangle-shape-1/triangle-clipart-triangle-shape-1-original.png");
//
//        playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
//        SDL_FreeSurface(tmpSurface);//Clear surface
        
        
        //clearing stuff
        SDL_RenderPresent(renderer);
        SDL_UpdateWindowSurface(window);
        isRuning = true;
    }
    else{
        isRuning = false;
    }
    
}

void GameEngine::handleEvents(){
    SDL_Event event;
    
    SDL_PollEvent(&event);
    
        switch (event.key.keysym.sym) {
            case SDL_QUIT:
                isRuning = false;
                break;
                
                
            case SDLK_UP:
                sprite.increaseY();
                //sprite.draw(screen);
                SDL_UpdateWindowSurface(window);
                render();
                break;
                
            case SDLK_LEFT:
               
                sprite.decreaseX();
                //sprite.draw(screen);
                SDL_UpdateWindowSurface(window);
                render();
                break;
                
            case SDLK_RIGHT:
                SDL_RenderClear(renderer);

                sprite.increaseX();
                //sprite.draw(screen);
                SDL_FreeSurface(screen);
                SDL_UpdateWindowSurface(window);
                render();
            default:
                break;
        }
  
        
}

    void GameEngine::update(){
        cnt++;
        destR.h = 32;
        destR.w = 32;
        
    }

    void GameEngine::render(){
    
        //This is used to redner things, kinda like a refresh after every event than occurs.
        SDL_RenderClear(renderer);
        //RenderCopy
        SDL_RenderCopy(renderer, playerTex, NULL, &destR);
        //SDL_RenderCopy(renderer, playerTex, NULL, sprite.getRect());
        SDL_RenderPresent(renderer);
        
    }

void GameEngine::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    IMG_Quit();
    
    
    SDL_Quit();
    std::cout << "SDL CLEANED and DESTROYED!...." << std::endl;
}

bool GameEngine::running(){
    return isRuning;
}
