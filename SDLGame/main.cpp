//
//  main.cpp
//  SDLGame
//
//  Created by Andrei Nechaev on 10/23/14.
//  Copyright (c) 2014 Andrei Nechaev. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include "game.h"
#include <fstream>

Game *game = nullptr;
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;
using namespace std;

int main(int argc, const char * argv[])
{
    Uint32 frameStart, frameTime;
    
    if (TheGame::Instance()->init("My Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false))
    {
        while (TheGame::Instance()->isRunning())
        {
            frameStart = SDL_GetTicks();
            TheGame::Instance()->handleEvents();
            TheGame::Instance()->update();
            TheGame::Instance()->render();
            
            frameTime = SDL_GetTicks() - frameStart;
            
            if (frameTime < DELAY_TIME) {
                SDL_Delay(static_cast<int>(DELAY_TIME - frameTime));
            }
        }
    }

    TheGame::Instance()->clean();
    return 0;
}

//    string line;
//    ifstream myfile ("arc1.png");
//    if (myfile.is_open())
//    {
//        while ( getline (myfile,line) )
//        {
//            cout << line << '\n';
//        }
//        myfile.close();
//    }else cout << "Unable to open file\n";
//
//    system("pwd");