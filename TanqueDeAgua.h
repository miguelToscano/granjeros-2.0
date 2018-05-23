/*
 * tanque de agua.h
 *
 *  Created on: Apr 30, 2018
 *      Author: carlos
 */

#ifndef TANQUE_DE_AGUA_H_
#define TANQUE_DE_AGUA_H_

class TanqueDeAgua{

private:

	int capacidadDelTanque;

	int cantidadDeAgua;

	int precioAmpliacion;


public:

	/*
	 * post: Crea un tanque de agua
	 */
	TanqueDeAgua();

	/*
	 * post: crea un tanque de agua con la capacidad
	 * 		maxima indicada.
	 */
	TanqueDeAgua(int capacidad);

	/*
	 * pre: El tanque debe haber sido inicializado.
	 * post: Devuelve la capacidad del tanque
	 */
	int obtenerCapacidad();

	/*
	 * pre: El tanque debe ser inicializado.
	 * post: Devuelve la cantidad de agua actual
	 * 		que posee el tanque.
	 */
	int obtenerCantidadAgua();

	/*
	 * pre: Debe pasarse por parametro un numero
	 * 		entero positivo mayor a 0.
	 * post: Aumenta la capidad indicada.
	 */
	void aumentarCapacidad(int aumento);

	/*
	 * pre: masAgua debe ser un numero entero positivo.
	 * post: Llena el tanque con la cantidad de agua
	 * 		pasada por parametro.
	 */
	void llenarTanque(int masAgua);

	/*
	 * Pre: costoRiego debe ser un numero entero positivo.
	 * Post: Devuelve true y disminuye el costoRiego, si el costo es mayor
	 * 		a la cantidad actual de agua devuelve false
	 * 		y no hace nada.
	 */
	bool disminuirAgua(int costoRiego);

//	Post: Devuelve el precio actual de la ampliacion del tanque

	int obtenerPrecioAumentoDeCapacidad();
};




#endif /* TANQUE_DE_AGUA_H_ */
