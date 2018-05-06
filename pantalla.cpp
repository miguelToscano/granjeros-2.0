/*
 * pantalla.cpp
 *
 *  Created on: 24/03/2018
 *      Author: Matias Figueroa
 */

#include "pantalla.h"
#include "jugador.h"
#include "error.h"
#include <iostream>

using namespace std;

void Pantalla::imprimirBienvenida(){
	cout << "Bienvenido a Granjeros V 2.0" << endl;
}

void Pantalla::solicitarJugadores(){
	cout << "Ingrese la cantidad de jugadores" << "(MAXIMO 5)" << endl;
}

void Pantalla::solicitarNombre(int jugN){
	cout << "Ingrese el nombre del jugador " << jugN << endl;
}

void Pantalla::imprimirMenu(){
	cout << "Seleccione una accion:" << endl
		<< "1.Regar //"
		<< "2.Comprar terreno"
		<< "3. Vender terreno"
		<< "4. Sembrar"
		<< "5. Cosechar"
		<< "6. Comprar capacidad de agua"
		<< "7. Comprar capacidad de almacén"
		<< "8. Enviar pedido"
		<< "9. Pasar turno"
		<< "10. Salir"
		<< endl;
}

void Pantalla::imprimirEstadoDelJugador(Jugador* jugadorPtr){
	int turnosRestantes = (jugadorPtr->obtenerTurno() - 1);
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
			<< endl;
}

void Pantalla::imprimirSeparador(){
	cout << "-----------------" << endl;
}

void Pantalla::imprimirTerreno(Jugador* jugadorPtr){
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

void Pantalla::separadorTerreno(){

	for( int i = 0; i < Jugador::maxColumnas(); i++){
			cout << " ___";
		}

	cout << endl;
}

int Pantalla::solicitarColumnaParcela(){
	cout << "Ingese numero de columna" << endl;
	int numeroColumna;
	cin >> numeroColumna;
	numeroColumna--;
	return numeroColumna;
}

int Pantalla::solicitarFilaParcela(){
	cout << "Ingese numero de fila" << endl;
	int numeroFila;
	cin >> numeroFila;
	numeroFila--;
	return numeroFila;
}

void Pantalla::menuSalir(Jugador* jugadorPtr){
	char eleccion;
	cout << "Esta seguro que quiere salir? (s/n)" << endl;
		cin >> eleccion;
		if(eleccion == 's'){

		}
}

char Pantalla::solicitarTipoCultivo(){
	char tipoCultivo;
	Error e;
	cout << "Ingrese un tipo de cultivo:: A B o C." << endl;
	cin >> tipoCultivo;
	while(((tipoCultivo < 'A')||
			(tipoCultivo > 'C'))){
		cout << e.cultivoInvalido()
				<< endl;
		cin >> tipoCultivo;
	};
	return tipoCultivo;
}

int Pantalla::cantidadAComprar(){
	int cantidad;
	cout << "Cuantas unidades quiere comprar?" << endl;
	cin >> cantidad;
	return cantidad;
}

void Pantalla::saludoFinal(Jugador* jugadorPtr){
	cout << "El juego a finalizado, su credito final es: " << jugadorPtr->obtenerCredito() << endl;
	imprimirSeparador();
	cout << endl;
}

void Pantalla::imprimirPantallaTurno(Jugador* jugadorPtr, bool* estadoJuegoPtr){
	if(jugadorPtr->obtenerTurno() == 1){
		*estadoJuegoPtr = false;
	}
	imprimirSeparador();
	imprimirEstadoDelJugador(jugadorPtr);
	imprimirTerreno(jugadorPtr);
	imprimirMenu();
	imprimirSeparador();
}

string Pantalla::msjTirarDado(){
	return MENSAJE_TIRAR_DADO;
}

string Pantalla::msjGalonesGanados(){
	return MENSAJE_GALONES_GANADOS;
}
