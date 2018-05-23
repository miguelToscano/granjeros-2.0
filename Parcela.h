/*
 * parcela.h
 *
 *  Created on: 24/03/2018
 *      Author: Matias Figueroa
 */

#ifndef PARCELA_H_
#define PARCELA_H_

#include "Cultivo.h"

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

		//Constructor
		Parcela();

		/*
		 * post: setea la recuperacion de la parcela
		 */
		Parcela &setearRecuperacion(int recuperacionArg);

		/*
		 * post: Remueve el cultivo y setea los parametros
		 */
		void liberarParcela();

		/*
		 * post: Indica si esta disponible para sembrar
		 */
		bool estaDisponible();

		/*
		 * post: Devuelve verdadero si el cultivo en la parcela
		 * no fue regado correctamente.
		 */
		bool estaSeca();

		/*
		 * post: Devuelve verdadero si fue regada en este turno.
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
		* para que la parcela este disponible nuevamente.
		*/
		int obtenerRecuperacion();

		/*
		 * post: Resta un tiempo de recuperacion.
		 */
		void reducirRecuperacion();

		/*
		 * post: Desocupa la parcela.
		 */
		void desocuparParcela();

		/*
		* post: Vuelve a falso el parametro seco de la parcela.
		*/
		void desSecarParcela();

		/*
		 * post: Le indica que la parcela fue ocupada
		 */
		void ocuparParcela();

		/*
		 * post: Vuelve a indicar que la parcela no fue regada,
		 * sirve para cuando cuambiemos de turno tegamos que
		 * volver a regarla.
		 */
		void noRegarParcela();

		/*
		 * pre: Debe haber un cultivo.
		 * post: Indica que la paracela se pudrio
		 */
		void pudrirParcela();

		/*
		 * post: cambia a la parcela que este podrida
		 */
		void despudrirParcela();

		/*
		 * post: Cambia a una parcela regada
		 */
		void regarParcela();

		/*
		 * post: Cambia a la parcela seca
		 */
		void secarParcela();

		/*
		 * post: Habilita la parcela
		 */
		void parcelaDisponible();

		/*
		 * post: Bloquea la parcela
		 */
		void bloquearParcela();

		/*
		 * post: Devuelve un char que indica el estado de
		 * la parcela. Si tiene un cultivo, si esta podrida,
		 * vacia, disponible, etc.
		 */
		char imagenRepresentativa();

		/*
		 * post: Devuelve un char que indica el estado de
		 * la cosecha, si hay que cosecharla, si esta regada.
		 */
		char infoParcela();

		/*
		 * post: Realiza la logica del cambio de turno.
		 */
		void pasoDeTurno();

		/*
		 * post: ------
		 */
		void copiarParcela(Parcela* parcelaArg);

		/*
		 * post: ------
		 */
		bool sePuedeCosechar();

		/*
		 * post: ------
		 */
		Cultivo cosecharParcela();
};



#endif /* PARCELA_H_ */
