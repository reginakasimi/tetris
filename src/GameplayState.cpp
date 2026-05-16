#include "GameplayState.h"
#include "GameEngine.h"
#include "GameOverState.h"
#include <stdio.h>

void GameplayState::handleInput(GameEngine& game) {
    
    if(game.getIsItI() == false){
        game.cleanPrevFrame();
    } else {
        game.cleanPrevFrameIShape();
    }
    
    
    game.getCurrentShape()->input(game.getMatrix());
}

void GameplayState::update(GameEngine& game) {
    auto& currentShape = game.getCurrentShape();
    char(&matrix)[20][10] = game.getMatrix();

   
    if(!currentShape->checkHashInTheBottom(matrix) && !currentShape->checkBoundDown()){
        currentShape->moveDown();
    } else {
        currentShape->drawShapeInBigMatrix(matrix);
        game.randomShapes();
        game.cleanLine();
        
        
        if (game.getCurrentShape()->checkHashInTheBottom(matrix)) {
            game.changeState(std::make_unique<GameOverState>());
        }
    }
}

void GameplayState::draw(GameEngine& game) {
    char(&matrix)[20][10] = game.getMatrix();
    
   
    game.getCurrentShape()->drawShapeInBigMatrix(matrix);
    game.getVisualDecorator()->drawFrame(matrix);
    printf("\n\n");
}
