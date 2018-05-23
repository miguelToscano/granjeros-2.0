#include "../src/Jugador.h"

using namespace std;

Jugador :: Jugador() {

    this->nombre = "Nombre no asignado";
    this->creditos = 0;
	this->unidadesRiego = 0;
}

void Jugador :: mostrarCampo() {

    if (this->obtenerCantidadTerrenos() == 0) {

        cout << endl << this->obtenerNombre() << " no posee terrenos actualmente" << endl;
    }
  
    else

        this->campoJugador.mostrarCampo();
}

Campo* Jugador::devolverCampo(){

	return &(this->campoJugador);
}

void Jugador :: imprimirInformacion() {

    cout << "\nNombre: " << this->obtenerNombre() << endl
        << "Creditos: " << this->obtenerCreditos() << endl
        << "Cantidad de terrenos: " << this->obtenerCantidadTerrenos() << endl
        << "Unidades de riego en tanque: " << this->tanque.obtenerCantidadAgua() << endl
		<< "Capacidad del tanque: " << tanque.obtenerCapacidad() << endl
    	<< "Capacidad de almacen: " << almacen.obtenerCapacidadMaxima() << endl
    	<< "Objetos en almacen: " << almacen.obtenerCantidadDeCosechas() << endl;
}

int Jugador :: obtenerCantidadTerrenos() {

    return this->campoJugador.obtenerCantidadTerrenos();
}

void Jugador :: establecerNombre(string nombre) {

    this->nombre = nombre;
}

void Jugador :: ingresarNombre() {

    cout << "Ingrese el nombre del jugador: ";

    cin >>  this->nombre;
}

string Jugador :: obtenerNombre() {

    return this->nombre;
}

void Jugador :: establecerCreditos() {

    this->creditos = 2 * (this->campoJugador.obtenerFilas()) * (this->campoJugador.obtenerColumnas());
}

int Jugador :: obtenerCreditos() {

    return this->creditos;
}

int Jugador :: obtenerUnidadesRiego() {

    return this->unidadesRiego;
}

void Jugador :: establecerUnidadesRiego(int unidadesRiego) {

    if (unidadesRiego < 0) {

        throw string("Se intentaron asignar unidades de riego negativas");
    }

    this->unidadesRiego = unidadesRiego;
}

void Jugador :: establecerFilas(int filas) {

    this->campoJugador.establecerFilas(filas);
}

void Jugador :: establecerColumnas(int columnas) {

    this->campoJugador.establecerColumnas(columnas);
}

int Jugador :: obtenerFilas() {

	return this->campoJugador.obtenerFilas();
}

void Jugador :: recibirAgua() {

	this->tanque.recibirAgua();
}

int Jugador :: obtenerColumnas() {

	return this->campoJugador.obtenerColumnas();
}

void Jugador :: crearCampo() {

    this->campoJugador.crearCampo();
}

void Jugador :: inicializarCapacidadTanque() {

	this->tanque.aumentarCapacidad(this->obtenerFilas() * this->obtenerColumnas());
}

bool Jugador :: hayCreditosDisponiblesTerreno() {

    return this->creditos >= this->campoJugador.obtenerPrecioTerreno();
}

void Jugador :: descontarCreditos(int valor) {

    this->creditos -= valor;
}

void Jugador :: comprarTerreno() {

    this->descontarCreditos(this->campoJugador.obtenerPrecioTerreno());
    this->campoJugador.agregarTerreno();
    this->campoJugador.actualizarPrecioTerreno();
}

void Jugador :: venderTerreno(int posicion) {

    float precioVentaTerreno;

    if (posicion < 0 || posicion > this->campoJugador.obtenerCantidadTerrenos()) {

        throw string("Se quiso acceder a una posicion de la lista invalida");
    }

    precioVentaTerreno = static_cast<float>(this->campoJugador.obtenerPrecioTerreno()) * 0.5;
    this->creditos += static_cast<int>(precioVentaTerreno);

    this->campoJugador.eliminarTerreno(posicion);
}

