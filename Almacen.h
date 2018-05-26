/*
 * Almacen.h
 *
 *  Created on: 1 may. 2018
 *      Author: tomas
 */

#ifndef ALMACEN_H_
#define ALMACEN_H_

#include "Lista.h"
#include "Destino.h"
#include "Cultivo.h"

class Almacen {

	private:

		Lista <Cultivo> ListaDeCosechas;
		int capacidadMaxima;

	public:

		Almacen(int N, int M);

		Almacen();

		bool agregarCosechaAlmacen(Cultivo cosecha);

		int despacharCosecha(Cultivo cosecha);

		void aumentarCapacidad(unsigned int cantidadDeLugares);

		int obtenerCapacidadMaxima();

		int obtenerCantidadDeCosechas();

		Cultivo obtenerElementoDePosicion(unsigned int posicion);

		bool hayLugar();

		bool estaVacio();

		virtual ~Almacen();

};

#endif /* ALMACEN_H_ */
