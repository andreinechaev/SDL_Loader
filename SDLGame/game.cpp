//
//  game.cpp
//  SDLGame
//
//  Created by Andrei Nechaev on 10/23/14.
//  Copyright (c) 2014 Andrei Nechaev. All rights reserved.
//

#include "game.h"
#include <iostream>
#include <SDL2_image/SDL_image.h>
#include "input_handler.h"

Game* Game::Instance_ = 0;

bool Game::init(const char* title,
                int xpos, int ypos,
                int width, int height,
                bool makeFullScreen)

{
    int screenMode = SDL_WINDOW_SHOWN;
    if(makeFullScreen)
        screenMode = SDL_WINDOW_FULLSCREEN_DESKTOP;
    
    if (SDL_Init(SDL_INIT_EVERYTHING < 0)) {
        std::cout << "an Error is caused\n";
        return false;
    }else{
        window_ = SDL_CreateWindow(title, xpos, ypos, width, height, screenMode);
        if (window_) {
            renderer_ = SDL_CreateRenderer(window_, -1, 0);
            if (renderer_){
                SDL_SetRenderDrawColor(renderer_, 0, 255, 0, 0);
            }else{
                std::cout << "Rendere raised an error\n";
                return false;
            }
        }else{
            std::cout << "window raised an error\n";
            return false;
        }
        TheInputHandler::Instance()->initialiseJoysticks();
        
        TheTextureManager::Instance()->load("arc2.png", "animate", renderer_);
        
        Player* p = new Player(new LoaderParams(100,100, 34, 42, "animate"));
        Enemy* e = new Enemy(new LoaderParams(150, 150, 34, 42, "animate"));
        
        gameObjects_.push_back(p);
        gameObjects_.push_back(e);
        
        isRunning_ = true;
        return true;
    }
}

void Game::render()
{
    //clear the render to the draw color
    SDL_RenderClear(renderer_);
    
    for (std::vector<SDLGameObject*>::size_type i = 0; i != gameObjects_.size(); i++) {
        gameObjects_[i]->draw();
    }
    //draw to the screen
    SDL_RenderPresent(renderer_);
}

void Game::update()
{
    for (std::vector<SDLGameObject*>::size_type i = 0; i != gameObjects_.size(); i++) {
        gameObjects_[i]->update();
    }
}

void Game::handleEvents()
{
    TheInputHandler::Instance()->update();
}

void Game::clean()
{
    std::cout << "cleaning the game\n";
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
    TheInputHandler::Instance()->clean();
    SDL_Quit();
}

void Game::quit()
{
    isRunning_ = false;
}

Game::Game(){}
