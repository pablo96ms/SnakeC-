#include <iostream>
#include "Mundo.h"
#include "glut.h"
#define COLUMNS 40
#define ROWS 40
#define MIN 2
#include <string>
#include <fstream>

using namespace std;

Mundo::Mundo()
{
	score = 0;
	gameover = false;


}


Mundo::~Mundo()
{
}

void Mundo::Inicializa() {
}

void Mundo::dibuja()
{
	
    serpiente.drawsnake();
    juegoterminado();
    escenario.DrawGrid();
    ComerFruta();
    fruta.drawFood();
	ComerBonus();
	if (score % 5 == 0 && score != 0) {
		std::cout << "LLAMANDO A BONUS DIBUJA" << std::endl;
		bonus.Dibuja(bonus.posicion);
	}
	if (score % 3 == 0 && score != 0) {
		std::cout << "LLAMANDO A ENEMIGO DIBUJA" << std::endl;
		enemigo.Dibuja(enemigo.posicion);
	}
}

void Mundo::juegoterminado()
{
	if ((Interaccion::colision(escenario,serpiente))||(Interaccion::colision(serpiente))||(Interaccion::colision(serpiente,enemigo)))
		gameover = true;
}
void Mundo::ComerFruta()
{
	if (Interaccion::colision(serpiente, fruta)) {
		score++;
		serpiente.snake_length++; //aumenta uno el tamaño de la serpiente
		if (serpiente.snake_length > MAX)
			serpiente.snake_length = MAX;
		fruta.food = true;
	}
	/*if (score % 5 == 0 && score!=0) {
		std::cout << "LLAMANDO A BONUS DIBUJA" << std::endl;
		bonus.Dibuja(posicion);
		
	}*/




	//hacer modificaciones en esta funcion para que el bonus solamente aparezca tras conseguir 5 puntos.

    
}
void Mundo::ComerBonus() {
	if (Interaccion::choque(serpiente, bonus)) {
		score += 3;//Cambio el valor de aumento de score, para que al aumentar no siga siendo multiplo de 5 y desaparezca
		serpiente.snake_length++; //aumenta uno el tamaño de la serpiente
		if (serpiente.snake_length > MAX)
			serpiente.snake_length = MAX;
		bonus.bonus = true;
	}
}
void Mundo::tecla(unsigned char key)
{
    switch (key) {
        case GLUT_KEY_UP:
            if(serpiente.posicion.sDirection!=DOWN)
                serpiente.posicion.sDirection=UP;
            break;
        case GLUT_KEY_DOWN:
            if(serpiente.posicion.sDirection!=UP)
                serpiente.posicion.sDirection=DOWN; break;
        case GLUT_KEY_LEFT:
            if(serpiente.posicion.sDirection!=RIGHT)
                serpiente.posicion.sDirection=LEFT;
            break;
        case GLUT_KEY_RIGHT:
            if(serpiente.posicion.sDirection!=LEFT)
                serpiente.posicion.sDirection=RIGHT;
            break;
    }
}
void Mundo::DibujaCuadricula()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); //Coloca la pantalla en rojo o cualquier color
    escenario.initGrid(COLUMNS, ROWS); //dibuja en rojo los bordes
}

void Mundo::Mover() {
	
}
void Mundo::GuardarPartida()
{
	ofstream archivoGuardado;
	archivoGuardado.open("archivoguardado.txt");
	//archivoGuardado << "h " << serpiente.posicion ;
	//archivoGuardado << "m " << num_mapa << " " << dificultad;
	archivoGuardado.close();
}


