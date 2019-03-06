#include <stdlib.h>
#include "Fruta.h"
#include "glut.h"
#include <ctime>
#include "Vector2D.h"



Fruta::Fruta()
{
	//posicion.x = 0.0;
	//posicion.y = 0.0;
	food = true;
}


Fruta::~Fruta()
{
}

void Fruta::drawFood()
{
    if(food)
        posicion.random(posicion.xfruta, posicion.yfruta);
    food=false;
    glColor3f(1.0, 0.0, 0.0);
    glRectf(posicion.xfruta, posicion.yfruta, posicion.xfruta+1, posicion.yfruta+1);
    
}
