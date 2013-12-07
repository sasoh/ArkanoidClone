//
//  BallObject.h
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#ifndef __Arkanoid__BallObject__
#define __Arkanoid__BallObject__

#include "SpriteObject.h"

class BallObject : public SpriteObject {
public:
    BallObject(struct Rectangle &rect, char *filename);
    virtual ~BallObject();
    virtual void Update(float delta, unsigned char keyStates, std::vector<GameObject *> &objects);
    virtual void Render(sf::RenderWindow *targetWindow);
    float speed;
private:
    struct Vector direction;
};

#endif /* defined(__Arkanoid__BallObject__) */
