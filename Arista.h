/*
 * Arista.h
 *
 *  Created on: 26/06/2018
 *      Author: algo2
 */

#ifndef ARISTA_H_
#define ARISTA_H_



class Arista{
	private:
		unsigned int destino;
		unsigned int costo;

	public:

		Arista();

		Arista(unsigned int destino, unsigned int costo);

		unsigned int obtenerDestino();

		bool esIgual(Arista otraArista);

		bool esDeMenorCosto(Arista otraArista);

		unsigned int obtenerCosto();

		void cambiarCosto(unsigned int costo);

};


#endif /* ARISTA_H_ */
