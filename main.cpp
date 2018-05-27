
#define ARCHIVO_CULTIVOS "cultivos.txt"

#include "../src/main.h"

using namespace std;

const int TURNOS = 10;

int main() {

    int cantidadJugadores;
    Jugador* jugadores = 0;
    Cultivo* cultivosDisponibles = 0;
    int cantidadCultivosDisponibles = 0;

    configurarJuego(jugadores, cantidadJugadores, cultivosDisponibles, cantidadCultivosDisponibles);
    try{
    // Empiezan a jugar
    for (int turno = 1; turno <= TURNOS; turno++) {

        for (int i = 0; i < cantidadJugadores; i++) {

            procesarTurno(jugadores[i], turno, cultivosDisponibles, cantidadCultivosDisponibles);
        }
    }

    mostrarInformacionJugadores(jugadores, cantidadJugadores);    

    mostrarGanador(jugadores, cantidadJugadores);

    }catch(string aux){
        cout << aux << endl;
    }
    delete[] cultivosDisponibles;
    delete[] jugadores;

    return 0;
}
