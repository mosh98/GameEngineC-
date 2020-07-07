//
//  EnemySprite.cpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud on 2020-06-30.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.
//

#include "EnemySprite.h"

EnemySprite::EnemySprite(int x, int y, int w, int h):Sprite(x, y, w, h){
    
}

SDL_Texture* EnemySprite:: set_image(const char filename[], SDL_Renderer *ren){
    
    
       
       if( ! (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
           std::cout << "Could not initalzie SDL image : " << IMG_GetError() << std::endl;
       }
       
       
       SDL_Surface *imageSurface = NULL;
       imageSurface = IMG_Load(filename);
       texMex = SDL_CreateTextureFromSurface(ren, imageSurface);
       //Free the surface aswell SDL_FreeSurface()
       
       SDL_FreeSurface(imageSurface);
       
       return texMex;
}

void EnemySprite::summonEnemy(SDL_Renderer* rend){
    renCpy(rend, texMex);
}
