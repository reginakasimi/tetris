#include "Oshape.h"
#include <stdio.h>

Oshape::Oshape(){
    initializeShapeMatrix();
    shapeO();
}


void Oshape::initializeShapeMatrix()
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            shapeMatrix[i][j].y = i;
            shapeMatrix[i][j].x = j + 4;
         }
    }
}


void Oshape::input(char matrix[20][10])
{
    
    char input;
    scanf(" %c", &input);
    
    if(input == 'A' || input == 'a')
    {
        if(!checkBoundLeft() && !checkHashOnTheLeft(matrix)){
            moveLeft();
        }
        
        
    }
    
    else if(input == 'D' || input == 'd'){
        if(!checkBoundRight() && !checkHashInTheRight(matrix)){
            moveRight();
        }
       
    }
    

}




void Oshape::resetSwitches(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            shapeMatrix[i][j].switches = false;
        }

    }

}

void Oshape::drawShapeInBigMatrix(char matrix[20][10]){
    for(int i = 0; i<3; i++){
        for(int j = 0; j <3; j++){
            if(shapeMatrix[i][j].switches == true){
                matrix[shapeMatrix[i][j].y][shapeMatrix[i][j].x] = '#';
            }

        }
    }
}
void Oshape::shapeO(){

    resetSwitches();
     
        shapeMatrix[0][1].switches = true;

       
        shapeMatrix[0][2].switches = true;

       
        shapeMatrix[1][1].switches = true;

      
        shapeMatrix[1][2].switches = true;


   
}



bool Oshape::checkBoundDown(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(shapeMatrix[i][j].y + 1 > 19 && shapeMatrix[i][j].switches == true){

                return true;
            }
            
        }
    }

    return false;
}

bool Oshape::checkHashInTheRight(char matrix[20][10]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(matrix[shapeMatrix[i][j].y][shapeMatrix[i][j].x + 1] == '#' && shapeMatrix[i][j].switches == true){
                
                return true;
            }
            
        }
    }
    return false;
}


void Oshape::iAmInsideHashOnTheRight(char matrix[20][10]){
    for(int i = 0; i < 3; i++){
        if(matrix[shapeMatrix[i][2].y][shapeMatrix[i][2].x] == '#' && shapeMatrix[i][2].switches == true){
            
            moveLeft();
            
            break;
        }
    }
}


bool Oshape::checkHashOnTheLeft(char matrix[20][10]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(matrix[shapeMatrix[i][j].y][shapeMatrix[i][j].x - 1] == '#' && shapeMatrix[i][j].switches == true){
                
                return true;
            }
            
        }
    }
    return false;
}


void Oshape::iAmInsideHashOnTheLeft(char matrix[20][10]){
    for(int i = 0; i < 3; i++){
        if(matrix[shapeMatrix[i][0].y][shapeMatrix[i][0].x] == '#' && shapeMatrix[i][0].switches == true){
            
            moveRight();
            
            break;
        }
    }
}


bool Oshape::checkHashInTheBottom(char matrix[20][10]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(matrix[shapeMatrix[i][j].y + 1][shapeMatrix[i][j].x] == '#' && shapeMatrix[i][j].switches == true){

                return true;
            }
            
        }
    }
    return false;
}


void Oshape::iAmInsideHashInTheBottom(char matrix[20][10]){
    for(int j = 0; j < 3; j++){
        if(matrix[shapeMatrix[2][j].y][shapeMatrix[2][j].x] == '#' && shapeMatrix[2][j].switches == true){
            
            moveUp();
            
            break;
        }
    }
}


bool Oshape::checkBoundLeft(){
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(shapeMatrix[i][j].x - 1 < 0 && shapeMatrix[i][j].switches == true){
                
                return true;
            }
            
        }
    }
    return false;
}

bool Oshape::checkBoundRight()
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(shapeMatrix[i][j].x + 1 > 9 && shapeMatrix[i][j].switches == true){
                
                return true;
            }
            
        }
    }
    return false;
}

void Oshape::iAmOutOfBoundInTheBottom(){
    
    for(int j =0; j<3; j++){
        if(shapeMatrix[2][j].y > 19 && shapeMatrix[2][j].switches == true){
            moveUp();
            break;
        }
    }
    
}
void Oshape::iAmOutOfBoundInTheLeft()
{
    for(int i =0; i<3; i++){
        if(shapeMatrix[i][0].x < 0 && shapeMatrix[i][0].switches == true){
            moveRight();
            break;
        }
    }
    
}



void Oshape::iAmOutOfBoundInTheRight()
{
    for(int i =0; i < 3; i++){
        if(shapeMatrix[i][2].x > 9 && shapeMatrix[i][2].switches == true){
            moveLeft();
            break;
        }
    }
    
}


void Oshape::dirrectionOfO1(){
    
    resetSwitches();
       
        shapeMatrix[0][1].switches = true;

     
        shapeMatrix[0][2].switches = true;

       
        shapeMatrix[1][1].switches = true;

    
        shapeMatrix[2][1].switches = true;
}



void Oshape::dirrectionOfO2(){
    resetSwitches();
        
        shapeMatrix[1][0].switches = true;

  
        shapeMatrix[1][2].switches = true;

    
        shapeMatrix[1][1].switches = true;

      
        shapeMatrix[2][2].switches = true;
}



void Oshape::dirrectionOfO3(){
    
    resetSwitches();
   
    shapeMatrix[0][1].switches = true;

    
    shapeMatrix[2][1].switches = true;

   
    shapeMatrix[1][1].switches = true;

  
    shapeMatrix[2][0].switches = true;

}


