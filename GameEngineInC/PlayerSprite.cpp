//
//  TriangleSprite.cpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud on 2020-06-24.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.
//

#include "PlayerSprite.h"

#include <iostream>
#include <SDL2/SDL_image.h>


PlayerSprite::PlayerSprite(int x, int y, int w, int h): Sprite(x, y, w, h){
    

}

PlayerSprite:: ~PlayerSprite(){
     std::cout<<"DELETING PLAYER SPRITE "<<std::endl;
}


void PlayerSprite:: increaseX(){
    if(getPosX() < 750){
        setPosX(getPosX()+25);
         std::cout<<"Rect_Increase x: "<<getPosX()<<std::endl;
    }else{
            std::cout<<"x cord LOCKED! "<< getPosX()<<std::endl;
        }
}

void PlayerSprite::  decreaseX(){
    if(getPosX() > -20){
         setPosX(getPosX() - 25);
        std::cout<<"Rect_decrease x: "<<getPosX()<<std::endl;
    }else{
             std::cout<<"x cord LOCKED! "<< getPosX()<<std::endl;
         }
}








