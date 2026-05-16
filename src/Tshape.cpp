
#include "Tshape.h"
#include <stdio.h>


Tshape::Tshape(){
    initializeShapeMatrix();
    shapeT();
   
}


void Tshape::initializeShapeMatrix()
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            shapeMatrix[i][j].y = i;
            shapeMatrix[i][j].x = j + 4;
         }
    }
}


void Tshape::input(char matrix[20][10])
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
            shapeT();
            break;


            case 2:
            dirrectionOfT1();
            break;

            case 3:
            dirrectionOfT2();
            break;

            case 4:
            dirrectionOfT3();
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




void Tshape::resetSwitches(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){

            shapeMatrix[i][j].switches = false;
        }

    }

}

void Tshape::drawShapeInBigMatrix(char matrix[20][10]){
    for(int i = 0; i<3; i++){
        for(int j = 0; j <3; j++){
            if(shapeMatrix[i][j].switches == true){
                matrix[shapeMatrix[i][j].y][shapeMatrix[i][j].x] = '#';
            }

        }
    }
}
void Tshape::shapeT(){

    resetSwitches();
     
        shapeMatrix[1][0].switches = true;

       
        shapeMatrix[1][2].switches = true;

       
        shapeMatrix[1][1].switches = true;

      
        shapeMatrix[2][1].switches = true;


   
}


bool Tshape::checkBoundDown(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(shapeMatrix[i][j].y + 1 > 19 && shapeMatrix[i][j].switches == true){

                return true;
            }
            
        }
    }

    return false;
}

bool Tshape::checkHashInTheRight(char matrix[20][10]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(matrix[shapeMatrix[i][j].y][shapeMatrix[i][j].x + 1] == '#' && shapeMatrix[i][j].switches == true){
                
                return true;
            }
            
        }
    }
    return false;
}


void Tshape::iAmInsideHashOnTheRight(char matrix[20][10]){
    for(int i = 0; i < 3; i++){
        if(matrix[shapeMatrix[i][2].y][shapeMatrix[i][2].x] == '#' && shapeMatrix[i][2].switches == true){
            
            moveLeft();
            
            break;
        }
    }
}


bool Tshape::checkHashOnTheLeft(char matrix[20][10]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(matrix[shapeMatrix[i][j].y][shapeMatrix[i][j].x - 1] == '#' && shapeMatrix[i][j].switches == true){
                
                return true;
            }
            
        }
    }
    return false;
}


void Tshape::iAmInsideHashOnTheLeft(char matrix[20][10]){
    for(int i = 0; i < 3; i++){
        if(matrix[shapeMatrix[i][0].y][shapeMatrix[i][0].x] == '#' && shapeMatrix[i][0].switches == true){
            
            moveRight();
            
            break;
        }
    }
}


bool Tshape::checkHashInTheBottom(char matrix[20][10]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(matrix[shapeMatrix[i][j].y + 1][shapeMatrix[i][j].x] == '#' && shapeMatrix[i][j].switches == true){
                

                return true;
            }
            
        }
    }
    return false;
}


void Tshape::iAmInsideHashInTheBottom(char matrix[20][10]){
    for(int j = 0; j < 3; j++){
        if(matrix[shapeMatrix[2][j].y][shapeMatrix[2][j].x] == '#' && shapeMatrix[2][j].switches == true){
            
            moveUp();
            
            break;
        }
    }
}


bool Tshape::checkBoundLeft(){
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            
            if(shapeMatrix[i][j].x - 1 < 0 && shapeMatrix[i][j].switches == true){
                
                return true;
            }
            
        }
    }
    return false;
}

bool Tshape::checkBoundRight()
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

void Tshape::iAmOutOfBoundInTheBottom(){
    
    for(int j =0; j<3; j++){
        if(shapeMatrix[2][j].y > 19 && shapeMatrix[2][j].switches == true){
            moveUp();
            break;
        }
    }
    
}
void Tshape::iAmOutOfBoundInTheLeft()
{
    for(int i =0; i<3; i++){
        if(shapeMatrix[i][0].x < 0 && shapeMatrix[i][0].switches == true){
            moveRight();
            break;
        }
    }
    
}



void Tshape::iAmOutOfBoundInTheRight()
{
    for(int i =0; i < 3; i++){
        if(shapeMatrix[i][2].x > 9 && shapeMatrix[i][2].switches == true){
            moveLeft();
            break;
        }
    }
    
}


void Tshape::dirrectionOfT1(){
    
    resetSwitches();
       
        shapeMatrix[0][1].switches = true;

     
        shapeMatrix[1][0].switches = true;

       
        shapeMatrix[1][1].switches = true;

    
        shapeMatrix[2][1].switches = true;
}



void Tshape::dirrectionOfT2(){
    resetSwitches();
        
        shapeMatrix[1][0].switches = true;

  
        shapeMatrix[1][2].switches = true;

    
        shapeMatrix[1][1].switches = true;

      
        shapeMatrix[0][1].switches = true;
}



void Tshape::dirrectionOfT3(){
    
    resetSwitches();
   
    shapeMatrix[0][1].switches = true;

    
    shapeMatrix[2][1].switches = true;

   
    shapeMatrix[1][1].switches = true;

  
    shapeMatrix[1][2].switches = true;

}
