//  Sprite.hpp
//  GameEngineInC

//  Created by Mosleh Mahamud (moma1820, -) on 2020-06-19.
//  Co-Creator Nyamgarig Naranbaatar (nyna2000)
//  Co-Creator Jimmy Ljungman  (jilj1595)
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.

// Basnivå1

#ifndef Sprite_h
#define Sprite_h

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
using namespace std;


class Sprite{
    
protected:
    Sprite(int x, int y, int w, int h);
    virtual ~Sprite();

    
public:
    SDL_Surface* get_image() const;
    SDL_Rect* getRect();
    
    SDL_Rect getRectobj() const;
    
    SDL_Texture* set_image_tex(const char filename[] = NULL, SDL_Renderer *ren = NULL);
    
    void setWidthAndHeight(int width, int height);
    void draw(SDL_Renderer* ren, SDL_Texture* tex);
    
    SDL_Renderer* getMyRen();
  
    SDL_Texture* getMyTex();
  
    
    //Cords X
    int getPosX();
    void setPosX(int x);
    // Cords Y
    void setPosY(int y);
    
    //setPath
    void setPath(std::string pth);
    
    
protected:
    SDL_Rect rect;
    string path;
    SDL_Renderer *saveMyRen = NULL; //TODO: (FIXED)  Becarefull you might leak from here
    SDL_Texture *saveMyTex = NULL ;
    Sprite(const Sprite& rhs) = delete;
    const Sprite& operator=(const Sprite& rhs) = delete;
    

};

#endif /* Sprite_hpp */
