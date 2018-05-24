
#define ARCHIVO_CULTIVOS "cultivos.txt"

#include "../src/main.h"

using namespace std;

const int TURNOS = 10;


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
