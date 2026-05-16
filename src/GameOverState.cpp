#include "GameOverState.h"
#include "GameEngine.h"
#include <iostream>
#include <stdio.h>

void GameOverState::handleInput(GameEngine& game) {
    char input;
    std::cin >> input;
    
   
    if (input == 'R' || input == 'r') {
        command = std::make_unique<RestartCommand>();
    } else if (input == 'Q' || input == 'q') {
        command = std::make_unique<QuitCommand>();
    } else {
        command = nullptr;
    }
}

void GameOverState::update(GameEngine& game) {
    if (command != nullptr) {
        command->execute(game);
    }
}

void GameOverState::draw(GameEngine& game) {
    printf("=========================\n");
    printf("       GAME OVER         \n");
    printf(" Press R to Restart      \n");
    printf(" Press Q to Quit         \n");
    printf("=========================\n\n");
}
