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


class TriangleSprite: public Sprite {
    
    
public:
    TriangleSprite (Uint32 color, int x, int y, int w=48, int h = 64);
    
    void set_image(const char filename[] = NULL);
    
    
    void increaseX(); //right button
    void decreaseX();//left button
    
    
    void update_properties();
    void set_position(int x , int y);
};

#endif /* TriangleSprite_h*/
