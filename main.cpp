
#define ARCHIVO_CULTIVOS "cultivos.txt"

#include "../src/main.h"

using namespace std;

const int TURNOS = 10;


/*

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
}*/

int main() {

    int cantidadJugadores;
    Jugador* jugadores;
    Cultivo* cultivosDisponibles;
    int cantidadCultivosDisponibles;

    //system("clear");

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
