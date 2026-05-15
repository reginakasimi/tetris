#include "Shape.h"

class Sshape:public Shape{
    block shapeMatrix[3][3];
    
    
    
public:
    Sshape();
    void initializeShapeMatrix();
    void resetMat(char matrix[20][10]);
    void printMat(char matrix[20][10]);
    void resetSwitches();
    void drawShapeInBigMatrix(char matrix[20][10]) override;
    void shapeS();
    bool checkHashInTheRight(char matrix[20][10]);
    bool checkHashOnTheLeft(char matrix[20][10]);
    bool checkHashInTheBottom(char matrix[20][10]) override;
    bool checkBoundDown() override;
    bool checkBoundLeft();
    bool checkBoundRight();
    void iAmOutOfBoundInTheBottom();
    void iAmOutOfBoundInTheLeft();
    void iAmOutOfBoundInTheRight();
    void dirrectionOfS1();
    void dirrectionOfS2();
    void dirrectionOfS3();
    void input(char matrix[20][10]) override;
    void iAmInsideHashOnTheRight(char matrix[20][10]);
    void iAmInsideHashOnTheLeft(char matrix[20][10]);
    void iAmInsideHashInTheBottom(char matrix[20][10]);
    prevMatrix getShapeMatrix() override
    {
        prevMatrix prevMat;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                prevMat.shapeMatrix[i][j] = shapeMatrix[i][j];
            }
        }
        
        return prevMat;

    }
    
    block (*getRawMatrix())[4] override {
        
        return (block (*)[4])shapeMatrix;
    }
    
};




