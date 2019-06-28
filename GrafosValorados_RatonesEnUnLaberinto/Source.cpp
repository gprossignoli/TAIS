// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "mazeExperiment.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N, S, T, P;

	std::cin >> N >> S >> T >> P;
	if (!std::cin)
		return false;

	GrafoDirigidoValorado<int> G(N);

	for (int i = 0; i < P; ++i) {
		int src, dst, distance;
		std::cin >> src >> dst >> distance;
		G.ponArista(AristaDirigida<int>(src - 1, dst - 1, distance));
	}

	Maze maze(G.inverso(), S - 1,T);

	std::cout << maze.getNumberMousesThatReachTheExit() << '\n';

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}