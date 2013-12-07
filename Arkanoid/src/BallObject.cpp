//
//  BallObject.cpp
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#include "BallObject.h"

BallObject::BallObject(struct Rectangle &rect, char *filename): SpriteObject(rect, filename) {
    
    speed = 1000.0f;
    direction.x = speed;
    direction.y = speed;
    
}

BallObject::~BallObject() {
    
}

void BallObject::Update(float delta, unsigned char keyStates, std::vector<GameObject *> &objects) {

    // update ball position according to direction
    frame.x += direction.x * delta;
    frame.y += direction.y * delta;
    
    // limit movement to screen bounds
    if (frame.x < BACKGROUND_BORDER_OFFSET) {
        direction.x *= -1;
    }
    if (frame.x + frame.width > WINDOW_WIDTH - BACKGROUND_BORDER_OFFSET) {
        direction.x *= -1;
    }
    if (frame.y < BACKGROUND_BORDER_OFFSET) {
        direction.y *= -1;
    }
    if (frame.y + frame.height > WINDOW_HEIGHT - BACKGROUND_BORDER_OFFSET) {
        direction.y *= -1;
    }
    
    // reposition
    sprite->setPosition(frame.x, frame.y);
    
}

void BallObject::Render(sf::RenderWindow *targetWindow) {

    SpriteObject::Render(targetWindow);
    
}