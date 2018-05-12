/*
 * Campo.cpp
 *
 *  Created on: 11 may. 2018
 *      Author: tomas
 */

#include "Campo.h"

Campo::Campo(unsigned int N, unsigned int M){
	this->tamanio = 0;
	this->M = M;
	this->N = N;
}

void Campo::agregarTerreno(){

	Parcela** parcelaNueva;

	parcelaNueva = new Parcela*[this->N];

	for(unsigned int i = 0; i < this->M; i++){
		parcelaNueva[i] = new Parcela[this->M];
	}

	this->ListaDeTerrenos.agregarElemento(parcelaNueva);
	this->tamanio++;

}

void Campo::mostrarCampo(){

	for(unsigned int i = 0; i < this->tamanio ; i++){
		mostrarTerreno(ListaDeTerrenos.mostrarElemento(i));
	}
}

void Campo::mostrarTerreno(Parcela** terreno){

	for(unsigned int i = 0; i < N; i++){
		for(unsigned int j = 0; j < M; j++)

			std::cout << terreno[i][j].infoParcela() << " - ";
		std:: cout << std::endl;
	}

	std::cout << "-----------------------" << std::endl;
}

void Campo::eliminarTerreno(unsigned int posicion){

	Parcela** parcelaAux;

	parcelaAux = ListaDeTerrenos.eliminarElemento(posicion);

	for(unsigned int i = 0; i < N; i++){
		delete[] parcelaAux[i];
	}
	this->tamanio--;
}

int Campo::devolverTamanio(){

	return this->tamanio;
}

Campo::~Campo() {
	for(unsigned int i = 1; i < this->tamanio; i++)
		eliminarTerreno(i);
}

