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
    delete b;
    window = NULL;
    renderer = NULL;
    screen = NULL;
    
    IMG_Quit();
    SDL_Quit();
    
    std::cout<<"GameEngine destructor called "<< std::endl;
}


void GameEngine::initialize_Loop(GameEngine *gameEngine){
    
    
    //Uint32 start = SDL_GetTicks(); // should be moved to .h class
    
    while(gameEngine -> running()) {
        
        if(gameEngine->running() == false){
            break;
        }
        
        
        gameEngine->handleEvents();
        
        gameEngine->tickSprites();
        gameEngine->drawSprites();
        
        gameEngine->updateSprites(); //tar bort removed sprites
       
    
        if(1000/FPS > SDL_GetTicks() - startTick)
            SDL_Delay(1000/FPS);
    }
    
    delete gameEngine;
}


void GameEngine::drawSprites(){
    
    SDL_UpdateWindowSurface(window);
    SDL_RenderClear(renderer);
    
    for(Bullet* bull: vecOfBullet){
       
        bull->draw(renderer,bull->getMyTex());
        
    }
    
     for(EnemySprite* enemy: vecOfEnemy){
         
         enemy->draw(renderer, enemy->getMyTex());
         
     }
       
       playerSprite->draw(renderer, playerTex);
    
       SDL_RenderPresent(renderer);
    
}



void GameEngine::tickSprites(){
   
    for(Bullet* bull: vecOfBullet){
       
        bull->tick();
        
    }
    
    checkCollision();
    
    for(EnemySprite* enemy: vecOfEnemy){
        enemy->tick();
        
    }
    
    
}

void GameEngine::checkCollision(){
    
    for(EnemySprite* enemyInVec: vecOfEnemy){
       
        const SDL_Rect &enem = enemyInVec->getRectobj();
        const SDL_Rect* enemyRect = &enem;
        
        for(Bullet* bull: vecOfBullet){
           
            
            const SDL_Rect &bulletPointer = bull->getRectobj();
            const SDL_Rect* rectBullet = &bulletPointer;
              
        
                if( SDL_HasIntersection ( rectBullet, enemyRect ) == SDL_TRUE ) {
                    
                    removedEnenmy.push_back(enemyInVec);
                    
                    std::cout<< "COLLIDED"<< std::endl;
                    
                }
            
        }
    
    }
    
}

void GameEngine::removeBullet(Bullet *bullet){
    removedBullet.push_back(bullet);
}

void GameEngine::updateSprites(){
    
    
    for(Bullet* b: removedBullet){
    for(vector<Bullet*>::iterator i = vecOfBullet.begin(); i != vecOfBullet.end();){
       
        if((*i) == b){
            i = vecOfBullet.erase(i);
            delete b;
        }else{
            i++;
        }
        }//inner
    }//outer
    
    
    for(EnemySprite* enemyInVec: removedEnenmy){
       for(vector<EnemySprite*>::iterator i = vecOfEnemy.begin(); i != vecOfEnemy.end();){
          
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
    
//    for(vector<Bullet*>::iterator i = vecOfBullet.begin(); i != vecOfBullet.end(); ){
//
//
//
//        if(*i == b){
//                 i = vecOfBullets.erase(i);
//                 delete b;
//
//             }else{
//                 i++;
//             }
//    }
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
    
//    playerSprite->setWindowWidth(width);
    
    if( SDL_Init(SDL_INIT_EVERYTHING) == 0 ) {
        
        std::cout << "Subsystems Initialized!...." << std::endl;
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        
        if(renderer){
            
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            std::cout << "Renderer Initialized!...." << std::endl;
        
        }
        
        
        screen = SDL_GetWindowSurface(window); //This "canvas" is where we gonna append our bmp picture to!
        
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
            //SDL_UpdateWindowSurface(window);
            //render();
            break;
            
        case SDLK_RIGHT:
            playerSprite->increaseX();
            //SDL_FreeSurface(screen);
            //SDL_UpdateWindowSurface(window);
           // render();
            break;
            

            
            
        case SDLK_SPACE:
            shoot();
            //SDL_FreeSurface(screen);
            //SDL_UpdateWindowSurface(window);
            //render();
            break;
            
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
    
    playerSprite->setPath(pathToImage);
    
    //set the texture
    playerTex = playerSprite->set_image_tex( pathToImage.c_str(), renderer );
    
    playerSprite->draw(renderer, playerTex);
    
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
        
        //enemyObj
        //EnemySprite* enemySpritez = new EnemySprite( x,y,enemyWidth,enemyHeight  ) ; //variying x and y attributes
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
    
    // std::map <EnemySprite*, SDL_Texture*>:: iterator it;
    
    for(EnemySprite* enemy: vecOfEnemy){
        
        
        enemy->tick();
    
        enemy->draw(renderer, enemy->getMyTex());
    }
}


void GameEngine:: setFPS(int fps){
    if(fps > 1){
        FPS = fps;
    }
    
}

void GameEngine::freeEnemies(){
    
    for(EnemySprite* enemy: vecOfEnemy){
        delete enemy;
    }
    vecOfEnemy.clear();
    std::cout<<"Vec of enemy:"<< vecOfEnemy.size() << std::endl;
    
}



void GameEngine:: addBulletImage(std::string pathToImage){
    bulletPath += pathToImage;
    
    b = b->create(20,20,pathToImage.c_str());
    b->setPath(pathToImage);
    b->set_image_tex(b->getPath().c_str(),renderer); //bullet path
}

void GameEngine::createBullet(){
    b = b->create(20,20,bulletPath.c_str());
       b->setPath(bulletPath);
       b->set_image_tex(b->getPath().c_str(),renderer); //bullet path
}

void GameEngine::shoot(){

   
   // b->shoot( playerSprite->getPosX(),renderer, vecOfEnemy );
     
    Bullet* tmpBullet = nullptr;
    tmpBullet = tmpBullet->create(20, 20, bulletPath.c_str());
    
    tmpBullet->setPosY(playerSprite->getPosY());
    tmpBullet->setPosX(playerSprite->getPosX());
    
    tmpBullet->setPath(bulletPath);
    tmpBullet->set_image_tex(tmpBullet->getPath().c_str(),renderer); //bullet path
    
    //tmpBullet->shoot(playerSprite->getPosX(), renderer, vecOfEnemy);
    
    vecOfBullet.push_back(tmpBullet);
    

  // renderAllEnemy();
    
    //delete bullet;
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
   // SDL_DestroyTexture(bulletTex);
    freeEnemies();

    std::cout << "SDL CLEANED and DESTROYED!...." << std::endl;
}

void GameEngine::removeSprite(Sprite* sprite){
    delete playerSprite;
}



bool GameEngine::running(){
    return isRuning;
}

GameEngine gE;
}

