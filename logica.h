/*
 * logica.h
 *
 *  Created on: 22/05/2018
 *      Author: algo2
 */

#ifndef SRC_LOGICA_H_
#define SRC_LOGICA_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include <string>
#include <fstream>
#include <iomanip>

#include "../src/configuracion.h"
#include "../src/Campo.h"
#include "../src/Jugador.h"
#include "../src/Lista.h"
#include "../src/Nodo.h"

/*
 * Constantes
 */

using namespace std;

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
void imprimirMenu(){
	cout << "Seleccione una accion:" << endl
		<< "1. Mostrar campo " << endl
		<< "2. Comprar terreno" << endl
		<< "3. Vender terreno" << endl
		<< "4. Sembrar" << endl
		<< "5. Cosechar" << endl
		<< "6. Comprar capacidad de tanque" << endl
		<< "7. Comprar capacidad de almacén" << endl
		<< "8. Enviar pedido" << endl
		<< "9. Pasar turno" << endl
		<< "10. Salir" << endl;
}


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

void sembrarParcela(Jugador& jugador, Cultivo* cultivosDisponibles, int cantidadCultivosDisponibles) {

    system("clear");

    int cantidadCultivos;
    Cultivo* cultivosComprados;
    char tipo;

    cout << endl << "Cultivos disponibles: " << endl << endl;

    // Muestra los cultivos disponibles (deberia ir en una funcion)
    for (int i = 0; i < cantidadCultivosDisponibles; i++) {

        cout << endl << "Tipo: " << cultivosDisponibles[i].obtenerTipo() << endl
        << "Costo semilla: " << cultivosDisponibles[i].obtenerCosto() << endl
        << "Tiempo de cosecha: " << cultivosDisponibles[i].obtenerTiempoCosecha() << endl
        << "Rentabilidad: " << cultivosDisponibles[i].obtenerRentabilidad() << endl
        << "Tiempo de recuperacion: " << cultivosDisponibles[i].obtenerTiempoDeRecuperacion() << endl
        << "Consumo de agua: " << cultivosDisponibles[i].obtenerConsumoDeAgua() << endl;
    }

    cout << "Ingrese el tipo de cultivo que quiere comprar: ";
    cin >> tipo;

    cout << endl << "Cantidad de semillas: ";
    cin >> cantidadCultivos;

    cultivosComprados = new Cultivo[cantidadCultivos];

    int indiceCultivoSeleccionado;
    bool coincideCultivo = false;

    for (int i = 0; i < cantidadCultivosDisponibles && coincideCultivo == false; i++) {

        if (cultivosDisponibles[i].obtenerTipo() == tipo) {

            indiceCultivoSeleccionado = i;
            coincideCultivo = true;
        }
    }

    for (int i = 0; i < cantidadCultivos; i++) {

        cultivosComprados[i] = cultivosDisponibles[indiceCultivoSeleccionado];
    }

    unsigned int terreno;
    int fila;
    int columna;

    for (int i = 0; i < cantidadCultivos; i++) {

        cout << "Ingrese las coordenadas de donde quiere semprar la semilla: " << endl;
        cin >> terreno;
        cin >> fila;
        cin >> columna;

        jugador.plantarSemilla(cultivosComprados[i], terreno, fila, columna);
        cout << endl << "Semilla plantada!" << endl;
    }
}

void actualizarTerreno(Parcela** terrenoJugador, unsigned int topeFila, unsigned int topeColumnas){

	for(unsigned int i = 0; i < topeFila ; i++)
		for(unsigned int j = 0; j < topeColumnas; j++)
			terrenoJugador[i][j].pasoDeTurno();
}


void actualizarCampo(Jugador& jugador){

	Campo* campoJugador;
	Parcela** terrenoJugador;
	campoJugador = jugador.devolverCampo();

	for(int i = 0; i < campoJugador->obtenerCantidadTerrenos() ; i++){

		terrenoJugador = campoJugador->devolverTerreno(i);
		actualizarTerreno(terrenoJugador, campoJugador->obtenerFilas(), campoJugador->obtenerColumnas());
	}

}

void procesarTurno(Jugador& jugador, int turno,
		Cultivo* cultivosDisponibles, int cantidadCultivosDisponibles) {

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

            	sembrarParcela(jugador, cultivosDisponibles, cantidadCultivosDisponibles);

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
