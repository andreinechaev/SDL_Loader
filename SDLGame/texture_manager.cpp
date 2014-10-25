//
//  texture_manager.cpp
//  SDLGame
//
//  Created by Andrei Nechaev on 10/23/14.
//  Copyright (c) 2014 Andrei Nechaev. All rights reserved.
//

#include "texture_manager.h"

TextureManager* TextureManager::instance_ = 0;

TextureManager::TextureManager(){
    
}

TextureManager::~TextureManager(){
    
}

bool TextureManager::load(const string& fileName,
                          const string& id,
                          SDL_Renderer *renderer)
{
    SDL_Surface* tempSurface = IMG_Load(fileName.c_str());
    if (!tempSurface) {
        return false;
    }
    
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    
    if (texture){
        textureMap_[id] = texture;
        return true;
    }
    
    return false;
}

void TextureManager::draw(const string& id, int x, int y,
                          int width, int height,
                          SDL_Renderer *renderer,
                          SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    
    srcRect.x = 0;
    srcRect.y = 44;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    
    SDL_RenderCopyEx(renderer, textureMap_[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(const string& id, int x, int y,
                               int width, int height,
                               int currentRow, int currentFrame,
                               SDL_Renderer *renderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = width * currentFrame;
    srcRect.y = height * (currentRow - 1);
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    
    SDL_RenderCopyEx(renderer, textureMap_[id], &srcRect, &destRect, 0, 0, flip);
}