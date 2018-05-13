#ifndef CONFIGURACION_H_
#define CONFIGURACION_H_

#include <iostream>
#include <fstream>
#include <string>
#include "jugador.h"
#include <iomanip>

using namespace std;

// Dificultades disponibles
typedef enum {NO_ASIGNADA = 0, FACIL = 1, MEDIA = 2, DIFICIL = 3} dificultad;

// Diccionarios para asignar valores segun la dificultad elegida
const int diccionarioFilas[] = {4, 6, 8};
const int diccionarioColumnas[] = {4, 6, 8};

// Constantes para que el usuario ingrese la dificultad que quiere
const int DIFICULTADES = 3;
const int DIFICULTAD_FACIL = 1;
const int DIFICULTAD_MEDIA = 2;
const int DIFICULTAD_DIFICIL = 3;

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


void mostrarInformacionJugadores(Jugador* jugadores, int cantidadJugadores);

#endif