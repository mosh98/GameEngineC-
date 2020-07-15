//
//  main.cpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud on 2020-06-19.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.
//


#include <iostream>

#include <SDL2/SDL.h>
#include "GameEngine.h"


GameEngine *gameEngine = nullptr;

int main(int argc, const char * argv[]) {
    

    
    int FPS = 25;
    //Declare
    gameEngine = new GameEngine();
    
    gameEngine->init("MOSH_Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    
    while(gameEngine -> running()){
        //
        Uint32 start = SDL_GetTicks();
     
        if(gameEngine->running() == false){
            break;
        }
        gameEngine->handleEvents();
        //gameEngine->update();
        gameEngine->render();
        
       if(1000/FPS > SDL_GetTicks() - start)
            SDL_Delay(1000/FPS);
        
    }

    gameEngine->clean();
    
    return 0;
}
