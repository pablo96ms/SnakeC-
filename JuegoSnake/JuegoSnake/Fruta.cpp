#include <stdlib.h>
#include "Fruta.h"
#include "glut.h"
#include <ctime>
#include "Vector2D.h"



Fruta::Fruta()
{
	radio = 1.0f;
	velocidad.x = 10.0f;
	velocidad.y = 5.0f;
	//posicion.x = 0.0;
	//posicion.y = 0.0;
}


Fruta::~Fruta()
{
}

void Fruta::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	glColor3f(rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio
	glutSolidSphere(radio, 5, 5);
	/*if(food)
	posicion.random(posicion.xfruta, posicion.yfruta);
	food=false;
	glColor3f(1.0, 0.0, 0.0);
	glRectf(posicion.xfruta, posicion.yfruta, posicion.xfruta+1, posicion.yfruta+1);
	*/
	//posicion.random(posicion.x, posicion.y);



	glPopMatrix();

}
