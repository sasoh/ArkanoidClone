//
//  TargetObject.cpp
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#include "TargetObject.h"

TargetObject::TargetObject(struct Rectangle &rect, int targetPrice, char *filename): price(targetPrice), SpriteObject(rect, filename) {
    
    tag = ObjectTagTarget;
    currentState = ObjectStatesAlive;
    
}

TargetObject::~TargetObject() {
    
}

void TargetObject::Update(float delta, unsigned char keyStates, std::vector<GameObject *> &objects) {

    // nothing yet
    
}

void TargetObject::Render(sf::RenderWindow *targetWindow) {
    
    if (currentState == ObjectStatesAlive) {
        SpriteObject::Render(targetWindow);
    }
    
}

void TargetObject::SetState(struct OBJECT_MESSAGE &msg) {
 
    currentState = msg.state;
}

void TargetObject::QueryState(struct OBJECT_MESSAGE &msg) {
    
    msg.state = currentState;
    
}