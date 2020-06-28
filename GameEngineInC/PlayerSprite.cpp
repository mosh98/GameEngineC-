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



PlayerSprite::PlayerSprite(Uint32 color, int x, int y, int w, int h): Sprite(color, x, y, w, h){
    
    update_properties();
}

//void set_image(const char filename[] = NULL);
SDL_Texture* PlayerSprite :: set_image(const char filename[], SDL_Renderer *ren){
    
    SDL_Texture *texMex = NULL;
    
    if( ! (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
        std::cout << "Could not initalzie SDL image : " << IMG_GetError() << std::endl;
    }
    
    
    SDL_Surface *imageSurface = NULL;
    imageSurface = IMG_Load(filename);
    
    texMex = SDL_CreateTextureFromSurface(ren, imageSurface);
    
    
    //Free the surface aswell SDL_FreeSurface()
    
    if(imageSurface == NULL){
        
    }
    
     image = imageSurface;
    
    int old_x = rect.x;
    int old_y = rect.y;
    
     rect = image->clip_rect;
    
         rect.x = old_x;
         rect.y = old_y;
    
    update_properties();
    
    SDL_FreeSurface(imageSurface);

//    if(filename != NULL){
//        SDL_Surface* loaded_image = NULL;
//        loaded_image = SDL_LoadBMP(filename);
//
//        if(loaded_image != NULL){
//
//            image = loaded_image;
//
//            int old_x = rect.x;
//            int old_y = rect.y;
//
//            rect = image->clip_rect;
//
//            rect.x = old_x;
//            rect.y = old_y;
//
//            update_properties();
//        }
//    }
    
    return texMex;
}

void PlayerSprite:: increaseX(){
    //            For right key
    rect.x += 10;
    
    std::cout<<"Rect_Increase x: "<<rect.x<<std::endl;
}

void PlayerSprite::  decreaseX(){
    rect.x -= 10;
    
    std::cout<<"Rect_decrease x: "<< rect.x<<std::endl;
}

void PlayerSprite:: increaseY(){
    rect.y -= 10;
    std::cout<<"Rect_increase y: "<<rect.y<<std::endl;
}

void PlayerSprite:: decreaseY(){
    rect.y += 10;
    
    std::cout<<rect.y<<std::endl;
}

void PlayerSprite::update_properties(){
    origin_x =0;
    origin_y=0;
    set_position(rect.x,rect.y);
}

void PlayerSprite::set_position(int x, int y){
    rect.x = x - origin_x;
    rect.y = y - origin_y;
}

