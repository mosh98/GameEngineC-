//
//  GameEngine.cpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud on 2020-06-19.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.
//

#include "GameEngine.h"

#include <iostream>

SDL_Texture *playerTex;
SDL_Texture *bulletTex;
SDL_Texture *enemyTex;

char *homeDir = getenv("PATH");


SDL_Rect srcR, destR;
//"/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/triangle-clipart-triangle-shape-1-original.png"
PlayerSprite sprite(400,500,48,48,"/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/triangle-clipart-triangle-shape-1-original.png");
 Bullet bs(20,20,"/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/bullet.png");

EnemySprite tmpEnemy(100,100,40,40);
EnemySprite tmpEnemy2(100,100,40,40);
EnemySprite tmpEnemy3(100,100,40,40);
EnemySprite tmpEnemy4(100,100,40,40);
EnemySprite tmpEnemy5(100,100,40,40);



GameEngine::GameEngine(){}

GameEngine::~GameEngine(){
    clean();
    window = NULL;
    renderer = NULL;
    screen = NULL;
}


//INITIALIZE
void GameEngine::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    
    int flag = 0;
    if(fullscreen){
        flag = SDL_WINDOW_FULLSCREEN;
    }
    
    if( SDL_Init(SDL_INIT_EVERYTHING) == 0 ) {
        std::cout << "Subsystems Initialized!...." << std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            std::cout << "Renderer Initialized!...." << std::endl;
        }
        
        
        screen = SDL_GetWindowSurface(window);//This "canvas" is where we gonna append our bmp picture to!
        //Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/triangle-clipart-triangle-shape-1-original.png
        
       
        std::cout<<homeDir<<std::endl;
        std::string sss = sprite.getPath();
        
        playerTex = sprite.set_image(sss.c_str(), renderer);
        
        
        //playerTex = sprite.set_image(imageLink, renderer);
        
        sprite.renCpy(renderer, playerTex);
        
        //put enemy Sprite and shit
        addEnemy(5);
        
        /* Up until now everything was drawn behind the scenes.
         This will show the new contents of the window. */
        
        //clearing stuff
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        SDL_UpdateWindowSurface(window);
        isRuning = true;
    }
    else{
        isRuning = false;
    }
}

void GameEngine::handleEvents(){
    SDL_Event event;
    
    SDL_PollEvent(&event);
    
    
        if(SDL_QUIT == event.type){
            //SDL_FlushEvent(&event);
            isRuning = false;
        }
    
    //event.key.keysym.sym
    switch (event.key.keysym.sym) {

        case SDLK_LEFT:
            sprite.decreaseX();
            SDL_UpdateWindowSurface(window);
            render();
            break;
            
        case SDLK_RIGHT:
            sprite.increaseX();
            SDL_FreeSurface(screen);
            SDL_UpdateWindowSurface(window);
            render();
            break;
        
        case SDLK_SPACE:
            //sprite.shoot();
            
            shoot();
            SDL_FreeSurface(screen);
            SDL_UpdateWindowSurface(window);
            render();
            
        default:
            break;
    }
    
    
}


//std::cout << "Size of x : " << x << std::endl;
  //     std::cout << "Size of y : " << y << std::endl;
       

//TODO: enemy Sprites with random x and y

//possibly also have the imageLink png in the parametres
void GameEngine:: addEnemy(int howManyEnemyYouNeed ){
    

       // enemyTex = tmpEnemy.set_image("/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/enemy.png",renderer);
        
    SDL_Texture* tmpTEX = tmpEnemy.set_image("/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/enemy.png",renderer);
    map.insert( std::pair<EnemySprite*, SDL_Texture*>( &tmpEnemy, tmpTEX ) );
    
    
    
    int counter = 0;

    //Loop
         
    while(counter < 5) {

        // int x = (rand() % 100) + 1;
        //int y = (rand() % 100) + 1;
        
        int x = 400;
        int y = 600;


        //enemyObj
          EnemySprite* tmp = new EnemySprite(x,y,40,40); //variying x and y attributes
          //enemyTex
          SDL_Texture* tmpTex = tmp->set_image("/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/enemy.png",renderer);
        
        map.insert( std::pair<EnemySprite*, SDL_Texture*>(tmp, tmpTex));
        counter++;
        
    }
    
    counter= 0;
    
    //reset counter
    
    std::cout << "Size of enemy map: " << map.size() << std::endl;
    renderAllEnemy();
   
        //clear memory
        render();
        
    //set the default val.
   // xAxis = 700;
    //yAxis = 450;
}

void GameEngine::freeEnemies(){
    //free textures from the arraylist
}



void GameEngine::shoot(){
    cnt++;
   // /Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/bullet.png
    bulletTex = bs.set_image("/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/bullet.png", renderer);
    bs.bulletLoop(sprite.getRect().x, renderer);
}



void GameEngine::render(){
    //This is used to redner things, kinda like a refresh after every event than occurs.
    SDL_UpdateWindowSurface(window);
    SDL_RenderClear(renderer);
    sprite.renCpy(renderer, playerTex);
    //bs.renCpy(renderer, bulletTex);
    tmpEnemy.renCpy(renderer, enemyTex);
    SDL_RenderPresent(renderer);
}

void GameEngine::renderAllEnemy(){
        
    int counter = 0;
    //loop through hashmaps and lay sprites
       std::map <EnemySprite*, SDL_Texture*>:: iterator it;
      
       for(it = map.begin(); it != map.end(); it++){
           counter++;
           std::cout << "counter:  " << counter << std::endl;
            //and RenderCpy and shit
           SDL_Texture* texz = it->second;
           it->first->renCpy(renderer, texz);
       }
       
    
   
}

void GameEngine::clean(){
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(playerTex);
    SDL_DestroyTexture(bulletTex);
    freeEnemies();
    SDL_Quit();
    
    
    std::cout << "SDL CLEANED and DESTROYED!...." << std::endl;
}

bool GameEngine::running(){
    return isRuning;
}
