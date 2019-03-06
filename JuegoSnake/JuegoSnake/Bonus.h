#pragma once
#ifndef Bonus_h
#define Bonus_h
#include "ObjetoMovil.h"
#include "Vector2D.h"
#include "Interaccion.h"
#include "Fruta.h"




class Bonus:public ObjetoMovil
{
	
public:
	Bonus();
	virtual ~Bonus();
	void Dibuja(Vector2D&);
	Vector2D posicion;
	bool bonus;
	friend class Interaccion;
private:
	unsigned char rojo;
	unsigned char azul;
	unsigned char verde;
	

	
	
};
#endif // !Bonus_h

