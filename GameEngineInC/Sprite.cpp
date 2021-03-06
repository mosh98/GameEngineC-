//  Sprite.cpp
//  GameEngineInC

//  Created by Mosleh Mahamud (moma1820, -) on 2020-06-19.
//  Co-Creator Nyamgarig Naranbaatar (nyna2000)
//  Co-Creator Jimmy Ljungman  (jilj1595)
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.

// Basnivå1

#include "Sprite.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


namespace gameengine {

Sprite::Sprite (int x, int y, int w, int h, std::string path ):path(path) {
    rect.h = h;
    rect.w = w;
    rect.x = x;
    rect.y = y;
}



Sprite::~Sprite(){
        
    SDL_DestroyTexture(saveMyTex);
    saveMyTex = NULL;
    
   
}



SDL_Rect Sprite::getRectobj() const {
    return rect;
}

SDL_Surface* Sprite:: get_image() const {
    return NULL;
}

void Sprite::setWidthAndHeight(int width, int height){
    rect.w = width;
    rect.h = height;
}



SDL_Texture* Sprite:: set_image_tex(const char filename[], SDL_Renderer *ren ){
    
    if( ! (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
       
    }
    
    SDL_Surface *imageSurface = NULL;
    imageSurface = IMG_Load(filename);
    
    
    saveMyTex = SDL_CreateTextureFromSurface(ren, imageSurface);
    
    SDL_FreeSurface(imageSurface);
    
    return saveMyTex;
}



SDL_Texture* Sprite::getMyTex() const{
    return saveMyTex;
    
}



void Sprite:: draw(SDL_Renderer* ren){
        
    SDL_RenderCopy(ren, saveMyTex, NULL, &rect);
    //comment
}

int Sprite:: getPosX() const{
    return rect.x;
}

void Sprite:: setPosX(int x){
    rect.x = x;
}
int Sprite:: getPosY() const{
    return rect.y;
}
void Sprite::setPath(std::string pth){
    path += pth;
}

//returns the image Path
std::string Sprite::getPath() const{
    
    return path;
    
}

void Sprite:: setPosY(int y){
    rect.y = y;
}

}



