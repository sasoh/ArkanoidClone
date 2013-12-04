//
//  TargetObject.cpp
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#include "TargetObject.h"

TargetObject::TargetObject(struct Rectangle &rect, int targetPrice): price(targetPrice) {
    
    frame = rect;
    
}

TargetObject::~TargetObject() {
    
}

void TargetObject::Update(float delta) {

    // nothing yet
    
}

void TargetObject::Render() {
    
    // graphcis code
    std::cout << "Render target at [x:" << frame.left << "; y:" << frame.top << "][w:" << frame.right << "; h:" << frame.bottom << "]" << std::endl;
    
}
