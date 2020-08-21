//
//  Bullet.cpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud (moma1820, -) on 2020-06-19.
//  Co-Creator Nyamgarig Naranbaatar (nyna2000)
//  Co-Creator Jimmy Ljungman  (jilj1595)
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.

// Basnivå1

#include "Bullet.h"
#include "GameEngine.h"


using namespace std;


namespace gameengine {
//Constructor
Bullet:: Bullet(int w, int h,std::string pathz)
: Sprite(0,0,w,h)
{
    
}

Bullet* Bullet::create(int x, int y, std::string path){
    return new Bullet(x,y,path);
}

void Bullet::tick(std::vector<Bullet*> *removedBullet ){

    setPosY(getPosY()-7);
    
   
    
    if(getPosY() <= 0) {
        
        removedBullet->push_back(this);
        
        
        
    }
}




}



