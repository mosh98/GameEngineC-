//
//  Bullet.hpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud on 2020-07-02.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.
//

#ifndef Bullet_h
#define Bullet_h



#include "PlayerSprite.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "EnemySprite.h"

#include <stdio.h>

class Bullet : public Sprite{
    
public:
    Bullet(int w, int h, std::string pathz);
    ~Bullet();
    
    void bulletLoop(int startPosX, SDL_Renderer* sl,EnemySprite* en = NULL);
    
    //remove the texture from the parametres
     SDL_Texture* set_image(const char filename[] = NULL, SDL_Renderer *ren = nullptr);
    
    bool checkCollision(SDL_Rect a, SDL_Rect b);
    bool chekkCollision(Bullet* bz,EnemySprite * e);
    
    void shoot(int posX, SDL_Renderer* ren = NULL, EnemySprite* en = NULL);
    
private:
    const int VERTICAL_HEIGHT = 600;
    SDL_Texture *texMex = NULL;

    
    
    
    
};

#endif /* Bullet_hpp */
