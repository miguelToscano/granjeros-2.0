#ifndef PARCELA_H_
#define PARCELA_H_

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>

class Parcela {

private:
	
	char estadoActual;
	int turnosRecuperacion;
	int turnosCrecimiento;
	bool fueRegada;

public:

	Parcela();

	~Parcela();

	char obtenerEstadoParcela();
};

#endif
