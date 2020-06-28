//  Sprite.cpp
//  GameEngineInC
//  Created by Mosleh Mahamud on 2020-06-21.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.

#include "Sprite.h"




Sprite::Sprite( Uint32 color, int x, int y, int w, int h ) {
    
    w=48;
    h=64;
    
    image = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
    SDL_FillRect(image, NULL, color);
    rect = image -> clip_rect;
    
    rect.x = x - origin_x;
    rect.y = y - origin_y;
}

void Sprite::setImage(SDL_Surface *imageParam){
    image= imageParam;
}

void Sprite::update(){
    
}

SDL_Rect Sprite:: getRect(){
    return rect;
}

//    getter for image becuase it is a private variable
SDL_Surface* Sprite:: get_image() const {
    return image;
}

void Sprite::draw(SDL_Surface *dest){
    SDL_BlitSurface(image, NULL, dest, &rect);
}
