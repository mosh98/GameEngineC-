//  Sprite.hpp
//  GameEngineInC
//  Created by Mosleh Mahamud on 2020-06-21.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.


#ifndef Sprite_h
#define Sprite_h

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
using namespace std;


class Sprite{
    
protected:
     
    //Uint32 color, int x, int y, int w, int h
    Sprite(int x, int y, int w, int h);
   virtual ~Sprite();
    
//    SDL_Texture* set_image_tex(const char filename[] = NULL, SDL_Renderer *ren = nullptr);
    
public:
    SDL_Surface* get_image() const;
    
    SDL_Rect getRect();
    
    Sprite& operator=(Sprite &rhs);
    SDL_Texture* set_image_tex(const char filename[] = NULL, SDL_Renderer *ren = NULL);
  
    void setWidthAndHeight(int width, int height);
    void draw(SDL_Renderer* ren, SDL_Texture* tex);
    SDL_Renderer* getMyRen();
    SDL_Texture* getMyTex();
    
//protected:
   // SDL_Surface *image;
    SDL_Rect rect;
    string path;
    
//TODO: (FIXED)  Becarefull you might leak from here
    SDL_Renderer *saveMyRen = NULL;
    SDL_Texture *saveMyTex = NULL ;

    
};

#endif /* Sprite_hpp */
