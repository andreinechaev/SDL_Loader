//
//  SDLGameObject.h
//  SDLGame
//
//  Created by Andrei Nechaev on 10/24/14.
//  Copyright (c) 2014 Andrei Nechaev. All rights reserved.
//

#ifndef __SDLGame__SDLGameObject__
#define __SDLGame__SDLGameObject__

#include <stdio.h>
#include "game_object.h"
#include "loader_params.h"
#include "vector2d.h"

class SDLGameObject : GameObject
{
public:
    SDLGameObject(const LoaderParams* params);
    virtual void draw();
    virtual void update();
    virtual void clean();
    
protected:
    Vector2D position;
    Vector2D velocity_;
    Vector2D acceleration_;
    
    int width_, height_;
    int currentRow_, currentFrame_;
    std::string textureID_;
};

#endif /* defined(__SDLGame__SDLGameObject__) */
