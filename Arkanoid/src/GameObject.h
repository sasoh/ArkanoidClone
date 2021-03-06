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
#include <vector>
#include <math.h>
#include "Common.cpp"
#include <SFML/Graphics.hpp>

enum OBJECT_TAG {
    ObjectTagSprite,
    ObjectTagBall,
    ObjectTagTarget,
    ObjectTagPaddle
};

enum OBJECT_STATES {
    ObjectStatesAlive,
    ObjectStatesDead
};

struct OBJECT_MESSAGE {
    int messageCode;
    enum OBJECT_STATES state;
    // other data
};

class GameObject {
public:
    virtual void Update(float delta, unsigned char keyStates, std::vector<GameObject *> &objects) = 0;
    virtual void Render(sf::RenderWindow *targetWindow) = 0;
    virtual ~GameObject() {}
    virtual void SetState(struct OBJECT_MESSAGE &msg) = 0;
    virtual void QueryState(struct OBJECT_MESSAGE &msg) = 0;
    
    struct Rectangle frame;
    sf::Sprite *sprite;
    sf::Texture *texture;
    enum OBJECT_TAG tag;
    enum OBJECT_STATES currentState;
private:
    
};

#endif /* defined(__Arkanoid__GameObject__) */
