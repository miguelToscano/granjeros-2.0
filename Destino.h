/*
 * Destino.h
 *
 *  Created on: 1 may. 2018
 *      Author: Tomas
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

	/*	Pre: -
	 *
	 * 	Post: Funcion auxiliar que devuelve la línea del archivo correspondiente al cultivo buscado
	 * 	en caso de que no exista en el archivo el cultivo se devuelve un STRING_IVALIDO de valor "******";
	 * 	en caso de que el cultivo esté repetido en el archivo sólo se tomará en cuenta su primera aparición.
	 */

	std::string leerInformacionDeArchivo();

	/* 	Pre: Recibe una línea leída del archivo, ya sea válido o inválido
	 *
	 * 	Post: Si se trata de un STRING_INVALIDO no se hace nada, pero si se trata de un string válido
	 * 	se inicializan los atributos con los valores correspondientes (según archivo).
	 */

	void guardarInformacionDeArchivo(std::string informacion);


public:

	/*	Constructor
	 *
	 * 	Pre: Recibe el caracter de un cultivo que tiene que existir en destinos.txt
	 *
	 * 	Post: Inicializa un destino con la distancia, nombre de destino y costo de envío
	 */

	Destino(char cultivoBuscado);

	/*	Pre: -
	 *
	 * 	Post: Devuelve el caracter del cultivo
	 */

	char mostrarCultivo();

	/* 	Pre: -
	 *
	 * 	Post: Devuelve el nombre correspondiente al destino del cultivo
	 */

	std::string mostrarNombreDestino();

	/* 	Pre: -
	 *
	 * 	Post: Devuelve la distancia a destino del cultivo
	 */

	int mostrarDistancia();

	/* 	Pre: -
	 *
	 * 	Post: Devuelve el costo de envío hasta el destino de un cultivo
	 */

	int mostrarCostoEnvio();

	virtual ~Destino();

};

#endif /* DESTINO_H_ */
