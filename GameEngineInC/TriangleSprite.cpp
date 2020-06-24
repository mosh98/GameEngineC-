//
//  TriangleSprite.cpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud on 2020-06-24.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.
//

#include "TriangleSprite.h"
#include <iostream>



TriangleSprite::TriangleSprite(Uint32 color, int x, int y, int w, int h): Sprite(color, x, y, w, h){
    
    update_properties();
}

//void set_image(const char filename[] = NULL);
void TriangleSprite :: set_image(const char filename[]){
    
    if(filename != NULL){
        SDL_Surface* loaded_image = NULL;
        loaded_image = SDL_LoadBMP(filename);
        
        if(loaded_image != NULL){
            
            image = loaded_image;
            
            int old_x = rect.x;
            int old_y = rect.y;
            
            rect = image->clip_rect;
            
            rect.x = old_x;
            rect.y = old_y;
            
            update_properties();
        }
    }
}

void TriangleSprite:: increaseX(){
    //            For right key
    rect.x += 10;
    
    std::cout<<rect.x<<std::endl;
}

void TriangleSprite::  decreaseX(){
    rect.x -= 10;
    
    std::cout<<rect.x<<std::endl;
}

void TriangleSprite::update_properties(){
    origin_x =0;
    origin_y=0;
    set_position(rect.x,rect.y);
}

void TriangleSprite::set_position(int x, int y){
    rect.x = x - origin_x;
    rect.y = y - origin_y;
}

