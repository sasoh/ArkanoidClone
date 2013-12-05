//
//  TargetObject.cpp
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#include "TargetObject.h"

TargetObject::TargetObject(struct Rectangle &rect, int targetPrice, char *filename): price(targetPrice), SpriteObject(rect, filename) {
    
}

TargetObject::~TargetObject() {
    
}

void TargetObject::Update(float delta) {

    // nothing yet
    
}

void TargetObject::Render(sf::RenderWindow *targetWindow) {
    
    SpriteObject::Render(targetWindow);
    
}
