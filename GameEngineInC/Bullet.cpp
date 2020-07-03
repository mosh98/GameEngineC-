//
//  Bullet.cpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud on 2020-07-02.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.
//

#include "Bullet.h"


//Constructor
Bullet:: Bullet(int w, int h,std::string pathz)
: Sprite(0,0,w,h)
{
    //path = pathz;
}


//Destructor
Bullet::~Bullet(){
    //free surfaces and other memory bound items
}
SDL_Texture *texMex = NULL;

//remove the texture from the parametres
SDL_Texture* Bullet :: set_image(const char filename[], SDL_Renderer *ren){

    

    if( ! (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
        std::cout << "Could not initalzie SDL image : " << IMG_GetError() << std::endl;
    }


    SDL_Surface *imageSurface = NULL;
    imageSurface = IMG_Load(filename);
    texMex = SDL_CreateTextureFromSurface(ren, imageSurface);
    //Free the surface aswell SDL_FreeSurface()
    saveMyRen = ren;
    SDL_FreeSurface(imageSurface);

    saveMyTex = texMex;
    
    return texMex;
}

void Bullet::bulletLoop(int startPosX, SDL_Renderer* sl){
    //while bla bla bla
    
    rect.x = startPosX+22;
    for(int i = 0; i < VERTICAL_HEIGHT; i+=100){
       
        rect.y = i;
        
        renCpy(sl, texMex);
        
        SDL_RenderPresent(sl);
        
        std::cout<< i << std::endl;
        
        if(i == 500){
            rect.y = 0;
            break;
        }
    }
    
    std::cout << "SDL render clear intialized " << std::endl;
    SDL_RenderClear(sl);
    
}

