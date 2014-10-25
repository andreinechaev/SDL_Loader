//
//  game_object.h
//  SDLGame
//
//  Created by Andrei Nechaev on 10/23/14.
//  Copyright (c) 2014 Andrei Nechaev. All rights reserved.
//

#ifndef __SDLGame__game_object__
#define __SDLGame__game_object__

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include "loader_params.h"

class GameObject{
public:
    virtual void draw()=0;
    virtual void update()=0;
    virtual void clean()=0;
    
protected:
    GameObject(const LoaderParams* params) {}
    virtual ~GameObject(){}
};

#endif /* defined(__SDLGame__game_object__) */
