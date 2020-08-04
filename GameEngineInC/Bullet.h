//
//  Bullet.hpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud on 2020-07-02.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.


#ifndef Bullet_h
#define Bullet_h



#include "PlayerSprite.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "EnemySprite.h"
#include <vector>
#include <stdio.h>

class Bullet : public Sprite {
    
public:
    
    Bullet(int w, int h, std::string pathz);
    ~Bullet();
    
    void shoot( int posX, SDL_Renderer* ren = NULL,  const std::vector<EnemySprite*> &vec = vector<EnemySprite*>() );
    
    SDL_Texture *texMex = NULL;
     
private:
    const int VERTICAL_HEIGHT = 600;
    
    void bulletLoop(int startPosX, SDL_Renderer* sl, const std::vector<EnemySprite*> &vec = vector<EnemySprite*>() );
    bool chekkCollision(Bullet* bz, const std::vector<EnemySprite*> &vec = vector<EnemySprite*>());
};

#endif /* Bullet_hpp */
