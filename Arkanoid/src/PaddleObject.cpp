//
//  PaddleObject.cpp
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#include "PaddleObject.h"

PaddleObject::PaddleObject(struct Rectangle &rect, char *filename): SpriteObject(rect, filename) {
    
}

PaddleObject::~PaddleObject() {
    
}

void PaddleObject::Update(float delta) {
    
    // update ball position according to direction
    frame.left += direction.x * delta;
    frame.top += direction.y * delta;
    
    // reposition
    sprite->setPosition(frame.left, frame.top);
    
}

void PaddleObject::Render(sf::RenderWindow *targetWindow) {
    
    SpriteObject::Render(targetWindow);
    
}