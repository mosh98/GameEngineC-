//
//  EnemySprite.hpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud (moma1820, -) on 2020-06-19.
//  Co-Creator Nyamgarig Naranbaatar (nyna2000)
//  Co-Creator Jimmy Ljungman  (jilj1595)
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.

// Basnivå1

#ifndef EnemySprite_h
#define EnemySprite_h
#include "Sprite.h"
#include <SDL2/SDL_image.h>
#include <iostream>


#include <stdio.h>

class EnemySprite: public Sprite {
    
public:
    
    ~EnemySprite();
    static EnemySprite* create(int x, int y, int w, int h) ;
    bool isDamaged();
    void setDamaged(bool dmg);
    
private:
    EnemySprite (int x, int y, int w, int h);
    bool damagedFlag = false;
    
};

#endif /* EnemySprite_h */
