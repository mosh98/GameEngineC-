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
    SDL_DestroyTexture(texMex);
    std::cout << "MEMORY CLEAN: SDL texture destroyed clear intialized " << std::endl;
    texMex = NULL;
    
    IMG_Quit();
}


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

bool Bullet:: checkCollision( SDL_Rect a, SDL_Rect b )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    //Calculate the sides of rect B
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

void Bullet::bulletLoop(int startPosX, SDL_Renderer* sl){
    //while bla bla bla
    
    rect.x = startPosX+16;
    
        
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
    
    
    SDL_DestroyTexture(texMex);
    SDL_RenderClear(sl);
    
    std::cout << "MEMORY CLEAN: SDL destroy texture  " << std::endl;
    std::cout << "MEMORY CLEAN: SDL render clear  " << std::endl;
    
}



