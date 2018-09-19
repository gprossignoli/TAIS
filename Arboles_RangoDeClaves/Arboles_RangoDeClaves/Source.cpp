// Gerardo Parra Rossignoli
// TAIS 20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "AVLtree_ext.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int nKeys;
	std::cin >> nKeys;
	if (nKeys == 0)
		return false;
	map_ext<int, int, std::less<int>> t;
	for (int i = 0; i < nKeys; ++i) {
		int key;
		std::cin >> key;
		t[key];
	}
	int k1, k2;
	std::cin >> k1 >> k2;

	std::vector<int> sol = t.findKeysInRank(k1, k2);
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