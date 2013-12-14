//
//  TargetObject.h
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#ifndef __Arkanoid__TargetObject__
#define __Arkanoid__TargetObject__

#include "SpriteObject.h"

class TargetObject : public SpriteObject {
public:
    TargetObject(struct Rectangle &rect, int targetPrice, char *filename);
    virtual ~TargetObject();
    virtual void Update(float delta, unsigned char keyStates, std::vector<GameObject *> &objects);
    virtual void Render(sf::RenderWindow *targetWindow);
    virtual void SetState(struct OBJECT_MESSAGE &msg);
    virtual void QueryState(struct OBJECT_MESSAGE &msg);
    
    int price;
private:
    
};

#endif /* defined(__Arkanoid__TargetObject__) */
