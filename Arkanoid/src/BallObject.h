//
//  BallObject.h
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#ifndef __Arkanoid__BallObject__
#define __Arkanoid__BallObject__

#include <iostream>
#include "GameObject.h"

class BallObject : public GameObject {
public:
    virtual void Update(float delta);
    virtual void Render();
    
private:
    // physics
    struct Vector direction;
};

#endif /* defined(__Arkanoid__BallObject__) */
