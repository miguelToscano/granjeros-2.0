#include "dificultad.h"

Dificultad::Dificultad(std::ifstream& archivo, int filas, int columnas){
	int multAgua = 0;
	int multCred = 0;
	int multAlmacen = 0;
	int nxm = filas*columnas;
	archivo >> multCred;
	archivo >> multAgua;
	archivo >> multAlmacen;

	this->capacidadAlmacen = multAlmacen * nxm;
	this->capacidadTanque = multAgua * nxm;
	this->creditos = multCred * nxm;
	this->filas = filas;
	this->columnas = columnas;
}
