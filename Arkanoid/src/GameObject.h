//
//  GameObject.h
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#ifndef __Arkanoid__GameObject__
#define __Arkanoid__GameObject__

#include <iostream>
#include "Common.cpp"
#include <SFML/Graphics.hpp>

class GameObject {
public:
    virtual void Update(float delta, unsigned char keyStates) = 0;
    virtual void Render(sf::RenderWindow *targetWindow) = 0;
    virtual ~GameObject() {}
    
    struct Rectangle frame;
    sf::Sprite *sprite;
    sf::Texture *texture;
    
private:
    
};

#endif /* defined(__Arkanoid__GameObject__) */
