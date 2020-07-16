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
#include "Sprite.h"
#include "PlayerSprite.h"
#include "EnemySprite.h"
#include <SDL2/SDL_image.h>
#include <map>
#include <stdlib.h>
#include "Bullet.h"


class GameEngine{
    
public:
    
    GameEngine();
    ~GameEngine();

    //intialize
    void init(const char*title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void render();
    void clean();
     bool running();
    
    
   
    //Add Features
    void addPlayerSprite(int width, int height, std::string pathToImage);
    void setEnemyAttributes(int width, int height, std::string pathToImage, int enemy);
    void addEnemy( int howManyEnemyYouNeed);
    void addBulletImage(std::string pathToImage);
    
   
    

    protected:
    void shoot();
    void remove(Sprite*); // found no use of this
    void renderAllEnemy();
    void freeEnemies();
    
    
    
    
private:
    
    int cnt;
    int enemyCnt;
    bool isRuning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *screen;
    PlayerSprite* sprite = new PlayerSprite(400,500,48,48);
    Bullet* bs = new Bullet(20,20,"/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/bullet.png");
    
    
    SDL_Texture *playerTex;
    SDL_Texture *bulletTex;

    
    //map for enemy_sprites
    std::map< EnemySprite*, SDL_Texture* > map;
    
};

#endif /* GameEngine_hpp */
