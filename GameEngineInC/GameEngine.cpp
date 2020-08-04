//
//  GameEngine.cpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud on 2020-06-19.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.
//

#include "GameEngine.h"
#include <iostream>


 

GameEngine::GameEngine( )
{
    
}

GameEngine::~GameEngine(){
    clean();
    freeBullet();
    freeEnemies();
    delete playerSprite;
    delete b;
    window = NULL;
    renderer = NULL;
    screen = NULL;
    
    std::cout<<"GameEngine destructor called "<< std::endl;
}


void GameEngine::initialize_Loop(GameEngine *gameEngine){
    
    int FPS = 25;
    
    Uint32 start = SDL_GetTicks(); // should be moved to .h class
    
    while(gameEngine -> running()){
        
        if(gameEngine->running() == false){
              break;
          }
        
        gameEngine->handleEvents();
        gameEngine->render();
          
         if(1000/FPS > SDL_GetTicks() - start)
              SDL_Delay(1000/FPS);
                moveEnemies();
      }
}

//INITIALIZE
void GameEngine::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    
    int flag = 0;
    if(fullscreen){
        flag = SDL_WINDOW_FULLSCREEN;
    }
    _width = width;
    _height = height;
    
    if( SDL_Init(SDL_INIT_EVERYTHING) == 0 ) {
        
        std::cout << "Subsystems Initialized!...." << std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            std::cout << "Renderer Initialized!...." << std::endl;
        }
        
        
        screen = SDL_GetWindowSurface(window);//This "canvas" is where we gonna append our bmp picture to!
    
        renderAllEnemy();
        
        /* Up until now everything was drawn behind the scenes.
         This will show the new contents of the window. */
        
        //clearing stuff
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
        SDL_UpdateWindowSurface(window);
        isRuning = true;
    }
    else {
        isRuning = false;
    
    }
}

void GameEngine::handleEvents(){
    
    SDL_Event event;
    
    SDL_PollEvent(&event);
    
        if(SDL_QUIT == event.type){
            isRuning = false;
        }
      switch ( event.key.keysym.sym ) {

        case SDLK_LEFT:
            playerSprite->decreaseX();
            SDL_UpdateWindowSurface(window);
            render();
            break;
            
        case SDLK_RIGHT:
            playerSprite->increaseX();
            SDL_FreeSurface(screen);
            SDL_UpdateWindowSurface(window);
            render();
            break;
        
        case SDLK_SPACE:
            shoot();
            SDL_FreeSurface(screen);
            SDL_UpdateWindowSurface(window);
            render();
            
        default:
            break;
    }
    
}

//"/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/triangle-clipart-triangle-shape-1-original.png"


void GameEngine:: addPlayerSprite(int width, int height, std::string pathToImage){
    
    flag = true;
    
    if( ! ( width <= 10 && height <= 10 ) ){
          playerSprite->setWidthAndHeight(width, height);
    }
   
    //set the texture
    playerTex = playerSprite->set_image_tex( pathToImage.c_str(), renderer );
    
      playerSprite->draw(renderer, playerTex);
  
}

void GameEngine::setEnemyAttributes(int width, int height, std::string pathToImage, int enemy){
    
    enemyPath = pathToImage;
    addEnemy(enemy);
    
}

void GameEngine:: addEnemy( int howManyEnemyYouNeed ) {
    
    
    int counter = 0;

    int x = 25;
    int y = 100;
    
    //Loop
    while( counter < howManyEnemyYouNeed) {

    
        std::cout << counter <<std::endl;
    
        //enemyObj
          EnemySprite* enemySpritez = new EnemySprite( x,y,30,30 ) ; //variying x and y attributes
         
    
        SDL_Texture* enemytextureTmp = enemySpritez->set_image_tex( enemyPath.c_str(), renderer );
    
        map.insert( std::pair<EnemySprite*, SDL_Texture*>( enemySpritez , enemytextureTmp ) );
        vecOfEnemy.push_back(enemySpritez);
    
        counter++;
        
        if(counter == (howManyEnemyYouNeed/2) ){
            x = 25;
            y += 35;
            
        } else {
            //x += 75;
            x += 20;
        }
        
        if(counter > howManyEnemyYouNeed)
            break;
        
        
    }
    std::cout << "Size of enemy map: " << map.size() << std::endl;
    
}


void GameEngine::moveEnemies(){

    std::map <EnemySprite*, SDL_Texture*>:: iterator it;



    //free textures from the map
    for(it = map.begin(); it != map.end(); it++){

        if(it->first->getPosX() >= 750){
            moveLeftFlag = true;
        }

        if(moveLeftFlag == true){
            if(it->first->getPosX() <= -20){
                moveLeftFlag = false;
            }
             it->first->setPosX(it->first->getPosX()-5);
        }else{
            it->first->setPosX(it->first->getPosX()+5);
        }

        it->first->draw(renderer, it->second);

    }
}


        
void GameEngine::freeEnemies(){
    
    for(EnemySprite* enemy: vecOfEnemy){
        delete enemy;
    }
    vecOfEnemy.clear();
    std::cout<<"Vec of enemy:"<< vecOfEnemy.size() << std::endl;
    
}

void GameEngine::freeBullet(){
    
    for(Bullet* bz: vec){
        delete bz;
    }
    vec.clear();
    
}

void GameEngine:: addBulletImage(std::string pathToImage){
    
    bulletPath += pathToImage;
    
}


void GameEngine::shoot(){
    
    b->set_image_tex(bulletPath.c_str(),renderer);
    b->shoot(playerSprite->getRect()->x,renderer, vecOfEnemy); //passing the enemy
    renderAllEnemy();
}



    

void GameEngine::render(){
    
    //This is used to redner things, kinda like a refresh after every event occurs.
    SDL_UpdateWindowSurface(window);
    SDL_RenderClear(renderer);
    
    playerSprite->draw(renderer, playerTex);
    renderAllEnemy();
    
    SDL_RenderPresent(renderer);
    
}

void GameEngine::renderAllEnemy() {
    
    std::vector<EnemySprite*>:: iterator it;

    for(it = vecOfEnemy.begin(); it != vecOfEnemy.end(); ++it){
        SDL_Texture *tx = (*it)->getMyTex();
        if((*it)->isDamaged() == false){
           //std::cout <<
            (*it)->draw(renderer, tx);
        }
      
    }
}

void GameEngine::clean(){
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(playerTex);
    freeEnemies();
    SDL_Quit();
    
    std::cout << "SDL CLEANED and DESTROYED!...." << std::endl;
}

bool GameEngine::running(){
    return isRuning;
}
