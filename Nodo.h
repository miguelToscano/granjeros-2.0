#ifndef NODO_H_
#define NODO_H_

template < typename dato >
class Nodo {

private:

	dato datoDelNodo;

	Nodo<dato>* siguienteNodo;

public:

	Nodo();

	void modificarSiguiente(Nodo<dato>* siguienteNodo);

	void modificarDato(dato datoNuevo);

	dato mostrarDato();

	Nodo<dato>* mostrarSiguiente();

	virtual ~Nodo();

};

template < typename dato >
Nodo<dato>::Nodo(){

	this->siguienteNodo = 0;
}

template < typename dato >
void Nodo<dato>::modificarSiguiente(Nodo<dato>* siguienteNodo){

	this->siguienteNodo = siguienteNodo;
}

template < typename dato >
void Nodo<dato>::modificarDato(dato datoNuevo){

	this->datoDelNodo = datoNuevo;
}

template < typename dato >
dato Nodo<dato>::mostrarDato(){

	return this->datoDelNodo;
}

template < typename dato >
Nodo<dato>* Nodo<dato>::mostrarSiguiente(){

	return this->siguienteNodo;
}

template < typename dato >
Nodo<dato>::~Nodo(){

}

#endif
