/*
 * Vertice.h
 *
 *  Created on: 26/06/2018
 *      Author: algo2
 */

#ifndef VERTICE_H_
#define VERTICE_H_

#include "Arista.h"
#include "Lista.h"


class Vertice{
	private:

		std::string nombre;

		Lista<Arista> listaAdyacencia;

		bool visitado;

	public:

		Vertice();

		Vertice(std::string nombre);

		Lista<Arista>* obtenerAristas();

		std::string obtenerNombre();

		bool esIgual(std::string verticeNombre);

		void agregarArista(Arista arista);

		bool exiteArista(Arista arista);

		bool fueVisitado();

		void noVisitado();

		void Visitado();

		~Vertice();
};


#endif /* VERTICE_H_ */
