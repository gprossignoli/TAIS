// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"

int resolver(PriorityQueue<int> & J, PriorityQueue<int> & C) {
	int camisetasReutilizadas = 0;
	int jugadores = J.size();

	while (!J.empty() && !C.empty()) {
		if (J.top() == C.top() || J.top() + 1 == C.top()) {
			++camisetasReutilizadas;
			J.pop();
			C.pop();
		}

		else if (C.top() < J.top()) C.pop();
		else if (C.top() > J.top() + 1) J.pop();
	}

	return jugadores - camisetasReutilizadas;
}


bool resuelveCaso() {
	int J,C;

	std::cin >> J >> C;
	if (!std::cin)
		return false;

	PriorityQueue<int> jugadores;
	for (int i = 0; i < J; ++i) {
		int aux;
		std::cin >> aux;
		jugadores.push(aux);
	}

	PriorityQueue<int> camisetas;
	for (int j = 0; j < C; ++j) {
		int aux;
		std::cin >> aux;
		camisetas.push(aux);
	}
	

	std::cout << resolver(jugadores, camisetas) << '\n';


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