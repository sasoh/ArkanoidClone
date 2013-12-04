//
//  PaddleObject.cpp
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#include "PaddleObject.h"

void PaddleObject::Update(float delta) {
    
    // update ball position according to direction
    position.x += direction.x * delta;
    position.y += direction.y * delta;
    
}

void PaddleObject::Render() {
    
    // graphcis code
    
}