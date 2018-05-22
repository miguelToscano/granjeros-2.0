#include "Parcela.h"

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

	this->cultivoParcela = cultivoElegido;
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
	Cultivo cultivo('V');
	cultivoParcela.cambiarCultivo(&cultivo);
	desocuparParcela();
	despudrirParcela();
	noRegarParcela();
}

void Parcela::pasoDeTurno(){
	if(estaOcupada()){
		if(!estaRegada()){
			secarParcela();
			setearRecuperacion(cultivoParcela.obtenerTiempoDeRecuperacion());
		}else{
			cultivoParcela.reducirTiempoCosecha();
			noRegarParcela();
		}
		if(cultivoParcela.obtenerTiempoCosecha() < 0){
			pudrirParcela();
			setearRecuperacion(cultivoParcela.obtenerTiempoDeRecuperacion()/2);
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
	if(cultivoParcela.obtenerTipo() == VACIA){
		return VACIA;
	}else{
		if(estaDisponible()){
			return DISPONIBLE;
		}else{
			if(estaSeca()){
				return SECA;
			}
			if(estaPodrida()){
				return PODRIDA;
			}
		}
		if(estaOcupada()){
			return cultivoParcela.obtenerTipo();
		}else{
			return ERROR_CHAR;
		}
	}
}

char Parcela::infoParcela(){
	if(cultivoParcela.obtenerTiempoCosecha() == 0){
		if(estaDisponible()){
			return SIN_REGAR;
		}else{
			return COSECHAR;
		}

	}else{
		if(estaRegada()){
			return REGADA;
		}else{
			return SIN_REGAR;
		}
	}
}
