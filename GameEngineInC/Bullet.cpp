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



//Constructor
Bullet:: Bullet(int w, int h,std::string pathz)
: Sprite(0,0,w,h)
{
   
}


//Destructor
Bullet::~Bullet(){
    
    std::cout << " :BULLET" << std::endl;
    //free surfaces and other memory bound items
    SDL_DestroyTexture(texMex);
    texMex = NULL;
    IMG_Quit();
     std::cout << "MEMORY CLEAN: SDL texture destroyed clear intialized BULLET" << std::endl;
}


void Bullet::bulletLoop(int startPosX, SDL_Renderer* sl, const std::vector<EnemySprite*> &vec){
    
    setPosX(startPosX+16);


        for(int i =400 ; i > -10 ; i-=20){

            setPosY(i);

            draw(sl, texMex);
            //draw(s1,saveMyTex);
            
            chekkCollision(this, vec);
            
            SDL_RenderPresent(sl);

            std::cout<< i << std::endl;

               SDL_RenderClear(sl);
        }
    
    std::cout << "MEMORY CLEAN: SDL destroy texture BULLET " << std::endl;
    std::cout << "MEMORY CLEAN: SDL render clear  BULLET" << std::endl;
    
}

void Bullet::shoot(int posX, SDL_Renderer* ren, const std::vector<EnemySprite*> &vec ){
    
    bulletLoop(posX,ren,vec);
}

bool Bullet::chekkCollision( Bullet* bz, const std::vector<EnemySprite*> &vec) {
    
    const SDL_Rect &bulletPointer = bz->getRectobj();
    const SDL_Rect* rectBullet = &bulletPointer;
    
    
    for(EnemySprite* enemyInVec: vec){
      
        const SDL_Rect &enem = enemyInVec->getRectobj();
        const SDL_Rect* enemyRect = &enem;
        
        
        if( SDL_HasIntersection ( rectBullet, enemyRect ) == SDL_TRUE ) {
        
            enemyInVec->setDamaged(true);
            
            std::cout<< "COLLIDED"<< std::endl;
        
        } else {
        
            std::cout<< "Did not collide"<< std::endl;
        
        }
    }

    
    return false;
}


