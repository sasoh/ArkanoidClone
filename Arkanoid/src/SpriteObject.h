//
//  SpriteObject.h
//  Arkanoid
//
//  Created by Alexander Popov on 12/5/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#ifndef __Arkanoid__SpriteObject__
#define __Arkanoid__SpriteObject__

#include "GameObject.h"

class SpriteObject : public GameObject {
public:
    SpriteObject(struct Rectangle &rect, char *filename);
    virtual ~SpriteObject();
    virtual void Update(float delta, unsigned char keyStates, std::vector<GameObject *> &objects);
    virtual void Render(sf::RenderWindow *targetWindow);
    virtual void SetState(struct OBJECT_MESSAGE &msg);
    virtual void QueryState(struct OBJECT_MESSAGE &msg);
    
private:
    
};

#endif /* defined(__Arkanoid__SpriteObject__) */
