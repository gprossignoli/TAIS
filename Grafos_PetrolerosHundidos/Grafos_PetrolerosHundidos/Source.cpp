// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include "sunkOilTanker.h"


bool resuelveCaso() {
	
	int Rows, Columns;
	std::cin >> Rows >> Columns;

	if (!std::cin)
		return false;
	
	std::cin.ignore(1);
	Map map(Rows);

	for (int r = 0; r < Rows; ++r) {
		std::string line;
		std::getline(std::cin, line);
		if (line.length() < 8) {
			int l = 8 - line.length();
			std::string tmp(l, ' ');
			line += tmp;
		}
			
		for (int c = 0; c < Columns; ++c) {
			map[r].push_back(line[c]);
		}
	}
	
	sunkOilTanker seaMap(map);
	
	std::cout << seaMap.getBiggerSlick();

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