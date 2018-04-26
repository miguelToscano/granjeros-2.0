#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

class Jugador {

private:

    std::string nombre;

    int creditos;

    int cantidadTerrenos;

    int unidadesRiego;

    // Arreglo de matrices que representa la cantidad de terrenos
    char*** terreno;

    // Parcela*** terreno;
    //
    // Tanque tanqueDeAgua;
    //
    // Almacen miAlmacen;

public:

    Jugador();

    void imprimirInformacion();

    // Pre: -
    // Post: Pide el nombre del jugador y lo asigna a nombre
    void ingresarNombre();

    // Pre: -
    // Post: asigna a nombre la cadena pasada como argumento
    void establecerNombre(std::string nombre);

    // Pre: -
    // Post: Devuelve el nombre del jugador
    std::string obtenerNombre();

    // Pre: El argumento debe ser positivo
    // Post: Asigna a creditos el valor pasado como argumento
    void establecerCreditos(int creditos);

    // Pre: -
    // Post: Devuelve la cantidad de creditos del jugador
    int obtenerCreditos();

    // Pre: El argumento debe ser positivo
    // Post: Redimensiona el arreglo de terrenos del jugador
    void establecerCantidadTerrenos(int cantidadTerrenos);

    // Pre: -
    // Post: Devuelve la cantidad de terrenos del jugador (coincide
    // con la primer dimension del arreglo de terrenos)
    int obtenerCantidadTerrenos();

    // Pre: El argumento debe ser positivo
    // Post: Asigna a unidadesRiego el valor pasado como argumento
    void establecerUnidadesRiego(int unidadesRiego);

    // Pre: -
    // Post: Devuelve el valor de unidadesRiego
    int obtenerUnidadesRiego();

    // Pre: El archivo recibido como argumento y los datos en el mismo deben
    // estar cada uno en una linea separada en el siguiente orden:
    // - creditos
    // - cantidadTerrenos
    // - unidadesRiego

    // Post: deja los atributos iniciales del jugador con los valores definidos
    // en el archivo pasado como argumento
    void cargarAtributos(std::ifstream& archivo);
};

#endif
