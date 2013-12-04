//
//  BallObject.cpp
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#include "BallObject.h"

BallObject::BallObject(struct Rectangle &rect) {
    
    frame = rect;
    
}

BallObject::~BallObject() {
    
}

void BallObject::Update(float delta) {

    // update ball position according to direction
    frame.left += direction.x * delta;
    frame.top += direction.y * delta;
}

void BallObject::Render() {

    // graphcis code
    
}