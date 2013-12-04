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
#include "GameObject.h"

class TargetObject : public GameObject {
public:
    TargetObject(struct Rectangle &rect, int targetPrice);
    virtual ~TargetObject();
    virtual void Update(float delta);
    virtual void Render();
    
    int price;
private:
    // ???
    
};

#endif /* defined(__Arkanoid__TargetObject__) */
