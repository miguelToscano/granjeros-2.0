#include "../src/configuracion.h"

void ingresarCantidadJugadores(int& cantidadJugadores) {

    cout << "Ingrese la cantidad de jugadores: ";
    cin >> cantidadJugadores;

    if (cantidadJugadores <= 0) {

        throw string("Error, cantidad de jugadores invalida");
    }

    //cin.clear();
}

void crearJugadores(Lista<Jugador*>* listaJugadores, int cantidadJugadores) {

    string nombre;

    for (int i = 1; i < cantidadJugadores + 1; i++) {

		Jugador* nuevoJugador = new Jugador;

		cout << "Ingrese el nombre del jugador " << i << ": ";
        	cin >> nombre;

        nuevoJugador->establecerNombre(nombre);
        listaJugadores->agregarElemento(nuevoJugador);
    }
}

void cargarAtributosIniciales(Lista<Jugador*>* listaJugadores, dificultad dificultadElegida) {

    listaJugadores->iniciarCursor();

    while (listaJugadores->avanzarCursor()) {

        Jugador* jugadorActual = listaJugadores->obtenerCursor();

        jugadorActual->establecerFilas(diccionarioFilas[dificultadElegida - 1]);
        jugadorActual->establecerColumnas(diccionarioColumnas[dificultadElegida - 1]);
        jugadorActual->crearCampo();
        jugadorActual->establecerCreditos();
        jugadorActual->inicializarCapacidadTanque();
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

void mostrarInformacionJugadores(Lista<Jugador*>* jugadores) {

    cout << endl << setw(10) << "Jugador" << setw(20) << "Creditos" << setw(30)
         << "Unidades de riego" << endl << endl;

    jugadores->iniciarCursor();
    while(jugadores->avanzarCursor()){

        cout << setw(10) << jugadores->obtenerCursor()->obtenerNombre() << setw(20) <<
            jugadores->obtenerCursor()->obtenerCreditos() << setw(30) <<
            jugadores->obtenerCursor()->obtenerUnidadesRiego() << endl;
    }
}

void cargarCultivos(Lista<Cultivo*>* listaCultivosDisponibles) {

    ifstream archivoCultivos("Cultivos.txt");
    string lineaLeida;
    int contadorLineasLeidas = 0;
    Cultivo* cultivo = new Cultivo;

    if (!(archivoCultivos.is_open())) {

        throw string("No se pudo abrir el archivo de cultivos");
    }

    // Cuenta cuantos cultivos hay
    while (!archivoCultivos.eof()) {

        contadorLineasLeidas++;
        getline(archivoCultivos, lineaLeida);
    }

    int cantidadCultivosDisponibles = (contadorLineasLeidas / 6);

    // Vuelve al principio del archivo
    archivoCultivos.seekg(ios::beg);

    char tipo;
	int costoSemilla;
	int tiempoCosecha;
	int rentabilidad;
	int tiempoDeRecuperacion;
	int consumoDeAgua;

    for (int i = 0; i < cantidadCultivosDisponibles; i++) {

        archivoCultivos >> tipo;
        archivoCultivos >> costoSemilla;
        archivoCultivos >> tiempoCosecha;
        archivoCultivos >> rentabilidad;
        archivoCultivos >> tiempoDeRecuperacion;
        archivoCultivos >> consumoDeAgua;

        cultivo->setearTipo(tipo);
        cultivo->setearCosto(costoSemilla);
        cultivo->setearTiempoCosecha(tiempoCosecha);
        cultivo->setearRentabilidad(rentabilidad);
        cultivo->setearTiempoDeRecuperacion(tiempoDeRecuperacion);
        cultivo->setearConsumoDeAgua(consumoDeAgua);

        listaCultivosDisponibles->agregarElemento(cultivo);
    }
}

void eliminarJugadores(Lista<Jugador*>* listaJugadores) {

   listaJugadores->iniciarCursor();
	
   while (listaJugadores->avanzarCursor()) {

	 Jugador* jugadorActual = listaJugadores->obtenerCursor();
	   
	 delete jugadorActual;
   }
}

void eliminarCultivos(Lista<Cultivo*>* listaCultivos) {

    listaCultivos->iniciarCursor();
	
    while (listaCultivos->avanzarCursor()) {
	
	Cultivo* cultivoActual = listaCultivos->obtenerCursor();
	    
	delete cultivoActual;
    }
}
void configurarJuego(Lista<Jugador*>* listaJugadores, Lista<Cultivo*>* listaCultivos) {

    int cantidadJugadores = 0;

    dificultad nivelElegido = NO_ASIGNADA;

    cargarCultivos(listaCultivos);
    ingresarCantidadJugadores(cantidadJugadores);
    crearJugadores(listaJugadores, cantidadJugadores);
    elegirDificultad(nivelElegido);
    cargarAtributosIniciales(listaJugadores, nivelElegido);
}
