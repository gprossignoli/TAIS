// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "truckRoutes.h"

bool resuelveCaso() {
	int vertex, edges;
	std::cin >> vertex >> edges;
	if (!std::cin)
		return false;

	GrafoValorado<int> graph(vertex);
	for (int i = 0; i < edges; ++i) {
		int src, dst, weight;
		std::cin >> src >> dst >> weight;
		graph.ponArista({ src - 1,dst-1,weight });
	}

	int querys;
	std::cin >> querys;
	for(int i = 0; i < querys;++i){ //querys * (edges + vertex)
		int src, dst, width;
		std::cin >> src >> dst >> width;
		TruckRoute route(graph, src-1, width); // (edges + vertex)
		if (route.existPath(dst-1))
			std::cout << "SI\n";
		else
			std::cout << "NO\n";
	}

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