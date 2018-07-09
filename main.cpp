
#define ARCHIVO_CULTIVOS "cultivos.txt"

#include "../src/main.h"

using namespace std;

const int TURNOS = 10;

int main() {
	Dibujador dibujo;
	dibujo.crearTemplates();
    int cantidadJugadores;
    Jugador* jugadores = 0;
    Cultivo* cultivosDisponibles = 0;
    int cantidadCultivosDisponibles = 0;

    configurarJuego(jugadores, cantidadJugadores, cultivosDisponibles, cantidadCultivosDisponibles);

    Lista<Grafo*> listaGrafos;
    cout << cantidadCultivosDisponibles;
    for(int i = 0; i < cantidadCultivosDisponibles; i++){
    	char tipoCultivo = ('A' + (char)i);
    	Lista<DestinosAristas> listaAristasAAgregar;
    	cearListaGrafo(tipoCultivo, &listaAristasAAgregar);
    	Grafo* nuevoGrafo = new Grafo();
    	nuevoGrafo->agregarListaAristas(&listaAristasAAgregar);
    	nuevoGrafo->crearCaminosMinimos(1);
    	listaGrafos.agregarElemento(nuevoGrafo);
    	listaAristasAAgregar.~Lista();
    }

    // Empiezan a jugar
    for (int turno = 1; turno <= TURNOS; turno++) {

        for (int i = 0; i < cantidadJugadores; i++) {

            procesarTurno(jugadores[i], turno, cultivosDisponibles, cantidadCultivosDisponibles, &listaGrafos);
        }
    }

    mostrarInformacionJugadores(jugadores, cantidadJugadores);    

    mostrarGanador(jugadores, cantidadJugadores);
    dibujo.eliminarTemplates();

    for(int i = 0; i < cantidadJugadores; i++){
    	for(int j = jugadores[i].obtenerCantidadTerrenos(); j > 0 ; j--){
    		dibujo.eliminarTerreno(&jugadores[i], j);
    	}
    }

    listaGrafos.iniciarCursor();
    while(listaGrafos.avanzarCursor()){
    	listaGrafos.obtenerCursor()->~Grafo();
    	delete listaGrafos.obtenerCursor();
    }
    listaGrafos.~Lista();
    delete[] cultivosDisponibles;
    delete[] jugadores;

    return 0;
}
