
#ifndef DESTINOS_H_
#define DESTINOS_H_

#include <string>
#include <fstream>

using namespace std;

class DestinosAristas{

	private:

		string origen;
		string destino;
		unsigned int costo;
		char tipoCultivo;

	public:

		DestinosAristas();
		string obtenerOrigen ();
		string obtenerDestino();
		unsigned int obtenerCosto ();
		char obtenerTipoCultivo ();
		void setearOrigen (string origenArchivo);
		void setearDestino (string destinoArchivo);
		void setearCosto (unsigned int costoArchivo);
		void setearTipoCultivo (char tipoCultivoArchivo);

};

#endif /* DESTINOS_H_ */
