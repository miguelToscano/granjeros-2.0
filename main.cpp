#include <iostream>
#include <cstdlib>
#include <string>
#include <string>
#include <fstream>
#include <iomanip>
#include "jugador.h"

using namespace std;

typedef enum {NO_ASIGNADA = 0, FACIL = 1, MEDIA = 2, DIFICIL = 3} dificultad;

const int DIFICULTADES = 3;
const int DIFICULTAD_FACIL = 1;
const int DIFICULTAD_MEDIA = 2;
const int DIFICULTAD_DIFICIL = 3;

const string ARCHIVO_FACIL = "dificultadFacil.txt";
const string ARCHIVO_MEDIA = "dificultadMedia.txt";
const string ARCHIVO_DIFICIL = "dificultadDificil.txt";

void ingresarCantidadJugadores(int& cantidadJugadores) {

    cout << "Ingrese la cantidad de jugadores: ";
    cin >> cantidadJugadores;
    cin.clear();
}

void crearArregloJugadores(Jugador*& jugadores, int cantidad) {

    jugadores = new Jugador[cantidad];

    if (jugadores == NULL) {

        throw string("No se pudo alocar la memoria pedida");
    }
}

void ingresarNombres(Jugador* jugadores, int cantidad) {

    string nombre;

    for (int i = 1; i <= cantidad; i++) {

        cout << "Jugador " << i << ": ";
        cin >> nombre;
        jugadores[i-1].establecerNombre(nombre);
    }
}

void elegirDificultad(dificultad& nivelElegido) {

    if (nivelElegido != NO_ASIGNADA) {

        throw string("Dificultad ya elegida");
    }

    cout << "\nIngrese la dificultad del juego, mientras mas dificil,"
        "menos seran los recursos con los que arranca cada jugador"
        << endl << "1. Facil" << endl << "2. Media" << endl
        << "3. Dificil" << endl;

        int dificultadIngresada = 0;

    do {

        static dificultad diccionarioDificultades[DIFICULTADES + 1] = {

            NO_ASIGNADA,
            FACIL,
            MEDIA,
            DIFICIL
        };

        cin >> dificultadIngresada;

        nivelElegido = diccionarioDificultades[dificultadIngresada];

        if (nivelElegido != DIFICULTAD_FACIL && nivelElegido != DIFICULTAD_MEDIA
            && nivelElegido != DIFICULTAD_DIFICIL ) {

                 cerr << "\nIngrese uno de los valores presentados" << endl;
        }

    } while (nivelElegido != DIFICULTAD_FACIL && nivelElegido != DIFICULTAD_MEDIA
            && nivelElegido != DIFICULTAD_DIFICIL);
}

void cargarAtributosIniciales(Jugador* jugadores, int cantidad, dificultad dificultadElegida) {

    if (dificultadElegida == NO_ASIGNADA) {

        throw string("Nivel no asignado");
    }

    static string diccionarioArchivos[DIFICULTADES] = {

        // Estas deberian ser constantes
        ARCHIVO_FACIL,
        ARCHIVO_MEDIA,
        ARCHIVO_DIFICIL
    };

    ifstream archivo;

    archivo.open(diccionarioArchivos[dificultadElegida-1], ios::in);

    if (archivo.eof() || !archivo.is_open()) {

        throw string ("Error al abrir el archivo de dificultades");
    }

    for (int i = 0; i < cantidad; i++) {

        jugadores[i].cargarAtributos(archivo);
    }

    archivo.close();
}

void mostrarInformacionJugadores(Jugador* jugadores, int cantidadJugadores) {

    for (int i = 0; i < cantidadJugadores; i++) {

        jugadores[i].imprimirInformacion();
    }
}

int main() {

    int cantidadJugadores = 0;
    Jugador* jugadores = NULL;
    dificultad nivelElegido = NO_ASIGNADA;

    ingresarCantidadJugadores(cantidadJugadores);
    crearArregloJugadores(jugadores, cantidadJugadores);
    ingresarNombres(jugadores, cantidadJugadores);
    elegirDificultad(nivelElegido);
    cargarAtributosIniciales(jugadores, cantidadJugadores, nivelElegido);



    /*

    Y BUE ACA HABRIA QUE HACER LO QUE TIENE QUE PASAR EN CADA
    TURNO

    */

    delete[] jugadores;

    return 0;
}
