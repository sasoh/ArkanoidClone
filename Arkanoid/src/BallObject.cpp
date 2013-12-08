//
//  BallObject.cpp
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#include "BallObject.h"

BallObject::BallObject(struct Rectangle &rect, char *filename): SpriteObject(rect, filename) {
    
    speed = 10.0f;
    direction.x = speed;
    direction.y = speed;
    
}

BallObject::~BallObject() {
    
}

void BallObject::Update(float delta, unsigned char keyStates, std::vector<GameObject *> &objects) {

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

    // update ball position according to direction
    frame.x += direction.x * delta;
    frame.y += direction.y * delta;
    
    for (std::vector<GameObject *>::iterator iterator = objects.begin(); iterator != objects.end(); ++iterator) {
        GameObject *obj = *iterator;
        if (obj->tag == ObjectTagTarget || obj->tag == ObjectTagPaddle) {
            if (IsRectangleIntersectingRectangle(frame, obj->frame)) {
                // collision handling
                float collisionLeft = (frame.x + frame.width) - obj->frame.x;
                float collisionRight = frame.x - (obj->frame.x + obj->frame.width);
                float collisionTop = (frame.y + frame.height) - obj->frame.y;
                float collisionBottom = frame.y - (obj->frame.y + obj->frame.height);

                // collisions would usually occur in very small amounts
                // reverse direction if needed (prevents bug when colliding with moving paddle)
                float cutoff = 1.0f;
                if (fabsf(collisionLeft) < cutoff) {
                    if (direction.x > 0.0) {
                        direction.x *= -1;
                    }
                }
                if (fabsf(collisionRight) < cutoff) {
                    if (direction.x < 0.0) {
                        direction.x *= -1;
                    }
                }
                if (fabsf(collisionTop) < cutoff) {
                    if (direction.y > 0.0) {
                        direction.y *= -1;
                    }
                }
                if (fabsf(collisionBottom) < cutoff) {
                    if (direction.y < 0.0) {
                        direction.y *= -1;
                    }
                }
            }
        }
    }
    
    // reposition
    sprite->setPosition(frame.x, frame.y);
    
}

void BallObject::Render(sf::RenderWindow *targetWindow) {

    SpriteObject::Render(targetWindow);
    
}