# GameEngineC-
![DEMO](https://github.com/mosh98/GameEngineC-/blob/master/ezgif.com-crop.gif)
## Quick Start Guide

### How to use the space invaders GameEngine API?

0. Make a GameEngine Object and set FPS

```
GameEngine *gameEngine =  new GameEngine();

gameEngine->setFPS(30);

```

1. Initialize
```
gameEngine->init("Name Of your Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, false);    

```
    
2.  setEnemyAttributes
```
gameEngine-> setEnemyAttributes(0, 0, "Path to your enemy picture.png", HowManyEnemiesPutItHere);

```


3. addPlayerSprite
```
gameEngine-> addPlayerSprite(WIDTH,HEIGHT, "Path to your player picture.png");

```
4. addBulletImage

```
gameEngine-> addBulletImage("Path to your enemy picture.png");

```
5. initialize_Loop
```
gameEngine-> initialize_Loop(gameEngine); //Pass in the Game Engine object your created earlier

```


It should look something like this

```

GameEngine *gameEngine = nullptr;

int main(int argc, const char * argv[]) {
       
    gameEngine = new GameEngine();
    
    gameEngine->setFPS(30);
    gameEngine->init("MOSH_Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    gameEngine-> setEnemyAttributes(30, 30, "/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/enemy.png", 8);
    gameEngine-> addPlayerSprite(48,48,"/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/triangle-clipart-triangle-shape-1-original.png");
    gameEngine-> addBulletImage("/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/bullet.png");
    gameEngine-> initialize_Loop();
    
    return 0;
}
```


