/*
 * Campo.h
 *
 *  Created on: 11 may. 2018
 *      Author: tomas
 */

#ifndef CAMPO_H_
#define CAMPO_H_

#include <iostream>
#include "../src/Lista.h"
#include "../src/Parcela.h"

const float FACTOR_PRECIO_TERRENO = 1.25;
const int PRECIO_TERRENO = 4;

class Campo {

private:

	Lista <Parcela**> ListaDeTerrenos;

	int cantidadTerrenos;

	unsigned int filas;

	unsigned int columnas;

	int precioTerreno; // Creditos por terreno

public:

	/*
	 * post: Crea un campo con "filas", "columnas", "cantidadTerrenos" en cero,
	 * 		y el precio del terreno.
	 */
	Campo();

	/*
	 * pre: filas y columnas deben ser numeros enteros mayores a cero.
	 * post: Crea un campo con un terreno, de las dimensiones pasadas por parametros.
	 */
	Campo(unsigned int filas,unsigned int columnas);

	/*
	 * pre: posicion debe ser un entero positivo, mayor a cero y menor a la cantidad
	 * 		de terrenos del jugador.
	 * post: Devuelve el nodo del terreno del incide pasado por parametro.
	 */
	Nodo<Parcela**>* obtenerTerreno(unsigned int posicion);

	/*
	 * pre: posicion debe ser un entero positivo, mayor a cero y menor a la cantidad
	 * 		de terrenos del jugador.
	 * post: Devuelve del terreno del incide pasado por parametro.
	 */
	Parcela** devolverTerreno(unsigned int posicion);

	/*
	 * post: Crea y agrega un terreno al campo del jugador
	 */
	void agregarTerreno();

	/*
	 * pre: Filas debe ser un numero entero positivo.
	 * post: Establece la cantidad de filas.
	 */
	void establecerFilas(int filas);

	/*
	 *
	 */
	void establecerColumnas(int columnas);

	/*
	 * post: Crea un campo, con un terreno.
	 */
	void crearCampo();

	/*
	 *
	 */
	void mostrarCampo();

	/*
	 * pre: recibe un puntero a Parcela.
	 * post: Muestra por consola las caracteristicas del terreno pasado por argumento
	 */
	void mostrarTerreno(Parcela** terreno);

	/*
	 * post: Obtiene la cantidad de terrenos que posee el campo del jugadpor
	 */
	int obtenerCantidadTerrenos();

	/*
	 * pre: posicion debe ser un numero entero positivo
	 * post: Elimina el terreno ubicado en la posicion pasada por argumento.
	 */
	void eliminarTerreno(unsigned int posicion);

	/*
	 * post: Devuelve la cantidad de filas que tienen las dimensiones de los terrenos
	 * 		del campo del jugador.
	 */
	int obtenerFilas();

	/*
	 * post: Devuelve la cantidad de columnas que tienen las dimensiones de los terrenos
	 * 		del campo del jugador.
	 */
	int obtenerColumnas();

	/*
	 * post: Devuelve el precio del terreno
	 */
	int obtenerPrecioTerreno();

	/*
	 * post: Actualiza el precio de compra del terreno.
	 */
	void actualizarPrecioTerreno();

	/*
	 * pre: terreno, fila y columna deben ser numeros enteros positivos.
	 * post: Devuelve la direccion de memoria de una parcela de las coordenadas
	 * 		pasadas por parametros.
	 */
	Parcela* obtenerPacela(int terreno, int fila, int columna);

	/*
	 * post: Elimina los terrenos del campo para liberar la memoria de los mismos
	 */
	virtual ~Campo();

};

#endif /* SRC_CAMPO_H_ */
