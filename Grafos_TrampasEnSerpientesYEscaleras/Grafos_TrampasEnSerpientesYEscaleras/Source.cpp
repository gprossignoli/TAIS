// Gerardo Parra Rossignoli
// TAIS 20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "shortestPath.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N, nDice, snakes, stairs; // nDice <= N

	std::cin >> N >> nDice >> snakes >> stairs;
	if (N == 0)
		return false;

	const int boardSize = N * N;
	GrafoDirigido implicitGraph(boardSize);

	/*	coste total de la formacion de grafo = O(N) sobre el tamaño del tablero, el pimer bucle seria 10N, 
	*	el segundo sera despreciable respecto de 10N con coste N - 10, 
	*	y el tercero es despreciable pues (snakes + stairs) sera como mucho N. 
	*/

	int i = 0;
	for (; i < (implicitGraph.V() - nDice); ++i) {
		int tmp = i + 1;
		for (int j = 0; j < nDice; ++j) {		
			implicitGraph.ponArista(i, tmp);
			++tmp;
		}
	}

	for (; i < implicitGraph.V() - 1; ++i) {
		implicitGraph.ponArista(i, i + 1);
	}

	for (int i = 0; i < snakes + stairs; ++i) {
		int s, d;
		std::cin >> s >> d;
		implicitGraph.ponArista(s, d);
	}

	int sol = 0;
	shortestPath(implicitGraph, sol);

	std::cout << sol << '\n';

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