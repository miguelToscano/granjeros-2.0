
#include "GranjerosBMP.h"

GranjerosBMP::GranjerosBMP (BMP imagen, Campo terreno){

	imagen.SetSize(resolucionColumna,resolucionFila);
	imagen.SetBitDepth(profundidadBit);
	pixelesParcelaFila= imagen.TellHeight()/ terreno.obtenerFilas();
	pixelesParcelaColumna= imagen.TellWidth()/ terreno.obtenerColumnas();
}

GranjerosBMP::GranjerosBMP(){

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
}



int GranjerosBMP::obtenerPixelesParcelaColumna (){

	return pixelesParcelaColumna;
}


int GranjerosBMP::obtenerPixelesParcelaFila (){

	return pixelesParcelaFila;
}


void GranjerosBMP:: pintarTodoElTerreno (BMP imagen){

	pintarFondo (imagen);
	pintarBordesExteriores (imagen);
	pintarBordesInternos (imagen, terreno);
	determinarColor (imagen, terreno, parcelaArg, cultivoParcela);
	guardarImagen (imagen);

}

void GranjerosBMP::pintarFondo (BMP imagen){

	for (int i = 0; i < imagen.TellHeight(); i++){
		for (int j = 0; j < imagen.TellWidth(); j++){
			imagen.SetPixel (i, j, marronDisponible);
		}
	}
}


void GranjerosBMP::pintarBordesExteriores(BMP imagen){

	for (int i = 0; i < imagen.TellWidth(); i++){
		for (int k = 0; k < grosorBordes; k++){
			imagen.SetPixel(i, k, verdeBordes);
			imagen.SetPixel(k, i, verdeBordes);
		}
	}

	for (int i = 0; i < imagen.TellWidth(); i++){
		for (int k = (imagen.TellHeight() - grosorBordes); k < imagen.TellHeight(); k++){
			imagen.SetPixel(i, k, verdeBordes);
			imagen.SetPixel(k, i, verdeBordes);
		}
	}
}


void GranjerosBMP::pintarBordesInternos (BMP imagen, Campo terreno){

	int n=1;

	while (n < terreno.obtenerFilas() ){
		for (int i = 0; i < imagen.TellHeight(); i++){
			for (int k = (n*pixelesParcelaFila); k < ((n*pixelesParcelaFila) + grosorBordes); k++){
				imagen.SetPixel(i, k, verdeBordes);
			}
			n++;
		}
	}

	while (n < terreno.obtenerColumnas() ){
		for (int i = 0; i < imagen.TellWidth(); i++){
			for (int k = (n*pixelesParcelaColumna); k < ((n*pixelesParcelaColumna) + grosorBordes); k++){
				imagen.SetPixel(i, k, verdeBordes);
			}
			n++;
		}
	}
}


void GranjerosBMP::pintarParcela (BMP imagen, RGBApixel color, Campo terreno){

	for (int i = ((terreno.obtenerColumnas() - 1) * pixelesParcelaColumna) + grosorBordes; i < ((terreno.obtenerColumnas() * pixelesParcelaColumna) - grosorBordes); i++){
		for (int j = ((terreno.obtenerFilas() - 1) *pixelesParcelaFila) + grosorBordes; j < ((terreno.obtenerFilas() * pixelesParcelaFila) - grosorBordes); j++){
			imagen.SetPixel (i, j, color);
		}
	}
}


void GranjerosBMP:: dibujarCuadradito (BMP imagen, RGBApixel color){

	int posicionColumnaSimbolito = obtenerPixelesParcelaColumna()*(4/5);
	int posicionFilaSimbolito = obtenerPixelesParcelaFila()*(1/5);

	for (int i= posicionColumnaSimbolito; i < (posicionColumnaSimbolito+(posicionColumnaSimbolito/10)); i++){
		for (int j= posicionFilaSimbolito; j < (posicionFilaSimbolito+(posicionFilaSimbolito/10)); j++){
			imagen.SetPixel(i, j, color);
		}
	}
}


void GranjerosBMP::determinarColor (BMP imagen, Campo terreno, Parcela parcelaArg, Cultivo cultivoParcela){

	if (!parcelaArg.estaPodrida() )
		pintarParcela (imagen, marronPodrido, terreno);

	else if (!parcelaArg.estaSeca() )
		pintarParcela (imagen, marronSeco, terreno);

	else if (parcelaArg.estaDisponible() )
		pintarParcela (imagen, marronDisponible, terreno);

	else
		pintarParcela (imagen, amarilloCultivo, terreno);


	if (parcelaArg.estaRegada() )
		dibujarCuadradito (imagen, azulAgua);

	else if (!parcelaArg.estaOcupada() && parcelaArg.cultivoParcela.obtenerTiempoCosecha()==0)
			dibujarCuadradito(imagen, violetaCosechar);

}


void GranjerosBMP:: guardarImagen (BMP imagen){

	imagen.WriteToFile("granjeros.bmp");

}






















