//
//  Common.cpp
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#ifndef __Arkanoid__Common__
#define __Arkanoid__Common__

struct Vector {
    float x;
    float y;
};

struct Rectangle {
    float x;
    float y;
    float width;
    float height;
};

const int WINDOW_WIDTH  = 800;
const int WINDOW_HEIGHT = 600;

const float BACKGROUND_BORDER_OFFSET = 10.0f;

const unsigned char KEYSTATE_LEFT   = 1 << 0;
const unsigned char KEYSTATE_RIGHT  = 1 << 1;
const unsigned char KEYSTATE_LAUNCH = 1 << 2;

inline bool IsPointInsideRectangle(struct Rectangle &rect, Vector &point) {

    bool result = true;
    
    if (point.x > rect.x + rect.width || point.x < rect.x || point.y > rect.y + rect.height || point.y < rect.y) {
        result = false;
    }
    
    return result;
    
}

inline bool IsRectangleIntersectingRectangle(struct Rectangle &rect1, struct Rectangle &rect2) {

    bool result = false;
    
    if ((rect1.x < rect2.x + rect2.width) && (rect1.x + rect1.width > rect2.x) &&
        (rect1.y < rect2.y + rect2.height) && (rect1.y + rect1.height > rect2.y)) {
        result = true;
    }
    
    return result;
    
}

#endif /* defined(__Arkanoid__Common__) */
