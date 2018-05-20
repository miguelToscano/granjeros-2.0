#include "main.h"

#define ARCHIVO_CULTIVOS "cultivos.txt"

using namespace std;

const int TURNOS = 10;

const int OPCION_MOSTRAR_CAMPO = 1;
const int OPCION_COMPRAR_TERRENO = 2;
const int OPCION_VENDER_TERRENO = 3;
const int OPCION_FINALIZAR_TURNO = 5;
const int OPCION_SEMBRAR_PARCELA = 4;

// Deberia ir en logica.cpp
int obtenerOpcion() {

    int opcionIngresada;

    cout << "\n1. Mostrar campo" << endl
        << "2. Comprar terreno" << endl
        << "3. Vender terreno" << endl
        << "4. Sembrar parcela" << endl
        << "5. Finalizar turno" << endl << endl;

    cout << "Ingrese una opcion: ";
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

// Deberia ir en logica.cpp
void procesarTurno(Jugador& jugador, int turno) {

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

                sembrarParcela(jugador);

                break;    

            default:

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

int main() {

    int cantidadJugadores;
    Jugador* jugadores;

    system("clear");

    configurarJuego(jugadores, cantidadJugadores);

    // Esta funcion es opcional, por ahora esta aca para ver si anda bien la configuracion
    mostrarInformacionJugadores(jugadores, cantidadJugadores);

    // Empiezan a jugar
    for (int turno = 1; turno <= TURNOS; turno++) {

        for (int i = 0; i < cantidadJugadores; i++) {

            procesarTurno(jugadores[i], turno);
        }
    }

    mostrarInformacionJugadores(jugadores, cantidadJugadores);    

    mostrarGanador(jugadores, cantidadJugadores);

    delete[] jugadores;

    return 0;
}
