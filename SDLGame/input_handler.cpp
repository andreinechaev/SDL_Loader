//
//  input_handler.cpp
//  SDLGame
//
//  Created by Andrei Nechaev on 10/24/14.
//  Copyright (c) 2014 Andrei Nechaev. All rights reserved.
//

#include "input_handler.h"
#include <SDL2/SDL_joystick.h>
#include <iostream>
#include "game.h"

InputHandler* InputHandler::Instance_ = 0;

void InputHandler::initialiseJoysticks()
{
    if (!SDL_WasInit(SDL_INIT_JOYSTICK)) {
        SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    }
    
    if (SDL_NumJoysticks() > 0) {
        for (int i = 0; i < SDL_NumJoysticks(); ++i) {
            SDL_Joystick* joy = SDL_JoystickOpen(i);
            
            if (joy) {
                joysticks_.push_back(joy);
            }else{
                std::cout << SDL_GetError();
            }
        }
        SDL_JoystickEventState(SDL_ENABLE);
        joysticksInitialised_ = true;
        
        std::cout << "Initialised " << joysticks_.size() << " joysticks\n";
    }else{
        std::cout << "No Joysticks\n";
        joysticksInitialised_ = false;
    }
}

void InputHandler::update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            TheGame::Instance()->quit();
        }
    }
}

void InputHandler::clean()
{
    if (joysticksInitialised_) {
        for (unsigned int i = 0; i < SDL_NumJoysticks(); ++i) {
            SDL_JoystickClose(joysticks_[i]);
        }
    }
}

InputHandler::InputHandler(){}
InputHandler::~InputHandler(){}
