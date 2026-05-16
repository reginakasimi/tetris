#pragma once
#include "GameState.h"
#include "Command.h"
#include <memory>

class GameOverState : public GameState {
private:
    std::unique_ptr<Command> command;
public:
    void handleInput(GameEngine& game) override;
    void update(GameEngine& game) override;
    void draw(GameEngine& game) override;
};
