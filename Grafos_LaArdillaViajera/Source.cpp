// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "ForestMap.h"



bool resuelveCaso() {
	int Rows, Col, MaxJumpDist, trees; //trees don't include the trees at the corners [0][0] and [Rows][Col] of the map
	std::cin >> Rows >> Col >> MaxJumpDist >> trees;
	if (!std::cin)
		return false;
	++Rows;
	Map map(Rows);

	for (int i = 0; i < trees; ++i) {
		int x, y;
		std::cin >> x >> y;
		map[x][y] = '#'; 
	}
	
	forest f(map, MaxJumpDist, Rows, Col);
	if (f.isPossible()) {

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