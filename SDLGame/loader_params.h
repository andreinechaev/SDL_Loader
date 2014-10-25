//
//  loader_params.h
//  SDLGame
//
//  Created by Andrei Nechaev on 10/24/14.
//  Copyright (c) 2014 Andrei Nechaev. All rights reserved.
//

#ifndef __SDLGame__loader_params__
#define __SDLGame__loader_params__

#include <stdio.h>
#include <string>

class LoaderParams
{
public:
    
    LoaderParams(int x, int y, int width, int height, const std::string& textureID);
    
    inline int getX() const { return x_; }
    int getY() const { return y_; }
    int getWidth() const { return width_; }
    int getHeight() const { return height_; }
    
    std::string getTextureID() const { return textureID_; }
    
    
private:
    int x_, y_;
    int width_, height_;
    std::string textureID_;
};

#endif /* defined(__SDLGame__loader_params__) */