void Jugador :: plantarSemilla(Cultivo& cultivo, int terreno, int fila, int columna) {

    Nodo<Parcela**>* terrenoParaSembrar = this->campoJugador.obtenerTerreno(terreno);

	if (terrenoParaSembrar->datoDelNodo[fila][columna].estaOcupada() == false
	 	&& terrenoParaSembrar->datoDelNodo[fila][columna].estaDisponible() == true) {

		terrenoParaSembrar->datoDelNodo[fila][columna].establecerCultivo(cultivo);
		terrenoParaSembrar->datoDelNodo[fila][columna].ocuparParcela();
		terrenoParaSembrar->datoDelNodo[fila][columna].bloquearParcela();
		terrenoParaSembrar->datoDelNodo[fila][columna].noRegarParcela();
		terrenoParaSembrar->datoDelNodo[fila][columna].desSecarParcela();
		terrenoParaSembrar->datoDelNodo[fila][columna].despudrirParcela();	 
	}

	else {

		cout << "No puede plantar ahi!" << endl;
	}
}

int Jugador :: obtenerCantidadAgua() {

	return this->tanque.obtenerCantidadAgua();
}

void Jugador :: regarParcela(int terreno, int fila, int columna) {

	Nodo<Parcela**>* terrenoParaRegar = this->campoJugador.obtenerTerreno(terreno);

	terrenoParaRegar->datoDelNodo[fila][columna].regarParcela();
}

bool Jugador :: hayAguaDisponible(int terreno, int fila, int columna) {

	Nodo<Parcela**>* terrenoParaRegar = this->campoJugador.obtenerTerreno(terreno);

	return this->tanque.obtenerCantidadAgua() >= terrenoParaRegar->datoDelNodo[fila][columna].obtenerConsumoDeAgua();
}

bool Jugador :: esUnTerrenoValido(int terreno){
	if(terreno > 0 && terreno <= campoJugador.obtenerCantidadTerrenos()){
		return true;
	}else{
		return false;
	}
}

bool Jugador :: esUnaFilaValida(int fila){
	if(fila > 0 && fila <= campoJugador.obtenerFilas()){
			return true;
		}else{
			return false;
		}
}

bool Jugador :: esUnaColumnaValida(int columna){
	if(columna > 0 && columna <= campoJugador.obtenerColumnas()){
			return true;
		}else{
			return false;
		}
}

bool Jugador :: cosechar(int terreno, int fila, int columna){
	Parcela* parcela = campoJugador.obtenerPacela(terreno, fila, columna);
	bool respuesta = true;
	if(parcela->sePuedeCosechar()){
		almacen.agregarCosechaAlmacen(parcela->cosecharParcela());
	}else{
		respuesta = false;
	}
	return respuesta;
}

bool Jugador :: hayLugarEnAlmacen(){
	return almacen.hayLugar();
}

bool Jugador :: sePuedeComprarCapacidadTanque(int capacidad){
	int costo = (capacidad * 3);
	bool respuesta = false;
	if (costo <= obtenerCreditos()){
		descontarCreditos(costo);
		tanque.aumentarCapacidad(capacidad);
		respuesta = true;
	}
	return respuesta;
}

bool Jugador :: sePuedeComprarCapacidadAlmacen(int capacidad){
	int costo = (capacidad * 5);
		bool respuesta = false;
		if (costo <= obtenerCreditos()){
			descontarCreditos(costo);
			almacen.aumentarCapacidad(capacidad);
			respuesta = true;
		}
		return respuesta;
}

bool Jugador :: sonCoordenadasValidasPlantar(int terreno, int fila, int columna) {

	Parcela* parcelaDondePlantar = this->campoJugador.obtenerPacela(terreno, fila, columna);

	return esUnTerrenoValido(terreno + 1) == true && esUnaFilaValida(fila + 1) == true && esUnaColumnaValida(columna + 1)
			&& parcelaDondePlantar->estaDisponible() == true && parcelaDondePlantar->estaOcupada() == false;
}

bool Jugador :: sonCoordenadasValidasRegar(int terreno, int fila, int columna) {

	Parcela* parcelaDondeRegar = this->campoJugador.obtenerPacela(terreno, fila, columna);

	return esUnTerrenoValido(terreno + 1) == true && esUnaFilaValida(fila + 1) == true && esUnaColumnaValida(columna + 1)
			&& !parcelaDondeRegar->estaDisponible() == true && parcelaDondeRegar->estaOcupada() == true
			 && !parcelaDondeRegar->estaRegada();
}

bool Jugador :: hayCreditosDisponibles(int valor) {

	return this->creditos >= valor;
}