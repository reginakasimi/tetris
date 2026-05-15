#include "Shape.h"

class Oshape:public Shape{
    block shapeMatrix[3][3];
    int next;
    
    
public:
    Oshape();
    void initializeShapeMatrix();
    void resetMat(char matrix[20][10]);
    void printMat(char matrix[20][10]);
    void resetSwitches();
    void drawShapeInBigMatrix(char matrix[20][10]);
    void shapeO();
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    bool checkHashInTheRight(char matrix[20][10]);
    bool checkHashOnTheLeft(char matrix[20][10]);
    bool checkHashInTheBottom(char matrix[20][10]);
    bool checkBoundDown()override;
    bool checkBoundLeft();
    bool checkBoundRight();
    void iAmOutOfBoundInTheBottom();
    void iAmOutOfBoundInTheLeft();
    void iAmOutOfBoundInTheRight();
    void dirrectionOfO1();
    void dirrectionOfO2();
    void dirrectionOfO3();
    void input(char matrix[20][10]);
    void iAmInsideHashOnTheRight(char matrix[20][10]);
    void iAmInsideHashOnTheLeft(char matrix[20][10]);
    void iAmInsideHashInTheBottom(char matrix[20][10]);
    prevMatrix getShapeMatrix()
    {
        prevMatrix prevMat;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                prevMat.shapeMatrix[i][j] = shapeMatrix[i][j];
            }
        }
        
        return prevMat;

    }
    
    
};



