//
//  GameEngine.cpp
//  GameEngineInC

//  Created by Mosleh Mahamud (moma1820, -) on 2020-06-19.
//  Co-Creator Nyamgarig Naranbaatar (nyna2000)
//  Co-Creator Jimmy Ljungman  (jilj1595)
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.

// Basnivå1

#include "GameEngine.h"
#include <iostream>



namespace gameengine {

GameEngine::GameEngine( )
{
    playerSprite =  playerSprite->create(400,500,48,48);
}

GameEngine::~GameEngine(){
    
    clean();
    delete playerSprite;
    window = NULL;
    renderer = NULL;
    screen = NULL;
    
    IMG_Quit();
    SDL_Quit();
    
    std::cout<<"GameEngine destructor called "<< std::endl;
}


void GameEngine::initialize_Loop(){
    
    while(running()) {
        
        if( running() == false){
            break;
        }
        
        
        handleEvents();
        tickSprites();
        drawSprites();
        updateSprites(); //tar bort removed sprites
       
    
        if(1000/FPS > SDL_GetTicks() - startTick)
            SDL_Delay(1000/FPS);
    }
    

}


void GameEngine::drawSprites(){
    
    SDL_UpdateWindowSurface(window);
    SDL_RenderClear(renderer);
    
    for(Bullet* bull: vecOfBullet){
        //bull->draw(renderer,bull->getMyTex());
        bull->draw(renderer);
    }
    
     for(EnemySprite* enemy: vecOfEnemy){
         enemy->draw(renderer);
     }
       
       //playerSprite->draw(renderer, playerTex);
        playerSprite->draw(renderer);
       
    SDL_RenderPresent(renderer);
    
}



void GameEngine::tickSprites(){
   
    for(Bullet* bull: vecOfBullet){
        bull->tick( &removedBullet );
    }
    
    checkCollision();
    
    for(EnemySprite* enemy: vecOfEnemy) {
        enemy->tick();
    }
}

void GameEngine::checkCollision(){
    
    for(EnemySprite* enemyInVec: vecOfEnemy){
       
        const SDL_Rect &enem = enemyInVec->getRectobj();
        const SDL_Rect* enemyRect = &enem;
        
        for(Bullet* bull: vecOfBullet) {
           
            const SDL_Rect &bulletPointer = bull->getRectobj();
            const SDL_Rect* rectBullet = &bulletPointer;
              
                if( SDL_HasIntersection ( rectBullet, enemyRect ) == SDL_TRUE ) {
                    removedEnenmy.push_back(enemyInVec);
                    std::cout<< "COLLIDED"<< std::endl;
                    
                }
        }
    
    }
    
}

void GameEngine::removeBullet(Bullet *bullet) {

    removedBullet.push_back(bullet);

}

void GameEngine::updateSprites(){
    
    for(Bullet* b: removedBullet){
        
        for(std::vector<Bullet*>::iterator i = vecOfBullet.begin(); i != vecOfBullet.end();) {
            
            if((*i) == b){
                i = vecOfBullet.erase(i);
                delete b;
            }else{
                i++;
            }
        }//inner
    }//outer
    
    
    for(EnemySprite* enemyInVec: removedEnenmy){
        for(std::vector<EnemySprite*>::iterator i = vecOfEnemy.begin(); i != vecOfEnemy.end();){
            
            if((*i) == enemyInVec){
                i = vecOfEnemy.erase(i);
                delete enemyInVec;
            }else{
                i++;
            }
        }//inner
    }//outer
    
    removedEnenmy.clear();
    removedBullet.clear();
    
}

//INITIALIZE
void GameEngine::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    
    int flag = 0;
    if(fullscreen){
        flag = SDL_WINDOW_FULLSCREEN;
    }
    
    this->width = width;
    
    this->height = height;
    
    
    if( SDL_Init(SDL_INIT_EVERYTHING) == 0 ) {
        
        std::cout << "Subsystems Initialized!...." << std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        
        if(renderer){
            
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            std::cout << "Renderer Initialized!...." << std::endl;
            
        }
        
        
        screen = SDL_GetWindowSurface(window); //This "canvas" is where we gonna append our bmp picture to!
        
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
            if( ! (playerSprite->getPosX() < 10) )
                playerSprite->decreaseX();
            break;
            
        case SDLK_RIGHT:
            if( ! (playerSprite->getPosX() > (width-70)) )
                playerSprite->increaseX();
            break;
            
        case SDLK_SPACE:
            shoot();
            break;
            
        default:
            break;
    }
    
}


void GameEngine:: addPlayerSprite(int width, int height, std::string pathToImage){
    
    if( ! ( width <= 10 && height <= 10 ) ){
        playerSprite->setWidthAndHeight(width, height);
    }
    
    playerSprite->setPath(pathToImage);
    playerTex = playerSprite->set_image_tex( pathToImage.c_str(), renderer );
    //playerSprite->draw(renderer, playerTex);
    playerSprite->draw(renderer);
    
}

void GameEngine::setEnemyAttributes(int width, int height, std::string pathToImage, int enemy){
    
    this->enemyWidth = width;
    this->enemyHeight = height;
    
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
        
        EnemySprite* enemySpritez = nullptr;
        enemySpritez = enemySpritez->create(x,y, enemyWidth, enemyHeight);
        enemySpritez->set_image_tex( enemyPath.c_str(), renderer );
        vecOfEnemy.push_back(enemySpritez);
        
        counter++;
        
        x += 20;
        
        if(counter > howManyEnemyYouNeed)
            break;
    }
}


//if last enemy in the vector has x
void GameEngine::moveEnemies(){
        
    for(EnemySprite* enemy: vecOfEnemy){
        enemy->tick();
        enemy->draw(renderer);
    }
}


void GameEngine:: setFPS(int fps){
    if(fps > 1){
        FPS = fps;
    }
    
}

void GameEngine:: addBulletImage(std::string pathToImage)
{
    bulletPath += pathToImage;

}



void GameEngine::shoot(){

    Bullet* tmpBullet = nullptr;
    tmpBullet = tmpBullet->create(20, 20, bulletPath.c_str());
    tmpBullet->setPosY(playerSprite->getPosY());
    tmpBullet->setPosX(playerSprite->getPosX());
    tmpBullet->setPath(bulletPath);
    tmpBullet->set_image_tex(tmpBullet->getPath().c_str(),renderer); //bullet path
        
    vecOfBullet.push_back(tmpBullet);
    
}


void GameEngine::clean(){
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(playerTex);
    std::cout << "SDL CLEANED and DESTROYED!...." << std::endl;
}

void GameEngine::removeSprite(Sprite* sprite){
    delete playerSprite;
}



bool GameEngine::running(){
    return isRuning;
}



}

