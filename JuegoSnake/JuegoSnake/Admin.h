#pragma once
#ifndef Admin_h
#define Admin_h


class Admin
{
public:
	Admin();
	enum Estado { INICIO, JUEGO, GAMEOVER, FIN, PAUSA };
	Estado estado;
	void Dibuja();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void Mueve();
	virtual ~Admin();
};
#endif 

