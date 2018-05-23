/*
 * Campo.h
 *
 *  Created on: 11 may. 2018
 *      Author: tomas
 */

#ifndef CAMPO_H_
#define CAMPO_H_

#include "Parcela.h"
#include "Lista.h"
#include <iostream>

const float FACTOR_PRECIO_TERRENO = 1.25;

class Campo {

private:

	Lista <Parcela**> ListaDeTerrenos;
	int cantidadTerrenos;
	unsigned int filas;
	unsigned int columnas;

	int precioTerreno; // Creditos por terreno

public:


	//Constructor
	Campo();

//	Post:Crea un campo con las dimensiones elejidas por el usuario
	Campo(unsigned int filas,unsigned int columnas);

//	Pre: Recibe una posicion valida de la lista
//	Post: Devuelve el terreno de la lista de una posicion deseada
	Nodo<Parcela**>* obtenerTerreno(unsigned int posicion);

	Parcela** devolverTerreno(unsigned int posicion);

//	Post: Agrega un terreno a la lista
	void agregarTerreno();

//	Post: Establece la cantidad de filas que posee el terreno
	void establecerFilas(int filas);

//	Post: Establece la cantidad de columnas que posee el terreno
	void establecerColumnas(int columnas);

//	Post: Crea el campo de parcelas con las dimensiones de filas y columnas deseadas
	void crearCampo();

	void mostrarCampo();

//	Post: Imprime por pantalla el terreno del jugador
	void mostrarTerreno(Parcela** terreno);

//	Post: Devuelve la cantidad det terrenos que posee el jugador
	int obtenerCantidadTerrenos();

//	Post: Elimina un terreno de la lista
	void eliminarTerreno(unsigned int posicion);

//	Post: Devuelve el numero de filas que posee el campo
	int obtenerFilas();

//	Post: Devuelve el numero de columnas que posee el campo
	int obtenerColumnas();

//	Post: Devuelve el precio actual de compra de un terreno
	int obtenerPrecioTerreno();

//	Post: Actualiza el precio de compra del terreno
	void actualizarPrecioTerreno();

//	Pre: recibe un terreno valido de un jugador
//	Post: pudre los cultivos que no fueron regados
	void pudrirCultivos();

	virtual ~Campo();

};

#endif /* SRC_CAMPO_H_ */
