/*
 * granjerosBMP.h
 *
 *  Created on: 06/05/2018
 *      Author: trini
 */

#include "EasyBMP.h"
#include "cultivo.h"
#include "Campo.h"
#include "parcela.h"


#ifndef GRANJEROSBMP_H_

#define GRANJEROSBMP_H_


class GranjerosBMP{

	private:

		RGBApixel marronDisponible;
		RGBApixel marronPodrido;
		RGBApixel marronSeco;
		RGBApixel verdeBordes;
		RGBApixel amarilloCultivo;
		RGBApixel azulAgua;
		RGBApixel violetaCosechar;

		BMP imagen;

		int resolucionFila;
		int resolucionColumna;
		int profundidadBit;
		int pixelesParcelaFila;
		int pixelesParcelaColumna;
		int grosorBordes;
		int posicionColumnaSimbolito;
		int	posicionFilaSimbolito;

	public:

		Campo terreno;
		Parcela parcelaArg;
		Cultivo cultivoParcela;

		//Constructor
		GranjerosBMP();

		//Post: devuelve los pixeles por columna
		int obtenerPixelesParcelaColumna ();

		//Post: devuelve los pixeles por fila
		int obtenerPixelesParcelaFila ();

		//Post: devuelve la imagen
		BMP obtenerImagen ();

		RGBApixel obtenerColorMarronDisponible ();

		RGBApixel obtenerColorMarronPodrido ();

		RGBApixel obtenerColorMarronSeco ();

		RGBApixel obtenerColorVerdeDisponible ();

		RGBApixel obtenerColorAmarilloCultivo ();

		RGBApixel obtenerColorAzulAgua ();

		RGBApixel obtenerColorVioletaCosechar ();

		int obtenerGrosorBordes();

		//Post: muestra el terreno
		void pintarTodoElTerreno ();


		//Post: pinta el fondo de la imagen con el color asignado
		void pintarFondo ();


		//Post: pinta los vordes exteriores de la imagen
		void pintarBordesExteriores();


		//Post: pinta las divisiones internas del terreno segun la canitdad de filas y columnas
		void pintarBordesInternos ();


		//Pre: debe recibir alguno de los colores establecidos
		//Post: pinta la parcela seleccionada segun el estado que tenga
		void pintarParcela (RGBApixel color);


		//Post: determina de que color se pintara la parcela en base a su estado
		void determinarColor ();

		//Post: dibuja un cuadradito celeste si la parcela tiene que ser regada
		// y un cuadradito violeta si la parcela tiene que ser cosechada
		void dibujarCuadradito (RGBApixel color);

		//Post: guarda la imagen que se pinto en un archivo .bmp
		void guardarImagen ();
};



#endif /* GRANJEROSBMP_H_ */
