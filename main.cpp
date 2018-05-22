#define ARCHIVO_CULTIVOS "cultivos.txt"

#include <iostream>
#include <cstdlib>
#include <string>
#include <string>
#include <fstream>
#include <iomanip>
#include "Jugador.h"
#include "Configuracion.h"
#include "Pantalla.h"
#include "Campo.h"
#include "Lista.h"
#include "Nodo.h"

using namespace std;

const int TURNOS = 10;

const int OPCION_MOSTRAR_CAMPO = 1;
const int OPCION_COMPRAR_TERRENO = 2;
const int OPCION_VENDER_TERRENO = 3;
const int OPCION_COSECHAR = 5;
const int OPCION_COMPRAR_AGUA = 6;
const int OPCION_SEMBRAR_PARCELA = 4;
const int OPCION_FINALIZAR_TURNO = 9;
const int OPCION_SALIR = 10;

// Deberia ir en logica.cpp
int obtenerOpcion() {

    int opcionIngresada;

    imprimirMenu();
    cin >> opcionIngresada;

    return opcionIngresada;
}

void mostrarCampo(Jugador& jugador) {

    jugador.mostrarCampo();
}

void comprarTerreno(Jugador& jugador) {

    if (jugador.hayCreditosDisponiblesTerreno() == false) {

        cout << "No tiene creditos suficientes" << endl;
    }

    else {

        jugador.comprarTerreno();
        cout << "Terreno comprado!" << endl;
    }
}

void venderTerreno(Jugador& jugador) {

    int posicion;

    cout << "Ingrese la posicion del terreno a vender: ";
    cin >> posicion;

    if (posicion < 0 || posicion > jugador.obtenerCantidadTerrenos()) {

        cout << endl << "La posicion indicada no corresponde a ninguno de los terrenos disponibles" << endl;
    }

    else {

        jugador.venderTerreno(posicion);
        cout << "Terreno vendido" << endl;
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

	for(unsigned int i = 0; i < campoJugador->obtenerCantidadTerrenos() ; i++){

		terrenoJugador = campoJugador->devolverTerreno(i);
		actualizarTerreno(terrenoJugador, campoJugador->obtenerFilas(), campoJugador->obtenerColumnas());
	}

}

// Deberia ir en logica.cpp
void procesarTurno(Jugador& jugador, int turno, Cultivo* cultivosDisponibles, int cantidadCultivosDisponibles) {

    int opcion;

    system("clear");

    cout << "\nTurno: " << turno << setw(15) << "Jugador: " << jugador.obtenerNombre() << endl;

    while ((opcion = obtenerOpcion()) != OPCION_FINALIZAR_TURNO) {

        switch (opcion) {

            case OPCION_MOSTRAR_CAMPO:

                mostrarCampo(jugador);
                
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

            default:

                break;
        }

		actualizarCampo(jugador);  // Función cabeza de termo, coloquialmente llamado.

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

int main() {

    int cantidadJugadores;
    Jugador* jugadores;
    Cultivo* cultivosDisponibles;
    int cantidadCultivosDisponibles;

    system("clear");

    configurarJuego(jugadores, cantidadJugadores, cultivosDisponibles, cantidadCultivosDisponibles);

    // Empiezan a jugar
    for (int turno = 1; turno <= TURNOS; turno++) {

        for (int i = 0; i < cantidadJugadores; i++) {

            procesarTurno(jugadores[i], turno, cultivosDisponibles, cantidadCultivosDisponibles);
        }
    }

    mostrarInformacionJugadores(jugadores, cantidadJugadores);    

    mostrarGanador(jugadores, cantidadJugadores);

    delete[] jugadores;

    return 0;
}
