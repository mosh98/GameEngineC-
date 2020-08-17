//
//  EnemySprite.cpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud (moma1820, -) on 2020-06-19.
//  Co-Creator Nyamgarig Naranbaatar (nyna2000)
//  Co-Creator Jimmy Ljungman  (jilj1595)
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.

// Basnivå1

#include "EnemySprite.h"


EnemySprite::EnemySprite(int x, int y, int w, int h):Sprite(x, y, w, h){
}


EnemySprite:: ~EnemySprite(){
    std::cout<< "Enemy Sprite Deleted" << std::endl;
}


bool EnemySprite::isDamaged(){
    return damagedFlag;
}

void EnemySprite::setDamaged(bool dmg){
    damagedFlag = dmg;
}
