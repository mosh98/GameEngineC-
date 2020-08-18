//
//  Bullet.hpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud (moma1820, -) on 2020-06-19.
//  Co-Creator Nyamgarig Naranbaatar (nyna2000)
//  Co-Creator Jimmy Ljungman  (jilj1595)
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.

// Basnivå1

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
    static Bullet* create(int x, int y, std::string path);
    Bullet(int w, int h, std::string pathz); //make private
    ~Bullet();
    void shoot( int posX, SDL_Renderer* ren,  const std::vector<EnemySprite*> &vec );
    //SDL_Texture *texMex = NULL;
     
  
    
private:
    const int VERTICAL_HEIGHT = 600;
    
    void bulletLoop(int startPosX, SDL_Renderer* sl, const std::vector<EnemySprite*> &vec  );
    bool chekkCollision(Bullet* bz, const std::vector<EnemySprite*> &vec  );
};

#endif /* Bullet_hpp */
