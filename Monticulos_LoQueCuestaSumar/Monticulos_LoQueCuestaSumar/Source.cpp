// Gerardo Parra Rossignoli
// TAIS 20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"

// función que resuelve el problema
int resolver(PriorityQueue<int, std::less<int>> q) {
	int suma = q.top();
	q.pop();
	int i = 0;
	const int j = q.size() + 1;
	while (i < j) {
		suma += q.top();
		q.pop();
		q.push(suma);
		++i;
	}
	return suma;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)
		return false;

	PriorityQueue<int, std::less<int>> queue;
	for (int i = 0; i < N; i++) {
		int elem;
		std::cin >> elem;
		queue.push(elem);
	}

	int sol = resolver(queue);

	std::cout << sol << '\n';

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