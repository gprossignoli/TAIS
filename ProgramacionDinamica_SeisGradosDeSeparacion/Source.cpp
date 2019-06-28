// Gerardo Parra Rossignoli
// TAIS20

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "Matriz.h"
#include <string>

#define INF 1000000000

void grados() {

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada

	int aristas, vertices;

	std::cin >> vertices >> aristas;

	if (!std::cin)
		return false;

	std::unordered_map<std::string, int> umap;
	std::string name;
	bool inserted;
	int index = 0;

	for (int i = 0; i < aristas*2; i++){
		std::cin >> name;
		inserted = umap.insert({ name, index}).second;
		if (inserted)
			++index;
	}


	// escribir sol


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