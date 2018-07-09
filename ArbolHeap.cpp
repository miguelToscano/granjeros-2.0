/*
 * ArbolHeap.cpp
 *
 *  Created on: 26/06/2018
 *      Author: algo2
 */
#include <iostream>

#include "ArbolHeap.h"

unsigned int ArbolHeap::obtenerTamanio(){
	return this->tamanio;
}

unsigned int exp(unsigned int exponencial){
	if(exponencial == 0){
		return 1;
	}else{
		exponencial = 2*exp(exponencial-1);
		return exponencial;
	}
}

void ArbolHeap::rotar(NodoHeap* nodoA, NodoHeap* nodoB){
	Arista datoAuxiliar = nodoA->obtenerDato();
	nodoA->cambiarDato(nodoB->obtenerDato());
	nodoB->cambiarDato(datoAuxiliar);
}


void ArbolHeap::cambiarUltimoPorRaiz(){
	rotar(ultimaHoja, raiz);
}


ArbolHeap::ArbolHeap(){
	this->raiz = NULL;
	this->ultimaHoja = NULL;
	this->tamanio = 0;
	this->altura = 0;
}

bool ArbolHeap::estaVacio(){
	return tamanio == 0;
}

void ArbolHeap::agregarElemento(Arista elemento){
	NodoHeap* nuevoNodo = new NodoHeap(elemento);
	NodoHeap* padre;
	if(estaVacio()){
		raiz = nuevoNodo;
		altura = 1;
	}else{
		if((tamanio%2) == 0){
			padre = ultimaHoja->obtenerPadre();
			padre->cambiarHijoDerecho(nuevoNodo);
			nuevoNodo->cambiarPadre(padre);
		}else{
			if(tamanio == 1){
				raiz->cambiarHijoIzquiero(nuevoNodo);
				nuevoNodo->cambiarPadre(raiz);
				altura++;
			}else{
				unsigned int nodosEnUltimaLinea, nodosMaximosEnNivel;
				unsigned int corte, nodosMaximosNivelAnterior;
				nodosMaximosEnNivel = exp(altura)-1;
				nodosMaximosNivelAnterior = exp(altura-1)-1;
				corte = nodosMaximosEnNivel - nodosMaximosNivelAnterior;
				int auxiliarCorte = corte;
				corte = (auxiliarCorte / 2);
				nodosEnUltimaLinea = (tamanio - nodosMaximosNivelAnterior);
				NodoHeap* auxiliar = raiz;
				if(nodosMaximosEnNivel == tamanio){
					for(unsigned int i = 1; i < altura; i++){
						padre = auxiliar->obtenerHijoIzquierdo();
						auxiliar = padre;
					}
					altura++;
				}else{
					for(unsigned int i = 1; i < altura; i++){
						padre = auxiliar;
						if(corte <= nodosEnUltimaLinea){
							nodosEnUltimaLinea = nodosEnUltimaLinea - corte;
							auxiliar = padre->obtenerHijoDerecho();
						}else{
							auxiliar = padre->obtenerHijoIzquierdo();
						}
						auxiliarCorte = corte;
						corte = auxiliarCorte / 2;
					}
				}
				padre->cambiarHijoIzquiero(nuevoNodo);
				nuevoNodo->cambiarPadre(padre);
			}

		}
	}
	tamanio++;
	ultimaHoja = nuevoNodo;
	reOrdenar(ultimaHoja);
}

void ArbolHeap::reOrdenar(NodoHeap* nodoModificado){
	bool ordenada = false;
	if(tamanio > 1){
		NodoHeap* padre = nodoModificado->obtenerPadre();
		NodoHeap* hijo = nodoModificado;
		NodoHeap* hijoMenor;
		while(padre != 0 && !ordenada){
			if(hijo->obtenerDato().esDeMenorCosto(padre->obtenerDato())){
				rotar(padre, hijo);
				hijo = padre;
				padre = hijo->obtenerPadre();
			}else{
				ordenada = true;
			}
		}
		ordenada = false;
		if(padre == 0){
			padre = hijo;
		}
		while(hijo->obtenerHijoIzquierdo() != 0 && !ordenada){
			if(hijo->obtenerHijoDerecho() == NULL){
				padre = hijo;
				hijoMenor = hijo->obtenerHijoIzquierdo();
				if(hijoMenor->obtenerDato().esDeMenorCosto(padre->obtenerDato())){
					rotar(padre, hijoMenor);
				}
				ordenada = true;

			}else{
				if(hijo->obtenerHijoIzquierdo()->obtenerDato().esDeMenorCosto(
						hijo->obtenerHijoDerecho()->obtenerDato())){
					hijoMenor = hijo->obtenerHijoIzquierdo();
				}else{
					hijoMenor = hijo->obtenerHijoDerecho();
				}
				if(hijoMenor->obtenerDato().esDeMenorCosto(padre->obtenerDato())){
					rotar(padre, hijoMenor);
					hijo = hijoMenor;
				}else{
					ordenada = true;
				}
			}
		}
	}
}

