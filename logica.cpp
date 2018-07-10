/*
 * logica.cpp
 *
 *  Created on: 13/06/2018
 *      Author: algo2
 */

#include "logica.h"


void imprimirMenu(){
	cout << "Seleccione una accion:" << endl
		<< "1. Regar parcela " << endl
		<< "2. Comprar terreno" << endl
		<< "3. Vender terreno" << endl
		<< "4. Sembrar" << endl
		<< "5. Cosechar" << endl
		<< "6. Comprar capacidad de tanque" << endl
		<< "7. Comprar capacidad de almacén" << endl
		<< "8. Enviar pedido" << endl
		<< "9. Pasar turno" << endl
		<< "10. Salir" << endl;
}

int obtenerOpcion(Jugador* jugador) {

    int opcionIngresada;
    jugador->imprimirInformacion();
    jugador->mostrarCampo();
    imprimirMenu();

    cin >> opcionIngresada;

    return opcionIngresada;
}

void validarTerreno(int* terreno, Jugador* jugador){
	do{
		cout << "Ingrese el numero de terreno: " << endl;
		cin >> *terreno;
		if(!jugador->esUnTerrenoValido(*terreno))
			cout << "Terreno Invalido" << endl;
	}
	while(!jugador->esUnTerrenoValido(*terreno));
}


void validarFila(int* fila, Jugador* jugador){
	do{
		cout << "Ingrese la fila" << endl;
		cin >> *fila;
		if(!jugador->esUnaFilaValida(*fila))
			cout << "Fila Invalida" << endl;
	}
	while(!jugador->esUnaFilaValida(*fila));
}

void cearListaGrafo(char tipoCultivo, Lista<DestinosAristas>* listaDestino){

	DestinosAristas destino;
	Lista<string> listaLineasDestino;
	string lineaLeida;
	ifstream archivo("destinos.txt");


	if(!archivo.is_open()){
		throw string("ERROR APERTURA DE ARCHIVO");
	}

	while(!archivo.eof()){
		getline(archivo, lineaLeida);
		listaLineasDestino.agregarElemento(lineaLeida);
	}

	archivo.close();
	cout << "linas leidas " << listaLineasDestino.contarElementos();
	listaLineasDestino.iniciarCursor();
	while(listaLineasDestino.avanzarCursor()){
		string aux;
		string informacion = listaLineasDestino.obtenerCursor();
		aux = informacion.substr(0, informacion.find(','));

		destino.setearOrigen(informacion.substr(0, informacion.find(',')));
		size_t posicionInicial = informacion.find(',') + 2;
		size_t desplazamiento = informacion.find(',', posicionInicial) - posicionInicial;

		destino.setearDestino(informacion.substr(posicionInicial, desplazamiento));

		posicionInicial = posicionInicial + 2 + desplazamiento;
		desplazamiento = informacion.find(',', posicionInicial) - posicionInicial;

		aux = informacion.substr(posicionInicial, desplazamiento);

		istringstream buffer(aux);
		int costo;
		buffer >> costo;
		destino.setearCosto((unsigned int)costo);
		posicionInicial = posicionInicial + 2 + desplazamiento;
		string cultivo = informacion.substr(informacion.length()-1);
		destino.setearTipoCultivo((char)cultivo[0]);

		if(tipoCultivo == destino.obtenerTipoCultivo()){

			listaDestino->agregarElemento(destino);
		}
	}
	listaLineasDestino.~Lista();
}

void validarColumna(int* columna, Jugador* jugador){
	do{
		cout << "Ingrese la columna" << endl;
		cin >> *columna;
		if(!jugador->esUnaColumnaValida(*columna))
			cout << "Columna Invalida" << endl;
	}
	while(!jugador->esUnaColumnaValida(*columna));
}


void ingresarCoordenadas(int* terreno, int* fila, int* columna, Jugador* jugador) {

    validarTerreno(terreno, jugador);
    validarFila(fila, jugador);
    validarColumna(columna, jugador);
}

