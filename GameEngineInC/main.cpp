//
//  main.cpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud (moma1820, -) on 2020-06-19.
//  Co-Creator Nyamgarig Naranbaatar (nyna2000, -)
//  Co-Creator Jimmy Ljungman  (jilj1595, -)
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.


// Basnivå

#include <iostream>

#include <SDL2/SDL.h>
#include "GameEngine.h"

using namespace gameengine;

GameEngine *gameEngine = nullptr;

int main(int argc, const char * argv[]) {
       
    gameEngine = new GameEngine();
    gameEngine->setFPS(30);
    gameEngine->init("MOSH_Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    gameEngine->setEnemyAttributes(30, 33, "/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/enemy.png", 8);
    gameEngine->addPlayerSprite(48,48,"/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/triangle-clipart-triangle-shape-1-original.png");
    gameEngine->addBulletImage("/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/bullet.png");
    gameEngine->initialize_Loop();
    delete gameEngine;

    return 0;
}
