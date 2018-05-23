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

    cout << endl;

    for (int i = 1; i <= cantidad; i++) {

        cout << "Nombre jugador " << i << ": ";
        cin >> nombre;
        jugadores[i-1].establecerNombre(nombre);
    }
}

void elegirDificultad(dificultad& nivelElegido) {

    if (nivelElegido != NO_ASIGNADA) {

        throw string("Dificultad ya elegida");
    }

    
        cout << endl << "Dificultad" << setw(30) << "Filas x Columnas"
        << endl << "1. Facil" << setw(21) << diccionarioFilas[0] << 
        " x " << diccionarioColumnas[0] << endl << "2. Media" << setw(21) << diccionarioFilas[1] << 
        " x " << diccionarioColumnas[1]<< endl
        << "3. Dificil" << setw(19) << diccionarioFilas[2] << 
        " x " << diccionarioColumnas[2] << endl;

        cout << "\nIngrese la dificultad: ";

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

    for (int i = 0; i < cantidad; i ++) {

        jugadores[i].establecerFilas(diccionarioFilas[dificultadElegida - 1]);
        jugadores[i].establecerColumnas(diccionarioColumnas[dificultadElegida - 1]);
        jugadores[i].crearCampo();
        jugadores[i].establecerCreditos();
    }    
}

void mostrarInformacionJugadores(Jugador* jugadores, int cantidadJugadores) {

    cout << endl << setw(10) << "Jugador" << setw(20) << "Creditos" << setw(30)
         << "Unidades de riego" << endl << endl;

    for (int i = 0; i < cantidadJugadores; i++) {

        cout << setw(10) << jugadores[i].obtenerNombre() << setw(20) <<
            jugadores[i].obtenerCreditos() << setw(30) <<
            jugadores[i].obtenerUnidadesRiego() << endl;
    }
}

void cargarCultivos(Cultivo*& cultivosDisponibles, int& cantidadCultivosDisponibles) {

    ifstream archivoCultivos("Cultivos.txt");
    string lineaLeida;
    int contadorLineasLeidas = 0;

    if (!(archivoCultivos.is_open())) {

        throw string("No se pudo abrir el archivo de cultivos");
    }

    // Cuenta cuantos cultivos hay
    while (!archivoCultivos.eof()) {

        contadorLineasLeidas++;
        getline(archivoCultivos, lineaLeida);
    }

    cantidadCultivosDisponibles = (contadorLineasLeidas / 6);

    cultivosDisponibles = new Cultivo[cantidadCultivosDisponibles];

    // Vuelve al principio del archivo
    archivoCultivos.seekg(ios::beg);

    // Variables para guardar los datos leidos
    char tipo;
	int costoSemilla;
	int tiempoCosecha;
	int rentabilidad;
	int tiempoDeRecuperacion;
	int consumoDeAgua;

    // Asignacion de los cultivos levantados del archivo   
    for (int i = 0; i < cantidadCultivosDisponibles; i++) {

        archivoCultivos >> tipo;
        archivoCultivos >> costoSemilla;
        archivoCultivos >> tiempoCosecha;
        archivoCultivos >> rentabilidad;
        archivoCultivos >> tiempoDeRecuperacion;
        archivoCultivos >> consumoDeAgua;

        cultivosDisponibles[i].setearTipo(tipo);
        cultivosDisponibles[i].setearCosto(costoSemilla);
        cultivosDisponibles[i].setearTiempoCosecha(tiempoCosecha);
        cultivosDisponibles[i].setearRentabilidad(rentabilidad);
        cultivosDisponibles[i].setearTiempoDeRecuperacion(tiempoDeRecuperacion);
        cultivosDisponibles[i].setearConsumoDeAgua(consumoDeAgua);

        cout << endl << "Tipo: " << cultivosDisponibles[i].obtenerTipo() << endl
        << "Costo semilla: " << cultivosDisponibles[i].obtenerCosto() << endl
        << "Tiempo de cosecha: " << cultivosDisponibles[i].obtenerTiempoCosecha() << endl
        << "Rentabilidad: " << cultivosDisponibles[i].obtenerRentabilidad() << endl
        << "Tiempo de recuperacion: " << cultivosDisponibles[i].obtenerTiempoDeRecuperacion() << endl
        << "Consumo de agua: " << cultivosDisponibles[i].obtenerConsumoDeAgua() << endl;
    }

    cout << endl;

    archivoCultivos.close();
}

void configurarJuego(Jugador*& jugadores, int& cantidadJugadores, Cultivo*& cultivosDisponibles, int& cantidadCultivosDisponibles) {

    jugadores = NULL;
    cantidadJugadores = 0;

    dificultad nivelElegido = NO_ASIGNADA;

    cargarCultivos(cultivosDisponibles, cantidadCultivosDisponibles);
    ingresarCantidadJugadores(cantidadJugadores);
    crearArregloJugadores(jugadores, cantidadJugadores);
    ingresarNombres(jugadores, cantidadJugadores);
    elegirDificultad(nivelElegido);
    cargarAtributosIniciales(jugadores, cantidadJugadores, nivelElegido);
}