void cosecharParcela(Jugador* jugador){

	int terreno, fila, columna;

	ingresarCoordenadas(&terreno, &fila, &columna, jugador);

	if(jugador->cosechar(terreno, fila, columna)){
		cout << "Parcela cosechada";
		Dibujador dibujador;
		dibujador.cosechar(jugador, terreno, fila -1, columna -1);
	}else{
		cout << "No se puede cosechar parcela";
	}
}


void comprarTerreno(Jugador* jugador) {

    if (jugador->hayCreditosDisponiblesTerreno()){

    	jugador->comprarTerreno();
    	Dibujador dibujador;
    	dibujador.dibujarNuevoTerreno(jugador);
    	cout << "Terreno comprado!" << endl;

    }else {

    	cout << "No tiene creditos suficientes" << endl;
    }
}

void venderTerreno(Jugador* jugador) {

	Dibujador dibujador;
    int posicion;
    validarTerreno(&posicion, jugador);

    if (posicion < 0 || posicion > jugador->obtenerCantidadTerrenos()) {

        cout << endl << "La posicion indicada no "
        		"corresponde a ninguno de los terrenos disponibles" << endl;
    }

    dibujador.eliminarTerreno(jugador, posicion);
    jugador->venderTerreno(posicion);

}

void comprarCapacidadAgua(Jugador* jugador){

	int capacidad;
	cout << "Ingrese cantidad de capacidad a comprar" << endl;
	cin >> capacidad;
	if(jugador->sePuedeComprarCapacidadTanque(capacidad)){
		cout << "Has aumentado en " << capacidad <<
				" la capacidad de tu tanque." << endl;
	}else{
		cout << "No posee creditos suficientes" << endl;
	}

}

void comprarCapacidadAlmacen(Jugador* jugador){
	int capacidad;
		cout << "Ingrese cantidad de capacidad a comprar" << endl;
		cin >> capacidad;
		if(jugador->sePuedeComprarCapacidadAlmacen(capacidad)){
			cout << "Has aumentado en " << capacidad <<
					" la capacidad de tu almacen." << endl;
		}else{
			cout << "No posee creditos suficientes" << endl;
		}
}

void sembrarParcela(Jugador* jugador, Lista<Cultivo*>* cultivosDisponibles) {

    system("clear");

    Cultivo cultivoComprados;
    char tipo;
    char primerCultivo;
    char ultimoCultivo;

    cout << endl << "Cultivos disponibles: " << endl << endl;

    // Muestra los cultivos disponibles (deberia ir en una funcion)
    cultivosDisponibles->iniciarCursor();
    while(cultivosDisponibles->avanzarCursor()){

        cout << endl << "Tipo: " << cultivosDisponibles->obtenerCursor()->obtenerTipo() << endl
        << "Costo semilla: " << cultivosDisponibles->obtenerCursor()->obtenerCosto() << endl
        << "Tiempo de cosecha: " << cultivosDisponibles->obtenerCursor()->obtenerTiempoCosecha() << endl
        << "Rentabilidad: " << cultivosDisponibles->obtenerCursor()->obtenerRentabilidad() << endl
        << "Tiempo de recuperacion: " << cultivosDisponibles->obtenerCursor()->obtenerTiempoDeRecuperacion() << endl
        << "Consumo de agua: " << cultivosDisponibles->obtenerCursor()->obtenerConsumoDeAgua() << endl;
    }
    primerCultivo = cultivosDisponibles->mostrarElemento(1)->obtenerTipo();
    ultimoCultivo = cultivosDisponibles->mostrarElemento(cultivosDisponibles->contarElementos())->obtenerTipo();

    do{
    	cout << "Ingrese el tipo de cultivo que quiere comprar: ";
    	cin >> tipo;}
    while(tipo < primerCultivo || tipo > ultimoCultivo);

    cultivosDisponibles->iniciarCursor();
    while(cultivosDisponibles->avanzarCursor())

        if (cultivosDisponibles->obtenerCursor()->obtenerTipo() == tipo)
            cultivoComprados.cambiarCultivo(cultivosDisponibles->obtenerCursor());


    int terreno;
    int fila;
    int columna;

    validarTerreno(&terreno, jugador);
    validarFila(&fila, jugador);
    validarColumna(&columna, jugador);

    if(jugador->plantarSemilla(cultivoComprados, terreno, fila, columna)){
    	cout << endl << "Semilla plantada!" << endl;
    	Dibujador dibujador;
    	dibujador.dibujarSemilla(jugador, terreno, fila - 1, columna - 1);
    }else{
    	cout << endl << "ESA UBICACION NO ESTA DISPONIBLE PARA SER PLANTADA!!!" << endl;
    }


}


