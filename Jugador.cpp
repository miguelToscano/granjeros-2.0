#include "../src/Jugador.h"

using namespace std;

Jugador :: Jugador() {
	this->tanque.aumentarCapacidad(25);
    this->nombre = "Nombre no asignado";
    this->creditos = 0;
    this->unidadesRiego = 0;
    this->almacen.aumentarCapacidad(5);
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
		<< "Unidades de riego disponibles: " << this->tanque.obtenerCantidadAgua() << endl
		<< "Capacidad del tanque: " << this->tanque.obtenerCapacidad() << endl
    	<< "Capacidad de almacen: " << this->almacen.obtenerCapacidadMaxima() << endl
    	<< "Objetos en almacen: " << this->almacen.obtenerCantidadDeCosechas() << endl;
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

int Jugador :: obtenerFilas() {

 	return this->campoJugador.obtenerFilas();

 }


 void Jugador :: recibirAgua() {

 	this->tanque.recibirAgua();
 }

int Jugador :: obtenerColumnas(){

	return this->campoJugador.obtenerColumnas();
}

void Jugador :: inicializarCapacidadTanque() {

	this->tanque.aumentarCapacidad(this->obtenerFilas() * this->obtenerColumnas());
}

int Jugador :: obtenerCantidadAgua() {

	return this->tanque.obtenerCantidadAgua();
}

void Jugador :: regarParcela(int terreno, int fila, int columna) {

	Nodo<Parcela**>* terrenoParaRegar = this->campoJugador.obtenerTerreno(terreno);

	terrenoParaRegar->obtenerDato()[fila][columna].regarParcela();

	int consumoAgua = terrenoParaRegar->obtenerDato()[fila][columna].obtenerConsumoDeAgua();

	this->tanque.disminuirAgua(consumoAgua);
}

bool Jugador :: hayAguaDisponible(int terreno, int fila, int columna) {

	Nodo<Parcela**>* terrenoParaRegar = this->campoJugador.obtenerTerreno(terreno);

	return this->tanque.obtenerCantidadAgua() >= terrenoParaRegar->obtenerDato()[fila][columna].obtenerConsumoDeAgua();
}

bool Jugador :: sonCoordenadasValidasRegar(int terreno, int fila, int columna) {

	Parcela* parcelaDondeRegar = this->campoJugador.obtenerPacela(terreno, fila -1, columna-1);
	if(esUnTerrenoValido(terreno)){
		cout << "terreno valido "<< endl;
	}
	if(esUnaFilaValida(fila)){
			cout << "es una fila valida"<< endl;
		}
	if(esUnaColumnaValida(columna)){
		cout << "es una columna valida"<< endl;
		}
	if(!parcelaDondeRegar->estaDisponible()){
		cout << "no esta disponible"<< endl;
		}
	if(parcelaDondeRegar->estaOcupada()){
		cout << "esta ocupada"<< endl;
		}
	if(parcelaDondeRegar->estaOcupada()){
			cout << "no esta regada" << endl;
			}
	cout << "se regara" << parcelaDondeRegar->cultivoParcela.obtenerTipo();

	return esUnTerrenoValido(terreno) && esUnaFilaValida(fila) && esUnaColumnaValida(columna)
			&& !parcelaDondeRegar->estaDisponible() && parcelaDondeRegar->estaOcupada()
			 && !parcelaDondeRegar->estaRegada();
}

void Jugador :: desecharExcesoDeAgua() {

	this->tanque.desecharExcesoDeAgua();
}

void Jugador :: establecerFilas(int filas) {

    this->campoJugador.establecerFilas(filas);
}

void Jugador :: establecerColumnas(int columnas) {

    this->campoJugador.establecerColumnas(columnas);
}

void Jugador :: crearCampo() {

    this->campoJugador.crearCampo();
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

bool Jugador :: plantarSemilla(Cultivo& cultivo, int terreno, int fila, int columna) {
	bool respuesta = false;

    Nodo<Parcela**>* terrenoParaSembrar = this->campoJugador.obtenerTerreno(terreno);
    if((*terrenoParaSembrar).obtenerDato()[fila - 1][columna - 1].estaDisponible()){

    	(*terrenoParaSembrar).obtenerDato()[fila - 1][columna - 1].establecerCultivo(cultivo);
    	(*terrenoParaSembrar).obtenerDato()[fila - 1][columna - 1].sembrar();
    	this->creditos -= cultivo.obtenerCosto();
    	respuesta = true;
    }

    return respuesta;
}

bool Jugador :: esUnTerrenoValido(int terreno){
	return (terreno > 0 && terreno <= campoJugador.obtenerCantidadTerrenos());
}

bool Jugador :: esUnaFilaValida(int fila){
	return(fila > 0 && fila <= campoJugador.obtenerFilas());
}

bool Jugador :: esUnaColumnaValida(int columna){
	return (columna > 0 && columna <= campoJugador.obtenerColumnas());
}

bool Jugador :: cosechar(int terreno, int fila, int columna){
	Parcela* parcela = campoJugador.obtenerPacela(terreno, fila -1, columna -1);
	bool respuesta = true;
	if(parcela->sePuedeCosechar()){
		almacen.agregarCosechaAlmacen(parcela->cultivoParcela);
		parcela->liberarParcela();
		parcela->noDisponible();
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

bool Jugador::tieneTerrenos(){
	bool respuesta = true;
	if(this->obtenerCantidadTerrenos() == 0){
		respuesta = false;
	}
	return respuesta;
}


bool Jugador::tieneCultivosEnAlmacen(){
	return !almacen.estaVacio();
}

Almacen* Jugador::obtenerAlmacen(){

	return &almacen;
	}

void Jugador::sumarCreditos(unsigned int creditos){

	this->creditos += creditos;
	}



Jugador::~Jugador(){

	almacen.~Almacen();

	campoJugador.~Campo();

}
