/*
 * Almacen.cpp
 *
 *  Created on: 1 may. 2018
 *      Author: tomas
 */

#include "Almacen.h"

using namespace std;

Almacen::Almacen(){
	this->capacidadMaxima = 0;
}

Almacen::Almacen(const int N, const int M){

	this->capacidadMaxima = 2 * (N + M);
}

bool Almacen::agregarCosechaAlmacen(Cultivo cosecha){

	bool fueAgregado = false;
	if(hayLugar()){

		this->ListaDeCosechas.agregarElemento(cosecha);
		fueAgregado = true;
	}
	return fueAgregado;
}

int Almacen::despacharCosecha(Cultivo cosecha){

	bool cosechaEncontrada = false;
	int posicion = 1;
	Destino destinoCosecha(cosecha.obtenerTipo());

	if( destinoCosecha.mostrarNombreDestino() == DESTINO_INEXISTENTE )
		throw string("ERROR: Semilla inexistente en destinos");

	ListaDeCosechas.iniciarCursor();
	while(ListaDeCosechas.avanzarCursor()){
		if(ListaDeCosechas.obtenerCursor().obtenerTipo() == cosecha.obtenerTipo())
			cosechaEncontrada = true;

		posicion++;
	}
	if( !cosechaEncontrada )
		throw string("ERROR: Cosecha no pertenece al almacén");

	ListaDeCosechas.eliminarElemento(posicion);
	return (cosecha.obtenerRentabilidad() - destinoCosecha.mostrarCostoEnvio());
}

void Almacen::aumentarCapacidad(unsigned int cantidadDeLugares){

	this->capacidadMaxima += cantidadDeLugares;
}

int Almacen::obtenerCantidadDeCosechas(){

	return ListaDeCosechas.obtenerTamanio();
}

int Almacen::obtenerCapacidadMaxima(){

	return capacidadMaxima;
}

Cultivo Almacen::obtenerElementoDePosicion(unsigned int posicion){
	if(posicion < 1 || posicion > this->obtenerCantidadDeCosechas())

		throw string("Posicion invalida de almacen");
	return this->ListaDeCosechas.mostrarElemento(posicion);
}

bool Almacen::hayLugar(){

	return (capacidadMaxima > obtenerCantidadDeCosechas());
}

bool Almacen::estaVacio(){

	return obtenerCantidadDeCosechas();
}

Almacen::~Almacen(){

	this->ListaDeCosechas.~Lista();
}

