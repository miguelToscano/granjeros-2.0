#include "Parcela.h"

Parcela :: Parcela() {

	this->estadoActual = 'A';
}

char Parcela :: obtenerEstadoParcela() {

	return this->estadoActual;
}

Parcela :: ~Parcela() {

	std::cout << "hola" << std::endl;
}
