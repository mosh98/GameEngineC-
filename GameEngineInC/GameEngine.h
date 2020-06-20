//
//  GameEngine.hpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud on 2020-06-19.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.
//

#ifndef GameEngine_h
#define GameEngine_h

#include <SDL2/SDL.h>
#include <iostream>

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
    
    bool running();
    
    

private:
    bool isRuning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    
    
};

#endif /* GameEngine_hpp */
