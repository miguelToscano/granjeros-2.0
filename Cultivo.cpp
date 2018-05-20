/*
 * cultivo.cpp
 *
 *  Created on: 25/03/2018
 *      Author: Matias Figueroa
 */

#include "Cultivo.h"

using namespace std;

Cultivo::Cultivo(){
	setearTipo('V');
	setearCosto(0);
	setearTiempoCosecha(0);
	setearRentabilidad(0);
	setearTiempoDeRecuperacion(0);
}

Cultivo::Cultivo(char tipoParametro){
	ifstream archivo(RUTA_CULTIVOS);
	char caracterLeido;

	if(!archivo.is_open())
		throw string("APERTURA DE ARCHIVO FALLIDA");

	while(!archivo.eof()){
		caracterLeido = (char) archivo.get();
		if(caracterLeido == tipoParametro){

			string informacion;
			getline(archivo, informacion);

			string aux;

			aux = informacion.substr(2, informacion.find(','));

			istringstream buffer(aux);
			buffer >> this->costoSemilla;

			size_t posicionInicial = informacion.find(',') + 2;
			size_t desplazamiento = informacion.find(',', posicionInicial) - posicionInicial;

			aux = informacion.substr(posicionInicial, desplazamiento);

			istringstream buffer2(aux);
			buffer2 >> this->tiempoCosecha;

			posicionInicial = posicionInicial + 2 + desplazamiento;
			desplazamiento = informacion.find(',', posicionInicial) - posicionInicial;

			aux = informacion.substr(posicionInicial, desplazamiento);

			istringstream buffer3(aux);
			buffer3 >> this->rentabilidad;

			posicionInicial = posicionInicial + 2 + desplazamiento;
			desplazamiento = informacion.find(',', posicionInicial) - posicionInicial;

			aux = informacion.substr(posicionInicial, desplazamiento);

			istringstream buffer4(aux);
			buffer4 >> this->tiempoDeRecuperacion;
		}

	}
	archivo.close();
}

	Cultivo &Cultivo::setearTipo(char tipoArg){
		tipo = tipoArg;
		return *this;
	}

	Cultivo &Cultivo::setearCosto(int costoArg){
		costoSemilla = costoArg;
		return *this;
	}

	Cultivo &Cultivo::setearTiempoCosecha(int tiempoCosechaArg){
		tiempoCosecha = tiempoCosechaArg;
		return *this;
	}

	Cultivo &Cultivo::setearRentabilidad(int rentabilidadArg){
		rentabilidad = rentabilidadArg;
		return *this;
	}

	Cultivo &Cultivo::setearTiempoDeRecuperacion(int tiempoDeRecuperacionArg){
		tiempoDeRecuperacion = tiempoDeRecuperacionArg;
		return *this;
	}

	char Cultivo::obtenerTipo(){
		return tipo;
	}

	int Cultivo::obtenerCosto(){
		return costoSemilla;
	}

	int Cultivo::obtenerTiempoCosecha(){
		return tiempoCosecha;
	}

	int Cultivo::obtenerRentabilidad(){
		return rentabilidad;
	}

	int Cultivo::obtenerTIempoDeRecuperacion(){
		return tiempoDeRecuperacion;
	}

	void Cultivo::cambiarCultivo(Cultivo* cultivoArg){
		setearTipo(cultivoArg->obtenerTipo());
		setearCosto(cultivoArg->obtenerCosto());
		setearRentabilidad(cultivoArg->obtenerRentabilidad());
		setearTiempoDeRecuperacion(cultivoArg->obtenerTIempoDeRecuperacion());
		setearTiempoCosecha(cultivoArg->obtenerTiempoCosecha());
	}

	void pasarTurno(){

	}

	void Cultivo::reducirTiempoCosecha(){
		tiempoCosecha--;
	}

	void Cultivo::reducirTIempoDeRecuperacion(){
		tiempoDeRecuperacion--;
	}




