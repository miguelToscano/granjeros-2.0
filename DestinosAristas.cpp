#include "DestinosAristas.h"

DestinosAristas:: DestinosAristas (){

	this-> origen =  "";
	this-> destino = "";
	this-> costo = 0;
	this-> tipoCultivo = ' ';

}

string DestinosAristas:: obtenerOrigen (){

	return this-> origen;
}

string DestinosAristas:: obtenerDestino(){

	return this-> destino;
}

unsigned int DestinosAristas:: obtenerCosto (){

	return this-> costo;
}

char DestinosAristas:: obtenerTipoCultivo (){

	return this-> tipoCultivo;
}


void DestinosAristas:: setearOrigen (string origenArchivo){

	this->origen = origenArchivo;
}

void DestinosAristas:: setearDestino (string destinoArchivo){

	this-> destino = destinoArchivo;
}

void DestinosAristas:: setearCosto (unsigned int costoArchivo){

	this-> costo = costoArchivo;
}

void DestinosAristas:: setearTipoCultivo (char tipoCultivoArchivo){

	this-> tipoCultivo = tipoCultivoArchivo;
}
