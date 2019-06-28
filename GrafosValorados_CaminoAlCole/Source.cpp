// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "PathsToSchool.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int Intersections, Streets;

	std::cin >> Intersections >> Streets;
	if (!std::cin)
		return false;
	
	GrafoValorado<int> G(Intersections);

	for (int i = 0; i < Streets; ++i) {
		int src, dst, weight;
		std::cin >> src >> dst >> weight;
		G.ponArista({ src-1,dst - 1,weight });
	}
	
	PathsToSchool gps(G, 0);
	int sol = gps.pathsTo(Intersections - 1);

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