#pragma once
#include "Juego.h"
#ifndef Admin_h
#define Admin_h



class Admin
{
public:
	Admin();
	enum Estado { INICIO, JUEGO, GAMEOVER, FIN, PAUSA };
	Estado estado;
	Juego juego;
	virtual ~Admin();
protected:
	void Dibuja();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void Mueve();

};
#endif 

