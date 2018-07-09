/*
 * Campo.cpp
 *
 *  Created on: 11 may. 2018
 *      Author: tomas
 */

#include "../src/Campo.h"

using namespace std;

Campo :: Campo() {

	this->columnas = 0;
	this->filas = 0;
	this->cantidadTerrenos = 0;
	this->precioTerreno = 1;
}

Campo::Campo(unsigned int filas, unsigned int columnas){

	this->cantidadTerrenos = 1;
	this->columnas = columnas;
	this->filas = filas;
	this->precioTerreno = 0; //modificar despues
	Parcela** parcelaNueva;

	parcelaNueva = new Parcela*[this->filas];

	for(unsigned int i = 0; i < this->columnas; i++){
		parcelaNueva[i] = new Parcela[this->columnas];
	}

	this->ListaDeTerrenos.agregarElemento(parcelaNueva);
	this->cantidadTerrenos++;
}

Parcela** Campo::devolverTerreno(unsigned int posicion){

	return this->ListaDeTerrenos.mostrarElemento(posicion);
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

	for(int i = 1; i <= this->cantidadTerrenos ; i++){
		cout << endl;
		mostrarTerreno(ListaDeTerrenos.mostrarElemento(i));
	}
}

void Campo::mostrarTerreno(Parcela** terreno){

	for(unsigned int i = 0; i < filas; i++){
		for(unsigned int j = 0; j < columnas; j++){

			std::cout << terreno[i][j].cultivoParcela.obtenerTipo();
			terreno[i][j].infoParcela();
			if(terreno[i][j].estaRegada()){
				std::cout << "*";
			}
			cout << "(r" << terreno[i][j].obtenerRecuperacion()
					<< "c" << terreno[i][j].cultivoParcela.obtenerTiempoCosecha() << ")";
			std::cout << " - ";
		}
		std:: cout << std::endl;

	}

	std::cout << "-----------------------" << std::endl;
}

void Campo::eliminarTerreno(unsigned int posicion){

	for(int fila = 0; fila < obtenerFilas(); fila++){
		delete[] obtenerPacela(posicion, fila, 0);
	}
	delete[] ListaDeTerrenos.mostrarElemento(posicion);
	ListaDeTerrenos.eliminarElemento(posicion);

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

Nodo<Parcela**>* Campo :: obtenerTerreno(unsigned int posicion) {

	return this->ListaDeTerrenos.obtenerPunteroNodo(posicion);
}

Parcela* Campo::obtenerPacela(int terreno, int fila, int columna){
	Parcela** hectarea = ListaDeTerrenos.mostrarElemento(terreno);
	return &hectarea[fila][columna];
}

Campo::~Campo() {
	if(!this->ListaDeTerrenos.estaVacia()){
			while(!this->ListaDeTerrenos.estaVacia()){
			this->eliminarTerreno(this->ListaDeTerrenos.contarElementos());
	}

}}


