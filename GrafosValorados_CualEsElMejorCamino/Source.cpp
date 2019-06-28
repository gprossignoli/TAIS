// Gerardo Parra Rossignoli
// TAIS20

/*
	Para resolver este problema debemos dividirlo en dos preguntas: 
	1) Cual es el camino minimo entre origen y destino teniendo en cuenta el numero de calles, es decir, 
	mirando las aristas que atraviesa.
	2) Cual es el camino minimo entre origen y destino teniendo en cuenta la distancia, es decir, el peso de
	las aristas.

	Para resolver 1) aplicaremos busqueda en anchura y para resolver 2) el algoritmo de dijkstra.
	
	El coste del algoritmo es:
	 para 1) (E + V) 
	 para 2) E * log(V)  donde E son aristas y V vertices.
	 Dado que aplicamos 1) y 2) para cada consulta tendremos que el coste total es: ( (E + V) + ( E * log(V)) ) * N
	 siendo N el numero de consultas.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "MinDistancePath.h"
#include "MinEdgesPath.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int V, E;
	std::cin >> V >> E;
	if (!std::cin)
		return false;

	GrafoValorado<int> G(V);
	for (int i = 0; i < E; ++i){
		int src, dst, weight;
		std::cin >> src >> dst >> weight;
		--src;
		--dst;
		G.ponArista({ src,dst,weight });
	}
	
	int nQueries;
	std::cin >> nQueries;
	

	for (int i = 0; i < nQueries; ++i) {
		int src, dst;
		std::cin >> src >> dst;
		--src;
		--dst;
		MinDistancePath mdp(G, src);
		MinEdgesPath mep(G, src);

		const auto mdpResults = mdp.getResults(dst);
		if (mdpResults.first == -1) {
			std::cout << "SIN CAMINO\n";
		}

		else if(mdpResults.second == mep.distancia(dst)){
			std::cout << mdpResults.first << " " << "SI\n";
		}
		else
			std::cout << mdpResults.first << " " << "NO\n";
	}

	std::cout << "----\n";

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