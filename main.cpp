#include "main.h"

using namespace std;

const int TURNOS = 10;

int main() {

    int cantidadJugadores;
    Jugador* jugadores;

    system("clear");

    configurarJuego(jugadores, cantidadJugadores);

    delete[] jugadores;

    return 0;
}
