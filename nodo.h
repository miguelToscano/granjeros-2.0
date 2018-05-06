#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif

template<class T> class Nodo {

    private:

        T dato;

        Nodo<T>* siguiente;

        Nodo<T>* anterior;

    public:

        /*
         * post: el Nodo resulta inicializado con el dato dado
         *       y sin un Nodo siguiente.
         */


        Nodo(T dato) {

            this->dato = dato;
            this->siguiente = NULL;
            this->anterior = NULL;
        }

        /*
         * post: devuelve el valor del dato.
         */
        T obtenerDato() {

            return this->dato;
        }

        /*
         * post: cambia el valor del dato.
         */
        void cambiarDato(T nuevoDato) {

            this->dato = nuevoDato;
        }

        /*
         * post: devuelve el siguiente Nodo.
         */
        Nodo<T>* obtenerSiguiente() {

            return this->siguiente;
        }

        /*
         * post: cambia el siguiente Nodo por nuevoSiguiente.
         */
        void cambiarSiguiente(Nodo<T>* nuevoSiguiente) {

            this->siguiente = nuevoSiguiente;
        }

        /*
         * post: obtiene el anterior Nodo.
         */
        Nodo<T>* obtenerAnterior(Nodo<T>* obtenerAnterior){
        	return this->anterior;
        }

        /*
         * post: cambia el anterior Nodo por nuevoSiguiente.
         */
        void cambiarAnterior(Nodo<T>* nuevoAnterior) {

            this->siguiente = nuevoAnterior;
        }
};


#endif /* NODO_H_ */
