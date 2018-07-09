/*
 * Grafo.h
 *
 *  Created on: 26/06/2018
 *      Author: algo2
 */

#ifndef GRAFO_H_
#define GRAFO_H_

#include "Vertice.h"
#include "DestinosAristas.h"
#include "Lista.h"
#include "ArbolHeap.h"

class Grafo{
	private:

		Lista<Vertice*> listaVertices;

		Lista<Arista> caminosMinimos;

		/*
		 * post: Recorre todos los vertices y los marca como no visitados
		 */
		void marcarNoVisitados();

		/*
		 * post: segun un nombre de un vertice, devuelve un entero, con la
		 * 		ubicacion en la listaDeVertices
		 */
		int buscarUbicacionVertice(std::string vertice, bool* esta);

		/*
		 * post: determina si ya existe el vertice.
		 */
		bool existeVertice(std::string vertice);


		/*
		 * pre: el vertice no debe existir
		 * post: agrega un nuevo Vertice pasado por parametro.
		 */
		void agregarVertice(Vertice nuevoVertice);

	public:

		/*
		 * post: crea una instancia de grafo vacia
		 */
		Grafo();

		/*
		 * pre: La arista no debe existir.
		 * post: Analiza cada vertice, si no esta, lo agrega, y agrega la arista a su
		 * 		vertice correspondiente.
		 */
		void agregarArista(std::string origen, std::string destino, unsigned int costo);

		/*
		 * post: Devuelve la lista de vertices del grafo.
		 */
		Lista<Vertice*>* obtenerVertices();

		/*
		 * post: para cada elemento de la lista, utiliza el metodo "agregarArista"
		 */
		void agregarListaAristas(Lista<DestinosAristas>* lista);

		/*
		 * pre: se tiene que haber ejecutado "crearCaminosMinimos".
		 * post: Devuelve los caminos minimos.
		 */
		Lista<Arista>* obtenerCaminosMinimos();

		/*
		 * post: devuelve el vertice.
		 */
		std::string obtenerVertice(unsigned int);

		/*
		 * post: Crea los caminos minomos desde un vertice de origen.
		 */
		void crearCaminosMinimos(unsigned int origen);


		~Grafo();
};



#endif /* GRAFO_H_ */
