/*
 * Destino.cpp
 *
 *  Created on: 1 may. 2018
 *      Author: tomas
 */

#include "../src/Destino.h"

using namespace std;

Destino::Destino(char cultivoBuscado){
	Lista<string> listaLineasDestino;
	this->costoEnvio = 0;
	this->cultivo = cultivoBuscado;
	this->distancia = 0;
	this->nombreDestino = DESTINO_INEXISTENTE;
	leerInformacionDeArchivo(listaLineasDestino);
	this->elegioUnDestino = guardarInformacionDeArchivo(listaLineasDestino);

}

void Destino::leerInformacionDeArchivo(Lista<string>& listaLineasDestino){
	string lineaLeida;
	ifstream archivo(RUTA_DESTINOS);

	if(!archivo.is_open())
		throw string("ERROR APERTURA DE ARCHIVO");
	while(!archivo.eof()){

		getline(archivo, lineaLeida);
		size_t tamanio = lineaLeida.size();
		if(lineaLeida[tamanio - 1] == this->cultivo){
			listaLineasDestino.agregarElemento(lineaLeida);
		}
	}

	archivo.close();

}

bool Destino::guardarInformacionDeArchivo(Lista<string>& listaLineasDestino){
	string informacion;
	cout << "A continuacion se mostrara por "
			"pantalla los destinos, seleccionar"
			" 's' para enviar a dicho destino o "
			"n para continuar leyendo registros." << endl;

	listaLineasDestino.iniciarCursor();
	bool eleccion = true;
	char seleccion;
	while(eleccion && listaLineasDestino.avanzarCursor()){
		string aux;
		string informacion = listaLineasDestino.obtenerCursor();
		this->nombreDestino = informacion.substr(0, informacion.find(','));
		cout << "Desea enviar el cultivo a: "
				<< nombreDestino << "?" << endl;
		cin >> seleccion;
		if(seleccion == 's'){
			eleccion = false;
			size_t posicionInicial = informacion.find(',') + 2;
			size_t desplazamiento = informacion.find(',', posicionInicial) - posicionInicial;

			aux = informacion.substr(posicionInicial, desplazamiento);

			istringstream buffer(aux);
			buffer >> this->distancia;

			posicionInicial = posicionInicial + 2 + desplazamiento;
			desplazamiento = informacion.find(',', posicionInicial) - posicionInicial;

			aux = informacion.substr(posicionInicial, desplazamiento);

			istringstream buffer2(aux);
			buffer2 >> this->costoEnvio;
		}

	}
	return !eleccion;
}

char Destino::mostrarCultivo(){
	return this->cultivo;
}

string Destino::mostrarNombreDestino(){

	return this->nombreDestino;
}

int Destino::mostrarDistancia(){
	return this->distancia;
}

int Destino::mostrarCostoEnvio(){

	return this->costoEnvio;
}

bool Destino::seSeleccionoUnPedido(){
	return this->elegioUnDestino;
}

Destino::~Destino() {
	// TODO Auto-generated destructor stub
}

