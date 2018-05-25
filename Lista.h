#ifndef LISTA_H_
#define LISTA_H_

#include <iostream>

#include "../src/Nodo.h"

template<class T> class Lista {

    private:

        Nodo<T>* primero;

        unsigned int tamanio;

        Nodo<T>* cursor;

    public:

        /*
         * post: Lista vacía.
         */
        Lista();

        /*
         * post: Lista que tiene los mismos elementos que otraLista.
         *       La instancia resulta en una copia de otraLista.
         */
        Lista(Lista<T>& otraLista);

        /*
         * post: indica si la Lista tiene algún elemento.
         */
        bool estaVacia();

        /*
         * post: devuelve la cantidad de elementos que tiene la Lista.
         */
        unsigned int contarElementos();

        /*
         * post: agrega el elemento al final de la Lista, en la posición:
         *       contarElementos() + 1.
         */
        void agregarElemento(T elemento);

        /*
         * pre : posición pertenece al intervalo: [1, contarElementos() + 1]
         * post: agrega el elemento en la posición indicada.
         *
         */
        void agregar(T elemento, unsigned int posicion);

        /*
         * post: agrega todos los elementos de otraLista
         *       a partir de la posición contarElementos() + 1.
         */
        void agregar(Lista<T> &otraLista);

        /*
         * pre : posición pertenece al intervalo: [1, contarElementos()]
         * post: devuelve el elemento en la posición indicada.
         */
        T mostrarElemento(unsigned int posicion);

        /*
         * pre : posicioó pertenece al intervalo: [1, contarElementos()]
         * post: cambia el elemento en la posición indicada por el
         *       elemento dado.
         */
        void asignar(T elemento, unsigned int posicion);

        /*
         * pre : posición pertenece al intervalo: [1, contarElementos()]
         * post: remueve de la Lista el elemento en la posición indicada.
         */
        void eliminarElemento(unsigned int posicion);

        /*
         * post: deja el cursor de la Lista preparado para hacer un nuevo
         *       recorrido sobre sus elementos.
         */
        void iniciarCursor();

        /*
         * pre : se ha iniciado un recorrido (invocando el método
         *       iniciarCursor()) y desde entonces no se han agregado o
         *       removido elementos de la Lista.
         * post: mueve el cursor y lo posiciona en el siguiente elemento
         *       del recorrido.
         *       El valor de retorno indica si el cursor quedó posicionado
         *       sobre un elemento o no (en caso de que la Lista esté vacía o
         *       no existan más elementos por recorrer.)
         */
        bool avanzarCursor();

        /*
         * pre : el cursor está posicionado sobre un elemento de la Lista,
         *       (fue invocado el método avanzarCursor() y devolvió true)
         * post: devuelve el elemento en la posición del cursor.
         *
         */
        T obtenerCursor();

        /*
         * post: Devuelve el tamanio de la lista.
         */
        int obtenerTamanio();

        /*
         * post: Retorna un puntero del Nodo indicado en dicha posicion
         */
        Nodo<T>* obtenerPunteroNodo(unsigned int posicion);

        /*
         * post: Muesta el elemento
         */
        T mostrarElemento();

        /*
         * post: Elimina todos los elementos de la lista.
         */
        void eliminarElementos();


        /*
         * post: libera los recursos asociados a la Lista.
         */
        ~Lista();

    private:

        /*
         * pre : posición pertenece al intervalo: [1, contarElementos()]
         * post: devuelve el nodo en la posición indicada.
         */
        T obtenerNodo(unsigned int posicion); // NOTA: primitiva PRIVADA
};

template<class T> Lista<T>::Lista() {

    this->primero = NULL;
    this->tamanio = 0;
    this->cursor = NULL;
}

template<class T> Lista<T>::Lista(Lista<T>& otraLista) {

    this->primero = NULL;
    this->tamanio = 0;
    this->cursor = NULL;

    /* copia los elementos de otraLista */
    this->agregar(otraLista);
}

