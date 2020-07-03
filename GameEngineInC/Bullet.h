//
//  Bullet.hpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud on 2020-07-02.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.
//

#ifndef Bullet_h
#define Bullet_h

#include "Sprite.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include <stdio.h>

class Bullet : public Sprite{
    
    Bullet(int x, int y, int w, int h, std::string pathz);
    ~Bullet();
    
    void bulletLoop(int startPosX);
    
private:
    const int VERTICAL_HEIGHT = 600;

    
    
    
    
};

#endif /* Bullet_hpp */
