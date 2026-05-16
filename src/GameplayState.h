#pragma once
#include "GameState.h"

class GameplayState : public GameState {
public:
    void handleInput(GameEngine& game) override;
    void update(GameEngine& game) override;
    void draw(GameEngine& game) override;
};
