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

    /*
     * post: Crea un jugador, con nombre "Nombre no asignado",
     * 		una capacidad de agua del tanque de 25 unidades,
     * 		una capacidad de almacen de 5 unidades,
     * 		cero creditos, y cero unidades de riego.
     */
    Jugador();

    /*
     * post: Imprime por pantalla toda la informacion del jugador.
     */
    void imprimirInformacion();

    /*
     * post: Devuelve la direccion de memoria, de la variable
     * 		Campo del jugador
     */
    Campo* devolverCampo();

    /*
     * post: Si tiene un campo lo imprime por consola, en caso de
     * 		no tener se imprime un mensaje indicando eso.
     */
    void mostrarCampo();

    /*
     * pre: El costo del terreno a comprar debe ser menor o igualç
     * 		a los creditos del jugador.
     * post:Agrega un terreno a la lista de terrenos del jugador,
     * 		descuenta su costo, y actualiza los precios de los terrenos.
     */
    void comprarTerreno();

    /*
     * pre: La posicion debe ser una posicion de la lista valida (debe haber un terreno)
     * post: Elimina la posicion de la lista, suma los creditos y reacomoda la lista
     */
    void venderTerreno(int posicion);

    /*
     * pre: -
     * post: Pide el nombre del jugador y lo asigna a nombre.
     */
    void ingresarNombre();

    /*
     * pre:
     * post: Asigna a nombre la cadena pasada como argumento.
     */
    void establecerNombre(std::string nombre);

    /*
     * post: Devuelve un string con el nombre del jugador.
     */
    std::string obtenerNombre();

    /*
     * pre: Esta funcion se debe llamar solo en la configuracion
     * 		del juego, cuando se elige la dificultad del juego.
     * post: Asigna un valor a filas segun la dificultad elegida.
     */
    void establecerFilas(int filas);

    /*
     * pre: Esta funcion se debe llamar solo en la configuracion
     * 		del juego, cuando se elige la dificultad del juego
     * post: Asigna un valor a columnas segun la dificultad elegida
     */
    void establecerColumnas(int columnas);

    /*
     * pre: re: Las filas y columnas del jugador deben
     * 		haber sido establecidas previamente.
     * post: ost: Asigna a creditos el valor segun las
     * 		filas y columnas del jugador
     */
    void establecerCreditos();

    /*
     * post: Devuelve un entero con la cantidad de creditos
     * 		del jugador.
     */
    int obtenerCreditos();

    /*
     * post: Agrega un nuevo terreno a la lista de terrenos.
     */
    void crearCampo();

    /*
     * post: Devuelve la cantidad de terrenos del jugador
     * (coincide con la primer dimension del arreglo de terrenos).
     */
    int obtenerCantidadTerrenos();

    /*
     * pre: unidadesRiego debe ser un numero entero positivo.
     * post: Asigna a unidadesRiego el valor pasado como argumento
     */
    void establecerUnidadesRiego(int unidadesRiego);

    /*
     * post: Devuelve el valor de unidadesRiego
     */
    int obtenerUnidadesRiego();

    /*
     * pre: Se debe pasar por referencia un Cultivo, el mismo debe
     * 		se uno valido, no puede ser un Cultivo vacio, terreno
     * 		debe ser un numero positivo mayor a cero y, fila y columna
     * 		deben ser un numero entero entre 0 y la cantidad de
     * 		filas y columnas segun la dificultad elegida.
     * post: Coloca el cultivo en la direccion de las cordenas de la
     * 		Parcela indicada, si se pudo realizar la operacion devuelve
     * 		verdadero, sino falso.
     */
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

    /*
     * post: Llama a la funcion recibirAgua de su tanqueDeAgua.
     */
    void recibirAgua();

    /*
     * post: Llama a la funcion desechar Exeso de agua de su
     * 		tanqueDeAgua.
     */
    void desecharExcesoDeAgua();

    /*
     * pre: Terreno debe ser un entero positivo y, fila y columna,
     * 		deben ser numeros enteros entre cero y la  cantidad de filas
     * 		y columnas segun la dificultad.
     * post: Si la parcela de las coordenadas es valida para regar
     * 		se cambio el estado de la parcela "regada" a verdadero,
     * 		y se disminuyen la cantidad de unidades de riego corres-
     * 		pondientes.
     */
    void regarParcela(int terreno, int fila, int columna);

    /*
     * post: Obtiene la cantidad de filas que tienen los terrenos
     * 		del jugador.
     */
    int obtenerFilas();

    /*
     * post: Obtiene la cantidad de columnas que tienen los terrenos
     * 		del jugador
     */
    int obtenerColumnas();

    /*
     * post: Obtiene la cantidad de Agua que tiene el jugador.
     */
    int obtenerCantidadAgua();

    /*
     * post: inicializa la cantidad de capacidad del tanque de agua
     *		segun la dificultad.
     */
    void inicializarCapacidadTanque();

    /*
     * pre: Terreno debe ser un entero positivo y, fila y columna,
     * 		deben ser numeros enteros entre cero y la  cantidad de filas
     * 		y columnas segun la dificultad.
     * post: Devuelve verdadero si el jugador tiene las suficientes
     * 		unidades de riego para regar la parcela ubicada en las
     * 		coordenadas dadas.
     */
    bool hayAguaDisponible(int terreno, int fila, int columna);

    /*
     * pre: Terreno debe ser un entero positivo y, fila y columna,
     * 		deben ser numeros enteros entre cero y la  cantidad de filas
     * 		y columnas segun la dificultad.
     * post: Devuelve verdadero si se puede plantar en la parcela
     * 		ubicada en las cordenadas dadas.
     */
    bool sonCoordenadasValidasPlantar(int terreno, int fila, int columna);

    /*
     * pre: Terreno debe ser un entero positivo y, fila y columna,
     * 		deben ser numeros enteros entre cero y la  cantidad de filas
     * 		y columnas segun la dificultad.
     * post: Devuelve verdadero si se puede plantar en la parcela
     * 		ubicada en las cordenadas dadas.
     */
    bool sonCoordenadasValidasRegar(int terreno, int fila, int columna);

    /*
     *
     */
    void enviarPedidos();

    /*
     * post: Devuelve verdadero si el jugador tiene cultivos en su Almacen
     */
    bool tieneCultivosEnAlmacen();

    /*
     * pre: creditos debe ser un numero postivo mayor o
     * 		igual a cero.
     * post: Suma los creditos pasados por argumento.
     */
    void sumarCreditos(unsigned int creditos);

    /*
     * post: Devuelve la direccion de memoria del almacen.
     */
    Almacen* obtenerAlmacen();

    /*
     * post: Libera la memoria reservada del Jugador.
     */
    ~Jugador();

};

#endif
