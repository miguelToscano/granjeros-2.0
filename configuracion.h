#ifndef CONFIGURACION_H_
#define CONFIGURACION_H_

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "../src/Jugador.h"

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
void configurarJuego(Lista<Jugador*>* listaJugadores, Lista<Cultivo*>* listaCultivos);

// Pre: -
// Post: asigna lo ingresado por teclado por el usuario a la cantida de jugadores
void ingresarCantidadJugadores(int& cantidadJugadores);

// Pre: El arreglo de jugadores debe estar inicializado en NULL para asegurar
// que no hayan multiples creaciones del mismo arreglo
// Post: Crea el arreglo segun la cantidad de jugadores pasada como argumento
void crearJugadores(Lista<Jugador*>* listaJugadores, int cantidad);

// Pre: nivelElegido debe ser NO_ASIGNADO para evitar multiples elecciones
// de dificultad
// Post: Deja un valor de dificultad en nivelElegido
void elegirDificultad(dificultad& nivelElegido);

// Pre: El arreglo jugadores debe estar creado y la dificultadElegida tambien
// Post: a cada jugador del arreglo le asigna los atributos que figuran en el archivo
// consultado segun la dificultad elegida
void cargarAtributosIniciales(Lista<Jugador*>* listaJugadores, dificultad dificultadElegida);

// Pre: El archivo de cultivos debe existir
// Post: carga los cultivos en un arreglo global
void cargarCultivos(Lista<Cultivo*>* listaCultivosDisponibles);

// Pre: jugadores es un arreglo de jugadores y cantidades de jugadores
//  	debe ser un numero entero positivo
// Post: Imprime por consola la informacion de los jugadores necesaria
//		para el desarrollo del juego.
void mostrarInformacionJugadores(Lista<Jugador*>* jugadores);

#endif
