/*
 * cultivo.cpp
 *
 *  Created on: 25/03/2018
 *      Author: Matias Figueroa
 */

#include "../src/Cultivo.h"

using namespace std;

	Cultivo::Cultivo(){
		setearTipo('V');
		setearCosto(0);
		setearTiempoCosecha(0);
		setearRentabilidad(0);
		setearTiempoDeRecuperacion(0);
	}

	void Cultivo::setearTipo(char tipoArg){
		tipo = tipoArg;
	}

	void Cultivo::setearCosto(int costoArg){
		costoSemilla = costoArg;
	}

	void Cultivo::setearTiempoCosecha(int tiempoCosechaArg){
		tiempoCosecha = tiempoCosechaArg;
	}

	void Cultivo::setearRentabilidad(int rentabilidadArg){
		rentabilidad = rentabilidadArg;
	}

	void Cultivo::setearTiempoDeRecuperacion(int tiempoDeRecuperacionArg){
		tiempoDeRecuperacion = tiempoDeRecuperacionArg;
	}

	void Cultivo :: setearConsumoDeAgua(int consumoDeAgua) {

		this->consumoDeAgua = consumoDeAgua;
		}

	int Cultivo :: obtenerConsumoDeAgua() {

		return this->consumoDeAgua;
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

	int Cultivo::obtenerTiempoDeRecuperacion(){
		return tiempoDeRecuperacion;
	}

	void Cultivo::cambiarCultivo(Cultivo* cultivoArg){
		setearTipo(cultivoArg->obtenerTipo());
		setearCosto(cultivoArg->obtenerCosto());
		setearRentabilidad(cultivoArg->obtenerRentabilidad());
		setearTiempoDeRecuperacion(cultivoArg->obtenerTiempoDeRecuperacion());
		setearTiempoCosecha(cultivoArg->obtenerTiempoCosecha());
		setearConsumoDeAgua(cultivoArg->obtenerConsumoDeAgua());
	}

	void Cultivo::reducirTiempoCosecha(){
		tiempoCosecha--;
	}

	void Cultivo::reducirTiempoDeRecuperacion(){
		tiempoDeRecuperacion--;
	}

	


