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
#include <SDL2/SDL_image.h>
#include "GameEngine.h"
#include <iostream>


namespace gameengine {

PlayerSprite::PlayerSprite(int x, int y, int w, int h, std::string path): Sprite(x, y, w, h, path){
}

PlayerSprite* PlayerSprite::create(int x, int y, int w, int h, std::string path){
    return new PlayerSprite(x,y,w,h,path);
}

void PlayerSprite:: increaseX(){
        setPosX(getPosX()+25);
}

void PlayerSprite::  decreaseX(){
        setPosX(getPosX() - 25);
}


}









