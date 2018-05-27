/*
 * parcela.h
 *
 *  Created on: 24/03/2018
 *      Author: Matias Figueroa
 */

#ifndef PARCELA_H_
#define PARCELA_H_

#include "../src/Cultivo.h"

class Parcela{
	private:
		bool disponible;
		bool ocupada;
		bool regada;
		bool podrida;
		bool seca;
		int recuperacion;

		static const char VACIA = 'V';
		static const char PODRIDA = '#';
		static const char SECA = 'S';
		static const char DISPONIBLE = 'D';
		static const char ERROR_CHAR = 'E';
		static const char REGADA = '*';
		static const char SIN_REGAR = ' ';
		static const char COSECHAR = 'Y';

	public:

		Cultivo cultivoParcela;

		/*
		 * post: Crea una parcela disponible para usar, y con un cultivo "Vacio".
		 */
		Parcela();

		/*
		 * post: setea la recuperacion de la parcela
		 */
		void setearRecuperacion(int recuperacionArg);

		/*
		 * pre: La parcela debe tener un cultivo no vacio.
		 * post: Se setea el tiempo de recuperacion con el del cultivo actual,
		 * 		luego se cambia el cultivo por uno Vacio, y cambia el estado de
		 * 		ocupada, podrida y regada a falso.
		 */
		void liberarParcela();

		/*
		 * pre: Se recibe por argumento un cultivo valido.
		 * post: Cambia el cultivo de la parcela por el pasado por argumento.
		 */
		void establecerCultivo(Cultivo& cultivo);

		/*
		 * post: Devuelve verdadero si esta disponible para sembrar.
		 */
		bool estaDisponible();

		/*
		 * post: Devuelve verdadero si el cultivo en la parcela
		 * 		esta seco.
		 */
		bool estaSeca();

		/*
		 * post: Devuelve verdadero si la Parcela fue regada en este turno.
		 */
		bool estaRegada();

		/*
		 * post: Devuelve verdadero si se pudrio el cultivo en la parcela.
		 */
		bool estaPodrida();

		/*
		 * post: Devuelve verdadero si hay un cultivo en la parcela.
		 */
		bool estaOcupada();

		/*
		 * post: Devuelve un entero con la cantidad de turnos que faltan
		 * 		para que la parcela este disponible nuevamente.
		 */
		int obtenerRecuperacion();

		/*
		 * post: Resta un tiempo de recuperacion.
		 */
		void reducirRecuperacion();

		/*
		 * post: Cambia el parametro "ocupada" a false.
		 */
		void desocuparParcela();

		/*
		* post: Cambia el parametro "seca" a false.
		*/
		void desSecarParcela();

		/*
		 * post: Cambia el parametro "ocupada" a verdadero.
		 */
		void ocuparParcela();

		/*
		 * post: Cambia el parametro "regada" a falso.
		 */
		void noRegarParcela();

		/*
		 * pre: Debe haber un cultivo en la Parcela
		 * post: Cambia el parametro "podrida" a verdadero y desocupa la Parcela.
		 */
		void pudrirParcela();

		/*
		 * post: Cambia el parametro "podrida" a falso.
		 */
		void despudrirParcela();

		/*
		 * post: Cambia el parametro "regada" a verdadero.
		 */
		void regarParcela();

		/*
		 * pre: Debe haber un cultivo en la Parcela.
		 * post: Cambia el parametro "seca" a verdadero y desocupa la Parcela.
		 */
		void secarParcela();

		/*
		 * post: Cambia el parametro "disponible" a verdadero.
		 */
		void parcelaDisponible();

		/*
		 * post: Cambia el parametro "disponible" a falso.
		 */
		void bloquearParcela();

		/*
		 * post: Devuelve un char que indica el estado de
		 * 		la parcela. Si tiene un cultivo, si esta podrida,
		 * 		vacia, disponible, etc.
		 */
		char imagenRepresentativa();

		/*
		 * post: Devuelve un char que indica el estado de
		 * 		la cosecha, si hay que cosecharla, si esta regada.
		 */
		char infoParcela();

		/*
		 * post: Realiza la logica de paso de turno para las parcelas.
		 * 		Si esta ocupada:
		 * 				+ si no se rego, seca la parcela.
		 * 				+ si se rego, reduce un tiempo para cosechar el
		 * 					cultivo y cambia el estado de regada a false.
		 * 				Independientemente si esta regada o no, si el tiempo
		 * 				de cosecha es negativo, pudre la Parcela. la libera,
		 * 				pero reduce su tiempo de recuperacion a la mitad.
		 * 		Si no esta ocupada:
		 * 				+ si el tiempo de recuperacion es mayor a 0, reduce
		 * 				un tiempo
		 * 				+ si el tiempo de recuperacion es igual a 0, cambia
		 * 				el estado de la parcela a disponible.
		 */
		void pasoDeTurno();



		/*
		 * post: Devuelve verdadero si la Parcela esta en tiempo de cosecha.
		 */
		bool sePuedeCosechar();

		/*
		 * pre: Debe haber un Cultivo en la parcela.
		 * post: Devuelve un entero con el consumo de agua del cultivo sembrado
		 * 		en la parcela.
		 */
		int obtenerConsumoDeAgua();

		/*
		 * pre: La parcela debe estar desocupada y tiempo de recuperacion en 0.
		 * post: Cambia el estado de "ocupada" y "disponible" a falso.
		 */
		void sembrar();


};



#endif /* PARCELA_H_ */
