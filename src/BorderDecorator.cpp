#include "BorderDecorator.h"
#include <stdio.h>

BorderDecorator::BorderDecorator(std::unique_ptr<GameComponent> component)
    : wrappedComponent(std::move(component)) {}

void BorderDecorator::drawFrame(char matrix[20][10]) {
    
    printf("=========================\n");
    
   
    for(int i = 0; i < 20; i++) {
        printf("|| ");
        for(int j = 0; j < 10; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("||\n");
    }
    
    printf("=========================\n");
}
