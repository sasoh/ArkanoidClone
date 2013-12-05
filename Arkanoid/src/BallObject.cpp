//
//  BallObject.cpp
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#include "BallObject.h"

BallObject::BallObject(struct Rectangle &rect, char *filename): SpriteObject(rect, filename) {
    
    direction.x = 0.0;
    direction.y = 0.0;
    
}

BallObject::~BallObject() {
    
}

void BallObject::Update(float delta) {

    // update ball position according to direction
    frame.left += direction.x * delta;
    frame.top += direction.y * delta;
    
    // reposition
    sprite->setPosition(frame.left, frame.top);
    
}

void BallObject::Render(sf::RenderWindow *targetWindow) {

    SpriteObject::Render(targetWindow);
    
}