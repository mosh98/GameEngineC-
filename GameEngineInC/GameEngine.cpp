//
//  GameEngine.cpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud on 2020-06-19.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.
//

#include "GameEngine.h"


SDL_Texture *playerTex;
char *homeDir = getenv("PATH");

SDL_Rect srcR, destR;
PlayerSprite sprite(NULL,400,500,48,48);

GameEngine::GameEngine(){}

GameEngine::~GameEngine(){
    clean();
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
        //Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/triangle-clipart-triangle-shape-1-original.png
        
        
       
        std::cout<<homeDir<<std::endl;
        
        playerTex = sprite.set_image("/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/triangle-clipart-triangle-shape-1-original.png", renderer);
        
        //playerTex = sprite.set_image(imageLink, renderer);
        
        sprite.renCpy(renderer, playerTex);
        
        
        
        /* Up until now everything was drawn behind the scenes.
         This will show the new contents of the window. */
        
        //clearing stuff
        SDL_RenderClear(renderer);
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
    
    
        if(SDL_QUIT == event.type){
            //SDL_FlushEvent(&event);
            isRuning = false;
        }
    
    //event.key.keysym.sym
    switch (event.key.keysym.sym) {

        case SDLK_LEFT:
            sprite.decreaseX();
            SDL_UpdateWindowSurface(window);
            render();
            break;
            
        case SDLK_RIGHT:
            sprite.increaseX();
            SDL_FreeSurface(screen);
            SDL_UpdateWindowSurface(window);
            render();
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
    sprite.renCpy(renderer, playerTex);
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
