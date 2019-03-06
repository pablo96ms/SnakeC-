#include "Snake.h"
#include "glut.h"


Snake::Snake()
{
	snake_length = 5;
}


Snake::~Snake()
{
}
void Snake::drawsnake()
{
    for(int i=snake_length-1;i>0;i--)
    {
        posicion.posX[i]=posicion.posX[i-1];
        posicion.posY[i]=posicion.posY[i-1];
    }
    if(posicion.sDirection==UP)
        posicion.posY[0]++;
    else if(posicion.sDirection==DOWN)
        posicion.posY[0]--;
    else if (posicion.sDirection==RIGHT)
        posicion.posX[0]++;
    else if (posicion.sDirection==LEFT)
        posicion.posX[0]--;
    glColor3f(0.0, 1.0, 0.0); //colour green
    for(int i=0;i<snake_length;i++)
    {
        if(i==0)
            glColor3f(0.0, 1.0, 0.0);
        else
            glColor3f(0.0, 0.0, 1.0);
        glRectd(posicion.posX[i], posicion.posY[i], posicion.posX[i]+1, posicion.posY[i]+1);
    }
    
    
}