void actualizarTerreno(Parcela** terrenoJugador, unsigned int topeFila, unsigned int topeColumnas){

	for(unsigned int i = 0; i < topeFila ; i++)
		for(unsigned int j = 0; j < topeColumnas; j++)
			terrenoJugador[i][j].pasoDeTurno();
}

void actualizarCampo(Jugador* jugador){

	Parcela** terrenoJugador;

	for(int i = 1; i < jugador->devolverCampo()->obtenerCantidadTerrenos() + 1 ; i++){

		terrenoJugador = jugador->devolverCampo()->devolverTerreno(i);
		actualizarTerreno(terrenoJugador, jugador->devolverCampo()->obtenerFilas(),
				jugador->devolverCampo()->obtenerColumnas());
	}
}


void regarCultivo(Jugador* jugador) {

	int terreno;
    int fila;
    int columna;

    bool corteWhile = true;

    if (jugador->obtenerCantidadAgua() > 0) {

        do {

          ingresarCoordenadas(&terreno, &fila, &columna, jugador);

          corteWhile = jugador->sonCoordenadasValidasRegar(terreno, fila, columna);

          if (corteWhile) {
        	  if (jugador->hayAguaDisponible(terreno, fila - 1, columna - 1)) {

        	     jugador->regarParcela(terreno, fila - 1, columna - 1);
        	     cout << endl << "Se rego parcela!" << endl;
        	     Dibujador dibujador;
				 dibujador.dibujarParcelaRegada(jugador, terreno, fila - 1 , columna - 1);
        	  }else {

                  cout << endl << "No tiene agua suficiente para regar ese cultivo!" << endl;
              }


          }else{
        	  cout << endl << "No se puede regar esa parcela!" << endl;
          }

        } while (!corteWhile);
    }

    else {

        cout << endl << "No posee creditos suficientes" << endl;
    }
}

int mostrarCaminosMinimos(char TipoCultivo, Lista<Grafo*>* listaGrafo){
	unsigned int ubicacion = (unsigned int)(TipoCultivo -64);
	Lista<Arista>* aristas =listaGrafo->mostrarElemento(ubicacion)->obtenerCaminosMinimos();
	aristas->iniciarCursor();
	int i = 1;
	while(aristas->avanzarCursor()){
		cout << endl << i << ") " <<"Destino: " << listaGrafo->mostrarElemento(ubicacion)->
				obtenerVertice(aristas->obtenerCursor().obtenerDestino());
		cout << "Costo: " << aristas->obtenerCursor().obtenerCosto();
		cout << endl;
		i++;
	}
	unsigned int opcion = 1000;
	while(opcion < 0 || opcion > aristas->contarElementos()){
		cout << "Seleccion Invalida, vuelva a elegir";
		cin >> opcion;
	}
	int costo = aristas->mostrarElemento(opcion).obtenerCosto();
	return costo;
}

