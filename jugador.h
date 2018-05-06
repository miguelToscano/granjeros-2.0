#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "parcela.h"
#include "lista.h"
#include "almacen.h"


class Jugador {

private:

    std::string nombre;

    int creditos;

    TanqueDeAgua miTanque;

    Lista<Parcela*> miTerreno;

    Almacen miAlmacen;

public:

    Jugador();

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
    // Post: agrega creditos.
    void establecerCreditos(int creditos);

    void sumarCreditos(int creditos);

    // Pre: -
    // Post: Devuelve la cantidad de creditos del jugador
    int obtenerCreditos();

    /*
     * pre: El jugador debe tener los creditos necesario para hacer la compra
     * post: agrega una cantidad de parcelas nxm al terreno.
     */
    void comprarTerreno(Dificultad dificultad);

    /*
     * pre: El jugador debe tener un terreno.
     * post: Se eliminan las parcelas del ultimo terreno que compro
     * y recibe la cantidad de creditos correspondientes
     */
    void venderTerreno(Dificultad dificultad);


    /*
     * pre: Se debe entregar una coordenada y numero de terreno validos.
     * post: obtiene el puntero a la parcela indicada.
     */
    Parcela* obtenerParcela(int nTerreno, int fila,
    		int columna, Dificultad dificultad);

    /*
     * post: devuelve la cantidad de terrenos del jugador.
     */
    int obtenerCantidadTerrenos(Dificultad dificultad);

    /*
     * post: aumenta la capacidad de las unidades de riego del tanque
     */
    void establecerUnidadesRiego(int unidadesRiego);

    /*
     * post: obtiene las unidades de riego del jugador
     */
    int obtenerUnidadesRiego();

    /*
     * pre: Los parametros de dificultad deben estar inicializados.
     * post: Asigna los valores iniciales del jugador.
     */
    void cargarAtributos(Dificultad dificultad);
};

#endif
