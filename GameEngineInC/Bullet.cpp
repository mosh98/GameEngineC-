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
   
}


//Destructor
Bullet::~Bullet(){
    
    std::cout << " :BULLET" << std::endl;
    //free surfaces and other memory bound items
    SDL_DestroyTexture(texMex);
    texMex = NULL;
    IMG_Quit();
     std::cout << "MEMORY CLEAN: SDL texture destroyed clear intialized BULLET" << std::endl;
}


//remove the texture from the parametres
SDL_Texture* Bullet :: set_image(const char filename[], SDL_Renderer *ren){

    if( ! (IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)){
        std::cout << "Could not initalzie SDL image : " << IMG_GetError() << std::endl;
    }
    SDL_Surface *imageSurface = NULL;
    imageSurface = IMG_Load(filename);
    texMex = SDL_CreateTextureFromSurface(ren, imageSurface);
    SDL_FreeSurface(imageSurface);
    imageSurface = NULL;
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
    
    //rect.x = startPosX+16;
    setPosX(startPosX+16);


        for(int i =400 ; i > -10 ; i-=20){

            //rect.y = i;
            setPosY(i);

            draw(sl, texMex);

            SDL_RenderPresent(sl);

            std::cout<< i << std::endl;

            if(i == 500){

                //rect.y = 0;
                setPosY(0);
                break;
            }

        }


    SDL_DestroyTexture(texMex);
    SDL_RenderClear(sl);

    std::cout << "MEMORY CLEAN: SDL destroy texture BULLET " << std::endl;
    std::cout << "MEMORY CLEAN: SDL render clear  BULLET" << std::endl;
    
}

void Bullet::shoot(int posX, SDL_Renderer* ren){

    bulletLoop(posX,ren);
}



