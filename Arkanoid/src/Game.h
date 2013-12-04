//
//  Game.h
//  Arkanoid
//
//  Created by Alexander Popov on 12/4/13.
//  Copyright (c) 2013 -. All rights reserved.
//

#ifndef __Arkanoid__Game__
#define __Arkanoid__Game__

#include <iostream>
#include <vector>
#include <time.h>
#include "GameObject.h"
#include "BallObject.h"
#include "TargetObject.h"
#include "PaddleObject.h"

class Game {
public:
    void Start();
    
private:
    void InitializeGameObjects();
    void InitializeBoard();
    void InitializeTargets();
    void InitializeBall();
    void InitializePaddle();
    void GameLoop();
    void Shutdown();
    void HandleInput();
    void Update(float delta);
    void Render();
    bool isRunning;
    std::vector<GameObject *> objects;
    std::vector<GameObject *> targets;
};

#endif /* defined(__Arkanoid__Game__) */
