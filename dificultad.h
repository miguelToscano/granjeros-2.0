#include <cstdlib>
#include <fstream>

class Dificultad {
	private:
		int creditos;
		int capacidadTanque;
		int capacidadAlmacen;
		int columnas;
		int filas;

	public:
		//constructor
		Dificultad(std::ifstream& archivo, int filas, int columnas);

		int obtenerCol();

		int obtenerFil();

		int obtenerCreditos();

		int obtenerCapacidadTanque();

		int obtenerCapacidadAlmacen();
};
