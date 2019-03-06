#pragma once
#ifndef Snake_h
#define Snake_h
#include "Vector2D.h"
#include "Fruta.h"
#include "Escenario.h"
#include "ObjetoMovil.h"

class Snake:public ObjetoMovil
{
public:
	Snake();
    void drawsnake();
	virtual ~Snake();
	int snake_length;
	Vector2D posicion;
	friend class Interaccion;

private:
    Fruta fruta;
    Escenario escenario;
    
   
	
};

#endif
