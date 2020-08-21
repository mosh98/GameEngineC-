//
//  TriangleSprite.cpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud (moma1820, -) on 2020-06-19.
//  Co-Creator Nyamgarig Naranbaatar (nyna2000, -)
//  Co-Creator Jimmy Ljungman  (jilj1595, -)
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.

// Basnivå1

#include "PlayerSprite.h"

#include <iostream>
#include <SDL2/SDL_image.h>


namespace gameengine {

PlayerSprite::PlayerSprite(int x, int y, int w, int h): Sprite(x, y, w, h){
}

PlayerSprite* PlayerSprite::create(int x, int y, int w, int h){
    return new PlayerSprite(x,y,w,h);
}

PlayerSprite:: ~PlayerSprite(){
    std::cout<<"DELETING PLAYER SPRITE "<<std::endl;
}


void PlayerSprite:: increaseX(){
   
    if(getPosX() < windowWidth){
        
        setPosX(getPosX()+25);
        
        std::cout<<"Rect_Increase x: "<<getPosX()<<std::endl;
    
    }else{
        
        std::cout<<"x cord LOCKED! "<< getPosX()<<std::endl;
    
    }
}

void PlayerSprite::  decreaseX(){
    if(getPosX() > 10){
        setPosX(getPosX() - 25);
        std::cout<<"Rect_decrease x: "<<getPosX()<<std::endl;
    }else{
        std::cout<<"x cord LOCKED! "<< getPosX()<<std::endl;
    }
}


void PlayerSprite:: setWindowWidth(int width){
    windowWidth = width-50;
}
}









