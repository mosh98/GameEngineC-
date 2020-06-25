//
//  GameEngine.cpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud on 2020-06-19.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.
//

#include "GameEngine.h"


GameEngine::GameEngine(){}

GameEngine::~GameEngine(){}


//INITIALIZE
void GameEngine::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    
    int flag = 0;
    if(fullscreen){
        flag = SDL_WINDOW_FULLSCREEN;
    }
    
    if( SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialized!...." << std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        
        if(renderer){
               SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
               std::cout << "Renderer Initialized!...." << std::endl;
           }
        
        
        screen = SDL_GetWindowSurface(window);//This "canvas" is where we gonna append our bmp picture to!
        


        TriangleSprite sprite(NULL,0,0);
        
        sprite.set_image("triangle-clipart-triangle-shape-1-original.bmp");
        sprite.set_position(100, 100);
        sprite.draw(screen);
        Controllersprite = &sprite;
        
        SDL_UpdateWindowSurface(window);
        //object.draw(screen);
    
        isRuning = true;
    }else{
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
                
            case SDLK_LEFT:
                
                //active_sprites.draw(screen);
                
                Controllersprite->decreaseX();
                Controllersprite->draw(screen);
                
                SDL_UpdateWindowSurface(window);
                break;
                
            case SDLK_RIGHT:
                SDL_RenderClear(renderer);
                //block.increaseX();
                //active_sprites.draw(screen);
                Controllersprite->increaseX();
                Controllersprite->draw(screen);
                
                SDL_UpdateWindowSurface(window);
                
            default:
                break;
        }
  
        
}

    void GameEngine::update(){
        cnt++;
    }

    void GameEngine::render(){
    
        //This is used to redner things, kinda like a refresh after every event than occurs.
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        
    }

void GameEngine::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "SDL CLEANED and DESTROYED!...." << std::endl;
}

bool GameEngine::running(){
    return isRuning;
}
