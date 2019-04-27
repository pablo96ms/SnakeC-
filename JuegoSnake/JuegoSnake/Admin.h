#pragma once

#ifndef Admin_h
#define Admin_h
#include "Juego.h"
#include "Mundo.h" 
class Admin
{
public:
	Admin();
	virtual ~Admin();
protected:
	enum Estado { INICIO, JUEGO, GAMEOVER, FIN, PAUSA };
	Estado estado;
	Mundo mundo;
	Juego juegoSnake;
public:
	void Dibuja();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void Mueve();
};
#endif 

