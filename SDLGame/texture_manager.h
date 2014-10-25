//
//  texture_manager.h
//  SDLGame
//
//  Created by Andrei Nechaev on 10/23/14.
//  Copyright (c) 2014 Andrei Nechaev. All rights reserved.
//

#ifndef __SDLGame__texture_manager__
#define __SDLGame__texture_manager__

#include <stdio.h>
#include <string>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

using std::string;


class TextureManager {    
public:
    static TextureManager* instance_;
    ~TextureManager();
    
    static TextureManager* Instance()
    {
        if (!instance_) {
            instance_ = new TextureManager();
            return instance_;
        }
        return instance_;
    }
    
    bool load(const string& fileName, const string& id, SDL_Renderer* renderer);
    
    void draw(const string& id, int x, int y,
              int width, int height,
              SDL_Renderer* renderer,
              SDL_RendererFlip = SDL_FLIP_NONE);
    
    void drawFrame(const string& id, int x, int y,
                   int width, int height,
                   int currentRow, int currentFrame,
                   SDL_Renderer* renderer, SDL_RendererFlip = SDL_FLIP_NONE);
    
private:
    TextureManager(); //singleton, call thru Instance()
    std::map<string, SDL_Texture*> textureMap_;
};

typedef TextureManager TheTextureManager;

#endif /* defined(__SDLGame__texture_manager__) */
