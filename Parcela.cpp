#include "../src/Parcela.h"

Parcela::Parcela(){
	disponible = true;
	Cultivo cultivo;
	cultivoParcela.cambiarCultivo(&cultivo);
	recuperacion = 0;
	ocupada = false;
	regada = false;
	podrida = false;
	seca = false;
}

void Parcela :: establecerCultivo(Cultivo& cultivoElegido) {

	this->cultivoParcela.cambiarCultivo(&cultivoElegido);
}

bool Parcela::estaDisponible(){
	return disponible;
}

void Parcela::parcelaDisponible(){
	disponible = true;
}

void Parcela::bloquearParcela(){
	disponible = false;
}

Parcela &Parcela::setearRecuperacion(int recuperacionArg){
	recuperacion = recuperacionArg;
	return *this;
}

int Parcela::obtenerRecuperacion(){
	return recuperacion;
}

void Parcela::reducirRecuperacion(){
	recuperacion--;
}

void Parcela::copiarParcela(Parcela* parcelaArg){
	setearRecuperacion(parcelaArg->obtenerRecuperacion());
}

bool Parcela::estaSeca(){
	return seca;
}


bool Parcela::estaRegada(){
	return regada;
}

bool Parcela::estaPodrida(){
	return podrida;
}

bool Parcela::estaOcupada(){
	return ocupada;
}

void Parcela::ocuparParcela(){
	ocupada = true;
}

void Parcela::desocuparParcela(){
	ocupada = false;
}

void Parcela::pudrirParcela(){
	podrida = true;
	desocuparParcela();
}

void Parcela::despudrirParcela(){
	podrida = false;
}

void Parcela::regarParcela(){
	regada = true;
}

void Parcela::noRegarParcela(){
	regada = false;
}

void Parcela::secarParcela(){
	seca = true;
	desocuparParcela();
}

void Parcela::desSecarParcela(){
	seca = false;
}

void Parcela::liberarParcela(){
	setearRecuperacion(cultivoParcela.obtenerTiempoDeRecuperacion());
	Cultivo cultivo;
	cultivo.setearTipo('V');
	cultivoParcela.cambiarCultivo(&cultivo);
	desocuparParcela();
	despudrirParcela();
	noRegarParcela();
}

void Parcela::pasoDeTurno(){
	if(estaOcupada()){
		if(!estaRegada()){
			liberarParcela();
			bloquearParcela();
			cultivoParcela.setearTipo('S');
		}else{
			cultivoParcela.reducirTiempoCosecha();
			noRegarParcela();
		}
		if(cultivoParcela.obtenerTiempoCosecha() < 0){
			liberarParcela();
			setearRecuperacion(obtenerRecuperacion()/2);
			pudrirParcela();
			cultivoParcela.setearTipo('P');
		}
	}else{
		if(obtenerRecuperacion() > 0){
			reducirRecuperacion();
		}
		if(obtenerRecuperacion() == 0){
			disponible = true;
		}

	}
}

char Parcela::imagenRepresentativa(){
	char respuesta = ' ';
	if(cultivoParcela.obtenerTipo() == VACIA){
		respuesta = VACIA;
	}else{
		if(estaDisponible()){
			respuesta = DISPONIBLE;
		}else{
			if(estaSeca()){
				respuesta = SECA;
			}
			if(estaPodrida()){
				respuesta = PODRIDA;
			}
		}
		if(estaOcupada()){
			respuesta = cultivoParcela.obtenerTipo();
		}else{
			respuesta = ERROR_CHAR;
		}
	}
	return respuesta;
}

char Parcela::infoParcela(){

	char respuesta = ' ';
	if(cultivoParcela.obtenerTiempoCosecha() == 0){
		if(estaOcupada()){
			respuesta = COSECHAR;
		}

	}else{
		if(estaRegada()){
			respuesta = REGADA;
		}else{
			respuesta = SIN_REGAR;
		}
	}

	return respuesta;
}

bool Parcela::sePuedeCosechar(){
	return (infoParcela() == COSECHAR);
}

Cultivo Parcela::cosecharParcela(){
	Cultivo cultivoParaAlmacenar;
	liberarParcela();
	return cultivoParaAlmacenar;
}

void Parcela::sembrar(){
	ocuparParcela();
	bloquearParcela();
}

int Parcela::obtenerConsumoDeAgua(){
	return this->cultivoParcela.obtenerConsumoDeAgua();
}
