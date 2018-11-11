// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "KruskalMST.h"

/*En este problema se pretende hayar la forma de conectar complementamente un archipiélago mediante puentes.
Se formará un grafo valorado sin ciclos en el que los vértices son las islas, y las aristas los puentes, que tendrán
un coste de construcción.
Para resolver el problema se buscará el árbol de recubrimiento mínimo del grafo usando el algoritmo de Kruskal.
*/

bool resuelveCaso() {
	int Islands, Bridges;
	std::cin >> Islands >> Bridges;
	if (!std::cin)
		return false;

	GrafoValorado<int> archipelago(Islands);
	edgesList edges;

	for (int i = 0; i < Bridges; ++i) {
		int src, dst, cost;
		std::cin >> src >> dst >> cost;
		Arista<int> e = { src - 1, dst - 1,cost };
		archipelago.ponArista(e);
		edges.push_back(e);
	}
	
	kruskalMST mst(archipelago,edges);
	
	if (mst.exists()) {
		std::cout << mst.getMSTCost();
	}

	else
		std::cout << "No hay puentes suficientes";

	std::cout << '\n';



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