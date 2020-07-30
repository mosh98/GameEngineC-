//
//  EnemySprite.hpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud on 2020-06-30.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.
//

#ifndef EnemySprite_h
#define EnemySprite_h
#include "Sprite.h"
#include <SDL2/SDL_image.h>
#include <iostream>


#include <stdio.h>

class EnemySprite: public Sprite {
  
public:
    EnemySprite (int x, int y, int w, int h);
    ~EnemySprite() override;
    
    void summonEnemy(SDL_Renderer* rend);
    bool isDamaged();
    void setDamaged(bool dmg);
private:
    SDL_Texture *texMex = NULL;
    bool damagedFlag = false;
};

#endif /* EnemySprite_h */
