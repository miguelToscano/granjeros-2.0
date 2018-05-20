#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "Campo.h"

class Jugador {

private:

    std::string nombre;

    int creditos;

    int unidadesRiego;
    
    Campo campoJugador;
    
public:

    Jugador();

    void imprimirInformacion();

    void mostrarCampo();

    void comprarTerreno();

    // Pre: La posicion debe ser una posicion de la lista valida (debe haber un terreno)
    // Post: Elimina la posicion de la lista, suma los creditos y reacomoda la lista
    void venderTerreno(int posicion);

    // Pre: -
    // Post: Pide el nombre del jugador y lo asigna a nombre
    void ingresarNombre();

    // Pre: -
    // Post: asigna a nombre la cadena pasada como argumento
    void establecerNombre(std::string nombre);

    // Pre: -
    // Post: Devuelve el nombre del jugador
    std::string obtenerNombre();

    // Pre: Esta funcion se debe llamar solo en la configuracion del juego, cuando se elige la dificultad del juego
    // Post: Asigna un valor a filas segun la dificultad elegida
    void establecerFilas(int filas);

    // Pre: Esta funcion se debe llamar solo en la configuracion del juego, cuando se elige la dificultad del juego
    // Post: Asigna un valor a columnas segun la dificultad elegida
    void establecerColumnas(int columnas);

    // Pre: Las filas y columnas del jugador deben haber sido establecidas previamente
    // Post: Asigna a creditos el valor segun las filas y columnas del jugador
    void establecerCreditos();

    // Pre: -
    // Post: Devuelve la cantidad de creditos del jugador
    int obtenerCreditos();

    void crearCampo();

    // Pre: El argumento debe ser positivo
    // Post: Redimensiona el arreglo de terrenos del jugador

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

    bool hayCreditosDisponiblesTerreno();

    void descontarCreditos(int valor);
};

#endif
