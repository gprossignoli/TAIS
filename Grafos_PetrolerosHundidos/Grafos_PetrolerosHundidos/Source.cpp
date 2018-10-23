// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "SeaMap.h"


bool resuelveCaso() {
	int Rows, Columns;
	std::cin >> Rows >> Columns;

	if (!std::cin)
		return false;

	map sea(Rows + Columns);

	for (char & sector : sea) {
		std::cin >> sector;
	}

	seaMap map(sea);

	std::cout << map.getBiggerSlickSize() << " ";

	int newSlicks;
	std::cin >> newSlicks;
	for (int i = 0; i < newSlicks; ++i) {
		int r,c;
		std::cin >> r >> c;
		sea[r][c] = '#';
		std::cout << map.addSlick(sea, r, c);
		if (i < newSlicks - 1)
			std::cout << ' ';
	}

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