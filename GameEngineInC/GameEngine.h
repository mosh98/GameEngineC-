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
    void removeSprite(Sprite* sprite);
    
    std::vector<EnemySprite*> getVecOfEnemies(){
        return vecOfEnemy;
    }
    
    
    void setFPS(int fps);
    
    int getFPS() const{
        return FPS;
    }
    
    void drawSprites();
    void tickSprites();
    
    void removeBullet(Bullet* bullet);
    
    void updateSprites();
    void checkCollision();
    
    int getWidth() const {
        return width;
        
    }
    
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
    Bullet* b = NULL;
    
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *screen;
    SDL_Texture *playerTex;
    SDL_Texture *bulletTex;
    Uint32 startTick = SDL_GetTicks();
    
    std::vector< EnemySprite* > vecOfEnemy; //enemy obj
    std::vector< EnemySprite* > removedEnenmy; //enemy obj
    std::vector< Bullet* > vecOfBullet; //Bullet obj
    std::vector< Bullet* > removedBullet; //Bullet obj
    
    void shoot();
    void remove(Sprite*); // found no use of this
    //void renderAllEnemy();
    void freeEnemies();
    void freeBullet();
    void addEnemy( int howManyEnemyYouNeed);
    void moveEnemies(); //should be moved back to protected
    void handleEvents();
    void render();
    void clean();
    bool running();
    
    
    
    
    
};
 
extern GameEngine gE;

}




#endif /* GameEngine_hpp */
