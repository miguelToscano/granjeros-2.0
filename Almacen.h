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

		Lista<Cultivo>* ListaDeCosechas;
		int capacidadMaxima;

	public:

		/* Constructor con parámetros
		 */
		Almacen(int N, int M);

		Almacen();

		/*	Pre : Recibe una cosecha para ser ingresada en almacén
		 * 	Post: Agrega (si hay lugar) la cosecha al almacén devolviendo
		 * 		  si fue exitoso, y false en caso contrario
		 */
		bool agregarCosechaAlmacen(Cultivo cosecha);

		/*	Pre : Recibe una cosecha la cual debe pertenecer al almacén
		 * 	Post: Elimina la cosecha del almacén devolviendo la ganancia de créditos
		 * 		  calculada como rentabilidad - costoDeEnvio
		 */
		int despacharCosecha(Cultivo cosecha, int posAlmacen);

		/*
		 * post:elimina la cosecha en la ubicacion indicada
		 */
		void eliminarCosecha(int posicionAlmacen);

		/*	Pre : Recibe un entero positivo de lugares a agregar
		 * 	Post: Aumenta en cantidadDeLugares la capacidad del almacén
		 */
		void aumentarCapacidad(unsigned int cantidadDeLugares);

		/*	Pre : -
		 * 	Post: Devuelve la capacidad máxima del almacén
		 */
		int obtenerCapacidadMaxima();

		/*	Pre : -
		 * 	Post: Devuelve la cantidad de cosechas del almacén
		 */
		int obtenerCantidadDeCosechas();

		/*	Pre : Recibe una posición (entero, positivo)
		 * 	Post: Devuelve el cultivo correspondiente a esa posición
		 */
		Cultivo obtenerElementoDePosicion(unsigned int posicion);

		/*	Pre : -
		 * 	Post: Devuelve si hay lugares disponibles en el almacén
		 */
		bool hayLugar();

		/*	Pre : -
		 * 	Post: Devuelve si no hay ninguna cosecha en el almacén
		 */
		bool estaVacio();

		/*
		 *  Destructor
		 *
		 */
		~Almacen();

};

#endif
