/*
 * Dibujador.cpp
 *
 *  Created on: 11/06/2018
 *      Author: algo2
 */


#include "Dibujador.h"

Dibujador::Dibujador(){
}

RGBApixel Dibujador::colorMarron(){
	RGBApixel pixelMarron;
	pixelMarron.Blue = 0;
	pixelMarron.Red = 204;
	pixelMarron.Green = 102;
	return pixelMarron;
}

RGBApixel Dibujador::colorCosechar(){
	RGBApixel pixelVerde;
	pixelVerde.Blue = 0;
	pixelVerde.Red = 0;
	pixelVerde.Green = 235;
	return pixelVerde;
}

RGBApixel Dibujador::colorRiego(){
	RGBApixel pixelRiego;
	pixelRiego.Blue = 235;
	pixelRiego.Red = 0;
	pixelRiego.Green = 160;
	return pixelRiego;
}

RGBApixel Dibujador::colorNegro(){
	RGBApixel pixelNegro;
	pixelNegro.Blue = 0;
	pixelNegro.Red = 0;
	pixelNegro.Green = 0;
	return pixelNegro;
}

RGBApixel Dibujador::colorSemilla(){
	RGBApixel pixelSemilla;
	pixelSemilla.Blue = 51;
	pixelSemilla.Red = 153;
	pixelSemilla.Green = 255;
	return pixelSemilla;
}

RGBApixel Dibujador::colorSeca(){
	RGBApixel pixelSemilla;
	pixelSemilla.Blue = 0;
	pixelSemilla.Red = 255;
	pixelSemilla.Green = 204;
	return pixelSemilla;
}

RGBApixel Dibujador::colorPodrida(){
	RGBApixel pixelPodrida;
	pixelPodrida.Blue = 102;
	pixelPodrida.Red = 153;
	pixelPodrida.Green = 51;
	return pixelPodrida;
}

void Dibujador::dibujarParcelaVacia(){
	BMP parcela;
	parcela.SetSize(TAMANIO_PARCELA,TAMANIO_PARCELA);
	for(int i = 0; i < TAMANIO_PARCELA; i++){
		for(int j = 0; j < TAMANIO_PARCELA; j++){
			parcela.SetPixel(i,j, colorMarron());
		}
	}
	dibujarLineaHorizontalGrosor3(&parcela, 0);
	dibujarLineaHorizontalGrosor3(&parcela, TAMANIO_PARCELA-3);
	dibujarLineaVerticalGrosor3(&parcela, 0);
	dibujarLineaVerticalGrosor3(&parcela, TAMANIO_PARCELA-3);
	parcela.WriteToFile(BMP_P_VACIA.c_str());
}

void Dibujador::dibujarParcelaACosechar(){
	BMP parcela;
	parcela.SetSize(TAMANIO_PARCELA,TAMANIO_PARCELA);
	for(int i = 0; i < TAMANIO_PARCELA; i++){
		for(int j = 0; j < TAMANIO_PARCELA; j++){
			parcela.SetPixel(i,j, colorCosechar());
		}
	}
	dibujarLineaHorizontalGrosor3(&parcela, 0);
	dibujarLineaHorizontalGrosor3(&parcela, TAMANIO_PARCELA-3);
	dibujarLineaVerticalGrosor3(&parcela, 0);
	dibujarLineaVerticalGrosor3(&parcela, TAMANIO_PARCELA-3);
	parcela.WriteToFile(BMP_P_COSECHAR.c_str());
}

void Dibujador::dibujarParcelaPodrida(){
	BMP parcela;
	parcela.ReadFromFile(BMP_P_VACIA.c_str());
	dibujarIndicadorPodrida(&parcela, 0, 0);
	parcela.WriteToFile(BMP_P_PODRIDA.c_str());
}

