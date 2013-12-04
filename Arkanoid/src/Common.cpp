//
//  Common.cpp
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#ifndef __Arkanoid__Common__
#define __Arkanoid__Common__

#include <iostream>

struct Vector {
    float x;
    float y;
};

struct Rectangle {
    float top;
    float left;
    float bottom;
    float right;
};

inline bool IsPointInsideRectangle(struct Rectangle &rect, Vector &point) {

    bool result = true;
    
    if (point.x > rect.right || point.x < rect.left || point.y > rect.top || point.y < rect.bottom ) {
        result = false;
    }
    
    return result;
    
}

inline bool IsRectangleIntersectingRectangle(struct Rectangle &rect1, struct Rectangle &rect2) {

    bool result = false;
    
    struct Vector topLeftPoint;
    topLeftPoint.x = rect2.left;
    topLeftPoint.y = rect2.top;
    
    struct Vector topRightPoint;
    topRightPoint.x = rect2.right;
    topRightPoint.y = rect2.top;
    
    struct Vector bottomLeftPoint;
    bottomLeftPoint.x = rect2.left;
    bottomLeftPoint.y = rect2.bottom;
    
    struct Vector bottomRightPoint;
    bottomRightPoint.x = rect2.right;
    bottomRightPoint.y = rect2.bottom;
    
    if (IsPointInsideRectangle(rect1, topLeftPoint) == true || IsPointInsideRectangle(rect1, topRightPoint) == true ||
        IsPointInsideRectangle(rect1, bottomLeftPoint) == true || IsPointInsideRectangle(rect1, bottomRightPoint) == true) {
        result = true;
    }
    
    return result;
    
}

#endif /* defined(__Arkanoid__Common__) */
