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

	/*	Pre : -
	 * 	Post: Devuelve una línea correspondiente a los datos del cultivo buscado
	 */
	std::string leerInformacionDeArchivo();

	/*	Pre : Recibe una línea de información del archivo
	 *	Post: Inicializa el destino con los valores de la línea actual leída (parseo)
	 */
	void guardarInformacionDeArchivo(std::string informacion);


public:

	/*	Pre : Recibe un caracter de cultivo existente en archivo
	 * 	Post: Crea el destino, inicializandolo con los valores propios de ese
	 * 		  cultivo en el archivo. En caso de que el cultivo no exista en el
	 * 		  archivo se inicializará con los valores DESTINO INVALIDO y valores nulos
	 * 		  en distancia y costoDeEnvio.
	 */
	Destino(char cultivoBuscado);

	/*	Pre : -
	 * 	Post: Devuelve el cultivo
	 */
	char mostrarCultivo();

	/*	Pre : -
	 * 	Post: Devuelve el nombre del destino del cultivo, en caso no ser valido
	 * 		  devolverá DESTINO INVALIDO
	 */
	std::string mostrarNombreDestino();

	/*	Pre : -
	 * 	Post: Devuelve la distancia en km hasta el destino
	 */
	int mostrarDistancia();

	/*	Pre : -
	 * 	Post: Devuelve el costo de envío hasta destino
	 */
	int mostrarCostoEnvio();

	virtual ~Destino();

};

#endif /* DESTINO_H_ */
