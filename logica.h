/*
 * logica.h
 *
 *  Created on: 22/05/2018
 *      Author: algo2
 */

#ifndef SRC_LOGICA_H_
#define SRC_LOGICA_H_

#include "Jugador.h"
#include "validaciones.h"

/*
 * Constantes
 */

const int OPCION_MOSTRAR_CAMPO = 1;
const int OPCION_COMPRAR_TERRENO = 2;
const int OPCION_VENDER_TERRENO = 3;
const int OPCION_SEMBRAR_PARCELA = 4;
const int OPCION_COSECHAR = 5;
const int OPCION_COMPRAR_AGUA = 6;
const int OPCION_COMPRAR_ALMACEN = 7;
const int OPCION_FINALIZAR_TURNO = 9;
const int OPCION_SALIR = 10;

/*
 * Funciones de logica
 */

int obtenerOpcion(Jugador& jugador) {

    int opcionIngresada;
    jugador.imprimirInformacion();
    jugador.mostrarCampo();
    imprimirMenu();

    cin >> opcionIngresada;

    return opcionIngresada;
}

/*
 * post:
 */
void cosecharParcela(Jugador& jugador){

	int terreno, fila, columna;

	validarTerreno(&terreno, jugador);
	validarFila(&fila, jugador);
	validarColumna(&columna, jugador);

	jugador.cosechar(terreno, fila, columna);
}


void comprarTerreno(Jugador& jugador) {

    if (jugador.hayCreditosDisponiblesTerreno()){

    	jugador.comprarTerreno();

    	cout << "Terreno comprado!" << endl;

    }else {

    	cout << "No tiene creditos suficientes" << endl;
    }
}

void venderTerreno(Jugador& jugador) {

    int posicion;

    cout << "Ingrese la posicion del terreno a vender: ";
    cin >> posicion;

    if (posicion < 0 || posicion > jugador.obtenerCantidadTerrenos()) {

        cout << endl << "La posicion indicada no corresponde a ninguno de los terrenos disponibles" << endl;
    }

    jugador.venderTerreno(posicion);
}



void sembrarParcela(Jugador& jugador) {

    cout << "hola" << endl;
}

void comprarCapacidadAgua(Jugador& jugador){

	int capacidad;
	cout << "Ingrese cantidad de capacidad a comprar" << endl;
	cin >> capacidad;
	if(jugador.sePuedeComprarCapacidadTanque(capacidad)){
		cout << "Has aumentado en " << capacidad <<
				" la capacidad de tu tanque." << endl;
	}else{
		cout << "No posee creditos suficientes" << endl;
	}

}


void comprarCapacidadAlmacen(Jugador& jugador){
	int capacidad;
		cout << "Ingrese cantidad de capacidad a comprar" << endl;
		cin >> capacidad;
		if(jugador.sePuedeComprarCapacidadAlmacen(capacidad)){
			cout << "Has aumentado en " << capacidad <<
					" la capacidad de tu almacen." << endl;
		}else{
			cout << "No posee creditos suficientes" << endl;
		}
}

void procesarTurno(Jugador& jugador, int turno) {

    int opcion;

    system("clear");

    cout << "\nTurno: " << turno << setw(15) << "Jugador: " << jugador.obtenerNombre() << endl;



    while ((opcion = obtenerOpcion(jugador)) != OPCION_FINALIZAR_TURNO) {


        switch (opcion) {

            case OPCION_MOSTRAR_CAMPO:

                jugador.mostrarCampo();

                break;

            case OPCION_COMPRAR_TERRENO:

                comprarTerreno(jugador);

                break;

            case OPCION_VENDER_TERRENO:

                venderTerreno(jugador);

                break;

            case OPCION_SEMBRAR_PARCELA:

                sembrarParcela(jugador);

                break;

            case OPCION_COSECHAR:

            	if(jugador.hayLugarEnAlmacen()){
            		cosecharParcela(jugador);
            	}else{
            		cout << "Almacen Lleno!!" << endl;
            	}

                break;

            case OPCION_COMPRAR_AGUA:

            	comprarCapacidadAgua(jugador);

                break;

            case OPCION_COMPRAR_ALMACEN:

                comprarCapacidadAlmacen(jugador);

                break;


            default:

            	cout << "Eliga una opcion valida!!" << endl;
                break;
        }
    }
}

void mostrarGanador(Jugador* jugadores, int cantidadJugadores) {

    int indiceJugadorGanador = 0;

    for (int i = 1; i < cantidadJugadores; i++) {

        if (jugadores[i].obtenerCreditos() > jugadores[indiceJugadorGanador].obtenerCreditos()) {

            indiceJugadorGanador = i;
        }
    }

    cout << endl << "El ganador es: " << jugadores[indiceJugadorGanador].obtenerNombre() << endl;
}


#endif /* SRC_LOGICA_H_ */
