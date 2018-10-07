// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Grafo.h"
#include "maxConnectedComponent.h"



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int persons,friendPairs;

	std::cin >> persons >> friendPairs;

	Grafo city(persons);
	for (int i = 0; i < friendPairs; ++i) {
		int a, b;
		std::cin >> a >> b;
		city.ponArista(a - 1, b - 1);
	}
	if (friendPairs > 0) {
		mcc m(city);
		std::cout << m.getMCC() << '\n';
	}
	else
		std::cout << 1 << '\n';
	
	


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}