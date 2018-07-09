/*
 * Dibujador.h
 *
 *  Created on: 11/06/2018
 *      Author: algo2
 */

#ifndef SRC_DIBUJADOR_H_
#define SRC_DIBUJADOR_H_

#include "EasyBMP.h"
#include "Jugador.h"
#include <string>
#include <stdlib.h>

int const TAMANIO_PARCELA = 36;
std::string const BMP_P_VACIA = "parcelaVacia.bmp";
std::string const BMP_P_PODRIDA = "parcelaPodrida.bmp";
std::string const BMP_P_SEMBRADA = "parcelaSembrada.bmp";
std::string const BMP_P_COSECHAR = "parcelaACosechar.bmp";
std::string const BMP_P_SECA = "parcelaSeca.bmp";
std::string const BMP_P_REGADA = "parcelaRegada.bmp";
std::string const BMP_P_NODISP = "parcelaNoDisp.bmp";


class Dibujador{
	private:

		BMP unaImagen;

		/*
		 * post: Devuelve un pixel color Marron.
		 */
		RGBApixel colorMarron();

		/*
		 * post: Devuelve un pixel color Negro.
		 */
		RGBApixel colorNegro();

		/*
		 * post: Devuelve un pixel color de las Semillas.
		 */
		RGBApixel colorSemilla();

		/*
		 * post: Devuelve un pixel color que representara a una semilla regada.
		 */
		RGBApixel colorRiego();

		/*
		 * post: Devuelve un pixel color indicador de podrido.
		 */
		RGBApixel colorPodrida();

		/*
		 * post: Devuelve un pixel color Verde.
		 */
		RGBApixel colorCosechar();

		/*
		 * post: Devuelve un pixel color indicador de seco.
		 */
		RGBApixel colorSeca();

		/*
		 * pre: Se requiere pasar un bitmap creado como una parcela vacia, para
		 * 		poder dibujar el indicador sobre ella, fila y columna deben ser numeros
		 * 		enteros, mayores o iguales a 0.
		 * post: Dibuja el indicador en en el medio de la parcela.
		 */
		void dibujarIndicadorSemilla(BMP* bmp, int fila, int columna);

		/*
		 * pre: Se requiere pasar un bitmap creado como una parcela vacia, para
		 * 		poder dibujar el indicador sobre ella, fila y columna deben ser numeros
		 * 		enteros, mayores o iguales a 0.
		 * post: Dibuja el indicador de parcela podrida en en el medio de la parcela.
		 */
		void dibujarIndicadorPodrida(BMP* bmp, int fila, int columna);

		/*
		 * pre: Se requiere pasar un bitmap creado como una parcela vacia, para
		 * 		poder dibujar el indicador sobre ella, fila y columna deben ser numeros
		 * 		enteros, mayores o iguales a 0.
		 * post: Dibuja el indicador de parcela seca en el medio de la parcela.
		 */
		void dibujarIndicadorSeca(BMP* bmp, int fila, int columna);

		/*
		 * pre: Se requiere pasar un bitmap creado como una parcela vacia, para
		 * 		poder dibujar el indicador sobre ella, fila y columna deben ser numeros
		 * 		enteros, mayores o iguales a 0.
		 * post: Dibuja el indicador de riego en la en el medio de la parcela.
		 */
		void dibujarIndicadorRiego(BMP* bmp, int fila, int columna);

		/*
		 * post: Dibuja una linea Horizontal en la fila indicada por parametro.
		 */
		void dibujarLineaHorizontalGrosor3(BMP* bmp, int fila);

		/*
		 * post: Dibuja una linea Vertical en la columna indicada por parametro.
		 */
		void dibujarLineaVerticalGrosor3(BMP* bmp, int columna);

		/*
		 * post: Crea un template de una parcela sembrada para ser usada por el dibujador
		 */
		void dibujarParcelaSembrada();

		/*
		 * post: Crea un template de una parcela seca para ser usada por el dibujador
		 */
		void dibujarParcelaSeca();

		/*
		 * post: Crea un template de una parcela vacia para ser usada por el dibujador
		 */
		void dibujarParcelaVacia();

