/*
 * granjerosBMP.h
 *
 *  Created on: 06/05/2018
 *      Author: trini
 */

#include "EasyBMP.h"

#ifndef GRANJEROSBMP_H_
#define GRANJEROSBMP_H_


class GranjerosBMP{

	private:
		RGBApixel marronDisponible;
		RGBApixel verdeBordes;
		RGBApixel rojoA;
		RGBApixel amarilloB;
		RGBApixel azulC;


	public:
		GranjerosBMP();
		void pintarFondo (BMP imagen);
		void pintarBordesExteriores(BMP imagen);


};



#endif /* GRANJEROSBMP_H_ */
