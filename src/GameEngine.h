#pragma once
#include "Shape.h"
#include "GameComponent.h"
#include <memory>

#include "GameState.h"

class GameEngine : public GameComponent {
private:
    char matrix[20][10];
    bool isItI;
    std::unique_ptr<Shape> currentShape;
    std::unique_ptr<GameComponent> visualDecorator;
    std::unique_ptr<GameState> currentState;

public:
    GameEngine();
    void startGame();
    void drawFrame(char matrix[20][10]) override;

    void changeState(std::unique_ptr<GameState> newState);
    
    void resetMat();
    void cleanPrevFrame();
    void cleanPrevFrameIShape();
    void cleanLine();
    void randomShapes();
    
    char (&getMatrix())[20][10] { return matrix; }
    bool getIsItI() { return isItI; }
    std::unique_ptr<Shape>& getCurrentShape() { return currentShape; }
    std::unique_ptr<GameComponent>& getVisualDecorator() { return visualDecorator; }
};
