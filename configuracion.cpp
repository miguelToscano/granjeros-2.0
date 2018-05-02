#include "configuracion.h"

void ingresarCantidadJugadores(int& cantidadJugadores) {

    cout << "Ingrese la cantidad de jugadores: ";
    cin >> cantidadJugadores;

    if (cantidadJugadores <= 0) {

        throw string("Error, cantidad de jugadores invalida");
    }
    cin.clear();
}

void crearArregloJugadores(Jugador*& jugadores, int cantidad) {

    if (jugadores != NULL) {

        throw string("Error, el arreglo de jugadores ya fue creado");
    }

    jugadores = new Jugador[cantidad];

    if (jugadores == NULL) {

        throw string("No se pudo alocar la memoria pedida");
    }
}

void ingresarNombres(Jugador* jugadores, int cantidad) {

    if (jugadores == NULL) {

        throw string("El arreglo de jugadores es invalido");
    }

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

    else if (jugadores == NULL) {

        throw string("El arreglo de jugadores no fue creado");
    }

    static string diccionarioArchivos[DIFICULTADES] = {

        ARCHIVO_FACIL,
        ARCHIVO_MEDIA,
        ARCHIVO_DIFICIL
    };

    ifstream archivo;

    archivo.open(diccionarioArchivos[dificultadElegida-1], ios::in);

    if (archivo.eof() || !archivo.is_open()) {

        throw string ("Error al abrir el archivo de dificultades");
    }

    // Carga los atributos del archivo para cada jugador
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

void procesarTurno(Jugador* jugadores, int turno) {

    cout << "Acciones del turno: "<< turno << endl;
}

void configurarJuego(Jugador*& jugadores, int& cantidadJugadores) {

    jugadores = NULL;
    cantidadJugadores = 0;

    dificultad nivelElegido = NO_ASIGNADA;

    ingresarCantidadJugadores(cantidadJugadores);
    crearArregloJugadores(jugadores, cantidadJugadores);
    ingresarNombres(jugadores, cantidadJugadores);
    elegirDificultad(nivelElegido);
    cargarAtributosIniciales(jugadores, cantidadJugadores, nivelElegido);
}
