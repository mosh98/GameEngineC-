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



#include <iostream>
#include "EnemySprite.h"
#include <vector>
#include <stdio.h>




namespace gameengine {
class Bullet : public Sprite {
    
public:
    static Bullet* create(int x, int y, std::string path);
    ~Bullet(){};
    void tick(std::vector<Sprite*> *removedBullet);
    
    
private:
    Bullet(int w, int h, std::string pathz);
   
    
};

}

#endif /* Bullet_hpp */
