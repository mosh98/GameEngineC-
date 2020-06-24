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
        
//        Uint32 red = SDL_MapRGB(screen->format, 255, 0, 0); defineing a color
        
//        SDL_FillRect(screen, NULL, red); Filling a quick rectangle with red color.
        

//        Sprite object = new Sprite(red, xpos/2, ypos/2); 
        
//        object.draw(screen);
    
        isRuning = true;
    }else{
        isRuning = false;
    }
       
}

void GameEngine::handleEvents(){
    SDL_Event event;
    
    SDL_PollEvent(&event);
    
        switch (event.type) {
            case SDL_QUIT:
                isRuning = false;
                break;
                
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
