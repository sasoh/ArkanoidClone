//
//  PaddleObject.cpp
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#include "PaddleObject.h"

PaddleObject::PaddleObject(struct Rectangle &rect, char *filename): SpriteObject(rect, filename) {
    
    speed = 50.0f;
    tag = ObjectTagPaddle;
    
}

PaddleObject::~PaddleObject() {
    
}

void PaddleObject::Update(float delta, unsigned char keyStates, std::vector<GameObject *> &objects) {
    
    // update frame
    if (keyStates & KEYSTATE_LEFT) {
        frame.x -= speed * delta;
    }
    if (keyStates & KEYSTATE_RIGHT) {
        frame.x += speed * delta;
    }
    
    // limit paddle movement to screen
    if (frame.x + frame.width > WINDOW_WIDTH - BACKGROUND_BORDER_OFFSET) {
        frame.x = WINDOW_WIDTH - frame.width - BACKGROUND_BORDER_OFFSET;
    }
    if (frame.x < BACKGROUND_BORDER_OFFSET) {
        frame.x = BACKGROUND_BORDER_OFFSET;
    }

    // update sprite position
    sprite->setPosition(frame.x, frame.y);
    
}

void PaddleObject::Render(sf::RenderWindow *targetWindow) {
    
    SpriteObject::Render(targetWindow);
    
}