/*
 * tanque de agua.cpp
 *
 *  Created on: Apr 30, 2018
 *      Author: carlos
 */


#include "../src/TanqueDeAgua.h"

TanqueDeAgua::TanqueDeAgua(){

	this->capacidadDelTanque = 0;
	this->cantidadDeAgua = 0;
}

TanqueDeAgua::TanqueDeAgua(int capacidad){

	this->capacidadDelTanque = capacidad;
	this->cantidadDeAgua = 0;
}

void TanqueDeAgua::aumentarCapacidad(int aumento){

	this->capacidadDelTanque += aumento;

}



int TanqueDeAgua::obtenerCapacidad(){
	return this->capacidadDelTanque;
}

int TanqueDeAgua::obtenerCantidadAgua(){
	return this->cantidadDeAgua;
}

bool TanqueDeAgua::disminuirAgua(int costoRiego){
	bool respuesta = false;
	if(costoRiego <= cantidadDeAgua){
		cantidadDeAgua -= costoRiego;
		respuesta = true;
	}
	return respuesta;
}




void TanqueDeAgua :: recibirAgua() {

	srand(time(NULL));
	int multiplicador = 1 + (rand() % 6);
	this->cantidadDeAgua += (multiplicador * AGUA_POR_TURNO);
}


void TanqueDeAgua::llenarTanque(int masAgua){

	srand(time(0));

	int multiplicador = (1 + rand() % (6));
	this->cantidadDeAgua += AGUA_POR_TURNO * multiplicador;

	if( this->cantidadDeAgua > this->capacidadDelTanque ){
		this->cantidadDeAgua = this->capacidadDelTanque;
	}

	cantidadDeAgua += masAgua;

}



void TanqueDeAgua :: desecharExcesoDeAgua() {

	if (this->cantidadDeAgua > this->capacidadDelTanque) {
		cantidadDeAgua = capacidadDelTanque;
	}
}
