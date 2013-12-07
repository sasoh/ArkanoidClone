//
//  Game.h
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#ifndef __Arkanoid__Game__
#define __Arkanoid__Game__

#include <vector>
#include <time.h>
#include <math.h>
#include "GameObject.h"
#include "SpriteObject.h"
#include "BallObject.h"
#include "TargetObject.h"
#include "PaddleObject.h"
#include <SFML/Graphics.hpp>

class Game {
public:
    void Start();
    
private:
    bool InitializeGameObjects();
    bool InitializeSFML();
    bool InitializeBoard();
    bool InitializeTargets();
    bool InitializeBall();
    bool InitializePaddle();
    void GameLoop();
    void Shutdown();
    void HandleInput();
    void HandleWindowInput();
    void HandleKeyboardInput();
    void HandleJoystickInput();
    void Update(float delta);
    void Render();
    bool isRunning;
    unsigned char keyStates;
    std::vector<GameObject *> objects;
    std::vector<GameObject *> targets;
    sf::RenderWindow *window;
};

#endif /* defined(__Arkanoid__Game__) */
