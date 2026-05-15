#include "Ishape.h"
#include <stdio.h>

Ishape::Ishape(){
    initializeShapeMatrix();
    shapeI();
}


void Ishape::initializeShapeMatrix()
{
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            shapeMatrix[i][j].y = i;
            shapeMatrix[i][j].x = j + 4;
         }
    }
}


void Ishape::input(char matrix[20][10])
{
    
    char input;
    scanf(" %c", &input);
    if((input == 'W' || input == 'w') && !checkHashOnTheLeft(matrix)){
        next++;


        if(next>2){
            next =1;
        }
        switch (next){

            case 1:
            shapeI();
            break;


            case 2:
            dirrectionOfI1();
            break;

            


        }
        iAmOutOfBoundInTheRight();
        iAmOutOfBoundInTheLeft();
        iAmOutOfBoundInTheBottom();
        iAmInsideHashOnTheRight(matrix);
        iAmInsideHashOnTheLeft(matrix);
        iAmInsideHashInTheBottom(matrix);
    }
    else if(input == 'A' || input == 'a')
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




void Ishape::resetSwitches(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){

            shapeMatrix[i][j].switches = false;
        }

    }

}

void Ishape::drawShapeInBigMatrix(char matrix[20][10]){
    for(int i = 0; i<4; i++){
        for(int j = 0; j <4; j++){
            if(shapeMatrix[i][j].switches == true){
                matrix[shapeMatrix[i][j].y][shapeMatrix[i][j].x] = '#';
            }

        }
    }
}
void Ishape::shapeI(){

    resetSwitches();
     
        shapeMatrix[1][0].switches = true;

       
        shapeMatrix[1][1].switches = true;

       
        shapeMatrix[1][2].switches = true;

      
        shapeMatrix[1][3].switches = true;


   
}


bool Ishape::checkBoundDown(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            
            if(shapeMatrix[i][j].y + 1 > 19 && shapeMatrix[i][j].switches == true){

                return true;
            }
            
        }
    }

    return false;
}

bool Ishape::checkHashInTheRight(char matrix[20][10]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            
            if(matrix[shapeMatrix[i][j].y][shapeMatrix[i][j].x + 1] == '#' && shapeMatrix[i][j].switches == true){
                
                return true;
            }
            
        }
    }
    return false;
}


void Ishape::iAmInsideHashOnTheRight(char matrix[20][10]){
    for(int i = 0; i < 4; i++){
        if(matrix[shapeMatrix[i][2].y][shapeMatrix[i][2].x] == '#' && shapeMatrix[i][2].switches == true){
            
            moveLeft();
            
            break;
        }
    }
}


bool Ishape::checkHashOnTheLeft(char matrix[20][10]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            
            if(matrix[shapeMatrix[i][j].y][shapeMatrix[i][j].x - 1] == '#' && shapeMatrix[i][j].switches == true){
                
                return true;
            }
            
        }
    }
    return false;
}


void Ishape::iAmInsideHashOnTheLeft(char matrix[20][10]){
    for(int i = 0; i < 4; i++){
        if(matrix[shapeMatrix[i][0].y][shapeMatrix[i][0].x] == '#' && shapeMatrix[i][0].switches == true){
            
            moveRight();
            
            break;
        }
    }
}


bool Ishape::checkHashInTheBottom(char matrix[20][10]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            
            if(matrix[shapeMatrix[i][j].y + 1][shapeMatrix[i][j].x] == '#' && shapeMatrix[i][j].switches == true){

                return true;
            }
            
        }
    }
    return false;
}


void Ishape::iAmInsideHashInTheBottom(char matrix[20][10]){
    for(int j = 0; j < 4; j++){
        if(matrix[shapeMatrix[2][j].y][shapeMatrix[2][j].x] == '#' && shapeMatrix[2][j].switches == true){
            
            moveUp();
            
            break;
        }
    }
}


bool Ishape::checkBoundLeft(){
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            
            if(shapeMatrix[i][j].x - 1 < 0 && shapeMatrix[i][j].switches == true){
                
                return true;
            }
            
        }
    }
    return false;
}

bool Ishape::checkBoundRight()
{
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            
            if(shapeMatrix[i][j].x + 1 > 9 && shapeMatrix[i][j].switches == true){
                
                return true;
            }
            
        }
    }
    return false;
}

void Ishape::iAmOutOfBoundInTheBottom(){
    
    for(int j =0; j<4; j++){
        if(shapeMatrix[3][j].y > 19 && shapeMatrix[3][j].switches == true){
            moveUp();
            break;
        }
    }
    
}
void Ishape::iAmOutOfBoundInTheLeft()
{
    for(int i =0; i<4; i++){
        if(shapeMatrix[i][0].x < 0 && shapeMatrix[i][0].switches == true){
            moveRight();
            moveRight();
            break;
        }
    }
    
}



void Ishape::iAmOutOfBoundInTheRight()
{
    for(int i =0; i < 4; i++){
        if(shapeMatrix[i][3].x > 9 && shapeMatrix[i][3].switches == true){
            moveLeft();
           
            break;
        }
    }
    
}


void Ishape::dirrectionOfI1(){
    
    resetSwitches();
       
        shapeMatrix[0][2].switches = true;

     
        shapeMatrix[1][2].switches = true;

       
        shapeMatrix[2][2].switches = true;

    
        shapeMatrix[3][2].switches = true;
}







