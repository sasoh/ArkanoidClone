//
//  SpriteObject.cpp
//  Arkanoid
//
//  Created by Alexander Popov on 12/5/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#include "SpriteObject.h"

SpriteObject::SpriteObject(struct Rectangle &rect, char *filename) {
    
    tag = ObjectTagSprite;
    frame = rect;
    
    texture = new sf::Texture();
    if (texture->loadFromFile(filename) == true) {
        sprite = new sf::Sprite();
        sprite->setTexture(*texture);
        sprite->setTextureRect(sf::IntRect(0, 0, rect.width, rect.height));
        sprite->setPosition(rect.x, rect.y);
        sprite->setColor(sf::Color(255, 255, 255, 255));
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

void SpriteObject::Update(float delta, unsigned char keyStates, std::vector<GameObject *> &objects) {

    // nothing
    
}

void SpriteObject::Render(sf::RenderWindow *targetWindow) {
    
    if (sprite != NULL) {
        targetWindow->draw(*sprite);
    }

}

void SpriteObject::SetState(struct OBJECT_MESSAGE &msg) {
    
    // nothing
    
}

void SpriteObject::QueryState(struct OBJECT_MESSAGE &msg) {
    
    // nothing
    
}