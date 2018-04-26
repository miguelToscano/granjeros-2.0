#include "jugador.h"

using namespace std;

Jugador :: Jugador() {

    this->nombre = "Nombre no asignado";
    this->creditos = 0;
    this->unidadesRiego = 0;
    this->cantidadTerrenos = 0;
    this->terreno = NULL;
}

void Jugador :: imprimirInformacion() {

    cout << "\nNombre: " << this->obtenerNombre() << endl
        << "Creditos: " << this->obtenerCreditos() << endl
        << "Cantidad de terrenos: " << this->obtenerCantidadTerrenos() << endl
        << "Unidades de riego: " << obtenerUnidadesRiego() << endl;
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

void Jugador :: establecerCreditos(int creditos) {

    this->creditos = creditos;
}

int Jugador :: obtenerCreditos() {

    return this->creditos;
}

void Jugador :: establecerCantidadTerrenos(int cantidadTerrenos) {

    this->cantidadTerrenos = cantidadTerrenos;
}

int Jugador :: obtenerCantidadTerrenos() {

    return this->cantidadTerrenos;
}

int Jugador :: obtenerUnidadesRiego() {

    return this->unidadesRiego;
}

void Jugador :: establecerUnidadesRiego(int unidadesRiego) {

    this->unidadesRiego = unidadesRiego;
}

void Jugador :: cargarAtributos(ifstream& archivo) {

    archivo >> this->creditos;
    archivo >> this->cantidadTerrenos;
    archivo >> this->unidadesRiego;

    archivo.seekg(0, archivo.beg);
}