void Dibujador::dibujarNoDisponible(){
	BMP parcela;
	parcela.ReadFromFile(BMP_P_VACIA.c_str());
	int indicador = (TAMANIO_PARCELA/2) - 3;
	dibujarLineaHorizontalGrosor3(&parcela, indicador);
	dibujarLineaVerticalGrosor3(&parcela, indicador);
	parcela.WriteToFile(BMP_P_NODISP.c_str());
}

void Dibujador::dibujarParcelaSembrada(){
	BMP parcela;
	parcela.ReadFromFile(BMP_P_VACIA.c_str());
	dibujarIndicadorSemilla(&parcela, 0, 0);
	parcela.WriteToFile(BMP_P_SEMBRADA.c_str());
}

void Dibujador::dibujarParcelaRegadaTemplate(){
	BMP parcela;
	parcela.ReadFromFile(BMP_P_VACIA.c_str());
	dibujarIndicadorRiego(&parcela, 0, 0);
	parcela.WriteToFile(BMP_P_REGADA.c_str());
}

void Dibujador::dibujarParcelaSeca(){
	BMP parcela;
	parcela.ReadFromFile(BMP_P_VACIA.c_str());
	dibujarIndicadorSeca(&parcela, 0, 0);
	parcela.WriteToFile(BMP_P_SECA.c_str());
}

void Dibujador::dibujarLineaHorizontalGrosor3(BMP* bmp, int fila){
	for(int i = 0; i < TAMANIO_PARCELA; i++){
			bmp->SetPixel(i,fila, colorNegro());
			bmp->SetPixel(i,fila + 1, colorNegro());
			bmp->SetPixel(i, fila + 2, colorNegro());
		}
}

void Dibujador::dibujarLineaVerticalGrosor3(BMP* bmp, int fila){
	for(int i = 0; i < TAMANIO_PARCELA; i++){
			bmp->SetPixel(fila,i, colorNegro());
			bmp->SetPixel(fila + 1,i, colorNegro());
			bmp->SetPixel(fila + 2,i, colorNegro());
		}
}

void Dibujador::dibujarIndicadorSemilla(BMP* bmp, int fila, int columna){

	fila = (fila + (TAMANIO_PARCELA/2) - 2) ;
	columna = (columna + (TAMANIO_PARCELA/2) - 2) ;

	int filaCorte = fila + 4;
	int columnaCorte = columna + 4;

	for(; fila < filaCorte; fila++){
		for(; columna < columnaCorte; columna++){
			bmp->SetPixel(fila,columna, colorSemilla());
		}
		columna = columna -4;
	}
}

void Dibujador::dibujarIndicadorRiego(BMP* bmp, int fila, int columna){

	fila = (fila + (TAMANIO_PARCELA/2) - 2) ;
	columna = (columna + (TAMANIO_PARCELA/2) - 2) ;

	int filaCorte = fila + 4;
	int columnaCorte = columna + 4;

	for(; fila < filaCorte; fila++){
		for(; columna < columnaCorte; columna++){
			bmp->SetPixel(fila,columna, colorRiego());
		}
		columna = columna -4;
	}
}

void Dibujador::dibujarIndicadorPodrida(BMP* bmp, int fila, int columna){

	fila = (fila + (TAMANIO_PARCELA/2) - 6) ;
	columna = (columna + (TAMANIO_PARCELA/2) - 6) ;

	int filaCorte = fila + 12;
	int columnaCorte = columna + 12;

	for(; fila < filaCorte; fila++){
		for(; columna < columnaCorte; columna++){
			bmp->SetPixel(fila,columna, colorPodrida());
		}
		columna = columna -12;
	}
}

void Dibujador::dibujarIndicadorSeca(BMP* bmp, int fila, int columna){

	fila = (fila + (TAMANIO_PARCELA/2) - 6) ;
	columna = (columna + (TAMANIO_PARCELA/2) - 6) ;

	int filaCorte = fila + 12;
	int columnaCorte = columna + 12;

	for(; fila < filaCorte; fila++){
		for(; columna < columnaCorte; columna++){
			bmp->SetPixel(fila,columna, colorSeca());
		}
		columna = columna -12;
	}
}

