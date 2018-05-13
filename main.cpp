#include "main.h"

using namespace std;

const int TURNOS = 10;

const int OPCION_MOSTRAR_CAMPO = 1;
const int OPCION_COMPRAR_TERRENO = 2;
const int OPCION_SEMBRAR_CULTIVO = 3;
const int OPCION_FINALIZAR_TURNO = 4;

// Deberia ir en logica.cpp
int obtenerOpcion() {

    int opcionIngresada;

    cout << "\n1. Mostrar campo" << endl
        << "2. Comprar terreno" << endl
        << "3.Finalizar turno" << endl << endl;

    cout << "Ingrese una accion: ";
    cin >> opcionIngresada;

    return opcionIngresada;
}

void mostrarCampo(Jugador& jugador) {

    jugador.mostrarCampo();
}

void comprarTerreno(Jugador& jugador) {

    //if (jugador.hayCreditosDisponibles()) {

        jugador.comprarTerreno();
    //}

    //else {

    //    cout << endl << jugador.obtenerNombre() << " no tiene creditos suficientes para comprar un terreno" << endl;
    //}
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

                cout << endl << "Creditos antes de comprar terreno: " << jugador.obtenerCreditos() << endl;
                comprarTerreno(jugador);
                cout << endl << "Creditos despues de comprar terreno: " << jugador.obtenerCreditos() << endl;

            case OPCION_SEMBRAR_CULTIVO:

                cout << "Aca iria la logica de sembrar cultivo" << endl;

                break;

            default:

                break;
        }
    }
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

    delete[] jugadores;

    return 0;
}
