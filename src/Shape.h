#pragma once
#include <stdio.h>

struct block {
    int x;
    int y;
    bool switches = false;
};

struct prevMatrix {
    block shapeMatrix[3][3];
    block shapeMatrixI[4][4];
};

class Shape {
protected:
    int next = 1;

public:
    virtual ~Shape() {}

    void moveDown();
    void moveLeft();
    void moveRight();
    void moveUp();

    
    virtual void drawShapeInBigMatrix(char matrix[20][10]) = 0;
    virtual void input(char matrix[20][10]) = 0;
    virtual prevMatrix getShapeMatrix() = 0;
    virtual bool checkBoundDown() = 0;
    virtual bool checkHashInTheBottom(char matrix[20][10]) = 0;
    
    virtual block (*getRawMatrix())[4] = 0;
};
