/*
 * Almacen.h
 *
 *  Created on: 1 may. 2018
 *      Author: tomas
 */

#ifndef ALMACEN_H_
#define ALMACEN_H_

class Almacen {

	private:

		//LISTA DE CULTIVOS
		char cultivo;//cambialo por una lista
		int cantidadActual;
		int capacidadMaxima;

	public:

		//Constructor
		Almacen();

		/*
		 * post:Agrega un cultivo al almacen
		 * si no hay lugar no hacer nada.
		 */
		void agregarCultivoAlmacen(char tipoCultivo);

		/*
		 * pre: recibis cultivo , y el destino como string
		 * post: Envia una cosecha a destino y me retornas un
		 * int con el precio total de la rentabilidad del cultivo
		 * mas el costo de envio
		 */
		int enviarCosecha(Cultivo cultivoArg, std::string destino);

		/*
		 * pre: capacidad debe ser un entero mayor a 0.
		 * post: aumenta la capacidad del maxima del almacen.
		 */
		int comprarCapacidad(int capacidad);


		//Destructor
		virtual ~Almacen();


};

#endif /* ALMACEN_H_ */
