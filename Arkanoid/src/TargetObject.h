//
//  TargetObject.h
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#ifndef __Arkanoid__TargetObject__
#define __Arkanoid__TargetObject__

#include <iostream>
#include "SpriteObject.h"

class TargetObject : public SpriteObject {
public:
    TargetObject(struct Rectangle &rect, int targetPrice, char *filename);
    virtual ~TargetObject();
    virtual void Update(float delta);
    virtual void Render(sf::RenderWindow *targetWindow);
    
    int price;
};

#endif /* defined(__Arkanoid__TargetObject__) */
