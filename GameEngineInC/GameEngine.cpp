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
    delete playerSprite;
    delete bs;
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
               // moveEnemies();
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

void GameEngine:: setEnemyAttributes(int width, int height, std::string pathToImage, int enemy){
    
    enemyPath = pathToImage;
    addEnemy(enemy);
    
}



//std::cout << "Size of x : " << x << std::endl;
  //     std::cout << "Size of y : " << y << std::endl;
       

//TODO: enemy Sprites with random x and y

//possibly also have the imageLink png in the parametres
void GameEngine:: addEnemy( int howManyEnemyYouNeed ) {
    
    
    int counter = 0;

    int x = 25;
    int y = 100;
    
    //Loop
    while( counter < howManyEnemyYouNeed) {

    
        std::cout << counter <<std::endl;
    
        
        //Enemy sprite and texutre gets deleted in freeEnemies();
        
        //enemyObj
          EnemySprite* enemySpritez = new EnemySprite( x,y,20,20 ) ; //variying x and y attributes
         
        //"/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/enemy.png"
        //enemyTex
        SDL_Texture* enemytextureTmp = enemySpritez->set_image_tex( enemyPath.c_str(), renderer );
    
        map.insert( std::pair<EnemySprite*, SDL_Texture*>( enemySpritez , enemytextureTmp ) );
        
    
        counter++;
        
        //if(x > 670){
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
    
    moveLeftFlag = true;
    
    if(moveLeftFlag == true){
        for(it = map.begin(); it != map.end(); it++){

               
               it->first->draw(renderer, it->second);
           }
    }
   
}


        
//        if(it->first->getPosX() >= 750){
//            moveLeftFlag = true;
//        }
//        if(moveLeftFlag == true){
//            if(it->first->getPosX() <= -20){
//                moveLeftFlag = false;
//            }
//             it->first->setPosX(it->first->getPosX()-2);
//        }else{
//            it->first->setPosX(it->first->getPosX()+2);
//        }
//
//
void GameEngine::freeEnemies(){
    
    std::map <EnemySprite*, SDL_Texture*>:: iterator it;
    
    //free textures from the map
    for(it = map.begin(); it != map.end(); it++){
        delete it->first;
        SDL_DestroyTexture(it->second);

    }
    map.clear(); //map deallocated ;)
    
}

void GameEngine:: addBulletImage(std::string pathToImage){
    bulletPath += pathToImage;
    // bulletTex = bs->set_image( bulletPath.c_str(),  renderer);
}



void GameEngine::shoot(){
    cnt++;
    bulletTex = bs->set_image(bulletPath.c_str(), renderer);
    
    // working
    bs->shoot(playerSprite->getRect()->x,renderer);
    
    chekCollision(bs);
    renderAllEnemy();
    
    SDL_DestroyTexture(bulletTex);
}

void GameEngine::chekCollision(Bullet* b){
      std::map <EnemySprite*, SDL_Texture*>:: iterator it;
    
    
    
    for(it = map.begin(); it != map.end(); it++){

        if( bs->checkCollision(bs->getRectobj(), it->first->getRectobj()) ) {
            map.erase(it->first);
            std::cout << "collided" << std::endl;
            
        }else{

            std::cout << "not collided" << std::endl;

        }
        
        SDL_Rect* bull(bs->getRect());
//DONT WORK
        //SDL_Rect* enemy(it->first->getRect());
        //if( SDL_HasIntersection(bull, it->first->getRect() ) == false ) {

            //it->second
                  // map.erase(it->first);
          //  std::cout << "collided" << std::endl;
    //}
        
        
    renderAllEnemy();
 }
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
        
    //loop through hashmaps and lay sprites
       std::map <EnemySprite*, SDL_Texture*>:: iterator it;

       for(it = map.begin(); it != map.end(); it++){
    
            //and RenderCpy and shit
           it->first->draw(renderer, it->second);

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
