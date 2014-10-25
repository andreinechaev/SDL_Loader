//
//  enemy.h
//  SDLGame
//
//  Created by Andrei Nechaev on 10/24/14.
//  Copyright (c) 2014 Andrei Nechaev. All rights reserved.
//

#ifndef __SDLGame__enemy__
#define __SDLGame__enemy__

#include <stdio.h>
#include "SDLGameObject.h"

class Enemy : public SDLGameObject{
public:
    Enemy(const LoaderParams* params);
    
    void draw();
    void update();
    void clean();
    
};

#endif /* defined(__SDLGame__enemy__) */
