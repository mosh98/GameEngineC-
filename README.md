# GameEngineC-

## Quick Start Guide

### How to use the space invaders GameEngine API?

Make a GameEngine Object

0. GameEngine *gameEngine =  new GameEngine();

1. Initialize
```
    gameEngine->init("MOSH_Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);        
```
    
2.  setEnemyAttributes
```
        gameEngine-> setEnemyAttributes(0, 0, "/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/enemy.png", 20);
```

3. addPlayerSprite
```

 gameEngine-> addPlayerSprite(48,48, "/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/triangle-clipart-triangle-shape-1-original.png");
```
4. addBulletImage

```
    gameEngine-> addBulletImage("/Users/moslehmahamud/Documents/GameEngineC-CloneFromGit/bullet.png");
```
5. initialize_Loop
```
gameEngine-> initialize_Loop(gameEngine);

```
6. 
```
delete gameEngine;

```
