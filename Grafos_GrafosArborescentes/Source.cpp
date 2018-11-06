// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "ArborescentGraph.h"

bool resuelveCaso() {
	int V, E;
	std::cin >> V >> E;
	if (!std::cin)
		return false;

	GrafoDirigido graph(V);

	for (int i = 0; i < E; ++i) {
		int src, dst;
		std::cin >> src >> dst;
		graph.ponArista(src, dst);
	}

	Arborescent arbgraph(graph);

	if (arbgraph.isArborescent()) 
		std::cout << "SI " << arbgraph.root() << '\n';

	else
		std::cout << "NO" << '\n';

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