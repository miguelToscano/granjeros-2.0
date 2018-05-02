#ifndef CONFIGURACION_H_
#define CONFIGURACION_H_

#include <iostream>
#include <fstream>
#include <string>
#include "jugador.h"

using namespace std;

// Dificultades disponibles
typedef enum {NO_ASIGNADA = 0, FACIL = 1, MEDIA = 2, DIFICIL = 3} dificultad;

// Constantes para que el usuario ingrese la dificultad que quiere
const int DIFICULTADES = 3;
const int DIFICULTAD_FACIL = 1;
const int DIFICULTAD_MEDIA = 2;
const int DIFICULTAD_DIFICIL = 3;

// Nombres de los archivos a consultar dependiendo la dificultad elegida
const string ARCHIVO_FACIL = "dificultadFacil.txt";
const string ARCHIVO_MEDIA = "dificultadMedia.txt";
const string ARCHIVO_DIFICIL = "dificultadDificil.txt";

// Funcion que se encarga de crear las condiciones iniciales del juego (pedir
// cantidad de jugadores, sus nombres, elegir dificultad, asignar cargarAtributos
// iniciales)

// Pre: -
// Post: Deja el juego listo para comenzar
void configurarJuego(Jugador*& jugadores, int& cantidadJugadores);

// Pre: -
// Post: asigna lo ingresado por teclado por el usuario a la cantida de jugadores
void ingresarCantidadJugadores(int& cantidadJugadores);

// Pre: El arreglo de jugadores debe estar inicializado en NULL para asegurar
// que no hayan multiples creaciones del mismo arreglo
// Post: Crea el arreglo segun la cantidad de jugadores pasada como argumento
void crearArregloJugadores(Jugador*& jugadores, int cantidad);

// Pre: El arreglo de jugadores debe ser distinto de NULL
// Post: le deja asignado los nombres a cada jugador del arreglo
void ingresarNombres(Jugador* jugadores, int cantidad);


// Pre: nivelElegido debe ser NO_ASIGNADO para evitar multiples elecciones
// de dificultad
// Post: Deja un valor de dificultad en nivelElegido
void elegirDificultad(dificultad& nivelElegido);

// Pre: El arreglo jugadores debe estar creado y la dificultadElegida tambien
// Post: a cada jugador del arreglo le asigna los atributos que figuran en el archivo
// consultado segun la dificultad elegida
void cargarAtributosIniciales(Jugador* jugadores, int cantidad, dificultad dificultadElegida);

#endif
