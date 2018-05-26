/*
 * Campo.h
 *
 *  Created on: 11 may. 2018
 *      Author: tomas
 */

#ifndef CAMPO_H_
#define CAMPO_H_

#include "parcela.h"
#include "Jugador.h"
#include "Lista.h"
#include "Nodo.h"
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

	Campo();

	Campo(unsigned int filas,unsigned int columnas);

	void agregarTerreno();

	void establecerFilas(int filas);

	void establecerColumnas(int columnas);

	void crearCampo();

	void mostrarCampo(Jugador* jugador);

	void mostrarTerreno(Parcela** parcelaArg, Jugador* jugador);

	int obtenerCantidadTerrenos();

	void eliminarTerreno(unsigned int posicion);

	int obtenerFilas();

	int obtenerColumnas();

	int obtenerPrecioTerreno();

	void actualizarPrecioTerreno();

	virtual ~Campo();

};

#endif /* SRC_CAMPO_H_ */
