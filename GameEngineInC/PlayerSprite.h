//
//  TriangleSprite.hpp
//  GameEngineInC
//
//  Created by Mosleh Mahamud on 2020-06-24.
//  Copyright © 2020 Mosleh Mahamud. All rights reserved.
//

#ifndef TriangleSprite_h
#define TriangleSprite_h
#include "Sprite.h"


#include <stdio.h>
#include <string>


class PlayerSprite: public Sprite {
    
    
public:
    PlayerSprite (int x, int y, int w, int h);
    
  ~PlayerSprite() override = default;
    
    void increaseX(); //right button
    void decreaseX();//left button
    void increaseY();
    void decreaseY();
    std::string getPath();
    
    
    


private:
    std::string path;
    
};

#endif /* TriangleSprite_h*/
