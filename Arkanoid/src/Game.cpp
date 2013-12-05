//
//  Game.cpp
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#include "Game.h"

void Game::Start() {
    
    std::cout << __func__ << std::endl;
    if (InitializeGameObjects() == true) {
        GameLoop();
    }
    
}

bool Game::InitializeGameObjects() {
    
    if (InitializeSFML() == false) {
        return false;
    }
    if (InitializeBoard() == false) {
        return false;
    }
    if (InitializeTargets() == false) {
        return false;
    }
    if (InitializePaddle() == false) {
        return false;
    }
    if (InitializeBall() == false) {
        return false;
    }
    
    return true;
    
}

bool Game::InitializeSFML() {
   
    bool result = true;
    
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Arkanoid clone");
    result = window->isOpen();
    
    return result;
    
}

bool Game::InitializeBoard() {
    
    bool result = true;
    
    struct Rectangle frame;
    frame.top = 0.0f;
    frame.left = 0.0f;
    frame.bottom = 600.0;
    frame.right = 800.0;
    
    char filename[] = "background.png";
    SpriteObject *boardObject = new SpriteObject(frame, filename);
    objects.push_back(boardObject);
    
    return result;
    
}

bool Game::InitializeTargets() {
    
    bool result = true;
    struct Vector offset;
    offset.x = 10;
    offset.y = 10;
    
    float targetHeight = 10.0f;
    float targetWidth = 50.0f;
    
    for (int i = 0; i < 5; ++i) {
        // prepare frame for object
        struct Rectangle frame;
        frame.top = 50 + offset.y;
        frame.left = i * (targetWidth + offset.x) + targetWidth;
        frame.bottom = targetHeight;
        frame.right = targetWidth;
        
        char filename[] = "../images/target_80x15.png";
        TargetObject *target = new TargetObject(frame, 5, filename);
        objects.push_back(target);
    }
    return result;
    
}

bool Game::InitializePaddle() {
    
    bool result = true;
    
    return result;
    
}

bool Game::InitializeBall() {
    
    bool result = true;
    
    struct Rectangle frame;
    // random value?
    frame.top = 100.0f;
    frame.left = 100.0f;
    frame.bottom = 10.0f;
    frame.right = 10.0f;
    
    // direction? towards center of paddle?
    
    char filename[] = "../images/ball_30X30.png";
    BallObject *ball = new BallObject(frame, filename);
    objects.push_back(ball);
    
    return result;
    
}

void Game::GameLoop() {
    
    isRunning = true;
    
    clock_t lastTime = clock();
    while (isRunning == true) {
        clock_t currentTime = clock();
        double delta = difftime(currentTime, lastTime) / CLOCKS_PER_SEC;
        lastTime = currentTime;
        
        // capture window events
        sf::Event event;
        while (window->pollEvent(event)) {
            // Close window : exit
            if (event.type == sf::Event::Closed) {
                window->close();
                isRunning = false;
            }
        }
        
        
        window->clear();
        
        // systems update
        HandleInput();
        Update(delta);
        Render();
 
        window->display();
    }
    
    Shutdown();
    
}

void Game::Shutdown() {
    
    // clear up
    std::cout << __func__ << std::endl;
    
    // clear all objects from memory
    std::vector<GameObject *>::iterator iterator;
    for (iterator = objects.begin(); iterator != objects.end(); ++iterator) {
        delete *iterator;
    }
    
    // targets is a convenience vector, nothing to release from there
    targets.clear();
    
    // destroy SFML window
    delete window;
    
}

void Game::HandleInput() {
    
    // stop loop
//    isRunning = false;

}

void Game::Update(float delta) {
    
    std::vector<GameObject *>::iterator iterator;
    for (iterator = objects.begin(); iterator != objects.end(); ++iterator) {
        (*iterator)->Update(delta);
    }
    
}

void Game::Render() {
    
    std::vector<GameObject *>::iterator iterator;
    for (iterator = objects.begin(); iterator != objects.end(); ++iterator) {
        (*iterator)->Render(window);
    }

}