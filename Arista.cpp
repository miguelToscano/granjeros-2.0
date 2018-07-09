/*
 * Arista.cpp
 *
 *  Created on: 26/06/2018
 *      Author: algo2
 */

#include "Arista.h"

Arista::Arista(){
	destino = 0;
	costo = 0;
}

Arista::Arista(unsigned int destino,unsigned int costo){
	this->destino = destino;
	this->costo = costo;
}

unsigned int Arista::obtenerDestino(){
	return destino;
}

unsigned int Arista::obtenerCosto(){
	return costo;
}

bool Arista::esIgual(Arista otraArista){
	return this->destino == otraArista.destino;
}

bool Arista::esDeMenorCosto(Arista otraArista){
	return this->costo < otraArista.obtenerCosto();
}

void Arista::cambiarCosto(unsigned int costo){
	this->costo = costo;
}
