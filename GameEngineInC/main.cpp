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
       
    gameEngine = new GameEngine();
    
    gameEngine->init("MOSH_Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    gameEngine-> setEnemyAttributes(0, 0, "/Users/scarlet/Documents/DSV20/CPROG/GameEngine/resources/enemy.png", 8);
    gameEngine-> addPlayerSprite(48,48, "/Users/scarlet/Documents/DSV20/CPROG/GameEngine/resources/triangle.png");
    gameEngine-> addBulletImage("/Users/scarlet/Documents/DSV20/CPROG/GameEngine/resources/bullet.png");
    gameEngine-> initialize_Loop(gameEngine);
    
    delete gameEngine;
    
    return 0;
}
