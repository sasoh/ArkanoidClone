//
//  BallObject.cpp
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#include "BallObject.h"

void BallObject::Update(float delta) {

    // update ball position according to direction
    position.x += direction.x * delta;
    position.y += direction.y * delta;
    
}

void BallObject::Render() {

    // graphcis code
    
}