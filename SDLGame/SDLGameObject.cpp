//
//  SDLGameObject.cpp
//  SDLGame
//
//  Created by Andrei Nechaev on 10/24/14.
//  Copyright (c) 2014 Andrei Nechaev. All rights reserved.
//

#include "SDLGameObject.h"
#include "texture_manager.h"
#include "game.h"

SDLGameObject::SDLGameObject(const LoaderParams* params) : GameObject(params), position(params->getX(), params->getY()), velocity_(0, 0), acceleration_(0, 0)
{
    width_ = params->getWidth();
    height_ = params->getHeight();
    
    textureID_ = params->getTextureID();
    
    currentFrame_ = 1;
    currentRow_ = 1;
}

void SDLGameObject::draw()
{
    TextureManager::Instance()->
    drawFrame(textureID_, static_cast<int>(position.getX()), static_cast<int>(position.getY()), width_, height_, currentRow_, currentFrame_, Game::Instance()->getRenderer());
}

void SDLGameObject::update()
{
    position += velocity_;
    position += acceleration_;
}

void SDLGameObject::clean()
{
    
}