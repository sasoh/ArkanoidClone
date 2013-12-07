//
//  PaddleObject.cpp
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#include "PaddleObject.h"

PaddleObject::PaddleObject(struct Rectangle &rect, char *filename): SpriteObject(rect, filename) {
    speed = 10000.0f;
}

PaddleObject::~PaddleObject() {
    
}

void PaddleObject::Update(float delta, unsigned char keyStates) {
    
    // update frame
    if (keyStates & KEYSTATE_LEFT) {
        frame.left -= speed * delta;
    }
    if (keyStates & KEYSTATE_RIGHT) {
        frame.left += speed * delta;
    }
    
    // limit paddle movement to screen
    float backgroundBorderOffset = 10.0f;
    if (frame.left + frame.right > WINDOW_WIDTH - backgroundBorderOffset) {
        frame.left = WINDOW_WIDTH - frame.right - backgroundBorderOffset;
    }
    if (frame.left < backgroundBorderOffset) {
        frame.left = backgroundBorderOffset;
    }
    
    // update sprite position
    sprite->setPosition(frame.left, frame.top);
    
}

void PaddleObject::Render(sf::RenderWindow *targetWindow) {
    
    SpriteObject::Render(targetWindow);
    
}