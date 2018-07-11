
#define ARCHIVO_CULTIVOS "cultivos.txt"

#include "../src/main.h"

using namespace std;

const int TURNOS = 10;

int main() {

    Lista<Jugador*>* listaJugadores = new Lista<Jugador*>;
    Lista<Cultivo*>* listaCultivos = new Lista<Cultivo*>;
    Dibujador dibujo;
    dibujo.crearTemplates();

    configurarJuego(listaJugadores, listaCultivos);

    Lista<Grafo*> listaGrafos;
  
    for(int i = 0; i < listaCultivos->obtenerTamanio(); i++){
    	char tipoCultivo = ('A' + (char)i);
    	Lista<DestinosAristas> listaAristasAAgregar;
    	cearListaGrafo(tipoCultivo, &listaAristasAAgregar);
    	Grafo* nuevoGrafo = new Grafo;
    	nuevoGrafo->agregarListaAristas(&listaAristasAAgregar);
    	nuevoGrafo->crearCaminosMinimos(1);
    	listaGrafos.agregarElemento(nuevoGrafo);
    }

    // Empiezan a jugar
    for (int turno = 1; turno <= TURNOS; turno++) {

        listaJugadores->iniciarCursor();

        while (listaJugadores->avanzarCursor()) {

            Jugador* jugadorActual = listaJugadores->obtenerCursor();

            procesarTurno(jugadorActual, turno, listaCultivos, &listaGrafos);
        }
    }

    mostrarInformacionJugadores(listaJugadores);
    mostrarGanador(listaJugadores);
	
    dibujo.eliminarTemplates();
    eliminarGrafos(&listaGrafos);
    eliminarJugadores(listaJugadores);
    eliminarCultivos(listaCultivos);
	
    delete listaJugadores;
    delete listaCultivos;

    return 0;
}
