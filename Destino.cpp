/*
 * Destino.cpp
 *
 *  Created on: 1 may. 2018
 *      Author: tomas
 */

#include "Destino.h"

using namespace std;

Destino::Destino(char cultivoBuscado){
	string informacion;
	this->costoEnvio = 0;
	this->cultivo = cultivoBuscado;
	this->distancia = 0;
	this->nombreDestino = DESTINO_INEXISTENTE;
	informacion = leerInformacionDeArchivo();
	guardarInformacionDeArchivo(informacion);
}

string Destino::leerInformacionDeArchivo(){
	string lineaLeida;
	bool encontrado = false;
	ifstream archivo(RUTA_DESTINOS);

	if(!archivo.is_open())
		throw string("ERROR APERTURA DE ARCHIVO");
	while(!archivo.eof() && !encontrado){

		getline(archivo, lineaLeida);
		size_t tamanio = lineaLeida.size();
		if(lineaLeida[tamanio - 1] == this->cultivo){

			encontrado = true;
		}
	}

	archivo.close();

	if(encontrado)
		return lineaLeida;
	else
		return STRING_INVALIDO;

}

void Destino::guardarInformacionDeArchivo(const string informacion){
	if(informacion != STRING_INVALIDO ){

		string aux;

		this->nombreDestino = informacion.substr(0, informacion.find(','));

		size_t posicionInicial = informacion.find(',') + 2;
		size_t desplazamiento = informacion.find(',', posicionInicial) - posicionInicial;

		aux = informacion.substr(posicionInicial, desplazamiento);

		istringstream buffer(aux);
		buffer >> this->distancia;

		posicionInicial = posicionInicial + 2 + desplazamiento;
		desplazamiento = informacion.find(',', posicionInicial) - posicionInicial;

		aux = informacion.substr(posicionInicial, desplazamiento);

		istringstream buffer2(aux);
		buffer2 >> this->costoEnvio;
	}
}

char Destino::mostrarCultivo(){
	return this->cultivo;
}

string Destino::mostrarNombreDestino(){

	return this->nombreDestino;
}

int Destino::mostrarDistancia(){

	return this->distancia;
}

int Destino::mostrarCostoEnvio(){

	return this->costoEnvio;
}

Destino::~Destino() {
	// TODO Auto-generated destructor stub
}

