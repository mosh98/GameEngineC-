//
//  GameEngine.hpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud (moma1820, -) on 2020-06-19.
//  Co-Creator Nyamgarig Naranbaatar (nyna2000)
//  Co-Creator Jimmy Ljungman  (jilj1595)
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.


// Basnivå1

#ifndef GameEngine_h
#define GameEngine_h


#include <SDL2/SDL.h>

#include "Sprite.h"

#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include "Bullet.h"
#include "PlayerSprite.h"
#include "EnemySprite.h"
#include <vector>



namespace gameengine {

class GameEngine {
    
    
    
public:
    
    GameEngine();
    ~GameEngine();
    
    //intialize
    void init(const char*title, int xpos, int ypos, int width, int height, bool fullscreen); //needs to be pub
    
    void initialize_Loop( );
    
    //Add Features
    void addPlayerSprite(int width, int height, std::string pathToImage);//needs to be pub
    
    //needs to be pub
    void setEnemyAttributes(int width, int height, std::string pathToImage, int enemy); //TODO: width and height for enemy logic
    
    
    void addBulletImage(std::string pathToImage);//needs to be pub
    
    void createBullet();
    
    // implement these
    void removePlayerSprite();
    
    std::vector<EnemySprite*> getVecOfEnemies(){
        return vecOfEnemy;
    }
    
    
    void setFPS(int fps);
    
    int getFPS() const{
        return FPS;
    }
    
    void drawSprites();
    void tickSprites();
    
  
    
    void updateSprites();
    void checkCollision();
    
    int getWidth() const {return width;}
    int getHeight() const {return height;}
    int getEnemyHeight() const {return enemyHeight;}
    int getEnemyWidth() const{return enemyHeight;}
    bool getIsRunning() const {return isRuning;}
    
    std::string getEnemyPath(){return enemyPath;}
    std::string getBulletPath(){return bulletPath;}
   // void removeBullet(Bullet* bullet);
    void remove(Sprite*); // found no use of this
    
private:
    
    //int cnt;
    int width; //get
    int height; //get
    int enemyWidth;//get
    int enemyHeight;//get
    bool isRuning;
  //  bool moveLeftFlag = false;
    std::string enemyPath;//get
    std::string bulletPath;//get
    int FPS = 25;
    
    PlayerSprite* playerSprite = NULL;

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *screen;
    Uint32 startTick = SDL_GetTicks();
    
    std::vector< Sprite* > removedSprites;
    
    std::vector< EnemySprite* > vecOfEnemy; //enemy obj
    std::vector< EnemySprite* > removedEnenmy; //enemy obj
    std::vector< Bullet* > vecOfBullet; //Bullet obj
    std::vector< Bullet* > removedBullet; //Bullet obj
    
    void shoot();
 
    
    void addEnemy( int howManyEnemyYouNeed);
    void handleEvents();
    void clean();
    bool running();
    
};
}




#endif /* GameEngine_hpp */
