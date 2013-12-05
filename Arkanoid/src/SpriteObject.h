//
//  SpriteObject.h
//  Arkanoid
//
//  Created by Alexander Popov on 12/5/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#ifndef __Arkanoid__SpriteObject__
#define __Arkanoid__SpriteObject__

#include <iostream>
#include "GameObject.h"

class SpriteObject : public GameObject {
public:
    SpriteObject(struct Rectangle &rect, char *filename);
    virtual ~SpriteObject();
    virtual void Update(float delta);
    virtual void Render(sf::RenderWindow *targetWindow);
    
private:
    
};

#endif /* defined(__Arkanoid__SpriteObject__) */
