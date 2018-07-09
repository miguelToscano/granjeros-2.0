/*
 * Almacen.cpp
 *
 *  Created on: 1 may. 2018
 *      Author: tomas
 */

#include "Almacen.h"

using namespace std;

Almacen::Almacen(){

	this->ListaDeCosechas = new Lista<Cultivo>;
	this->capacidadMaxima = 0;
}

Almacen::Almacen(const int N, const int M){

	this->ListaDeCosechas = new Lista<Cultivo>;
	this->capacidadMaxima = 2 * (N + M);
}

bool Almacen::agregarCosechaAlmacen(Cultivo cosecha){

	bool fueAgregado = false;
	if(hayLugar()){

		this->ListaDeCosechas->agregarElemento(cosecha);
		fueAgregado = true;
	}
	return fueAgregado;
}

void Almacen::eliminarCosecha(int posAlmacen){

	ListaDeCosechas->eliminarElemento(posAlmacen);
}

int Almacen::despacharCosecha(Cultivo cosecha, int posAlmacen){

	bool cosechaEncontrada = false;
	int respuesta = 0;
	int posicion = 1;
	Destino destinoCosecha(cosecha.obtenerTipo());

	if(destinoCosecha.seSeleccionoUnPedido()){
		ListaDeCosechas->eliminarElemento(posAlmacen);
		respuesta = cosecha.obtenerRentabilidad() - destinoCosecha.mostrarCostoEnvio();
		cout << "Se han agregado " << respuesta << " a sus creditos" << endl;

		cout << "Su cultivo ha sido enviado" << endl;
	}

	return respuesta;
}

void Almacen::aumentarCapacidad(unsigned int cantidadDeLugares){

	this->capacidadMaxima += cantidadDeLugares;
}

int Almacen::obtenerCantidadDeCosechas(){

	return ListaDeCosechas->obtenerTamanio();
}

int Almacen::obtenerCapacidadMaxima(){

	return capacidadMaxima;
}

Cultivo Almacen::obtenerElementoDePosicion(unsigned int posicion){

	if(posicion < 1 || posicion > (unsigned int)this->obtenerCantidadDeCosechas())
		throw string("Posicion invalida de almacen");

	return this->ListaDeCosechas->mostrarElemento(posicion);
}

bool Almacen::hayLugar(){

	return (capacidadMaxima > obtenerCantidadDeCosechas());
}

bool Almacen::estaVacio(){

	return obtenerCantidadDeCosechas() == 0;
}

Almacen::~Almacen(){

	delete this->ListaDeCosechas;
}

