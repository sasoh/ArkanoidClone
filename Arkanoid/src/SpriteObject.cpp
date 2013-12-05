//
//  SpriteObject.cpp
//  Arkanoid
//
//  Created by Alexander Popov on 12/5/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#include "SpriteObject.h"

SpriteObject::SpriteObject(struct Rectangle &rect, char *filename) {
    
    frame = rect;
    
    texture = new sf::Texture();
    if (texture->loadFromFile(filename) == true) {
        sprite = new sf::Sprite();
        sprite->setTexture(*texture);
        sprite->setTextureRect(sf::IntRect(rect.left, rect.top, rect.right, rect.bottom));
        sprite->setPosition(rect.left, rect.top);
        sprite->setColor(sf::Color(255, 255, 255, 200));
    } else {
        sprite = NULL;
    }
    
}

SpriteObject::~SpriteObject() {
    
    if (sprite != NULL) {
        delete sprite;
    }
    
    if (texture != NULL) {
        delete texture;
    }
    
}

void SpriteObject::Update(float delta) {

    // nothing
    
}

void SpriteObject::Render(sf::RenderWindow *targetWindow) {
    
    if (sprite != NULL) {
        targetWindow->draw(*sprite);
    }

}