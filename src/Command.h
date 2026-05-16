#pragma once
#include "GameEngine.h"
#include "GameplayState.h"
#include <stdio.h>
#include <stdlib.h>

class Command {
public:
    virtual void execute(GameEngine& game) = 0;
    virtual ~Command() = default;
};

class RestartCommand : public Command {
public:
    void execute(GameEngine& game) override {
        game.resetMat();
        game.randomShapes();
        game.changeState(std::make_unique<GameplayState>());
    }
};

class QuitCommand : public Command {
public:
    void execute(GameEngine& game) override {
        game.changeState(nullptr); 
        printf("Goodbye!\n");
        exit(0);
    }
};
