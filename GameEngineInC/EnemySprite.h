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

class EnemySprite: public Sprite{
  
    EnemySprite (Uint32 color, int x, int y, int w, int h);
     
     SDL_Texture* set_image(const char filename[] = NULL, SDL_Renderer *ren = nullptr);
     
     
};

#endif /* EnemySprite_h */
