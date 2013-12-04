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
    InitializeGameObjects();
    GameLoop();
    
}

void Game::InitializeGameObjects() {
    
    std::cout << __func__ << std::endl;
    InitializeBoard();
    InitializeTargets();
    InitializePaddle();
    InitializeBall();
    
}

void Game::InitializeBoard() {
    
}

void Game::InitializeTargets() {
    
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
        
        TargetObject *target = new TargetObject(frame, 5);
        objects.push_back(target);
    }
    
}

void Game::InitializePaddle() {
    
    
    
}

void Game::InitializeBall() {
    
    struct Rectangle frame;
    // random value?
    frame.top = 100.0f;
    frame.left = 100.0f;
    frame.bottom = 10.0f;
    frame.right = 10.0f;
    
    // direction? towards center of paddle?
    
    BallObject *ball = new BallObject(frame);
    objects.push_back(ball);
    
}

void Game::GameLoop() {
    
    isRunning = true;
    
    clock_t lastTime = clock();
    while (isRunning == true) {
        clock_t currentTime = clock();
        double delta = difftime(currentTime, lastTime) / CLOCKS_PER_SEC;
        lastTime = currentTime;
    
        // systems update
        HandleInput();
        Update(delta);
        Render();
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
    
}

void Game::HandleInput() {
    
    // stop loop
    isRunning = false;

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
        (*iterator)->Render();
    }

}