/*
 * ArbolHeap.h
 *
 *  Created on: 26/06/2018
 *      Author: algo2
 */

#ifndef ARBOLHEAP_H_
#define ARBOLHEAP_H_

#include "NodoHeap.h"
#include "Arista.h"


class ArbolHeap{
	private:

		NodoHeap* raiz;
		NodoHeap* ultimaHoja;
		unsigned int tamanio;
		unsigned int altura;

		/*
		 * pre: el nodo debe pertenecer al arbol
		 * post: Dado un nodo modificado, re ordena el arbol
		 */
		void reOrdenar(NodoHeap* nodoModificado);

		/*
		 * pre: los nodos deben pertenecer al arbol
		 * pre: cambia el dato de los nodos pasados por parametro
		 */
		void rotar(NodoHeap* padre, NodoHeap* hijo);

		/*
		 * post: rota la ultima hoja con la raiz
		 */
		void cambiarUltimoPorRaiz();

		/*
		 * pre: se tiene que haber ejecurado cambiarUltimoPorRaiz
		 * post: reacomoda el arbol
		 */
		void reacomodarRaiz();

		/*
		 * pre: el elemento debe ser una arista valida
		 * post: recorrido en profundidad preOrden, busca el elemento, indica si esta
		 * 		si lo encuentra, y es de menor costo lo modifica.
		 */
		void buscarMejoraPreOrden(NodoHeap* nodo, Arista elemento, bool *esta);

	public:

		/*
		 * post: crea un arbol vacio.
		 */
		ArbolHeap();

		/*
		 * post: indica si el arbol esta vacio
		 */
		bool estaVacio();

		/*
		 * post: se remueve la raiz y se reordena el arbol
		 */
		Arista removerRaiz();

		/*
		 * post: busca si el elemento pasado se puede mejorar en el arbol
		 */
		void buscarSiHayMejora(Arista elemento, bool *esta);

		/*
		 * post: agrega un elemento en la ultima hoja del arbol
		 */
		void agregarElemento(Arista elemento);

		/*
		 * post: devuelve el tamnio del arbol.
		 */
		unsigned int obtenerTamanio();

};


#endif /* ARBOLHEAP_H_ */
