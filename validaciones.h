/*
 * validaciones.h
 *
 *  Created on: 22/05/2018
 *      Author: algo2
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

using namespace std;
void validarTerreno(int* terreno, Jugador& jugador){
	do{
			cout << "Ingrese el numero de terreno: " << endl;
			cin >> *terreno;
			if(!jugador.esUnTerrenoValido(*terreno)){
				cout << "Terreno Invalido" << endl;
			}
		}
		while(!jugador.esUnTerrenoValido(*terreno));
}

void validarFila(int* fila, Jugador& jugador){
	do{
			cout << "Ingrese la fila" << endl;
			cin >> *fila;
			if(!jugador.esUnaFilaValida(*fila)){
				cout << "Fila Invalida" << endl;
			}
		}
		while(!jugador.esUnaFilaValida(*fila));
}

void validarColumna(int* columna, Jugador& jugador){
	do{
			cout << "Ingrese la columna" << endl;
			cin >> *columna;
			if(!jugador.esUnaColumnaValida(*columna)){
				cout << "Columna Invalida" << endl;
			}
		}
		while(!jugador.esUnaColumnaValida(*columna));
}
#endif /* VALIDACIONES_H_ */
