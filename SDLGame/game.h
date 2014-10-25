//
//  game.h
//  SDLGame
//
//  Created by Andrei Nechaev on 10/23/14.
//  Copyright (c) 2014 Andrei Nechaev. All rights reserved.
//

#ifndef __SDLGame__game__
#define __SDLGame__game__

#include <stdio.h>
#include <SDL2/SDL.h>
#include <vector>
#include "texture_manager.h"
#include "game_object.h"
#include "player.h"
#include "enemy.h"


class Game
{
public:
    static Game* Instance()
    {
        if (!Instance_) {
            Instance_ = new Game();
        }
        return Instance_;
    }
    bool init(const char* title, int xpos, int ypos, int width, int height, bool makeFullScreen);
    SDL_Renderer* getRenderer() const { return renderer_; }
    void render();
    void update();
    void handleEvents();
    void clean();
    void quit();
    
    inline bool isRunning(){ return isRunning_; }
    
private:
    Game();
    static Game* Instance_;
    
    SDL_Window* window_;
    SDL_Renderer* renderer_;
  
    
    bool isRunning_ = false;
    
    std::vector<SDLGameObject*> gameObjects_;
};

typedef Game TheGame;

#endif /* defined(__SDLGame__game__) */
