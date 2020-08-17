//  Sprite.cpp
//  GameEngineInC

//  Created by Mosleh Mahamud (moma1820, -) on 2020-06-19.
//  Co-Creator Nyamgarig Naranbaatar (nyna2000)
//  Co-Creator Jimmy Ljungman  (jilj1595)
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.

// Basnivå1

#include "Sprite.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>


Sprite::Sprite(int x, int y, int w, int h ){
    rect.h = h;
    rect.w = w;
    rect.x = x;
    rect.y = y;
}



 Sprite::~Sprite(){
    
    SDL_DestroyRenderer(saveMyRen);
    saveMyRen = NULL;
    
    SDL_DestroyTexture(saveMyTex);
    saveMyTex = NULL;
   
    IMG_Quit();
    SDL_Quit();
    
    std::cout<<"MEMORY CLEAN: SDL memory freed from Sprite class"<<std::endl;
}

SDL_Rect* Sprite:: getRect()  {

    return &rect;
}

SDL_Rect Sprite::getRectobj() const {
    return rect;
}

//    getter for image becuase it is a private variable
SDL_Surface* Sprite:: get_image() const {
     return NULL;
}

void Sprite::setWidthAndHeight(int width, int height){
    rect.w = width;
    rect.h = height;
}



SDL_Texture* Sprite:: set_image_tex(const char filename[], SDL_Renderer *ren ){

       if( ! (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
           std::cout << "Could not initalzie SDL image : " << IMG_GetError() << std::endl;
       }
        
       SDL_Surface *imageSurface = NULL;
       imageSurface = IMG_Load(filename);
   
  
        saveMyTex = SDL_CreateTextureFromSurface(ren, imageSurface);
    
        SDL_FreeSurface(imageSurface);
       
    return saveMyTex;
}

SDL_Renderer* Sprite::getMyRen(){
    return saveMyRen;
}
SDL_Texture* Sprite::getMyTex(){
    return saveMyTex;
}

void Sprite:: draw(SDL_Renderer* ren, SDL_Texture* tex){
    saveMyRen = ren;
    saveMyTex = tex;
    SDL_RenderCopy(ren, tex, NULL, &rect);
}

int Sprite:: getPosX(){
    return rect.x;
}

void Sprite:: setPosX(int x){
    rect.x = x;
}

void Sprite::setPath(std::string pth){
    path = pth;
}
void Sprite:: setPosY(int y){
    rect.y = y;
}
