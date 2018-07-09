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
#include "Lista.h"

static const char RUTA_DESTINOS[] = "destinos.txt";
static const std::string DESTINO_INEXISTENTE = "DESTINO INVALIDO";
static const std::string STRING_INVALIDO = "*****";

class Destino {

private:

	char cultivo;

	int distancia;

	int costoEnvio;

	bool elegioUnDestino;


	std::string nombreDestino;

	/*	Pre : -
	 * 	Post: Devuelve una lista correspondiente a las lineas
	 * 		con la informacion del cultivo deseado
	 */
	void leerInformacionDeArchivo(Lista<std::string>& listaLineasDestino);

	/*	Pre : Recibe una línea de información del archivo
	 *	Post: Inicializa el destino con los valores de la línea actual leída (parseo)
	 */
	bool guardarInformacionDeArchivo(Lista<std::string>& listaLineasDestino);


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

	/*
	 * post: Devuelve si se selecciono un destino para enviar.
	 */
	bool seSeleccionoUnPedido();

	virtual ~Destino();

};

#endif /* DESTINO_H_ */
