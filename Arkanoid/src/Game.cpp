//
//  Game.cpp
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#include "Game.h"

void Game::Start() {
    
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
    
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Arkanoid clone", sf::Style::Close);
    result = window->isOpen();
    
    return result;
    
}

bool Game::InitializeBoard() {
    
    bool result = true;
    
    struct Rectangle frame;
    frame.x = 0.0f;
    frame.y = 0.0f;
    frame.width = WINDOW_WIDTH;
    frame.height = WINDOW_HEIGHT;
    
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
    
    float targetHeight = 15.0f;
    float targetWidth = 80.0f;
    
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 7; ++j) {
            // prepare frame for object
            struct Rectangle frame;
            frame.x = j * (targetWidth + offset.x) + targetWidth;
            frame.y = 50 + offset.y + (i * targetHeight * 2);
            frame.height = targetHeight;
            frame.width = targetWidth;
            
            char filename[] = "target_80x15.png";
            TargetObject *target = new TargetObject(frame, 5, filename);
            objects.push_back(target);
        }
    }
    return result;
    
}

bool Game::InitializePaddle() {
    
    bool result = true;
    
    struct Rectangle frame;
    frame.width = 100.0f;
    frame.height = 15.0f;
    frame.x = (WINDOW_WIDTH - frame.width) / 2;
    frame.y = 550.0f;
    
    char filename[] = "paddle_100x15.png";
    PaddleObject *paddleObject = new PaddleObject(frame, filename);
    objects.push_back(paddleObject);
    
    return result;
    
}

bool Game::InitializeBall() {
    
    bool result = true;
    
    struct Rectangle frame;
    // random value?
    frame.x = 300.0f;
    frame.y = 250.0f;
    frame.width = 30.0f;
    frame.height = 30.0f;
    
    // direction? towards center of paddle?
    
    char filename[] = "ball_30x30.png";
    BallObject *ball = new BallObject(frame, filename);
    objects.push_back(ball);
    
    return result;
    
}

void Game::GameLoop() {
    
    isRunning = true;
    hasStarted = false;
    
    float desiredFrameFreq = 1.0 / 120.0;
    
    clock_t lastTime = clock();
    while (isRunning == true) {
        clock_t currentTime = clock();
        double delta = difftime(currentTime, lastTime) / CLOCKS_PER_SEC;
        lastTime = currentTime;
        
        while (delta < desiredFrameFreq) {
            delta += desiredFrameFreq;
            
            HandleInput();
            Update(desiredFrameFreq);
        }
        
        Render();
    }
    
    Shutdown();
    
}

void Game::Shutdown() {
    
    // clear all objects from memory
    std::vector<GameObject *>::iterator iterator;
    for (iterator = objects.begin(); iterator != objects.end(); ++iterator) {
        delete *iterator;
    }
    
    // destroy SFML window
    delete window;
    
}

void Game::HandleInput() {
    
    keyStates = 0; // reset states for current frame
    HandleWindowInput();
    HandleKeyboardInput();
    HandleJoystickInput();
    
    if (keyStates != 0) {
        hasStarted = true;
    }
    
}

void Game::HandleWindowInput() {

    // SFML window message handling
    sf::Event event;
    while (window->pollEvent(event)) {
        // Close window : exit
        if (event.type == sf::Event::Closed) {
            window->close();
            isRunning = false;
        }
    }
    
}

void Game::HandleKeyboardInput() {
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == true) {
        keyStates |= KEYSTATE_LEFT;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == true) {
        keyStates |= KEYSTATE_RIGHT;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == true) {
        keyStates |= KEYSTATE_LAUNCH;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) == true) {
        // this kills the app
        isRunning = false;
    }
    
}

void Game::HandleJoystickInput() {
 
    unsigned int joystickId = 0; // default
    if (sf::Joystick::isConnected(joystickId) == true) {
        float x = sf::Joystick::getAxisPosition(joystickId, sf::Joystick::Axis::X);
        // limit value to [-1; 1] range
        x = x / 100;
        
        float deadZone = 0.15; // just fine on my xbox controller
        if (fabsf(x) < deadZone) {
            x = 0.0f;
        }
        
        // analog input for a future release?
        
        if (x > 0.0f) {
            keyStates |= KEYSTATE_RIGHT;
        }
        if (x < 0.0f) {
            keyStates |= KEYSTATE_LEFT;
        }
        
        bool firstButtonPressed = sf::Joystick::isButtonPressed(joystickId, 0);
        if (firstButtonPressed == true) {
            keyStates |= KEYSTATE_LAUNCH;
        }
    }
    
}

void Game::Update(float delta) {
    
    if (hasStarted == true) {
        std::vector<GameObject *>::iterator iterator;
        for (iterator = objects.begin(); iterator != objects.end(); ++iterator) {
            GameObject *obj = *iterator;
            obj->Update(delta, keyStates, objects);
        }
    }
    
}

void Game::Render() {
    
    window->clear();
    
    std::vector<GameObject *>::iterator iterator;
    for (iterator = objects.begin(); iterator != objects.end(); ++iterator) {
        GameObject *obj = *iterator;
        obj->Render(window);
    }
    
    window->display();
    
}