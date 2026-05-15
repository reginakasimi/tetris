#include "Sshape.h"
#include <stdio.h>

Sshape::Sshape(){
    initializeShapeMatrix();
    shapeS();
}


void Sshape::initializeShapeMatrix()
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            shapeMatrix[i][j].y = i;
            shapeMatrix[i][j].x = j + 4;
         }
    }
}


void Sshape::input(char matrix[20][10])
{
    
    char input;
    scanf(" %c", &input);
    if((input == 'W' || input == 'w') && !checkHashOnTheLeft(matrix)){
        next++;


        if(next>4){
            next =1;
        }
        switch (next){

            case 1:
            shapeS();
            break;


            case 2:
            dirrectionOfS1();
            break;

            case 3:
            dirrectionOfS2();
            break;

            case 4:
            dirrectionOfS3();
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




void Sshape::resetSwitches(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            shapeMatrix[i][j].switches = false;
        }

    }

}

void Sshape::drawShapeInBigMatrix(char matrix[20][10]){
    for(int i = 0; i<3; i++){
        for(int j = 0; j <3; j++){
            if(shapeMatrix[i][j].switches == true){
                matrix[shapeMatrix[i][j].y][shapeMatrix[i][j].x] = '#';
            }

        }
    }
}
void Sshape::shapeS(){

    resetSwitches();
     
        shapeMatrix[0][1].switches = true;

       
        shapeMatrix[0][2].switches = true;

       
        shapeMatrix[1][1].switches = true;

      
        shapeMatrix[1][0].switches = true;


   
}



bool Sshape::checkBoundDown(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(shapeMatrix[i][j].y + 1 > 19 && shapeMatrix[i][j].switches == true){

                return true;
            }
            
        }
    }

    return false;
}

bool Sshape::checkHashInTheRight(char matrix[20][10]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(matrix[shapeMatrix[i][j].y][shapeMatrix[i][j].x + 1] == '#' && shapeMatrix[i][j].switches == true){
                
                return true;
            }
            
        }
    }
    return false;
}


void Sshape::iAmInsideHashOnTheRight(char matrix[20][10]){
    for(int i = 0; i < 3; i++){
        if(matrix[shapeMatrix[i][2].y][shapeMatrix[i][2].x] == '#' && shapeMatrix[i][2].switches == true){
            
            moveLeft();
            
            break;
        }
    }
}


bool Sshape::checkHashOnTheLeft(char matrix[20][10]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(matrix[shapeMatrix[i][j].y][shapeMatrix[i][j].x - 1] == '#' && shapeMatrix[i][j].switches == true){
                
                return true;
            }
            
        }
    }
    return false;
}


void Sshape::iAmInsideHashOnTheLeft(char matrix[20][10]){
    for(int i = 0; i < 3; i++){
        if(matrix[shapeMatrix[i][0].y][shapeMatrix[i][0].x] == '#' && shapeMatrix[i][0].switches == true){
            
            moveRight();
            
            break;
        }
    }
}


bool Sshape::checkHashInTheBottom(char matrix[20][10]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(matrix[shapeMatrix[i][j].y + 1][shapeMatrix[i][j].x] == '#' && shapeMatrix[i][j].switches == true){

                return true;
            }
            
        }
    }
    return false;
}


void Sshape::iAmInsideHashInTheBottom(char matrix[20][10]){
    for(int j = 0; j < 3; j++){
        if(matrix[shapeMatrix[2][j].y][shapeMatrix[2][j].x] == '#' && shapeMatrix[2][j].switches == true){
            
            moveUp();
            
            break;
        }
    }
}


bool Sshape::checkBoundLeft(){
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(shapeMatrix[i][j].x - 1 < 0 && shapeMatrix[i][j].switches == true){
                
                return true;
            }
            
        }
    }
    return false;
}

bool Sshape::checkBoundRight()
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

void Sshape::iAmOutOfBoundInTheBottom(){
    
    for(int j =0; j<3; j++){
        if(shapeMatrix[2][j].y > 19 && shapeMatrix[2][j].switches == true){
            moveUp();
            break;
        }
    }
    
}
void Sshape::iAmOutOfBoundInTheLeft()
{
    for(int i =0; i<3; i++){
        if(shapeMatrix[i][0].x < 0 && shapeMatrix[i][0].switches == true){
            moveRight();
            break;
        }
    }
    
}



void Sshape::iAmOutOfBoundInTheRight()
{
    for(int i =0; i < 3; i++){
        if(shapeMatrix[i][2].x > 9 && shapeMatrix[i][2].switches == true){
            moveLeft();
            break;
        }
    }
    
}


void Sshape::dirrectionOfS1(){
    
    resetSwitches();
       
        shapeMatrix[0][1].switches = true;

     
        shapeMatrix[1][2].switches = true;

       
        shapeMatrix[1][1].switches = true;

    
        shapeMatrix[2][2].switches = true;
}



void Sshape::dirrectionOfS2(){
    resetSwitches();
        
        shapeMatrix[2][0].switches = true;

  
        shapeMatrix[2][1].switches = true;

    
        shapeMatrix[1][1].switches = true;

      
        shapeMatrix[1][2].switches = true;
}



void Sshape::dirrectionOfS3(){
    
    resetSwitches();
   
    shapeMatrix[0][0].switches = true;

    
    shapeMatrix[1][0].switches = true;

   
    shapeMatrix[1][1].switches = true;

  
    shapeMatrix[2][1].switches = true;

}