template<class T> bool Lista<T>::estaVacia() {

    return (this->tamanio == 0);
}

template<class T> unsigned int Lista<T>::contarElementos() {

    return this->tamanio;
}

template<class T> void Lista<T>::agregarElemento(T elemento) {

    this->agregar(elemento, this->tamanio + 1);
}

template<class T> void Lista<T>::agregar(T elemento, unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio + 1)) {

        Nodo<T>* nuevo = new Nodo<T>(elemento);

        if (posicion == 1) {

            nuevo->modificarSiguiente(this->primero);
            this->primero = nuevo;

        } else {

            Nodo<T>* anterior = obtenerPunteroNodo(posicion - 1);
            nuevo->modificarSiguiente(anterior->obtenerSiguiente());
            anterior->modificarSiguiente(nuevo);
        }

        this->tamanio++;

        /* cualquier recorrido actual queda invalidado */
        this->iniciarCursor();
    }

}

template<class T> void Lista<T>::agregar(Lista<T> &otraLista) {

    otraLista.iniciarCursor();
    while (otraLista.avanzarCursor()) {
        this->agregar(otraLista.obtenerCursor());
    }
}


template<class T> T Lista<T>::obtenerNodo(unsigned int posicion) {

    T elemento;

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        elemento = this->obtenerNodo(posicion);
    }

    return elemento;
}

template<class T> void Lista<T>::asignar(T elemento, unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        this->obtenerNodo(posicion)->cambiarDato(elemento);
    }
}

template<class T> void Lista<T>::eliminarElemento(unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        Nodo<T>* removido;

        if (posicion == 1) {

            removido = this->primero;
            this->primero = removido->obtenerSiguiente();

        } else {

            Nodo<T>* anterior = this->obtenerPunteroNodo(posicion - 1);
            removido = anterior->obtenerSiguiente();
            anterior->modificarSiguiente(removido->obtenerSiguiente());
        }

        delete removido;
        this->tamanio--;

        /* cualquier recorrido actual queda invalidado */
        this->iniciarCursor();
    }
}

template<class T> void Lista<T>::iniciarCursor() {

    this->cursor = NULL;
}

template<class T> bool Lista<T>::avanzarCursor() {

    if (this->cursor == NULL) {

        this->cursor = this->primero;

    } else {

        this->cursor = this->cursor->obtenerSiguiente();
    }

    /* pudo avanzar si el cursor ahora apunta a un nodo */
    return (this->cursor != NULL);
}

template<class T> T Lista<T>::obtenerCursor() {

    T elemento;

    if (this->cursor != NULL) {

        elemento = this->cursor->obtenerDato();
    }

    return elemento;
}

template<class T> Lista<T>::~Lista() {

    while (this->primero != NULL) {

        Nodo<T>* aBorrar = this->primero;
        this->primero = this->primero->obtenerSiguiente();

        delete aBorrar;
    }
}

template<class T> Nodo<T>* Lista<T>::obtenerPunteroNodo(unsigned int posicion) {

    Nodo<T>* actual = this->primero;
    for (unsigned int i = 1; i < posicion; i++) {

        actual = actual->obtenerSiguiente();
    }

    return actual;
}

template < class T > T Lista<T>::mostrarElemento(unsigned int posicion){

	Nodo<T>* nodoAux = obtenerPunteroNodo(posicion);

	return nodoAux->obtenerDato();
}

template < class T > int Lista<T>::obtenerTamanio(){

	return this->tamanio;
}

template < class T > void Lista<T>::eliminarElementos(){

	while (this->primero != NULL) {

	        Nodo<T>* aBorrar = this->primero;
	        this->primero = this->primero->obtenerSiguiente();

	        delete aBorrar;
	    }
	tamanio = 0;
}




#endif /* SRC_LISTA_H_ */
