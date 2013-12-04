//
//  GameObject.h
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#ifndef __Arkanoid__GameObject__
#define __Arkanoid__GameObject__

#include <iostream>
#include "Common.cpp"

class GameObject {
public:
    virtual void Update(float delta) = 0;
    virtual void Render() = 0;
    virtual ~GameObject() {}
    
    // publicly accessible
    struct Rectangle frame;
private:    
    // maybe something graphical
    
};

#endif /* defined(__Arkanoid__GameObject__) */
