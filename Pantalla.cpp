/*
 * pantalla.cpp
 *
 *  Created on: 24/03/2018
 *      Author: Matias Figueroa
 */

#include "Pantalla.h"

#include "Jugador.h"
//#include "error.h"
#include <iostream>

using namespace std;

void imprimirBienvenida(){
	cout << "Bienvenido a Granjeros V 2.0" << endl;
}

void solicitarJugadores(){
	cout << "Ingrese la cantidad de jugadores" << "(MAXIMO 5)" << endl;
}

void solicitarNombre(int jugN){
	cout << "Ingrese el nombre del jugador " << jugN << endl;
}

void imprimirMenu(){
	cout << "Seleccione una accion:" << endl
		<< "1. Regar " << endl
		<< "2. Comprar terreno" << endl
		<< "3. Vender terreno" << endl
		<< "4. Sembrar" << endl
		<< "5. Cosechar" << endl
		<< "6. Comprar capacidad de agua" << endl
		<< "7. Comprar capacidad de almacén" << endl
		<< "8. Enviar pedido" << endl
		<< "9. Pasar turno" << endl
		<< "10. Salir" << endl;
}

void imprimirEstadoDelJugador(Jugador* jugadorPtr){
	/*int turnosRestantes = (jugadorPtr->obtenerTurno() - 1);
	cout << "Nombre: "
			<< jugadorPtr->obtenerNombre()
			<< endl
			<< "Creditos: "
			<< jugadorPtr->obtenerCredito()
			<< endl
			<< "Galones de agua: "
			<< jugadorPtr->obtenerGalonesDeAgua()
			<< endl
			<< "Agua de turno: "
			<< jugadorPtr->obtenerAguaTurno()
			<< endl
			<< "Turnos restantes: "
			<< turnosRestantes
			<< endl;*/
}

void imprimirSeparador(){
	cout << "-----------------" << endl;
}

void imprimirTerreno(Jugador* jugadorPtr){
	/*
	 * Aca imprimimos los terrenos por ahora vacio hasta implementar la lista
	 * separadorTerreno();
	for( int i = 0; i < Jugador::maxFilas(); i++){

		for( int j = 0; j < Jugador::maxColumnas(); j++){
			cout << "| "
				<< jugadorPtr->terreno[i][j].imagenRepresentativa()
				<< jugadorPtr->terreno[i][j].infoParcela();
		}
		cout << "|"
				<< endl;
	}
	separadorTerreno();
	cout << endl;
	*/


}

void separadorTerreno(){

	/*for( int i = 0; i < ; i++){
			cout << " ___";
		}

	cout << endl;*/
}

int solicitarColumnaParcela(){
	cout << "Ingese numero de columna" << endl;
	int numeroColumna;
	cin >> numeroColumna;
	numeroColumna--;
	return numeroColumna;
}

int solicitarFilaParcela(){
	cout << "Ingese numero de fila" << endl;
	int numeroFila;
	cin >> numeroFila;
	numeroFila--;
	return numeroFila;
}

void menuSalir(Jugador* jugadorPtr){
	char eleccion;
	cout << "Esta seguro que quiere salir? (s/n)" << endl;
		cin >> eleccion;
		if(eleccion == 's'){

		}
}

char solicitarTipoCultivo(){
	/*char tipoCultivo;
	Error e;
	cout << "Ingrese un tipo de cultivo:: A B o C." << endl;
	cin >> tipoCultivo;
	while(((tipoCultivo < 'A')||
			(tipoCultivo > 'C'))){
		cout << e.cultivoInvalido()
				<< endl;
		cin >> tipoCultivo;
	};
	return tipoCultivo;*/
}

int cantidadAComprar(){
	int cantidad;
	cout << "Cuantas unidades quiere comprar?" << endl;
	cin >> cantidad;
	return cantidad;
}

void saludoFinal(Jugador* jugadorPtr){
	/*cout << "El juego a finalizado, su credito final es: " << jugadorPtr->obtenerCredito() << endl;
	imprimirSeparador();
	cout << endl;*/
}

void imprimirPantallaTurno(Jugador* jugadorPtr, bool* estadoJuegoPtr){
	/*if(jugadorPtr->obtenerTurno() == 1){
		*estadoJuegoPtr = false;
	}
	imprimirSeparador();
	imprimirEstadoDelJugador(jugadorPtr);
	imprimirTerreno(jugadorPtr);
	imprimirMenu();
	imprimirSeparador();*/
}

string msjTirarDado(){
	return MENSAJE_TIRAR_DADO;
}

string msjGalonesGanados(){
	return MENSAJE_GALONES_GANADOS;
}
