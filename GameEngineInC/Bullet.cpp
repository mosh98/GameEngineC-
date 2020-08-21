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


//Destructor
Bullet::~Bullet()
{
    std::cout << " :BULLET" << std::endl;
    //free surfaces and other memory bound items
    //SDL_DestroyTexture(texMex);
    //texMex = NULL;
    std::cout << " BULLET memory FREED " << std::endl;
}

Bullet* Bullet::create(int x, int y, std::string path){
    return new Bullet(x,y,path);
}


void Bullet::bulletLoop(int startPosX, SDL_Renderer* sl,  std::vector<EnemySprite*> &vec){
    
    setPosX(startPosX+16);
    
    
    for(int i =400 ; i > -10 ; i-=20){
        
        setPosY(i);
        
        draw(sl, getMyTex());
        // draw(s1,saveMyTex);
        
        chekkCollision(this, vec);
        
        SDL_RenderPresent(sl);
        
        std::cout<< i << std::endl;
        
        SDL_RenderClear(sl);
    }
    
    std::cout << "MEMORY CLEAN: SDL destroy texture BULLET " << std::endl;
    std::cout << "MEMORY CLEAN: SDL render clear  BULLET" << std::endl;
    
}

void Bullet::tick( ){

    setPosY(getPosY()-7);
    
    if( getPosY() <= 0) {
        
        gE.removeBullet(this);
        
        //setPosY( VERTICAL_HEIGHT );
        
    }
}

void Bullet::shoot(int posX, SDL_Renderer* ren,  std::vector<EnemySprite*> &vec ){
    
    bulletLoop(posX,ren,vec);
}

bool Bullet::chekkCollision( Bullet* bz,  std::vector<EnemySprite*> &vec) {
    
    std::vector< EnemySprite* > discardedEnemy;
    
    const SDL_Rect &bulletPointer = bz->getRectobj();
    const SDL_Rect* rectBullet = &bulletPointer;
    
    
    for(EnemySprite* enemyInVec: vec){
        
        const SDL_Rect &enem = enemyInVec->getRectobj();
        const SDL_Rect* enemyRect = &enem;
        
        
        if( SDL_HasIntersection ( rectBullet, enemyRect ) == SDL_TRUE ) {
            
            enemyInVec->setDamaged(true);
            
            //vec.erase(enemyInVec);
            discardedEnemy.push_back(enemyInVec);
            
            std::cout<< "COLLIDED"<< std::endl;
            
        } else {
            
            std::cout<< "Did not collide"<< std::endl;
            
        }
    }
    

    return false;
}
}



