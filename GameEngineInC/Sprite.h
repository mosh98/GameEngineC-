//  Sprite.hpp
//  GameEngineInC
//  Created by Mosleh Mahamud on 2020-06-21.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.


#ifndef Sprite_h
#define Sprite_h

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Sprite{
    
public:
     
    //Uint32 color, int x, int y, int w, int h
    Sprite(int x, int y, int w, int h);
    ~Sprite();
    
//    SDL_Texture* set_image_tex(const char filename[] = NULL, SDL_Renderer *ren = nullptr);
    
    void setImage(SDL_Surface *imageParam);
    
    void update();//can be overriden
    
    void draw(SDL_Surface *dest);
    SDL_Surface* get_image() const;
    
    SDL_Rect getRect();
    
    Sprite& operator=(Sprite &rhs);
    
  
    
    void renCpy(SDL_Renderer* ren, SDL_Texture* tex);
    SDL_Renderer* getMyRen();
    SDL_Texture* getMyTex();
    
protected:
    SDL_Surface *image;
    SDL_Rect rect;
    //std:: string path;
    
//    Becarefull you might leak from here
    SDL_Renderer *saveMyRen = NULL;
    SDL_Texture *saveMyTex = NULL ;
    
    int origin_x;
    int origin_y;
    
    
};

#endif /* Sprite_hpp */
