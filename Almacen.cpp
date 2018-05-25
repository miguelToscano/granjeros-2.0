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
	int capacidad = 2 * (N + M);
	this->capacidadMaxima = capacidad;
}

bool Almacen::agregarCosechaAlmacen(Cultivo cosecha){
	if(hayLugar()){
		this->ListaDeCosechas.agregarElemento(cosecha);
		return true;
	}else{
		return false;
	}
}

int Almacen::despacharCosechas(){
	cout << "hasta aca llega 1";
	this->ListaDeCosechas.iniciarCursor();
	cout << "hasta aca llega 2";
	int rentabilidad = 0;
	int ganancias = 0;
	int i = 1;
	cout << "hasta aca llega";
	while(ListaDeCosechas.avanzarCursor()){
		Cultivo cultivo = ListaDeCosechas.obtenerCursor();
		rentabilidad = cultivo.obtenerRentabilidad();
		cout << "rentabilidad =" << cultivo.obtenerRentabilidad();
		Destino DestinoCosecha(cultivo.obtenerTipo());
		cout << "costo envio" << DestinoCosecha.mostrarCostoEnvio();
		ganancias += (rentabilidad - DestinoCosecha.mostrarCostoEnvio());
		cout << i;

	}
	ListaDeCosechas.eliminarElementos();
	cout << this->ListaDeCosechas.contarElementos();
	cout << "ganancias =" << ganancias;
	return ganancias;
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

bool Almacen::hayLugar(){
	return (capacidadMaxima > obtenerCantidadDeCosechas());
}

bool Almacen::estaVacio(){

	return this->ListaDeCosechas.estaVacia();
}
Almacen::~Almacen(){
	this->ListaDeCosechas.eliminarElementos();
}

