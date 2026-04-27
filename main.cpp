#include <iostream>
#include <stdio.h>
#include <time.h>
#include <vector>

#include <stdlib.h>
#include "Lshape.h"
#include "Shape.h"
#include "Jshape.h"
#include "Tshape.h"
#include "Sshape.h"
#include "Zshape.h"
#include "Oshape.h"
#include "Ishape.h"
#include <memory>

char matrix[20][10];


bool isItI = false;

block shapeMatrix[3][3];

void resetMat(){
    for(int i = 0; i<20; i++){
        for(int j = 0; j<10; j++){
            matrix[i][j] = '*';
            
        }
    }
}


void printMat(){
    for(int i = 0; i<20; i++){
        for(int j = 0; j<10; j++){
            printf("%c ", matrix[i][j]);
            
        }
        printf("\n");
    }
}

    
void cleanPrevFrame(Shape& shape){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(shape.getShapeMatrix().shapeMatrix[i][j].switches == true){
                matrix[shape.getShapeMatrix().shapeMatrix[i][j].y][shape.getShapeMatrix().shapeMatrix[i][j].x] = '*';
            }
            
        }
    }
    
}

void cleanPrevFrameIShape(Shape& shape){
    printf("HIIII\n");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(shape.getShapeMatrix().shapeMatrixI[i][j].switches == true){
                matrix[shape.getShapeMatrix().shapeMatrixI[i][j].y][shape.getShapeMatrix().shapeMatrixI[i][j].x] = '*';
            }
            
        }
    }
}
void cleanLine(){
    
    
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
std::unique_ptr<Shape> randomShapes()
{
    int shape = rand()% 7;
    
    switch (shape){
        case 0:
            isItI = false;
            return std::make_unique<Lshape>();
            
            break;
            
        case 1:
            isItI = false;
            return std::make_unique<Tshape>();
            
            break;
        case 2:
            isItI = false;
            return std::make_unique<Jshape>();
            
            break;
        case 3:
            isItI = false;
            return std::make_unique<Sshape>();
            
            break;
        case 4:
            isItI = false;
            return std::make_unique<Zshape>();
            
            break;
        case 5:
            isItI = false;
            return std::make_unique<Oshape>();
            break;
        case 6:
            isItI = true;
            return std::make_unique<Ishape>();
            
            break;
        default:
            return nullptr;
    }
}

int main(){

    srand(time(NULL));
  
    
    
   
    Lshape lshape;
    
    std::unique_ptr<Shape> shape = randomShapes();
    
    resetMat();
    
    
    printMat();

    
    
    while(true){

        
        
        
        if(isItI == false){
            cleanPrevFrame(*shape);
        }
        else{
            cleanPrevFrameIShape(*shape);
        }
        
        
        
        
        shape->input(matrix);
        if(!shape->checkHashInTheBottom(matrix) && !shape->checkBoundDown()){
            shape->moveDown();
            
        }
        else{
            
            shape->drawShapeInBigMatrix(matrix);
           
            shape = randomShapes();
            
            cleanLine();
            
            continue;
          
        }
        
        
        shape->drawShapeInBigMatrix(matrix);
        printMat();
        printf("\n\n");
     





    }
    
   
    
    


    return 0;
}


