#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

#include "../src/Campo.h"
#include "../src/TanqueDeAgua.h"
#include "../src/Almacen.h"

class Jugador {

private:

    std::string nombre;

    int creditos;

    int unidadesRiego;
    
    Campo campoJugador;
    
    TanqueDeAgua tanque;

    Almacen almacen;

public:

    Jugador();

    void imprimirInformacion();

    void sumarCreditos(unsigned int creditos);

    Almacen* obtenerAlmacen();

    Campo* devolverCampo();

    void mostrarCampo();

    /*
     * pre:
     * post:
     */
    void comprarTerreno();

    /*
     * pre: La posicion debe ser una posicion de la lista valida (debe haber un terreno)
     * post: Elimina la posicion de la lista, suma los creditos y reacomoda la lista
     */
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

    bool plantarSemilla(Cultivo& cultivo, int terreno, int fila, int columna);

    /*
     * post: retorna verdadero si hay suficiente credito
     * 		para comprar un terrreno
     */
    bool hayCreditosDisponiblesTerreno();

    /*
     * pre: Se requiere un entero posito menos o igual a la cantidad
     * 		actual de creditos.
     * post: Descuenta los creditos pasados por parametro
     */
    void descontarCreditos(int valor);

    /*
     * post: devuelve verdadero si existe el terreno indicado
     */
    bool esUnTerrenoValido(int terreno);

    /*
     * post: Devuelve verdadero si existe la fila indicada.
     */
    bool esUnaFilaValida(int fila);

    /*
     * post: Devuelve verdadero si existe la columna indicada
     */
    bool esUnaColumnaValida(int columna);

    /*
     * pre: Se solicita el numero de terreno, la fila y columna,
     * 		los tres valores deben ser numeros positivos y debe existir
     * 		la direccion de esa parcela.
     * post:Si se puede cosechar, cosecha la parcela y devuelve
     * 		verdadero si se realizo la operecion, sino devuelve falso.
     */
    bool cosechar(int terreno, int fila, int columna);

    /*
     * post: Devuelve verdadero si hay lugar en el almacen,
     */
    bool hayLugarEnAlmacen();

    /*
     * pre: Se pasa un numero entero positivo con la capacidad a comprar
     * post: Obtiene verdadero si se puede comprar, compra y descuenta los creditos
     * 		si no se puede no hace nada y devuelve falso.
     */
    bool sePuedeComprarCapacidadTanque(int capacidad);

    /*
     * pre: Se pasa un numero entero positivo con la capacidad a comprar
     * post: Obtiene verdadero si se puede comprar, compra y descuenta los creditos
     * 		si no se puede no hace nada y devuelve falso.
     */
    bool sePuedeComprarCapacidadAlmacen(int capacidad);

    /*
     * post:Devuelve verdadero si el jugador tiene por lo menos un terreno.
     */
    bool tieneTerrenos();

    void recibirAgua();


    void desecharExcesoDeAgua();

    void regarParcela(int terreno, int fila, int columna);

    int obtenerFilas();

    int obtenerColumnas();

    int obtenerCantidadAgua();

    void inicializarCapacidadTanque();

    bool hayAguaDisponible(int terreno, int fila, int columna);

    bool sonCoordenadasValidasPlantar(int terreno, int fila, int columna);

    bool sonCoordenadasValidasRegar(int terreno, int fila, int columna);

    bool tieneCultivosEnAlmacen();

    ~Jugador();

};

#endif
