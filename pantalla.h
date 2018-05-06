/*
 * pantalla.h
 *
 *  Created on: 24/03/2018
 *      Author: Tomás
 */

#ifndef INTERFACES_PANTALLA_H_
#define INTERFACES_PANTALLA_H_

#include <string>
#include "jugador.h"

class Jugador;
class Parcela;

const std::string MENSAJE_TIRAR_DADO = "Se tiro el dado----> Su numero es: ";
const std::string MENSAJE_GALONES_GANADOS = "Por ello ha recibido los siguientes galones de agua:";

void imprimirBienvenida();
void imprimirPantallaTurno(Jugador* jugadorPtr, bool* estadoJuegoPtr);
void imprimirMenu();
void solicitarNombre(int jugN);
void imprimirEstadoDelJugador(Jugador* jugadorPtr);
void solicitarJugadores();
void imprimirSeparador();
void imprimirTerreno(Jugador* jugadorPtr);
void separadorTerreno();
int solicitarColumnaParcela();
int solicitarFilaParcela();
char menuComprar();
void menuCosechar();
void menuRegar();
void menuSalir(Jugador* jugadorPtr);
int cantidadAComprar();
void saludoFinal(Jugador* jugadorPtr);
char solicitarTipoCultivo();
std::string msjTirarDado();
std::string msjGalonesGanados();

#endif
