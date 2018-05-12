/*
 * Campo.h
 *
 *  Created on: 11 may. 2018
 *      Author: tomas
 */

#ifndef SRC_CAMPO_H_
#define SRC_CAMPO_H_

#include "parcela.h"
#include "Lista.h"

class Campo {

private:

	Lista <Parcela**> ListaDeTerrenos;
	unsigned int tamanio;
	unsigned int N;
	unsigned int M;

public:

	Campo(unsigned int N, unsigned int M);

	void agregarTerreno();

	void eliminarTerreno(unsigned int posicion);

	int devolverTamanio();

	virtual ~Campo();

};

#endif /* SRC_CAMPO_H_ */
