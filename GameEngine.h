#pragma once
#include "Shape.h"
#include "GameComponent.h"
#include <memory>


class GameEngine : public GameComponent {
private:
    char matrix[20][10];
    bool isItI;
    std::unique_ptr<Shape> currentShape;
    std::unique_ptr<GameComponent> visualDecorator;

    void resetMat();
    void cleanPrevFrame();
    void cleanPrevFrameIShape();
    void cleanLine();
    void randomShapes();

public:
    GameEngine();
    void startGame();
    void drawFrame(char matrix[20][10]) override; 
};
