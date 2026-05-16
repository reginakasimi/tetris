#pragma once
class GameEngine;

class GameState {
public:
    virtual ~GameState() = default;
    virtual void handleInput(GameEngine& game) = 0;
    virtual void update(GameEngine& game) = 0;
    virtual void draw(GameEngine& game) = 0;
};
