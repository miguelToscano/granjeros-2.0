/*
 * logica.h
 *
 *  Created on: 22/05/2018
 *      Author: algo2
 */

#ifndef SRC_LOGICA_H_
#define SRC_LOGICA_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include <string>
#include <fstream>
#include <iomanip>

#include "../src/configuracion.h"
#include "../src/Campo.h"
#include "../src/Jugador.h"
#include "../src/Lista.h"
#include "../src/Nodo.h"
#include "Dibujador.h"
#include "Grafo.h"
#include "DestinosAristas.h"

/*
 * Constantes
 */

using namespace std;

const int OPCION_REGAR_CULTIVO = 1;
const int OPCION_COMPRAR_TERRENO = 2;
const int OPCION_VENDER_TERRENO = 3;
const int OPCION_SEMBRAR_PARCELA = 4;
const int OPCION_COSECHAR = 5;
const int OPCION_COMPRAR_AGUA = 6;
const int OPCION_COMPRAR_ALMACEN = 7;
const int OPCION_ENVIAR_PEDIDOS = 8;
const int OPCION_FINALIZAR_TURNO = 9;
const int OPCION_SALIR = 10;

/*
 * Funciones de logica
 */

/*
 * post: Imprime por pantalla el menu de acciones
 * 		que se pueden realizar
 */
void imprimirMenu();

/*
 * pre: recibe una lista de destinos vacia
 * post: segun un archivo determinado con costos de destinos, crea una lista de
 * 		los vertices a agregar en el grafo.
 */
void cearListaGrafo(char tipoCultivo, Lista<DestinosAristas>* listaAristas);

/*
 * pre: Se recibe por paarametro la direccion de memoria de un Jugador
 * post: Solicita por pantalla que se seleccione una opcion y
 * 		devuelve un entero con la opcion seleccionada.
 */
int obtenerOpcion(Lista<Jugador*>* jugadores);

/*
 * pre: Se recibe un puntero a int terreno, y un Jugador
 * 		por referencia
 * post: Se solicita por pantalla que se ingrese un numero
 * 		de terreno y le asigna ese numero a la direccion del
 * 		puntero terreno. Aclaracion: Si no es un terreno valido
 * 		se pedira el reingreso del mismo.
 */
void validarTerreno(int* terreno, Jugador* jugador);

/*
 * pre: Se recibe un puntero a int fila, y un Jugador
 * 		por referencia
 * post: Se solicita por pantalla que se ingrese un numero
 * 		de terreno y le asigna ese numero a la direccion del
 * 		puntero fila. Aclaracion: Si no es una fila valido
 * 		se pedira el reingreso del mismo.
 */
void validarFila(int* fila, Jugador* jugador);

/*
 * pre: Se recibe un puntero a int columna, y un Jugador
 * 		por referencia
 * post: Se solicita por pantalla que se ingrese un numero
 * 		de terreno y le asigna ese numero a la direccion del
 * 		puntero columna. Aclaracion: Si no es una columna valido
 * 		se pedira el reingreso del mismo.
 */
void validarColumna(int* columna, Jugador* jugador);

/*
 * pre: Se recibe tres punteros a int terreno, fila y columna,
 * 		y un Jugador por referencia.
 * post: Solicita las coordenas al usuario, terreno, fila y columna.
 * 		asigna esos valores a las direcciones que tiene los punteros
 * 		pasados por argumentos.
 */
void ingresarCoordenadas(int* terreno, int* fila, int* columna, Jugador* jugador);
/*
 * pre: Se recibe la direccion de memoria de un Jugador.
 * post: Se solicitan coordenadas y se solicita cosechar
 * 		la parcela en dicha coordenada.
 */
void cosecharParcela(Jugador* jugador);

/*
 * pre: Se recibe la direccion de memoria de un Jugador.
 * post: Agrega un terreno a la lista de terrenos del jugador
 * 		y descuenta los creditos correspondientes.
 */
void comprarTerreno(Jugador* jugador);

/*
 * pre: Se recibe la direccion de memoria de un Jugador.
 * post: Solicita el ingreso de un terreno y lo vende.
 */
void venderTerreno(Jugador* jugador);
/*
 * pre: Se recibe la direccion de memoria de un Jugador.
 * post: Aumenta la capacidad del Tanque y disminuye los
 * 		creditos necesarios.
 */
void comprarCapacidadAgua(Jugador* jugador);

/*
 * pre: Se recibe la direccion de memoria de un Jugador.
 * post: Aumenta la capacidad del almacen y disminuye los
 * 		creditos.
 */
void comprarCapacidadAlmacen(Jugador* jugador);
/*
 * pre: Se recibe la direccion de memoria de un Jugador,
 * 		cultivosDesponibles es un arreglo de cultivos validos.
 * post:
 */
void sembrarParcela(Jugador* jugador, Lista<Cultivo*>* cultivosDisponibles);
/*
 * pre: Se recibe la direccion de memoria de un Jugador.
 * post: Realiza la secuencia de paso de turno en todas las parcelas.
 */
void actualizarTerreno(Parcela** terrenoJugador,
		unsigned int topeFila, unsigned int topeColumnas);

/*
 * pre: Se recibe la direccion de memoria de un Jugador.
 * post: Actualiza el campo del jugador.
 */
void actualizarCampo(Jugador* jugador);

/*
 * pre: Se recibe la direccion de memoria de un Jugador.
 * post: Se solicita el ingreso de cordenadas para regar una parcela
 * 		en caso que la misma se pueda regar lo realiza.
 */
void regarCultivo(Jugador* jugador);
/*
 * pre: Se recibe un objeto jugador.
 * post:Envia a destino un el cultivo que el jugador elija.
 * 		Se actualizaran los creditos correspondientes.
 */
void enviarPedido(Jugador jugador, Lista<Grafo*>* listaGrafo);

/*
 * pre: Se recibe la direccion de memoria de un Jugador, turno y
 * 		cantidadCultivosDisponibles deben ser dos numeros enteros
 * 		mayores a cero. Ademas se recibe un puntero a un arreglo
 * 		de cultivos.
 * post: Se realiza la secuencia del turno.
 * 		"El jugador recibe agua y elige que acciones realizar.
 * 		puede realizar tantas opciones como quiera hasta que elija
 * 		pasar de turno. Una vez hecho esto se eliminan las unidades
 * 		de agua que superen la capacidad del tanque.
 * 		Finalmente se actualiza el campo."
 */
void procesarTurno(Jugador* jugador, int turno, Lista<Cultivo*>* cultivosDisponibles, Lista<Grafo*>* listaGrafo);
/*
 
 * post: Imprime el nombre del jugador con mas creditos. En caso que listaJugadores este vacia no imprime nada
 */
void mostrarGanador(Lista<Jugador*>* jugadores);


#endif /* SRC_LOGICA_H_ */
