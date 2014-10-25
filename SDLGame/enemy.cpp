//
//  enemy.cpp
//  SDLGame
//
//  Created by Andrei Nechaev on 10/24/14.
//  Copyright (c) 2014 Andrei Nechaev. All rights reserved.
//

#include "enemy.h"

Enemy::Enemy(const LoaderParams* params) : SDLGameObject(params)
{
    currentRow_ = 3;
}

void Enemy::draw()
{
    SDLGameObject::draw();
}

void Enemy::update()
{
    position.setX(position.getX()+1);
    position.setY(position.getY()+1);
    currentFrame_ = int((SDL_GetTicks()) / 110) % 18;
    
    SDLGameObject::update();
}

void Enemy::clean()
{
    
}