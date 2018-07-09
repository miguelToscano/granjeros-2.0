/*
 * Grafo.cpp
 *
 *  Created on: 26/06/2018
 *      Author: algo2
 */

#include "Grafo.h"

Grafo::Grafo(){

}

std::string Grafo::obtenerVertice(unsigned int ubicacion){
	return this->listaVertices.mostrarElemento(ubicacion)->obtenerNombre();
}

bool Grafo::existeVertice(std::string nombreVertice){
	Vertice verticeAuxiliar;
	bool esta;
	listaVertices.iniciarCursor();
	while(listaVertices.avanzarCursor() && !esta){
		verticeAuxiliar = *listaVertices.obtenerCursor();
		if(verticeAuxiliar.esIgual(nombreVertice)){
			esta = true;
		}
	}
	return esta;
}

void Grafo::agregarListaAristas(Lista<DestinosAristas>* lista){
	lista->iniciarCursor();
	while(lista->avanzarCursor()){
		this->agregarArista(lista->obtenerCursor().obtenerOrigen(),
				lista->obtenerCursor().obtenerDestino(),
				lista->obtenerCursor().obtenerCosto());
	}
}

int Grafo::buscarUbicacionVertice(std::string nombre, bool* esta){
	unsigned int ubicacion = 0;
	Vertice* verticeAuxiliar;
	listaVertices.iniciarCursor();
	while(listaVertices.avanzarCursor() && !*esta){
			verticeAuxiliar = listaVertices.obtenerCursor();
			if(verticeAuxiliar->esIgual(nombre)){
				*esta = true;
			}
			ubicacion++;
		}
	if(!*esta){
		ubicacion = 0;
	}
	return ubicacion;
}


void Grafo::agregarArista(std::string origen, std::string destino,unsigned int costo){
	bool estaOrigen = false;
	bool estaDestino = false;
	unsigned int ubicacionOrigen = buscarUbicacionVertice(origen, &estaOrigen);
	unsigned int ubicacionDestino = buscarUbicacionVertice(destino, &estaDestino);
	if(!estaOrigen){
		Vertice vertice(origen);
		agregarVertice(vertice);
		ubicacionOrigen = listaVertices.contarElementos();
	}
	if(!estaDestino){
		Vertice vertice(destino);
		agregarVertice(vertice);
		ubicacionDestino = listaVertices.contarElementos();
	}
	Arista nuevaArista(ubicacionDestino, costo);
	listaVertices.mostrarElemento(ubicacionOrigen)->agregarArista(nuevaArista);
}

void Grafo::agregarVertice(Vertice nuevoVertice){
	Vertice* pVertice = new Vertice(nuevoVertice);
	this->listaVertices.agregarElemento(pVertice);
}

void Grafo::marcarNoVisitados(){
	listaVertices.iniciarCursor();
	while(listaVertices.avanzarCursor()){
		listaVertices.obtenerCursor()->noVisitado();
	}
}



void Grafo::crearCaminosMinimos(unsigned int origen){
	int auxiliar = 0;
	if(origen <= listaVertices.contarElementos()){
		marcarNoVisitados();
		Vertice* verticeOrigen = listaVertices.mostrarElemento(origen);
		verticeOrigen->Visitado();
		verticeOrigen->obtenerAristas()->iniciarCursor();
		ArbolHeap monticulo;
		verticeOrigen->obtenerAristas()->iniciarCursor();
		while(verticeOrigen->obtenerAristas()->avanzarCursor()){
			Arista arista = verticeOrigen->obtenerAristas()->obtenerCursor();
			monticulo.agregarElemento(arista);
		}
		while(!monticulo.estaVacio()){
			unsigned int costoParcial = 0;
			Arista aristaRemovida = monticulo.removerRaiz();
			caminosMinimos.agregarElemento(aristaRemovida);
			costoParcial = aristaRemovida.obtenerCosto();
			auxiliar = aristaRemovida.obtenerDestino();
			Vertice* verticePuente = listaVertices.mostrarElemento(auxiliar);
			verticePuente->Visitado();
			verticePuente->obtenerAristas()->iniciarCursor();
			while(verticePuente->obtenerAristas()->avanzarCursor()){
				Arista aristaAuxiliar = verticePuente->obtenerAristas()->obtenerCursor();
				Arista aristaAgregar = verticePuente->obtenerAristas()->obtenerCursor();
				costoParcial = costoParcial + aristaAuxiliar.obtenerCosto();
				aristaAuxiliar.cambiarCosto(costoParcial);
				if(!listaVertices.mostrarElemento(
						aristaAuxiliar.obtenerDestino())->fueVisitado()){
					bool esta = false;
					monticulo.buscarSiHayMejora(aristaAuxiliar, &esta);
					if(!esta){
						monticulo.agregarElemento(aristaAgregar);
					}
				}
			}
		}
	}
}

Lista<Arista>* Grafo::obtenerCaminosMinimos(){
	return &this->caminosMinimos;
}

Lista<Vertice*>* Grafo::obtenerVertices(){
	return &this->listaVertices;
}

Grafo::~Grafo(){
	listaVertices.iniciarCursor();
	while(listaVertices.avanzarCursor()){
		delete listaVertices.obtenerCursor();
	}
	listaVertices.~Lista();
	caminosMinimos.~Lista();
}
