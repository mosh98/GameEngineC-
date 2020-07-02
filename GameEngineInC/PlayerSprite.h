//
//  TriangleSprite.hpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud on 2020-06-24.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.
//

#ifndef TriangleSprite_h
#define TriangleSprite_h
#include "Sprite.h"

#include <stdio.h>


class PlayerSprite: public Sprite {
    
    
public:
    PlayerSprite (Uint32 color, int x, int y, int w, int h);
    
    SDL_Texture* set_image(const char filename[] = NULL, SDL_Renderer *ren = nullptr);
    
    
    void increaseX(); //right button
    void decreaseX();//left button
    void increaseY();
    void decreaseY();
    
    void update_properties();
    
};

#endif /* TriangleSprite_h*/
