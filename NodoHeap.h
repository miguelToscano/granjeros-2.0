/*
 * NodoHeap.h
 *
 *  Created on: 26/06/2018
 *      Author: algo2
 */

#ifndef NODOHEAP_H_
#define NODOHEAP_H_

#include "Arista.h"

class NodoHeap{
	private:

		Arista dato;
		NodoHeap* hijoIzquierda;
		NodoHeap* hijoDerecho;
		NodoHeap* padre;

	public:

		/*
		 * post: crea un nodo con el dato pasado por parametro, sin hijos ni padre
		 */
		NodoHeap(Arista dato);

		void cambiarDato(Arista dato);

		/*
		 * post: cambia la direccion del nodo hijo izquierdo.
		 */
		void cambiarHijoIzquiero(NodoHeap* nuevoHijoIzquierdo);

		/*
		 * post: cambia la direccion del nodo hijo derecho
		 */
		void cambiarHijoDerecho(NodoHeap* nuevoHijoDerecho);

		/*
		 * post: cambia la direccion del nodo padre.
		 */
		void cambiarPadre(NodoHeap* nuevoPadre);

		/*
		 * post: devuelve el dato del nodo
		 */
		Arista obtenerDato();

		/*
		 * post: obtiene el puntero del nodo hijo izuierdo
		 */
		NodoHeap* obtenerHijoIzquierdo();

		/*
		 * post: obtiene el puntero del nodo hijo derecho
		 */
		NodoHeap* obtenerHijoDerecho();

		/*
		 * post: obtiene el puntero del nodo padre
		 */
		NodoHeap* obtenerPadre();

		/*
		 * post: si el puntero pasado por parametro councide con algun hijo lo elimina
		 */
		bool eliminarHijo(NodoHeap* hijoAEliminar);

};


#endif /* NODOHEAP_H_ */
