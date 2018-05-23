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

static const char RUTA_CULTIVOS[] = "cultivos.txt";


class Cultivo{
	private:

		char tipo;
		int costoSemilla;
		int tiempoCosecha;
		int rentabilidad;
		int tiempoDeRecuperacion;
		int consumoDeAgua;

	public:

		//Constructor
		Cultivo();

		/*
		 * pre: se debe entregar un caracter que sea un tipo de cultivo
		 * valido.
		 * post: Crea un cultivo con las caracteristicas de dicho cultivo.
		 */
		Cultivo(char tipoParametro);

		Cultivo &setearTipo(char tipoArg);
		Cultivo &setearCosto(int costoArg);
		Cultivo &setearTiempoCosecha(int tiempoCosechaArg);
		Cultivo &setearRentabilidad(int rentabilidadArg);
		Cultivo &setearTiempoDeRecuperacion(int tiempoDeRecuperacionArg);

		/*
		 * post: devuelve el un char con el tipo del cultivo
		 */
		char obtenerTipo();

		/*
		* post: devuelve un int con el costo del cultivo
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
		int obtenerTIempoDeRecuperacion();

		/*
		* post: Reemplaza el cultivo
		*/
		void cambiarCultivo(Cultivo* cultivoArg);

		/*
		* post: Realiza las acciones que se producen en el cultivo
		* al pasar de turno
		*/
		void pasarTurno();

		/*
		* post: Reduce el tiempo de cosecha en una unidad
		*/
		void reducirTiempoCosecha();

		/*
		* post: Reduce el tiempo de recuperacion en una unidad
		*/
		void reducirTIempoDeRecuperacion();

};


#endif /* CULTIVO_H_ */
