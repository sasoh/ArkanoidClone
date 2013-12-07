//
//  PaddleObject.h
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#ifndef __Arkanoid__PaddleObject__
#define __Arkanoid__PaddleObject__

#include "SpriteObject.h"

class PaddleObject : public SpriteObject {
public:
    PaddleObject(struct Rectangle &rect, char *filename);
    virtual ~PaddleObject();
    virtual void Update(float delta, unsigned char keyStates, std::vector<GameObject *> &objects);
    virtual void Render(sf::RenderWindow *targetWindow);
    
private:
    float speed;
};

#endif /* defined(__Arkanoid__PaddleObject__) */
