#pragma once
#ifndef Fruta_h
#define Fruta_h
#include "Vector2D.h"
#include "ObjetoMovil.h"

class Fruta :public ObjetoMovil
{

public:
	Fruta();
	virtual ~Fruta();
	void dibuja();
	//void random(float &x, float &y);//funcion que genera un numero aleatorio
	friend class Interaccion;
private:
	float radio;


};
#endif
