

#define ARCHIVO_CULTIVOS "cultivos.txt"

#include <iostream>
#include <cstdlib>
#include <string>
#include <string>
#include <fstream>
#include <iomanip>
#include "Jugador.h"
#include "configuracion.h"
#include "pantalla.h"
#include "Campo.h"
#include "Lista.h"
#include "logica.h"
#include "Nodo.h"

using namespace std;

const int TURNOS = 10;




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
            //jugadores[i].finDeTurno();
        }
    }

    mostrarInformacionJugadores(jugadores, cantidadJugadores);    

    mostrarGanador(jugadores, cantidadJugadores);

    delete[] jugadores;

    return 0;
}
