//
//  GameEngine.hpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud on 2020-06-19.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.
//

#ifndef GameEngine_h
#define GameEngine_h

//#include <SDL2/SDL.h>
#include <SDL2/SDL.h>
#include <iostream>
#include "Sprite.h"
#include "TriangleSprite.h"
#include <SDL2/SDL_image.h>


class GameEngine{
    
public:
    GameEngine();
    ~GameEngine();

    //intialize
    void init(const char*title, int xpos, int ypos, int width, int height, bool fullscreen);
    
    //void add();
    //void remove();
    
    void handleEvents();
    void update();
    void render();
    void clean();
    
    void add(Sprite*);
    void remove(Sprite*);
    
    bool running();
    
    

private:
    int cnt;
    bool isRuning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *screen;
    //TriangleSprite *sprite(NULL,0,0);
    TriangleSprite *Controllersprite;
    //vector for sprites
    
    
    
};

#endif /* GameEngine_hpp */
