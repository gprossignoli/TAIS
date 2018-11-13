// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "DijkstraSPT.h"

bool resuelveCaso() {
	int houses, paths;
	std::cin >> houses;
	if (!std::cin)
		return false;
	std::cin >> paths;

	GrafoDirigidoValorado<int> region(houses);
	for (int i = 0; i < paths; ++i) {
		int src, tgt, effort;
		std::cin >> src >> tgt >> effort;
		region.ponArista({ src - 1,tgt - 1,effort });
	}
	int postmanOffice, packages;
	std::cin >> postmanOffice >> packages;
	--postmanOffice;
	int totalEffort = 0;
	int i = 0;
	bool possibleDelivery = true;
	int addressOfDelivery;
	while(i < packages && possibleDelivery) {
		std::cin >> addressOfDelivery;
		--addressOfDelivery;
		DijkstraSP delivery(region, postmanOffice);
		try {
			totalEffort += delivery.getDisTo(addressOfDelivery);
			++i;
		}
		catch (std::domain_error e) {
			std::cout << e.what() << '\n';
			possibleDelivery = false;
		}
	}

	if (possibleDelivery) {
		try {
			DijkstraSP returnToOffice(region, addressOfDelivery);
			totalEffort += returnToOffice.getDisTo(postmanOffice);
			std::cout << totalEffort << '\n';
		}
		catch (std::domain_error e) {
			std::cout << e.what() << '\n';
		}
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