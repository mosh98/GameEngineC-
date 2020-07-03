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


 Bullet bullet(10,10,"/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/bullet.png");

PlayerSprite::PlayerSprite(int x, int y, int w, int h, std::string pathz): Sprite(x, y, w, h){
    
  
   //assigning to global var
    path += pathz;
    update_properties();
}

////void set_image(const char filename[] = NULL);
SDL_Texture* PlayerSprite :: set_image(const char filename[], SDL_Renderer *ren){

    SDL_Texture *texMex = NULL;

    if( ! (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
        std::cout << "Could not initalzie SDL image : " << IMG_GetError() << std::endl;
    }


    SDL_Surface *imageSurface = NULL;
    imageSurface = IMG_Load(filename);
    texMex = SDL_CreateTextureFromSurface(ren, imageSurface);
    //Free the surface aswell SDL_FreeSurface()
    saveMyRen = ren;
    saveMyTex = texMex;
    
    update_properties();
    SDL_FreeSurface(imageSurface);

    return texMex;
}

void PlayerSprite:: increaseX(){
    //            For right key
    if(rect.x < 750){
        rect.x += 35;
           std::cout<<"Rect_Increase x: "<<rect.x<<std::endl;
    }else{
        std::cout<<"x cord LOCKED! "<< rect.x<<std::endl;
    }
   
}

void PlayerSprite::  decreaseX(){
    
    if(rect.x > -20){
        rect.x -= 35;
        std::cout<<"Rect_decrease x: "<< rect.x<<std::endl;
    }else{
        std::cout<<"x cord LOCKED! "<< rect.x<<std::endl;
    }
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

}

std::string PlayerSprite::getPath(){
    return path;
}

void PlayerSprite::shoot(){
    
    bullet.set_image("/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/bullet.png",saveMyRen);
    bullet.bulletLoop(this->rect.x, saveMyRen);
}





