//
//  TriangleSprite.hpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud (moma1820, -) on 2020-06-19.
//  Co-Creator Nyamgarig Naranbaatar (nyna2000, -)
//  Co-Creator Jimmy Ljungman  (jilj1595, -)
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.

// Tilläggsnivå1

#ifndef TriangleSprite_h
#define TriangleSprite_h
#include "Sprite.h"


#include <stdio.h>
#include <string>
#include <iostream>


class PlayerSprite: public Sprite {
    
    
public:
    static PlayerSprite* create(int x, int y, int w, int h);
    ~PlayerSprite();
    void increaseX(); //right button
    void decreaseX();//left button
    
private:
    PlayerSprite (int x, int y, int w, int h);
    
    
    
};

#endif /* TriangleSprite_h*/
