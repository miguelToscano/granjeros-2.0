/*
 * Almacen.cpp
 *
 *  Created on: 1 may. 2018
 *      Author: Tomas
 */

#include "Almacen.h"

using namespace std;

Almacen::Almacen(){
	this->cantidadCosechas = 0;
	this->capacidadMaxima = 0;
}


Almacen::Almacen(const int N, const int M){
	int capacidad = 2 * (N + M);
	for(int i = 0; i < capacidad ; i++)
		this->ListaDeCosechas.agregarElemento(ESPACIO_VACIO);
	this->cantidadCosechas = 0;
	this->capacidadMaxima = capacidad;
}

void Almacen::agregarCosechaAlmacen(Cultivo cosecha){
	if(capacidadMaxima > cantidadCosechas){
		this->ListaDeCosechas.agregarElemento(cosecha);
		this->cantidadCosechas++;
	}
}

int Almacen::despacharCosecha(Cultivo cosecha){

	int ganancias = 0;
	bool existeEnAlmacen = false;
	Destino DestinoCosecha(cosecha.obtenerTipo());

	ganancias = cosecha.obtenerRentabilidad() - DestinoCosecha.mostrarCostoEnvio();

	for(int i = 0; i < this->cantidadCosechas; i++){
		Cultivo aux = ListaDeCosechas.mostrarElemento(i);
		if(aux.obtenerTipo() == cosecha.obtenerTipo()){
			ListaDeCosechas.eliminarElemento(i);
			existeEnAlmacen = true;
		}
	}
	if(!existeEnAlmacen)
		throw string ("Cosecha inexistente en almacén");
	return ganancias;
}

void Almacen::aumentarCapacidad(unsigned int cantidadDeLugares){
	for(unsigned int i = 0; i < cantidadDeLugares; i++)
		ListaDeCosechas.agregarElemento(ESPACIO_VACIO);
	this->capacidadMaxima += cantidadDeLugares;

}

Almacen::~Almacen(){
	cout << "Almacen destruido" << endl;
}

