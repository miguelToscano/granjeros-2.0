#include "main.h"

using namespace std;

int main() {

    int cantidadJugadores = 0;
    Jugador* jugadores = NULL;
    dificultad nivelElegido = NO_ASIGNADA;

    ingresarCantidadJugadores(cantidadJugadores);
    crearArregloJugadores(jugadores, cantidadJugadores);
    ingresarNombres(jugadores, cantidadJugadores);
    elegirDificultad(nivelElegido);
    cargarAtributosIniciales(jugadores, cantidadJugadores, nivelElegido);

    // Para ver que onda
    mostrarInformacionJugadores(jugadores, cantidadJugadores);

    /*

    Y BUE ACA HABRIA QUE HACER LO QUE TIENE QUE PASAR EN CADA
    TURNO

    */

    delete[] jugadores;

    return 0;
}
