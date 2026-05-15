#include "Jshape.h"
#include <stdio.h>

Jshape::Jshape(){
    initializeShapeMatrix();
    shapeJ();
    next = 1;
}


void Jshape::initializeShapeMatrix()
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            shapeMatrix[i][j].y = i;
            shapeMatrix[i][j].x = j + 4;
         }
    }
}


void Jshape::input(char matrix[20][10])
{
    printf(":)\n");
    
    char input;
    scanf(" %c", &input);
    if((input == 'W' || input == 'w') && !checkHashOnTheLeft(matrix)){
        next++;


        if(next>4){
            next =1;
        }
        switch (next){

            case 1:
            shapeJ();
            break;


            case 2:
            dirrectionOfJ1();
            break;

            case 3:
            dirrectionOfJ2();
            break;

            case 4:
            dirrectionOfJ3();
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
    /*else if(input == 'S' || input == 's'){
        if(!checkBoundDown() && !checkHashInTheBottom(matrix)){
            moveDown();
        }
    }
     */

}




void Jshape::resetSwitches(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            shapeMatrix[i][j].switches = false;
        }

    }

}

void Jshape::drawShapeInBigMatrix(char matrix[20][10]){
    for(int i = 0; i<3; i++){
        for(int j = 0; j <3; j++){
            if(shapeMatrix[i][j].switches == true){
                matrix[shapeMatrix[i][j].y][shapeMatrix[i][j].x] = '#';
            }

        }
    }
}
void Jshape::shapeJ(){

    resetSwitches();
     
        shapeMatrix[0][0].switches = true;

       
        shapeMatrix[1][0].switches = true;

       
        shapeMatrix[1][1].switches = true;

      
        shapeMatrix[1][2].switches = true;


   
}
void Jshape::moveUp(){
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            shapeMatrix[i][j].y--;
            
        }
    }
    
}
void Jshape::moveDown(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            shapeMatrix[i][j].y++;
            
        }
    }
}


void Jshape::moveRight()
{
    
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            shapeMatrix[i][j].x++;
            
        }
    }
    
    
}

void Jshape::moveLeft(){
    
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            shapeMatrix[i][j].x--;
        }
    }
}


bool Jshape::checkBoundDown(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(shapeMatrix[i][j].y + 1 > 19 && shapeMatrix[i][j].switches == true){

                return true;
            }
            
        }
    }

    return false;
}

bool Jshape::checkHashInTheRight(char matrix[20][10]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(matrix[shapeMatrix[i][j].y][shapeMatrix[i][j].x + 1] == '#' && shapeMatrix[i][j].switches == true){
                
                return true;
            }
            
        }
    }
    return false;
}


void Jshape::iAmInsideHashOnTheRight(char matrix[20][10]){
    for(int i = 0; i < 3; i++){
        if(matrix[shapeMatrix[i][2].y][shapeMatrix[i][2].x] == '#' && shapeMatrix[i][2].switches == true){
            
            moveLeft();
            
            break;
        }
    }
}


bool Jshape::checkHashOnTheLeft(char matrix[20][10]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(matrix[shapeMatrix[i][j].y][shapeMatrix[i][j].x - 1] == '#' && shapeMatrix[i][j].switches == true){
                
                return true;
            }
            
        }
    }
    return false;
}


void Jshape::iAmInsideHashOnTheLeft(char matrix[20][10]){
    for(int i = 0; i < 3; i++){
        if(matrix[shapeMatrix[i][0].y][shapeMatrix[i][0].x] == '#' && shapeMatrix[i][0].switches == true){
            
            moveRight();
            
            break;
        }
    }
}


bool Jshape::checkHashInTheBottom(char matrix[20][10]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(matrix[shapeMatrix[i][j].y + 1][shapeMatrix[i][j].x] == '#' && shapeMatrix[i][j].switches == true){
                printf("KILL ME\n");

                return true;
            }
            
        }
    }
    return false;
}


void Jshape::iAmInsideHashInTheBottom(char matrix[20][10]){
    for(int j = 0; j < 3; j++){
        if(matrix[shapeMatrix[2][j].y][shapeMatrix[2][j].x] == '#' && shapeMatrix[2][j].switches == true){
            
            moveUp();
            
            break;
        }
    }
}


bool Jshape::checkBoundLeft(){
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(shapeMatrix[i][j].x - 1 < 0 && shapeMatrix[i][j].switches == true){
                
                return true;
            }
            
        }
    }
    return false;
}

bool Jshape::checkBoundRight()
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

void Jshape::iAmOutOfBoundInTheBottom(){
    
    for(int j =0; j<3; j++){
        if(shapeMatrix[2][j].y > 19 && shapeMatrix[2][j].switches == true){
            moveUp();
            break;
        }
    }
    
}
void Jshape::iAmOutOfBoundInTheLeft()
{
    for(int i =0; i<3; i++){
        if(shapeMatrix[i][0].x < 0 && shapeMatrix[i][0].switches == true){
            moveRight();
            break;
        }
    }
    
}



void Jshape::iAmOutOfBoundInTheRight()
{
    for(int i =0; i < 3; i++){
        if(shapeMatrix[i][2].x > 9 && shapeMatrix[i][2].switches == true){
            moveLeft();
            break;
        }
    }
    
}


void Jshape::dirrectionOfJ1(){
    
    resetSwitches();
       
        shapeMatrix[0][1].switches = true;

     
        shapeMatrix[0][2].switches = true;

       
        shapeMatrix[1][1].switches = true;

    
        shapeMatrix[2][1].switches = true;
}



void Jshape::dirrectionOfJ2(){
    resetSwitches();
        
        shapeMatrix[1][0].switches = true;

  
        shapeMatrix[1][2].switches = true;

    
        shapeMatrix[1][1].switches = true;

      
        shapeMatrix[2][2].switches = true;
}



void Jshape::dirrectionOfJ3(){
    
    resetSwitches();
   
    shapeMatrix[0][1].switches = true;

    
    shapeMatrix[2][1].switches = true;

   
    shapeMatrix[1][1].switches = true;

  
    shapeMatrix[2][0].switches = true;

}


