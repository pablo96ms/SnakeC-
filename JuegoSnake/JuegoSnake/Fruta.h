#pragma once
#ifndef Fruta_h
#define Fruta_h
#include "Vector2D.h"
#include "Escenario.h"
#include "ObjetoMovil.h"
class Fruta:public ObjetoMovil
{
	
public:
	Fruta();
	virtual ~Fruta();
	void drawFood();
	bool food;
	friend class Interaccion;
private:
	Vector2D posicion;

    
};
#endif
