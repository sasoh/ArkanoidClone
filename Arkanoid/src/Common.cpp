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
    
    struct Vector topLeftPoint;
    topLeftPoint.x = rect2.x;
    topLeftPoint.y = rect2.y;
    
    struct Vector topRightPoint;
    topRightPoint.x = rect2.x + rect2.width;
    topRightPoint.y = rect2.y;
    
    struct Vector bottomLeftPoint;
    bottomLeftPoint.x = rect2.x;
    bottomLeftPoint.y = rect2.y + rect2.height;
    
    struct Vector bottomRightPoint;
    bottomRightPoint.x = rect2.x + rect2.width;
    bottomRightPoint.y = rect2.y + rect2.height;
    
    if (IsPointInsideRectangle(rect1, topLeftPoint) == true || IsPointInsideRectangle(rect1, topRightPoint) == true ||
        IsPointInsideRectangle(rect1, bottomLeftPoint) == true || IsPointInsideRectangle(rect1, bottomRightPoint) == true) {
        result = true;
    }
    
    return result;
    
}

#endif /* defined(__Arkanoid__Common__) */
