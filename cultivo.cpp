/*
 * cultivo.cpp
 *
 *  Created on: 25/03/2018
 *      Author: Matias Figueroa
 */

#include "cultivo.h"

Cultivo::Cultivo(){
	setearTipo('V');
	setearCosto(0);
	setearTiempoCosecha(0);
	setearRentabilidad(0);
	setearTiempoDeRecuperacion(0);
}

Cultivo::Cultivo(char tipoParametro){
	/*Aca agregar un constructor que segun el char que nos dan
	 * leemos el archivo y le asignamos las propiedades correspondientes
	 *
	 * Ej:
	 * 	segun los parametros que leemos.
		setearCosto(1);
		setearTiempoCosecha(2);
		setearRentabilidad(10);
		setearTiempoDeRecuperacion(1);

	 */

	}

	Cultivo &Cultivo::setearTipo(char tipoArg){
		tipo = tipoArg;
		return *this;
	}

	Cultivo &Cultivo::setearCostoRiego(int costoArg){
		costoRiego = costoArg;
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

	int Cultivo::obtenerCostoRiego(){
		return costoRiego;
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




