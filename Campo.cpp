/*
 * Campo.cpp
 *
 *  Created on: 11 may. 2018
 *      Author: tomas
 */

#include "Campo.h"
#include "GranjerosBMP.h"

using namespace std;

Campo :: Campo() {

	this->columnas = 0;
	this->filas = 0;
	this->cantidadTerrenos = 0;
	this->precioTerreno = 50;
}

Campo::Campo(unsigned int filas, unsigned int columnas){
	this->cantidadTerrenos = 1;
	this->columnas = columnas;
	this->filas = filas;

	Parcela** parcelaNueva;

	parcelaNueva = new Parcela*[this->filas];

	for(unsigned int i = 0; i < this->columnas; i++){
		parcelaNueva[i] = new Parcela[this->columnas];
	}

	this->ListaDeTerrenos.agregarElemento(parcelaNueva);
	this->cantidadTerrenos++;
}

void Campo :: establecerFilas(int filas) {

	this->filas = filas;
}

void Campo :: establecerColumnas(int columnas) {

	this->columnas = columnas;
}

void Campo :: crearCampo() {

	Parcela** parcelaNueva;

	parcelaNueva = new Parcela*[this->filas];

	for(unsigned int i = 0; i < this->columnas; i++){
		parcelaNueva[i] = new Parcela[this->columnas];
	}

	this->cantidadTerrenos = 1;

	for (int i = 0; i < this->cantidadTerrenos; i++)
		this->ListaDeTerrenos.agregarElemento(parcelaNueva);
}

int Campo :: obtenerFilas() {

	return this->filas;
}

int Campo :: obtenerColumnas() {

	return this->columnas;
}

void Campo::agregarTerreno(){

	Parcela** parcelaNueva;

	parcelaNueva = new Parcela*[this->filas];

	for(unsigned int i = 0; i < this->columnas; i++){
		parcelaNueva[i] = new Parcela[this->columnas];
	}

	this->ListaDeTerrenos.agregarElemento(parcelaNueva);
	this->cantidadTerrenos++;
}

void Campo::mostrarCampo(){

	for(unsigned int i = 0; i < this->cantidadTerrenos ; i++){
		cout << endl;
		mostrarTerreno(ListaDeTerrenos.mostrarElemento(i));
	}
}

void Campo::mostrarTerreno(Parcela** terreno){

	GranjerosBMP granja;
	//granja.pintarTodoElTerreno (imagen);
}

void Campo::eliminarTerreno(unsigned int posicion){

	Parcela** parcelaAux;

	parcelaAux = ListaDeTerrenos.eliminarElemento(posicion);

	for(unsigned int i = 0; i < filas; i++){
		delete[] parcelaAux[i];
	}
	this->cantidadTerrenos--;
}

int Campo::obtenerCantidadTerrenos(){

	return this->cantidadTerrenos;
}

int Campo :: obtenerPrecioTerreno() {

	return this->precioTerreno;
}

void Campo :: actualizarPrecioTerreno() {

	float nuevoPrecioTerreno;

	nuevoPrecioTerreno = static_cast<float>(this->precioTerreno) * FACTOR_PRECIO_TERRENO;

	this->precioTerreno = static_cast<int>(nuevoPrecioTerreno);
}

Campo::~Campo() {
	for(unsigned int i = 1; i < this->cantidadTerrenos; i++)
		eliminarTerreno(i);
}
