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


PlayerSprite::PlayerSprite(int x, int y, int w, int h): Sprite(x, y, w, h){
    

}

PlayerSprite:: ~PlayerSprite(){
     std::cout<<"DELETING PLAYER SPRITE "<<std::endl;
}


void PlayerSprite:: increaseX(){
    //            For right key
//    if(rect.x < 800){
//        rect.x += 25;
//
//           std::cout<<"Rect_Increase x: "<<rect.x<<std::endl;
//    }else{
//        std::cout<<"x cord LOCKED! "<< rect.x<<std::endl;
//    }
//
    
    if(getPosX() < 750){
        setPosX(getPosX()+25);
         std::cout<<"Rect_Increase x: "<<getPosX()<<std::endl;
    }else{
            std::cout<<"x cord LOCKED! "<< getPosX()<<std::endl;
        }
    
}

void PlayerSprite::  decreaseX(){
    
//    if(rect.x > -20){
//        rect.x -= 25;
//
//        std::cout<<"Rect_decrease x: "<< rect.x<<std::endl;
//    }else{
//        std::cout<<"x cord LOCKED! "<< rect.x<<std::endl;
//    }
    if(getPosX() > -20){
         setPosX(getPosX() - 25);
          
        std::cout<<"Rect_Increase x: "<<getPosX()<<std::endl;
     
    }else{
             std::cout<<"x cord LOCKED! "<< getPosX()<<std::endl;
         }
    
}

void PlayerSprite:: increaseY(){
    
//    rect.y -= 10;
//    std::cout<<"Rect_increase y: "<<rect.y<<std::endl;
    
}

void PlayerSprite:: decreaseY(){
//    rect.y += 10;
//    std::cout<<rect.y<<std::endl;
}







