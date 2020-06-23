//  Sprite.hpp
//  GameEngineInC
//  Created by Mosleh Mahamud on 2020-06-21.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.


#ifndef Sprite_h
#define Sprite_h

#include <stdio.h>
#include <SDL2/SDL.h>

class Sprite{
    
public:
    
    //Uint32 color, int x, int y, int w, int h
    inline Sprite(Uint32 color, int x, int y, int w, int h);
        
        
    void setImage(SDL_Surface *imageParam);
    
    void update();//can be overriden
    
    void draw(SDL_Surface *dest);
    
    
    
private:
    SDL_Surface *image;
    SDL_Rect rect;
    
    int origin_x;
    int origin_y;
    
    
};

#endif /* Sprite_hpp */
