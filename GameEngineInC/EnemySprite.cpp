//
//  EnemySprite.cpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud on 2020-06-30.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.
//

#include "EnemySprite.h"
#include <iostream>

EnemySprite::EnemySprite(int x, int y, int w, int h):Sprite(x, y, w, h){
}


//    EnemySprite:: ~EnemySprite(){
//    std::cout<<"DELETING PLAYER SPRITE "<<std::endl;
//    }

//EnemySprite::~EnemySprite(){
//    
//}


void EnemySprite::summonEnemy(SDL_Renderer* rend){
    draw(rend, texMex);
}
