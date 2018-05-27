/*
 * Cultivo.h
 *
 *  Created on: 24/03/2018
 *      Author: Matias Figueroa
 */

#ifndef CULTIVO_H_
#define CULTIVO_H_

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

static const char RUTA_CULTIVOS[] = "../src/Cultivos.txt";


class Cultivo{

	private:

		char tipo;
		int costoSemilla;
		int tiempoCosecha;
		int rentabilidad;
		int tiempoDeRecuperacion;
		int consumoDeAgua;

	public:

		/*
		 * post:Crea un objeto cultivo, setea el tipo como "V" y todas
		 * 		sus otras variables las inicializa en 0.
		 */
		Cultivo();

		/*
		 * pre: se debe entregar un caracter que sea un tipo de cultivo
		 * 		valido.
		 * post: Crea un cultivo con las caracteristicas de dicho cultivo.
		 */
		Cultivo(char tipoParametro);

		/*
		 * pre: tipoArg debe ser un char.
		 * post: Cambia el valor de "Tipo" por el pasado por argumento.
		 */
		void setearTipo(char tipoArg);

		/*
		 * pre: costoArg debe ser un numero entero mayor o igual a 0.
		 * post: Cambia el valor de "costo" por el pasado por argumento.
		 */
		void setearCosto(int costoArg);

		/*
		 * pre: tiempoCosechaArg debe ser un numero entero mayor o igual a 0.
		 * post: Cambia el valor de "tiempoCosechaArg" por el pasado por argumento.
		 */
		void setearTiempoCosecha(int tiempoCosechaArg);

		/*
		 * pre: rentabilidadArg debe ser un numero entero mayor o igual a 0.
		 * post: Cambia el valor de "tiempoCosechaArg" por el pasado por argumento.
		 */
		void setearRentabilidad(int rentabilidadArg);

		/*
		 * pre: tiempoDeRecuperacionArg debe ser un numero entero mayor o igual a 0.
		 * post:Cambia el valor de "tiempoDeRecuperacionArg" por
		 * 		 el pasado por argumento.
		 */
		void setearTiempoDeRecuperacion(int tiempoDeRecuperacionArg);

		/*
		 * pre: consumoDeAgua debe ser un numero entero mayor o igual a 0.
		 * post: Cambia el valor de "consumoDeAgua" por el pasado por argumento.
		 */
		void setearConsumoDeAgua(int consumoDeAgua);

		/*
		 * post: Devuelve el un char con el tipo del Cultivo.
		 */
		char obtenerTipo();

		/*
		 * post: Devuelve un int con el consumo de agua del Cultivo
		 */
		int obtenerConsumoDeAgua();

		/*
		 * post: Devuelve un int con el costo del cultivo
		 */
		int obtenerCosto();

		/*
		 * post: Devuelve un int con el tiempo de cosecha del cultivo
		 */
		int obtenerTiempoCosecha();

		/*
		 * post: Devuelve un int con la rentabilidad del cultivo
		 */
		int obtenerRentabilidad();

		/*
		 * post: Devuelve un int con el tiempo de recuperacion del cultivo
		 */
		int obtenerTiempoDeRecuperacion();

		/*
		 * pre: cultivoArg debe ser un puntero a un Objeto Cultivo.
		 * post: Le asigna los parametros del cultivoArg a los de este Cultivo.
		 */
		void cambiarCultivo(Cultivo* cultivoArg);

		/*
		 * post: Reduce el tiempo de cosecha en una unidad.
		 */
		void reducirTiempoCosecha();

		/*
		 * post: Reduce el tiempo de recuperacion en una unidad.
		 */
		void reducirTiempoDeRecuperacion();

};


#endif /* CULTIVO_H_ */