Arista ArbolHeap::removerRaiz(){

	if(!estaVacio()){
		Arista datoEliminado = raiz->obtenerDato();
		if(tamanio == 1){
			delete raiz;
			raiz = NULL;
			altura = 0;
			ultimaHoja = NULL;
			tamanio--;
		}else{
			cambiarUltimoPorRaiz();
			NodoHeap* nodoPadre = ultimaHoja->obtenerPadre();
			nodoPadre->eliminarHijo(ultimaHoja);
			delete this->ultimaHoja;
			if((tamanio%2) == 0){
				unsigned int nodosEnUltimaLinea, nodosMaximosEnNivel;
				unsigned int corte, nodosMaximosNivelAnterior;
				nodosMaximosEnNivel = exp(altura)-1;
				nodosMaximosNivelAnterior = exp(altura-1)-1;
				corte = nodosMaximosEnNivel - nodosMaximosNivelAnterior;
				int auxiliarCorte = corte;
				corte = (auxiliarCorte / 2);
				nodosEnUltimaLinea = (tamanio - nodosMaximosNivelAnterior);
				NodoHeap* padreAux = raiz;
				NodoHeap* hijoAux;
				tamanio--;
				if(nodosEnUltimaLinea == 1){
					altura--;
					for(unsigned int i = 1; i < altura-1; i++){
						hijoAux = padreAux->obtenerHijoDerecho();
						padreAux = hijoAux;
					}
				}else{
					for(unsigned int i = 1; i < altura - 1; i++){
						if((corte + 1) < nodosEnUltimaLinea){
							nodosEnUltimaLinea = nodosEnUltimaLinea - corte;
							hijoAux = padreAux->obtenerHijoDerecho();
						}else{
							hijoAux = padreAux->obtenerHijoIzquierdo();
						}
						auxiliarCorte = corte;
						corte = auxiliarCorte / 2;
						padreAux = hijoAux;
					}
				}
				ultimaHoja = padreAux->obtenerHijoDerecho();
			}else{
				tamanio--;
				ultimaHoja = nodoPadre->obtenerHijoIzquierdo();
			}

			reacomodarRaiz();
		}
		return datoEliminado;

	}else{
		throw std::string("El arbol esta vacio");
	}
}

void ArbolHeap::reacomodarRaiz(){
	NodoHeap* auxiliarPadre = raiz;
	NodoHeap* auxiliarIzq = raiz->obtenerHijoIzquierdo();
	NodoHeap* auxiliarDer = raiz->obtenerHijoDerecho();
	NodoHeap* menorHijo;
	bool encontroSuLugar = false;
	while(auxiliarIzq != NULL &&
			!encontroSuLugar){
		if(auxiliarDer == NULL){
			if(auxiliarIzq->obtenerDato().esDeMenorCosto(auxiliarPadre->obtenerDato())){
				rotar(auxiliarPadre, auxiliarIzq);
			}
			encontroSuLugar = true;
		}else{
			if(auxiliarIzq->obtenerDato().esDeMenorCosto(auxiliarDer->obtenerDato())){
				menorHijo = auxiliarIzq;
			}else{
				menorHijo = auxiliarDer;
			}
			if(auxiliarPadre->obtenerDato().esDeMenorCosto(menorHijo->obtenerDato())){
				encontroSuLugar = true;
			}else{
				rotar(auxiliarPadre, menorHijo);
				auxiliarPadre = menorHijo;
				auxiliarIzq = menorHijo->obtenerHijoIzquierdo();
				auxiliarDer = menorHijo->obtenerHijoDerecho();
			}
		}
	}
}

void ArbolHeap::buscarMejoraPreOrden(NodoHeap* nodo, Arista elemento, bool *esta){
	if(nodo != NULL){
		if(nodo->obtenerDato().obtenerDestino() == elemento.obtenerDestino()){
			*esta = true;
			if(!nodo->obtenerDato().esDeMenorCosto(elemento)){
				nodo->cambiarDato(elemento);
				reOrdenar(nodo);
			}
		}
		if(!(*esta)){
			if(nodo->obtenerHijoIzquierdo() != NULL){
				buscarMejoraPreOrden(nodo->obtenerHijoIzquierdo(), elemento, esta);
			}
			if(nodo->obtenerHijoDerecho() !=  NULL ){
				buscarMejoraPreOrden(nodo->obtenerHijoDerecho(), elemento, esta);
			}
		}

	}
}

void ArbolHeap::buscarSiHayMejora(Arista aristaNueva, bool *esta){
	buscarMejoraPreOrden(raiz, aristaNueva, esta);
}
