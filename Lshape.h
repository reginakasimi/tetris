#include "Shape.h"

class Lshape:public Shape{
    block shapeMatrix[3][3];
    int next;
    
    
public:
    Lshape();
    void initializeShapeMatrix();
    void resetMat(char matrix[20][10]);
    void printMat(char matrix[20][10]);
    void resetSwitches();
    void drawShapeInBigMatrix(char matrix[20][10]);
    void shapeL();
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
    void dirrectionOfL1();
    void dirrectionOfL2();
    void dirrectionOfL3();
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



