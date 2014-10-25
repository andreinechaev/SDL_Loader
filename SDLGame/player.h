//
//  player.h
//  SDLGame
//
//  Created by Andrei Nechaev on 10/23/14.
//  Copyright (c) 2014 Andrei Nechaev. All rights reserved.
//

#ifndef __SDLGame__player__
#define __SDLGame__player__

#include <stdio.h>
#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:
    Player(const LoaderParams* params);
    
    void draw();
    void update();
    void clean();
};

#endif /* defined(__SDLGame__player__) */
