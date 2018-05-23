#ifndef LISTA_H_
#define LISTA_H_

#include <iostream>
#include "Nodo.h"

template < typename dato >
class Lista {

private:

	int tamanio;

	Nodo<dato>* primerNodo;

public:

	Lista();

	void agregarElemento(dato datoNuevo);

	Nodo<dato>* obtenerNodo(unsigned int posicion);

	dato eliminarElemento(unsigned int posicion);

	dato mostrarElemento(unsigned int posicion);

	bool ListaVacia();

	virtual ~Lista();

};

template < typename dato >
Lista<dato>::Lista() {

	this->primerNodo = 0;
	this->tamanio = 0;
}

template < typename dato >
void Lista<dato>::agregarElemento(dato datoNuevo){

	Nodo<dato>* nuevoNodo = new Nodo<dato>;
	Nodo<dato>* nodoAux = primerNodo;

	if(this->ListaVacia()){
		nuevoNodo->modificarDato(datoNuevo);
		primerNodo = nuevoNodo;
	}
	else{
		while(nodoAux->mostrarSiguiente() != NULL)
			nodoAux = nodoAux->mostrarSiguiente();
		nodoAux->modificarSiguiente(nuevoNodo);
		nuevoNodo->modificarDato(datoNuevo);
	}
	this->tamanio++;
}

template < typename dato >
Nodo<dato>* Lista<dato>::obtenerNodo(unsigned int posicion){

	Nodo<dato>* nodoAux = this->primerNodo;

	for(unsigned int i = 0; i < posicion; i++)
		nodoAux = nodoAux->mostrarSiguiente();

	return nodoAux;
}

template < typename dato >
dato Lista<dato>::eliminarElemento(unsigned int posicion){

	posicion = posicion - 1;

	Nodo<dato>* nodoAux = obtenerNodo(posicion);

	if(posicion == 0)

		primerNodo = nodoAux->mostrarSiguiente();
	else{

		Nodo<dato>* nodoAnterior = obtenerNodo(posicion - 1);
		nodoAnterior->modificarSiguiente(nodoAux->mostrarSiguiente());
	}

	this->tamanio--;

	dato ultimoDato = nodoAux->mostrarDato();

	delete nodoAux;

	return ultimoDato;
}

template < typename dato >
dato Lista<dato>::mostrarElemento(unsigned int posicion){

	Nodo<dato>* nodoAux = obtenerNodo(posicion);

	return nodoAux->mostrarDato();
}

template < typename dato >
bool Lista<dato>::ListaVacia(){

	return (this->primerNodo == 0);
}

template < typename dato >
Lista<dato>::~Lista() {
	int i = 0;
	while(!ListaVacia())
		eliminarElemento(i + 1);
}

#endif /* SRC_LISTA_H_ */
