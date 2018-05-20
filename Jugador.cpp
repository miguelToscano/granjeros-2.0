#include "jugador.h"

using namespace std;

Jugador :: Jugador() {

    this->nombre = "Nombre no asignado";
    this->creditos = 0;
    this->unidadesRiego = 0;
}

void Jugador :: mostrarCampo() {

    if (this->obtenerCantidadTerrenos() == 0) {

        cout << endl << this->obtenerNombre() << " no posee terrenos actualmente" << endl;
    }
  
    else

        this->campoJugador.mostrarCampo();
}

void Jugador :: imprimirInformacion() {

    cout << "\nNombre: " << this->obtenerNombre() << endl
        << "Creditos: " << this->obtenerCreditos() << endl
        << "Cantidad de terrenos: " << this->obtenerCantidadTerrenos() << endl
        << "Unidades de riego: " << obtenerUnidadesRiego() << endl;
}

int Jugador :: obtenerCantidadTerrenos() {

    this->campoJugador.obtenerCantidadTerrenos();
}

void Jugador :: establecerNombre(string nombre) {

    this->nombre = nombre;
}

void Jugador :: ingresarNombre() {

    cout << "Ingrese el nombre del jugador: ";

    cin >>  this->nombre;
}

string Jugador :: obtenerNombre() {

    return this->nombre;
}

void Jugador :: establecerCreditos() {

    this->creditos = 2 * (this->campoJugador.obtenerFilas()) * (this->campoJugador.obtenerColumnas());
}

int Jugador :: obtenerCreditos() {

    return this->creditos;
}

int Jugador :: obtenerUnidadesRiego() {

    return this->unidadesRiego;
}

void Jugador :: establecerUnidadesRiego(int unidadesRiego) {

    if (unidadesRiego < 0) {

        throw string("Se intentaron asignar unidades de riego negativas");
    }

    this->unidadesRiego = unidadesRiego;
}

void Jugador :: establecerFilas(int filas) {

    this->campoJugador.establecerFilas(filas);
}

void Jugador :: establecerColumnas(int columnas) {

    this->campoJugador.establecerColumnas(columnas);
}

void Jugador :: crearCampo() {

    this->campoJugador.crearCampo();
}

bool Jugador :: hayCreditosDisponiblesTerreno() {

    return this->creditos >= this->campoJugador.obtenerPrecioTerreno();
}

void Jugador :: descontarCreditos(int valor) {

    this->creditos -= valor;
}

void Jugador :: comprarTerreno() {

    this->descontarCreditos(this->campoJugador.obtenerPrecioTerreno());
    this->campoJugador.agregarTerreno();
    this->campoJugador.actualizarPrecioTerreno();
}

void Jugador :: venderTerreno(int posicion) {

    float precioVentaTerreno;

    if (posicion < 0 || posicion > this->campoJugador.obtenerCantidadTerrenos()) {

        throw string("Se quiso acceder a una posicion de la lista invalida");
    }

    precioVentaTerreno = static_cast<float>(this->campoJugador.obtenerPrecioTerreno()) * 0.5;
    this->creditos += static_cast<int>(precioVentaTerreno);

    this->campoJugador.eliminarTerreno(posicion);
}
