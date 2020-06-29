//  Sprite.cpp
//  GameEngineInC
//  Created by Mosleh Mahamud on 2020-06-21.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.

#include "Sprite.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>



Sprite::Sprite( Uint32 color, int x, int y, int w, int h ) {
    
    w=48;
    h=64;
    
    image = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
    SDL_FillRect(image, NULL, color);
    rect = image -> clip_rect;
    
    rect.h = 48;
    rect.w = 48;
    
    
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

//this dun work
Sprite &Sprite::operator=(Sprite &rhs){
//    if(this == &rhs){
//        return *this;
//    }
//
//    this->rect = rhs.rect;
//    this->image = rhs.image;
//
//    this->rect.x = rhs.origin_x;
//    this->rect.y = rhs.origin_y;
//

    
    return *this;
}
void Sprite:: renCpy(SDL_Renderer* ren, SDL_Texture* tex){
    
    SDL_RenderCopy(ren, tex, NULL, &rect);
}
