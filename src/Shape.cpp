#include "Shape.h"

void Shape::moveRight() {
    block (*matrix)[4] = getRawMatrix();
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            matrix[i][j].x++;
        }
    }
}

void Shape::moveLeft() {
    block (*matrix)[4] = getRawMatrix();
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            matrix[i][j].x--;
        }
    }
}

void Shape::moveDown() {
    block (*matrix)[4] = getRawMatrix();
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            matrix[i][j].y++;
        }
    }
}

void Shape::moveUp() {
    block (*matrix)[4] = getRawMatrix();
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            matrix[i][j].y--;
        }
    }
}
