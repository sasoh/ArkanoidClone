//
//  PaddleObject.h
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#ifndef __Arkanoid__PaddleObject__
#define __Arkanoid__PaddleObject__

#include <iostream>
#include "SpriteObject.h"

class PaddleObject : public SpriteObject {
public:
    PaddleObject(struct Rectangle &rect, char *filename);
    virtual ~PaddleObject();
    virtual void Update(float delta);
    virtual void Render(sf::RenderWindow *targetWindow);
    
    struct Vector direction;
};

#endif /* defined(__Arkanoid__PaddleObject__) */
