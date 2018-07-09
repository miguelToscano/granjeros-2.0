/*
 * NodoHeap.cpp
 *
 *  Created on: 26/06/2018
 *      Author: algo2
 */

#include "NodoHeap.h"

NodoHeap::NodoHeap(Arista dato){
	this->dato = dato;
	this->padre = 0;
	this->hijoDerecho = 0;
	this->hijoIzquierda = 0;
}

void NodoHeap::cambiarDato(Arista dato){
	this->dato = dato;
}

void NodoHeap::cambiarHijoIzquiero(NodoHeap* nuevoHijoIzquierdo){
	this->hijoIzquierda = nuevoHijoIzquierdo;
}

void NodoHeap::cambiarHijoDerecho(NodoHeap* nuevoHijoDerecho){
	this->hijoDerecho = nuevoHijoDerecho;
}

void NodoHeap::cambiarPadre(NodoHeap* nuevoPadre){
	this->padre = nuevoPadre;
}

Arista NodoHeap::obtenerDato(){
	return this->dato;
}

NodoHeap* NodoHeap::obtenerHijoIzquierdo(){
	return this->hijoIzquierda;
}

NodoHeap* NodoHeap::obtenerHijoDerecho(){
	return this->hijoDerecho;
}

NodoHeap* NodoHeap::obtenerPadre(){
	return this->padre;
}

bool NodoHeap::eliminarHijo(NodoHeap* hijoAEliminar){
	bool respuesta = false;
	if(this->hijoIzquierda == hijoAEliminar){
		hijoIzquierda = 0;
		respuesta = true;
	}
	if(this->hijoDerecho == hijoAEliminar){
		hijoDerecho = 0;
		respuesta = true;
	}
	return respuesta;
}
