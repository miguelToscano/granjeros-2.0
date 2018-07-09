/*
 * Vertice.cpp
 *
 *  Created on: 26/06/2018
 *      Author: algo2
 */

#include "Vertice.h"

Vertice::Vertice(){
	visitado = false;
}

Vertice::Vertice(std::string nombre){
	this->nombre = nombre;
	visitado = false;
}

std::string Vertice::obtenerNombre(){
	return nombre;
}

Lista<Arista>* Vertice::obtenerAristas(){
	return &listaAdyacencia;
}

void Vertice::agregarArista(Arista arista){
	if(!exiteArista(arista)){
		listaAdyacencia.agregarElemento(arista);
	}
}

bool Vertice::esIgual(std::string verticeNombre){
	return this->nombre == verticeNombre;
}

bool Vertice::exiteArista(Arista arista){
	bool esta = false;
	listaAdyacencia.iniciarCursor();
	while(listaAdyacencia.avanzarCursor() && !esta){
		Arista aristaObj = listaAdyacencia.obtenerCursor();
		if(aristaObj.esIgual(arista)){
			esta = true;
		}
	}
	return esta;
}

bool Vertice::fueVisitado(){
	return this->visitado;
}

void Vertice::noVisitado(){
	visitado = false;
}

void Vertice::Visitado(){
	visitado = true;
}

Vertice::~Vertice(){
	listaAdyacencia.~Lista();
}
