#pragma once
#include <stdio.h>
struct block
{
    int x;
    int y;
    bool switches = false;
};
struct prevMatrix{
    
    block shapeMatrix[3][3];
    block shapeMatrixI[4][4];
};
class Shape{
    
public:
    virtual void input(char matrix[20][10]) {};
    virtual bool checkHashInTheBottom(char matrix[20][10]){return true;};
    virtual bool checkBoundDown(){return true;};
    virtual void moveDown(){};
    virtual void drawShapeInBigMatrix(char matrix[20][10]){};
    virtual prevMatrix getShapeMatrix()
    {
         return prevMatrix();
       
    }
    virtual ~Shape() {}
};
