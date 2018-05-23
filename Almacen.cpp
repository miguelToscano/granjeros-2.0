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

int Almacen::despacharCosecha(Cultivo cosecha){

	int ganancias = 0;
	int posicionCosecha = -1;
	Destino DestinoCosecha(cosecha.obtenerTipo());

	ganancias = cosecha.obtenerRentabilidad() - DestinoCosecha.mostrarCostoEnvio();
	for(int i = 0; i < obtenerCantidadDeCosechas(); i++){
		Cultivo aux = ListaDeCosechas.mostrarElemento(i);
		if(aux.obtenerTipo() == cosecha.obtenerTipo()){
			ListaDeCosechas.eliminarElemento(i);
		}
	}
	if(posicionCosecha == -1)
		throw string ("Cosecha NO EXISTE EN ALMACEN");
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

Almacen::~Almacen(){

}

