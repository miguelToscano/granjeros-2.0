
/*
 * granjerosBMP.h
 *
 *  Created on: 06/05/2018
 *      Author: trini
 */

#include "EasyBMP.h"
#include "Cultivo.h"
#include "Campo.h"
#include "Parcela.h"


#ifndef GRANJEROSBMP_H_

#define GRANJEROSBMP_H_


class GranjerosBMP{

	private:

		RGBApixel marronDisponible;
		RGBApixel verdeBordes;
		RGBApixel rojoA;
		RGBApixel amarilloB;
		RGBApixel azulC;
		RGBApixel marronPodrido;
		RGBApixel marronSeco;

		BMP imagen;

		int resolucionFila;
		int resolucionColumna;
		int profundidadBit;
		int pixelesParcelaFila;
		int pixelesParcelaColumna;
		int grosorBordes;

	public:

		//Constructor
		GranjerosBMP();


		//Post: setea la resolucion de la imagen y los pixeles de las filas y columnas
		GranjerosBMP (BMP imagen, Campo terreno);


		//Post: devuelve los pixeles por columna
		int obtenerPixelesParcelaColumna ();


		//Post: devuelve los pixeles por fila
		int obtenerPixelesParcelaFila ();


		//Post: pinta el fondo de la imagen con el color asignado
		void pintarFondo (BMP imagen);


		//Post: pinta los vordes exteriores de la imagen
		void pintarBordesExteriores(BMP imagen);


		//Post: pinta las divisiones internas del terreno segun la canitdad de filas y columnas
		void pintarBordesInternos (BMP imagen, Campo terreno);


		//Pre: debe recibir uno de los colores establecidos
		//Post: pinta la parcela seleccionada segun el estado que tenga
		void pintarParcela (BMP imagen, RGBApixel color, Campo terreno);


		//Post: determina de que color se pintara la parcela en base a su estaado
		void determinarColor (BMP imagen, Campo terreno, Parcela parcelaArg, Cultivo cultivoParcela);


		//Post: guarda la imagen que se pinto en un archivo .bmp
		void guardarImagen (BMP imagen);
};



#endif /* GRANJEROSBMP_H_ */