void Dibujador::dibujarParcelaEnTerreno(BMP& parcela, BMP& terreno, int fila, int columna){
	fila = fila * TAMANIO_PARCELA;
	columna = columna * TAMANIO_PARCELA;
	for(int i = 0; i < TAMANIO_PARCELA; i++){
			for(int j = 0; j < TAMANIO_PARCELA; j++){
				PixelToPixelCopy(parcela, i, j,
						terreno, i + columna, j + fila);
			}
	}
}


void Dibujador::crearTerrenoInicial(Jugador* jugador){
	dibujarNuevoTerreno(jugador);
}
std::string convertidor(int numero){
	std::string respuesta = "";
	switch(numero){
		case 1:
			respuesta = "1";
			break;
		case 2:
			respuesta = "2";
			break;
		case 3:
			respuesta = "3";
			break;
		case 4:
			respuesta = "4";
			break;
		case 5:
			respuesta = "5";
			break;
		case 6:
			respuesta = "6";
			break;
		case 7:
			respuesta = "7";
			break;
		case 8:
			respuesta = "8";
			break;
		case 9:
			respuesta = "9";
			break;
	}
	return respuesta;
}

void Dibujador::dibujarSemilla(Jugador* jugador, int terreno, int fila, int columna){
	std::string terrenoString = convertidor(terreno);
	std::string nombreArchivo = jugador->obtenerNombre() + "-" + terrenoString + ".bmp";
	BMP parcela;
	parcela.ReadFromFile(BMP_P_SEMBRADA.c_str());
	unaImagen.ReadFromFile(nombreArchivo.c_str());
	dibujarParcelaEnTerreno(parcela, unaImagen, fila, columna);
	unaImagen.WriteToFile(nombreArchivo.c_str());
}

void Dibujador::cosechar(Jugador* jugador, int terreno, int fila, int columna){
	std::string terrenoString = convertidor(terreno);
	std::string nombreArchivo = jugador->obtenerNombre() + "-" + terrenoString + ".bmp";
	BMP parcela;
	parcela.ReadFromFile(BMP_P_NODISP.c_str());
	unaImagen.ReadFromFile(nombreArchivo.c_str());
	dibujarParcelaEnTerreno(parcela, unaImagen, fila, columna);
	unaImagen.WriteToFile(nombreArchivo.c_str());
}

void Dibujador::dibujarParcelaRegada(Jugador* jugador, int terreno, int fila, int columna){
	std::string terrenoString = convertidor(terreno);
	std::string nombreArchivo = jugador->obtenerNombre() + "-" + terrenoString + ".bmp";
	BMP parcela;
	parcela.ReadFromFile(BMP_P_REGADA.c_str());
	unaImagen.ReadFromFile(nombreArchivo.c_str());
	dibujarParcelaEnTerreno(parcela, unaImagen, fila, columna);
	unaImagen.WriteToFile(nombreArchivo.c_str());
}

void Dibujador::dibujarPudrirParcela(Jugador* jugador, int terreno, int fila, int columna){
	std::string terrenoString = convertidor(terreno);
	std::string nombreArchivo = jugador->obtenerNombre() + "-" + terrenoString + ".bmp";
	BMP parcela;
	parcela.ReadFromFile(BMP_P_PODRIDA.c_str());
	unaImagen.ReadFromFile(nombreArchivo.c_str());
	dibujarParcelaEnTerreno(parcela, unaImagen, fila, columna);
	unaImagen.WriteToFile(nombreArchivo.c_str());
}

void Dibujador::dibujarNuevoTerreno(Jugador* jugador){
	this->unaImagen.SetSize(jugador->obtenerFilas() * TAMANIO_PARCELA,
				jugador->obtenerColumnas() * TAMANIO_PARCELA);
	std::string terrenoString = convertidor(jugador->obtenerCantidadTerrenos());
	BMP parcela;
	parcela.ReadFromFile(BMP_P_VACIA.c_str());
	for(int i = 0; i < jugador->obtenerFilas(); i++){
		for(int j = 0; j < jugador->obtenerColumnas(); j++){
			dibujarParcelaEnTerreno(parcela, unaImagen, i, j);
		}
	}
	std::string nombreArchivo = jugador->obtenerNombre() + "-"
			+ terrenoString + ".bmp";
	unaImagen.WriteToFile(nombreArchivo.c_str());
}