void enviarPedido(Jugador* jugador, Lista<Grafo*>* listaGrafo){
	int opcion;
	Almacen* almacenJugador = jugador->obtenerAlmacen();
	cout << "Su almacen contiene: "
			<< almacenJugador->obtenerCantidadDeCosechas() << endl;
	for(int i = 1; i < almacenJugador->obtenerCantidadDeCosechas() + 1; i++){
		cout << "	(" << i << "): Cultivo " << almacenJugador->obtenerElementoDePosicion(i).obtenerTipo()
			<< ", Rentabilidad: " << almacenJugador->obtenerElementoDePosicion(i).obtenerRentabilidad()
			<< endl;
	}
	cout << "Seleccione el numero del cultivo a enviar a destino :";
	cin >> opcion;
	while(opcion > almacenJugador->obtenerCantidadDeCosechas() || opcion <= 0){
		cout << "Seleccion invalida!!!, Vuelva a ingresar un numero de cultivo.";
		cin >> opcion;
	}
	cout << endl;

	Cultivo cultivoAEnviar = almacenJugador->obtenerElementoDePosicion(opcion);
	cout << "Seleccione un destino, las siguientes opciones son los costos minimos:" << endl;
	int costo = 0;

	costo = mostrarCaminosMinimos(cultivoAEnviar.obtenerTipo(), listaGrafo);

	unsigned int creditosGanados = cultivoAEnviar.obtenerRentabilidad() - costo;
	//int creditosGanados = almacenJugador->despacharCosecha(cultivoAEnviar, opcion);
	almacenJugador->eliminarCosecha(opcion);
	jugador->sumarCreditos(creditosGanados);
}



void procesarTurno(Jugador* jugador, int turno, Lista<Cultivo*>* cultivosDisponibles, Lista<Grafo*>* listaGrafo) {

    int opcion;
    system("clear");
    cout << "\nTurno: " << turno << setw(15) << "Jugador: " << jugador->obtenerNombre() << endl;

    Dibujador dibujador;
    jugador->recibirAgua();

    while ((opcion = obtenerOpcion(jugador)) != OPCION_FINALIZAR_TURNO) {


        switch (opcion) {

            case OPCION_REGAR_CULTIVO:

            	if(jugador->tieneTerrenos())
            		regarCultivo(jugador);

            	else

            		cout << "No posee terrenos" << endl;

                break;

            case OPCION_COMPRAR_TERRENO:

                if(jugador->obtenerCantidadTerrenos() >= 9)
                	cout << "No se puede tener mas de 9 terrenos!!!!";

                else

                	comprarTerreno(jugador);

                break;

            case OPCION_VENDER_TERRENO:

                venderTerreno(jugador);

                break;

            case OPCION_SEMBRAR_PARCELA:

            	if(jugador->tieneTerrenos())
            		sembrarParcela(jugador, cultivosDisponibles);

            	else

            		cout << "No posee terrenos" << endl;

                break;

            case OPCION_COSECHAR:

            	if(jugador->hayLugarEnAlmacen()){
            		if(jugador->tieneTerrenos()){

            			cosecharParcela(jugador);

            		}else{

            			cout << "No posee terrenos" << endl;
            		           	    }
            	}else{

            		cout << "Almacen Lleno!!" << endl;

            	}

                break;

            case OPCION_COMPRAR_AGUA:

            	comprarCapacidadAgua(jugador);

                break;

            case OPCION_COMPRAR_ALMACEN:

                comprarCapacidadAlmacen(jugador);

                break;

            case OPCION_ENVIAR_PEDIDOS:

            	if(jugador->tieneCultivosEnAlmacen())

            		enviarPedido(jugador, listaGrafo);

            	else

            		cout << "Su almacen esta vacio";

                break;


            default:

            	cout << "Eliga una opcion valida!!" << endl;

            	break;
        }
    }

    jugador->desecharExcesoDeAgua();
    actualizarCampo(jugador);
    dibujador.pasoDeTurnoJugador(jugador);


}

void mostrarGanador(Lista<Jugador*>* listaJugadores) {

    Jugador* ganador = NULL;

    listaJugadores->iniciarCursor();

    while (listaJugadores->avanzarCursor()) {

 	Jugador* jugadorActual = listaJugadores->obtenerCursor();

	if (ganador == NULL || jugadorActual->obtenerCreditos() > ganador->obtenerCreditos()) {

 	   ganador = jugadorActual;
	}
    }
    
    if (ganador != NULL) {
	    
        cout << endl << "El ganador es: " << ganador->obtenerNombre() << endl;
    }
}
