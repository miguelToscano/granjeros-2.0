

#include "granjerosBMP.h"

using namespace std;



GranjerosBMP::GranjerosBMP(){

	marronDisponible.Red=130;

	marronDisponible.Green=47;

	marronDisponible.Blue=0;

	marronDisponible.Alpha=0;


	verdeBordes.Red=0;

	verdeBordes.Green=160;

	verdeBordes.Blue=31;

	verdeBordes.Alpha=0;


	rojoA.Red=255;

	rojoA.Green=8;

	rojoA.Blue=0;

	rojoA.Alpha=0;


	amarilloB.Red=248;

	amarilloB.Green=255;

	amarilloB.Blue=63;

	amarilloB.Alpha=0;


	azulC.Red=2;

	azulC.Green=173;

	azulC.Blue=234;

	azulC.Alpha=0;

}


void GranjerosBMP::pintarFondo (BMP imagen){

	for (int i=0; i<imagen.TellHeight();i++){

		for (int j=0; j<imagen.TellWidth();j++){

			imagen.SetPixel (i,j,marronDisponible);

		}

	}

}


void GranjerosBMP::pintarBordesExteriores(BMP imagen){

	for (int i=0; i<imagen.TellWidth();i++){
		for (int k=0; k<30; k++){
			imagen.SetPixel(i,k,verdeBordes);
			imagen.SetPixel(k,i,verdeBordes);
		}
	}

	for (int i=0; i<imagen.TellWidth();i++){
		for (int k=2970; k<imagen.TellHeight(); k++){
			imagen.SetPixel(i,k,verdeBordes);
			imagen.SetPixel(k,i,verdeBordes);
		}
	}
}


void GranjerosBMP::pintarBordesInternos (BMP imagen, int fila, int columna){

	int pixelesParcelaFila= imagen.TellHeight()/ fila;

	int n=1;


	while (n<fila){

		for (int i=0; i<imagen.TellHeight();i++){

			for (int k=(n*pixelesParcelaFila); k<((n*pixelesParcelaFila)+30); k++){

				imagen.SetPixel(i,k,verdeBordes);

			}

			n++;

		}

	}


	int pixelesParcelaColumna= imagen.TellWidth()/ columna;

	while (n<columna){

		for (int i=0; i<imagen.TellWidth();i++){

			for (int k=(n*pixelesParcelaColumna); k<((n*pixelesParcelaColumna)+30); k++){

				imagen.SetPixel(i,k,verdeBordes);

			}

			n++;

		}

	}

}