void Dibujador::pasoDeTurnoJugador(Jugador* jugador){
	for(int i = 1; i < jugador->obtenerCantidadTerrenos() + 1; i++){
		std::string terrenoString = convertidor(i);
		std::string nombreArchivo = jugador->obtenerNombre() + "-" +
				terrenoString + ".bmp";
		unaImagen.ReadFromFile(nombreArchivo.c_str());
		actualizarBMP(unaImagen, jugador->devolverCampo()->devolverTerreno(i),
				jugador->obtenerFilas());
		unaImagen.WriteToFile(nombreArchivo.c_str());

	}
}

void Dibujador::actualizarBMP(BMP& terrenoBmp, Parcela** terreno,int tope){
	int columna = 0;
	int fila = 0;
	BMP parcela;

	for(columna = 0; columna < tope; columna ++){
		for(fila = 0; fila < tope; fila ++){

			if(!terreno[fila][columna].estaOcupada()){

				if(terreno[fila][columna].estaDisponible()){
					parcela.ReadFromFile(BMP_P_VACIA.c_str());
				}else{
					parcela.ReadFromFile(BMP_P_NODISP.c_str());
				}
				if(terreno[fila][columna].estaPodrida()){
					parcela.ReadFromFile(BMP_P_PODRIDA.c_str());
				}
				if(terreno[fila][columna].estaSeca()){
					parcela.ReadFromFile(BMP_P_SECA.c_str());
				}


			}else{
				if(terreno[fila][columna].sePuedeCosechar()){
					parcela.ReadFromFile(BMP_P_COSECHAR.c_str());
				}else{
					parcela.ReadFromFile(BMP_P_SEMBRADA.c_str());
					if(terreno[fila][columna].estaPodrida()){
						parcela.ReadFromFile(BMP_P_PODRIDA.c_str());
					}
					if(terreno[fila][columna].estaSeca()){
						parcela.ReadFromFile(BMP_P_SECA.c_str());
					}

				}

			}
			dibujarParcelaEnTerreno(parcela, terrenoBmp, fila, columna);
		}
	}
}

void Dibujador::crearTemplates(){
	dibujarParcelaVacia();
	dibujarParcelaPodrida();
	dibujarParcelaSeca();
	dibujarParcelaSembrada();
	dibujarParcelaACosechar();
	dibujarNoDisponible();
	dibujarParcelaRegadaTemplate();
}

void Dibujador::eliminarTemplates(){
	remove(BMP_P_NODISP.c_str());
	remove(BMP_P_VACIA.c_str());
	remove(BMP_P_PODRIDA.c_str());
	remove(BMP_P_SEMBRADA.c_str());
	remove(BMP_P_REGADA.c_str());
	remove(BMP_P_COSECHAR.c_str());
	remove(BMP_P_SECA.c_str());
}

void Dibujador::eliminarTerreno(Jugador* jugador, int posicion){
	std::string templateString = jugador->obtenerNombre() + "-";
	std::string nombreArchivoAEliminar;
	std::string nombreViejo;
	std::string nombreNuevo;

	nombreArchivoAEliminar = templateString + convertidor(posicion) + ".bmp";
	remove(nombreArchivoAEliminar.c_str());
	if(posicion != jugador->obtenerCantidadTerrenos()){
		for(int i = posicion; i < jugador->obtenerCantidadTerrenos() + 1; i++){
			nombreNuevo = templateString + convertidor(i) + ".bmp";
			nombreViejo = templateString + convertidor(i + 1) + ".bmp";
			rename(nombreViejo.c_str(), nombreNuevo.c_str());
		}
	}

}
