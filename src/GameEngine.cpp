#include "GameEngine.h"
#include "Lshape.h"
#include "Jshape.h"
#include "Tshape.h"
#include "Sshape.h"
#include "Zshape.h"
#include "Oshape.h"
#include "Ishape.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BorderDecorator.h"
#include "GameplayState.h"

GameEngine::GameEngine() {
    srand(static_cast<unsigned>(time(NULL)));
    isItI = false;
}

void GameEngine::resetMat() {
    for(int i = 0; i<20; i++){
        for(int j = 0; j<10; j++){
            matrix[i][j] = '*';
        }
    }
}

void GameEngine::cleanPrevFrame() {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(currentShape->getShapeMatrix().shapeMatrix[i][j].switches == true){
                matrix[currentShape->getShapeMatrix().shapeMatrix[i][j].y][currentShape->getShapeMatrix().shapeMatrix[i][j].x] = '*';
            }
        }
    }
}

void GameEngine::cleanPrevFrameIShape() {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(currentShape->getShapeMatrix().shapeMatrixI[i][j].switches == true){
                matrix[currentShape->getShapeMatrix().shapeMatrixI[i][j].y][currentShape->getShapeMatrix().shapeMatrixI[i][j].x] = '*';
            }
        }
    }
}

void GameEngine::cleanLine() {
    int i;
    int count = 0;
    for(i = 0; i < 20; i++){
        count = 0;
        for(int j = 0; j < 10; j++){
            if(matrix[i][j] == '#'){
                count++;
            }
        }
        if(count == 10){
            break;
        }
    }
    if(count != 10){
        return;
    }
    for(; i > 0; i--){
        for(int j = 0; j < 10; j++){
            matrix[i][j] = matrix[i-1][j];
        }
    }
}

void GameEngine::randomShapes() {
    int shape = rand() % 7;
    switch (shape){
        case 0: isItI = false; currentShape = std::make_unique<Lshape>(); break;
        case 1: isItI = false; currentShape = std::make_unique<Tshape>(); break;
        case 2: isItI = false; currentShape = std::make_unique<Jshape>(); break;
        case 3: isItI = false; currentShape = std::make_unique<Sshape>(); break;
        case 4: isItI = false; currentShape = std::make_unique<Zshape>(); break;
        case 5: isItI = false; currentShape = std::make_unique<Oshape>(); break;
        case 6: isItI = true;  currentShape = std::make_unique<Ishape>(); break;
    }
}
void GameEngine::changeState(std::unique_ptr<GameState> newState) {
    currentState = std::move(newState);
}
void GameEngine::startGame() {
    resetMat();
    randomShapes();
    
    visualDecorator = std::make_unique<BorderDecorator>(nullptr);
    visualDecorator->drawFrame(matrix);

    printf("W - change direction\n");
    printf("D - go right\n");
    printf("A - go left\n");
    printf("S - go down\n");
    
    
    changeState(std::make_unique<GameplayState>());

    
    while(currentState != nullptr){
        currentState->handleInput(*this);
        if (currentState == nullptr) break;
        currentState->update(*this);
        if (currentState == nullptr) break;
        currentState->draw(*this);
    }
}

void GameEngine::drawFrame(char matrix[20][10]) {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 10; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}
