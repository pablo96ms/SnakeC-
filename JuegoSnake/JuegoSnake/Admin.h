#pragma once
#include "Mundo.h"
#ifndef Admin_h
#define Admin_h



class Admin
{
public:
	Admin();
	enum Estado { INICIO, JUEGO, GAMEOVER, FIN, PAUSA };
	Estado estado;
	Mundo mundo;
	virtual ~Admin();
protected:
	void Dibuja();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void Mueve();

};
#endif 