		/*
		 * post: Crea un template de una parcela podrida para ser usada por el dibujador
		 */
		void dibujarParcelaPodrida();

		/*
		 * post: Crea un template de una parcela a cosechar para ser usada por el dibujador
		 */
		void dibujarParcelaACosechar();

		/*
		 * post: Crea un template de una parcela regada para ser usada por el dibujador
		 */
		void dibujarParcelaRegadaTemplate();

		/*
		 * post: Crea un template de una parcela no disponible para ser usada por el dibujador
		 */
		void dibujarNoDisponible();

		/*
		 * pre: terrenoBmp debe existir, debe tener una dimension de parcelas de igual tamaño
		 * 		que tope, y el terreno,debe existir.
		 * post: actualiza el Bmp pasado por parametro, con respecto al terreno.
		 */
		void actualizarBMP(BMP& terrenoBmp, Parcela** terreno, int tope);

	public:

		/*
		 * post: Crea un objeto dibujador.
		 */
		Dibujador();

		/*
		 * pre: el jugador debe haberce inicializado, y debe tener un numbre asignado.
		 * post: Crea un bmp con el terreno inicial del jugador, con todas sus parcelas vacias.
		 */
		void crearTerrenoInicial(Jugador* jugador);

		/*
		 * pre: parcela y terreno, deben ser dos bmp ya creados, fila y columna numeros enteros
		 * 		positivos.
		 * post: copia la "parcela" , en las coordenadas del "terreno".
		 */
		void dibujarParcelaEnTerreno(BMP& parcela, BMP& terreno, int fila, int columna);

		/*
		 * pre: terreno, fila y columna, deben ser numeros enteros positivos, el jugador debe
		 * 		tener un bmp creado correspondiente a las coordenadas pasadas.
		 * post: Dibuja el indicador de parcela podrida en las coordenadas del campo dadas
		 */
		void dibujarPudrirParcela(Jugador* jugador, int terreno, int fila, int columna);

		/*
		 * pre: terreno, fila y columna, deben ser numeros enteros positivos, el jugador debe
		 * 		tener un bmp creado correspondiente a las coordenadas pasadas.
		 * post: Dibuja el indicador de semilla plantada en las coordenadas del campo dadas
		 */
		void dibujarSemilla(Jugador* jugador, int terreno, int fila, int columna);

		/*
		 * pre:terreno, fila y columna, deben ser numeros enteros positivos, el jugador debe
		 * 		tener un bmp creado correspondiente a las coordenadas pasadas.
		 * post: Dibuja el indicador de parcela regada en las coordenadas del campo dadas
		 */
		void dibujarParcelaRegada(Jugador* jugador, int terreno, int fila, int columna);

		/*
		 * pre: el jugador debe tener menos de 9 terrenos
		 * post: crea un nuevo bmp para el jugador pasado por argumento
		 */
		void dibujarNuevoTerreno(Jugador* jugador);



		/*
		 * post: actualiza todos los bmp del jugador.
		 */
		void pasoDeTurnoJugador(Jugador* jugador);

		/*
		 * post: Crea los templates para ser usados por el dibujador.
		 */
		void crearTemplates();

		/*
		 * pre: terreno, fila y columna deben ser un numero entero mayor a cero, jugador, debe tener una
		 * 		parcela que este lista para ser cosechada en dichas coordenas de su campo.
		 * post: Dibuja en la parcela indicada por coordenadas, una parcela no disponible.
		 */
		void cosechar(Jugador* jugador, int terreno, int fila, int columna);

		/*
		 * pre: Se debe haber llamado previamente a la funcion "crearTemplates()".
		 * post: Elimina todos los templates creados por la funcion "crearTemplates()"
		 */
		void eliminarTemplates();

		/*
		 * pre: terreno debe ser un numero entero positivo, jugador debe tener por lo menos 1 terreno.
		 * post: Elimina el terreno, ubicado en la posicion valida.
		 */
		void eliminarTerreno(Jugador* jugador, int posicion);
};


#endif /* SRC_DIBUJADOR_H_ */
