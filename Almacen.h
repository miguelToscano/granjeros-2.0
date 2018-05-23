/*
 * Almacen.h
 *
 *  Created on: 1 may. 2018
 *      Author: Tomas
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

		/*	Constructor:
		 *
		 *	Pre: Recibe N y M parámetros definidos según la dificultad del juego
		 *
		 * 	Post: Inicializa el almacén con 2(N + M) espacios
		 */

		Almacen(int N, int M);

		/*
		 * 	Constructor de oficio
		 */

		Almacen();

		/*	Pre: Recibe una cosecha para ser guardada
		 *
		 *	Post: Si existe capacidad disponible guarda la cosecha en el almacén, caso
		 *	contrario la cosecha se pierde
		 */

		void agregarCosechaAlmacen(Cultivo cosecha);

		/*	Pre: Recibe la cosecha para ser despachada. La cosecha debe estar guardada en el
		 * 	almacén caso contrario se lanza una excepción.
		 *
		 * 	Post: Elimina la cosecha del almacén, y retorna el valor de la ganancia: calculado como
		 * 	rentabilidad - costo de envío.
		 */

		int despacharCosecha(Cultivo cosecha);

		/*	Pre: Recibe la cantidad de lugares a agregar en el almacén, número positivo
		 *
		 * 	Post: Agrega al almacén la cantidad de lugares
		 */

		void aumentarCapacidad(unsigned int cantidadDeLugares);

		virtual ~Almacen();
};

#endif /* ALMACEN_H_ */
