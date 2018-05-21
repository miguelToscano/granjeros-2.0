/*
 * Destino.h
 *
 *  Created on: 1 may. 2018
 *      Author: tomas
 */

#ifndef DESTINO_H_
#define DESTINO_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

static const char RUTA_DESTINOS[] = "destinos.txt";
static const std::string DESTINO_INEXISTENTE = "DESTINO INVALIDO";
static const std::string STRING_INVALIDO = "*****";

class Destino {

private:

	char cultivo;

	int distancia;

	int costoEnvio;

	std::string nombreDestino;

	std::string leerInformacionDeArchivo();

	void guardarInformacionDeArchivo(std::string informacion);


public:

	Destino(char cultivoBuscado);

	char mostrarCultivo();

	std::string mostrarNombreDestino();

	int mostrarDistancia();

	int mostrarCostoEnvio();

	virtual ~Destino();

};

#endif /* DESTINO_H_ */
