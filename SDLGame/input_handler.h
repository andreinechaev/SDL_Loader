//
//  input_handler.h
//  SDLGame
//
//  Created by Andrei Nechaev on 10/24/14.
//  Copyright (c) 2014 Andrei Nechaev. All rights reserved.
//

#ifndef __SDLGame__input_handler__
#define __SDLGame__input_handler__

#include <stdio.h>
#include <vector>
#include <SDL2/SDL.h>

class InputHandler
{
public:
    static InputHandler* Instance()
    {
        if (!Instance_) {
            Instance_ = new InputHandler();
        }
        return Instance_;
    }
    
    void update();
    void clean();
    
    void initialiseJoysticks();
    bool joysticksInitialised(){ return joysticksInitialised_; }
    
private:
    InputHandler();
    ~InputHandler();
    
    static InputHandler* Instance_;
    std::vector<SDL_Joystick*> joysticks_;
    bool joysticksInitialised_;
};

typedef InputHandler TheInputHandler;

#endif /* defined(__SDLGame__input_handler__) */
