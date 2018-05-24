
#include "GranjerosBMP.h"

GranjerosBMP::GranjerosBMP () {

	marronDisponible.Red=130;
	marronDisponible.Green=47;
	marronDisponible.Blue=0;
	marronDisponible.Alpha= 1.0;

	verdeBordes.Red=0;
	verdeBordes.Green=160;
	verdeBordes.Blue=31;
	verdeBordes.Alpha= 1.0;

	violetaCosechar.Red=148;
	violetaCosechar.Green=0;
	violetaCosechar.Blue=132;
	violetaCosechar.Alpha= 1.0;

	amarilloCultivo.Red=248;
	amarilloCultivo.Green=255;
	amarilloCultivo.Blue=63;
	amarilloCultivo.Alpha= 1.0;

	azulAgua.Red=2;
	azulAgua.Green=173;
	azulAgua.Blue=234;
	azulAgua.Alpha= 1.0;

	marronPodrido.Red= 97;
	marronPodrido.Green= 68;
	marronPodrido.Blue = 19;
	marronPodrido.Alpha= 1.0;

	marronSeco.Red = 153;
	marronSeco.Green = 101;
	marronSeco.Blue = 21;
	marronSeco.Alpha = 1.0;

	resolucionColumna= 3000;
	resolucionFila= 3000;
	profundidadBit= 8;
	grosorBordes=30;

	imagen.SetSize(resolucionColumna,resolucionFila);
	imagen.SetBitDepth(profundidadBit);
	pixelesParcelaFila= imagen.TellHeight()/ terreno.obtenerFilas();
	pixelesParcelaColumna= imagen.TellWidth()/ terreno.obtenerColumnas();
}



int GranjerosBMP::obtenerPixelesParcelaColumna (){

	return pixelesParcelaColumna;
}


int GranjerosBMP::obtenerPixelesParcelaFila (){

	return pixelesParcelaFila;
}


BMP GranjerosBMP::obtenerImagen (){

	return imagen;
}


RGBApixel GranjerosBMP:: obtenerColorMarronDisponible (){

	return marronDisponible;
}


RGBApixel GranjerosBMP::obtenerColorMarronPodrido (){

	return marronPodrido;
}


RGBApixel GranjerosBMP::obtenerColorMarronSeco (){

	return marronSeco;
}


RGBApixel GranjerosBMP::obtenerColorVerdeDisponible (){

	return verdeBordes;
}


RGBApixel GranjerosBMP::obtenerColorAmarilloCultivo (){

	return amarilloCultivo;
}


RGBApixel GranjerosBMP::obtenerColorAzulAgua (){

	return azulAgua;
}


RGBApixel GranjerosBMP::obtenerColorVioletaCosechar (){

	return violetaCosechar;
}


int GranjerosBMP:: obtenerGrosorBordes(){

	return grosorBordes;
}


void GranjerosBMP:: pintarTodoElTerreno (){

	pintarFondo ();
	pintarBordesExteriores ();
	pintarBordesInternos ();
	determinarColor ();
	guardarImagen ();

}

void GranjerosBMP::pintarFondo (){

	for (int i = 0; i < imagen.TellHeight(); i++){
		for (int j = 0; j < imagen.TellWidth(); j++){
			imagen.SetPixel (i, j, marronDisponible);
		}
	}
}


void GranjerosBMP::pintarBordesExteriores(){

	for (int i = 0; i < imagen.TellWidth(); i++){
		for (int j= 0; j < grosorBordes; j++){
			imagen.SetPixel(i, j, verdeBordes);
			imagen.SetPixel(j, i, verdeBordes);
		}
	}

	for (int i = 0; i < imagen.TellWidth(); i++){
		for (int j = (imagen.TellHeight() - grosorBordes); j < imagen.TellHeight(); j++){
			imagen.SetPixel(i, j, verdeBordes);
			imagen.SetPixel(j, i, verdeBordes);
		}
	}
}


void GranjerosBMP::pintarBordesInternos (){

	do{
		int filas=terreno.obtenerFilas();
		filas--; //como filas = columnas, da lo mismo para cualquiera de los dos
		int filasP=filas*pixelesParcelaFila;
		for (int i = 0; i < imagen.TellHeight(); i++){
			for (int j = (filasP); j < (filasP + grosorBordes); j++){
				imagen.SetPixel(i, j, verdeBordes);
				imagen.SetPixel(j, i, verdeBordes);
			}
		}
	}
	while (terreno.obtenerFilas()>0);
}


void GranjerosBMP::pintarParcela (RGBApixel color){

	for (int i = ((terreno.obtenerColumnas() - 1) * pixelesParcelaColumna) + grosorBordes;
			i < ((terreno.obtenerColumnas() * pixelesParcelaColumna) - grosorBordes); i++){
		for (int j = ((terreno.obtenerFilas() - 1) *pixelesParcelaFila) + grosorBordes;
				j < ((terreno.obtenerFilas() * pixelesParcelaFila) - grosorBordes); j++){
			imagen.SetPixel (i, j, color);
		}
	}
}


void GranjerosBMP:: dibujarCuadradito (RGBApixel color){

	int posicionColumnaSimbolito = obtenerPixelesParcelaColumna()*(4/5);
	int posicionFilaSimbolito = obtenerPixelesParcelaFila()*(1/5);

	for (int i= posicionColumnaSimbolito; i < (posicionColumnaSimbolito+(posicionColumnaSimbolito/10)); i++){
		for (int j= posicionFilaSimbolito; j < (posicionFilaSimbolito+(posicionFilaSimbolito/10)); j++){
			imagen.SetPixel(i, j, color);
		}
	}
}


void GranjerosBMP::determinarColor (){

	if (!parcelaArg.estaPodrida() )
		pintarParcela (marronPodrido);

	else if (!parcelaArg.estaSeca() )
		pintarParcela (marronSeco);

	else if (parcelaArg.estaDisponible() )
		pintarParcela (marronDisponible);

	else
		pintarParcela (amarilloCultivo);


	if (parcelaArg.estaRegada() )
		dibujarCuadradito (azulAgua);

	else if (!parcelaArg.estaOcupada() && parcelaArg.cultivoParcela.obtenerTiempoCosecha()==0)
			dibujarCuadradito (violetaCosechar);

}


void GranjerosBMP:: guardarImagen (){

	imagen.WriteToFile("granjeros.bmp");

}






















