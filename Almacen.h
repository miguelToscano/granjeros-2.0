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

typedef char dato;

const dato ESPACIO_VACIO = ' ';

class Almacen {

	private:

		Lista <Cultivo> ListaDeCosechas;
		int cantidadCosechas;
		int capacidadMaxima;

	public:

		//Constructor con parámetros
		Almacen(int N, int M);

		//Constructor sin parámetros
		Almacen();

		/*
		 * post:Agrega un cultivo al almacen
		 * si no hay lugar no hacer nada.
		 */
		void agregarCosechaAlmacen(Cultivo cosecha);

		/*
		 * pre: recibis cultivo , y el destino como string
		 * post: Envia una cosecha a destino y me retornas un
		 * int con el precio total de la rentabilidad del cultivo
		 * mas el costo de envio
		 */
		int despacharCosecha(Cultivo cosecha);

		/*
		 * Pre: Recibe cantidadDeLugares > 0, entero.
		 * Post: Aumenta capacidad de almacen en cantidadDeLugares.
		 */

		void aumentarCapacidad(unsigned int cantidadDeLugares);


		//Destructor
		virtual ~Almacen();


};

#endif /* ALMACEN_H_ */
