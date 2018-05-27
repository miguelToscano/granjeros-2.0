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

	Nodo<Parcela**>* obtenerTerreno(unsigned int posicion);

	Parcela** devolverTerreno(unsigned int posicion);

	void agregarTerreno();

	void establecerFilas(int filas);

	void establecerColumnas(int columnas);

	void crearCampo();

	void mostrarCampo();

	void mostrarTerreno(Parcela** terreno);

	int obtenerCantidadTerrenos();

	void eliminarTerreno(unsigned int posicion);

	int obtenerFilas();

	int obtenerColumnas();

	int obtenerPrecioTerreno();

	void actualizarPrecioTerreno();

	Parcela* obtenerPacela(int terreno, int fila, int columna);

	virtual ~Campo();

};

#endif /* SRC_CAMPO_H_ */
