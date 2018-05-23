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
/*
Cultivo :: Cultivo(const Cultivo& cultivoArg) {

	this->tipo = cultivoArg.obtenerTipo();
	this->costoSemilla = cultivoArg.obtenerCosto();
	this->tiempoCosecha = cultivoArg.obtenerTiempoCosecha();
	this->rentabilidad = cultivoArg.obtenerRentabilidad();
	this->tiempoDeRecuperacion = cultivoArg.obtenerTiempoDeRecuperacion();
	this->consumoDeAgua = cultivoArg.obtenerConsumoDeAgua();
}*/

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
			int intAux = 0;
			string aux;

			aux = informacion.substr(2, informacion.find(','));

			istringstream buffer(aux);
			buffer >> intAux;
			setearCosto(intAux);

			size_t posicionInicial = informacion.find(',') + 2;
			size_t desplazamiento = informacion.find(',', posicionInicial) - posicionInicial;

			aux = informacion.substr(posicionInicial, desplazamiento);

			istringstream buffer2(aux);
			buffer2 >> intAux;
			setearTiempoCosecha(intAux);

			posicionInicial = posicionInicial + 2 + desplazamiento;
			desplazamiento = informacion.find(',', posicionInicial) - posicionInicial;

			aux = informacion.substr(posicionInicial, desplazamiento);

			istringstream buffer3(aux);
			buffer3 >> intAux;
			setearRentabilidad(intAux);

			posicionInicial = posicionInicial + 2 + desplazamiento;
			desplazamiento = informacion.find(',', posicionInicial) - posicionInicial;

			aux = informacion.substr(posicionInicial, desplazamiento);

			istringstream buffer4(aux);
			buffer4 >> intAux;
			setearTiempoDeRecuperacion(intAux);
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

	Cultivo& Cultivo :: setearConsumoDeAgua(int consumoDeAgua) {

		this->consumoDeAgua = consumoDeAgua;
		return *this;
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
	}

	void pasarTurno(){

	}

	void Cultivo::reducirTiempoCosecha(){
		tiempoCosecha--;
	}

	void Cultivo::reducirTiempoDeRecuperacion(){
		tiempoDeRecuperacion--;
	}

	


