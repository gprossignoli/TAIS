// Gerardo Parra Rossignoli
// TAIS 20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "DijkstraSPT.h"

bool resuelveCaso() {
	int webPages;
	std::cin >> webPages;
	if (webPages == 0)
		return false;

	std::vector<int> loadTimes;
	for (int i = 0; i < webPages; ++i) {
		int tmp;
		std::cin >> tmp;
		loadTimes.push_back(tmp);
	}

	GrafoDirigidoValorado<int> internet(webPages);
	int links;
	std::cin >> links;

	for (int i = 0; i < links; ++i) {
		int srcP, dstP, timeBetweenPages;
		std::cin >> srcP >> dstP >> timeBetweenPages;
		internet.ponArista({ srcP - 1, dstP - 1, (timeBetweenPages + loadTimes[srcP - 1]) });
	}

	DijkstraSP sp(internet, 0);

	try {  
		std::cout << sp.getDisTo(webPages - 1) + loadTimes[webPages-1];
	}
	catch (std::domain_error e) {
		std::cout << e.what();
	}
	
	std::cout << '\n';

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