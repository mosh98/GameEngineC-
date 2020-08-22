//
//  EnemySprite.cpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud (moma1820, -) on 2020-06-19.
//  Co-Creator Nyamgarig Naranbaatar (nyna2000)
//  Co-Creator Jimmy Ljungman  (jilj1595)
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.

// Basnivå1

#include "EnemySprite.h"
#include "Sprite.h"

namespace gameengine {
EnemySprite::EnemySprite(int x, int y, int w, int h, std::string path): Sprite(x, y, w, h, path){
}





EnemySprite* EnemySprite::create( int x, int y, int w, int h, std::string path){
    return new EnemySprite(x, y,  w, h, path);
}

void EnemySprite:: tick(){
    
    if(moveLeftFlag == true ){
        
        setPosX( getPosX( ) - 5 );
        
        std::cout << getPosX( ) << std::endl;
        
        if( getPosX() == 10 ){
            moveLeftFlag = false;
        }
        
    } else{
        
        setPosX( getPosX() + 5 );
        
        if(getPosX() >= 750){
            moveLeftFlag = true;
        }
        
    }
}

}
