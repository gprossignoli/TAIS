// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "BipartiteGraph.h"



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int vertex, edges;

	std::cin >> vertex >> edges;
	if (!std::cin)
		return false;

	Grafo g(vertex);
	for (int i = 0; i < edges; ++i) {
		int a, b;
		std::cin >> a >> b;
		g.ponArista(a, b);
	}
	
	bipartiteGraph bg(g);

	if (bg.isBipartite())
		std::cout << "SI\n";
	else
		std::cout << "NO\n";

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