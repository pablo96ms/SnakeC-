//
//  main.cpp
//  JuegoSnake
//
//  Created by Richard villanera quiroga on 24/4/18.
//  Copyright © 2018 Richard villanera quiroga. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "glut.h"
#include <iostream>
#include "Mundo.h"
#include "Admin.h"
#include <stdio.h>
#include <string.h>
#define COLUMNS 40
#define ROWS 40
#define FPS 10 //marca la velocidad de la animacion
Admin juegoSnake;


//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void Display_callbacks(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(int key, int x, int y); //cursores
void init();
void reshape_callback(int, int);
void OnSpecialKeyboardDown(int key, int x, int y);

int main(int argc, char* argv[])
{
    //Inicializar el gestor de ventanas GLUT
    //y crear la ventana
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Snake C++");
    
    //habilitar luces y definir perspectiva
    /*glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(40.0, 800 / 600.0f, 0.1, 150);*/
    
    //Registrar los callbacks
    glutDisplayFunc(Display_callbacks);
    glutReshapeFunc(reshape_callback);
    init();
    glutTimerFunc(0, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
    glutSpecialFunc(OnKeyboardDown);
    //glutKeyboardFunc(OnKeyboardDown);
    
    //pasarle el control a GLUT,que llamara a los callbacks
    glutMainLoop();
    
    return 0;
}

void Display_callbacks(void) //display callback
{
    //Borrado de la pantalla
    glClear(GL_COLOR_BUFFER_BIT);
    
    //Para definir el punto de vista
    
    
    //aqui es donde hay que poner el cÛdigo de dibujo
	
	juegoSnake.dibuja();
	
    //no borrar esta linea ni poner nada despues
    glutSwapBuffers(); //Activa Buffers
    if(juegoSnake.gameover) //si gameover es true
    {
       char _score[10];
       _itoa(mundo.score,_score,10); //score coge la puntuacion y se la lleva a _score 10 es decimal
     char text[50]="SCORE: ";
       strcat(text, _score);
       MessageBox(NULL,text,"GAME OVER",0);
        exit(0);
    }
}
void OnKeyboardDown(int key, int x_t, int y_t)
{
	juegoSnake.tecla(key);
}
void OnSpecialKeyboardDown(int key, int x, int y)
{
	juegoSnake.TeclaEspecial(key);

	glutPostRedisplay();

}

void OnTimer(int value)
{
	juegoSnake.Mover();
    glutPostRedisplay();
    glutTimerFunc(1000/FPS, OnTimer, 0); //necesita que sea asi, porque la serpiente se movera muy rapido
}
void init()
{
	juegoSnake.DibujaCuadricula();
}
void reshape_callback(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);//agrandar o hace mas pequeña la pantalla
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}

