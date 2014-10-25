//
//  player.cpp
//  SDLGame
//
//  Created by Andrei Nechaev on 10/23/14.
//  Copyright (c) 2014 Andrei Nechaev. All rights reserved.
//

#include "player.h"

Player::Player(const LoaderParams* params):SDLGameObject(params)
{
    this->currentRow_ = 6;
}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    currentFrame_ = int((SDL_GetTicks()) / 110) % 18;
    
    velocity_.setX(1);
    acceleration_.setX(1);
    
    SDLGameObject::update();
}

void Player::clean()
{
    
}

