// Gerardo Parra Rossignoli
// TAIS 20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"

// función que resuelve el problema
int resolver(PriorityQueue<int, std::less<int>> q) {
	int i = 2; int sol = 0; 
	std::vector<int> efforts; //contains the effort of each node
	std::vector<int> elems; //elements order by heapsort
	elems.push_back(0);
	elems.push_back(q.top());
	q.pop();
	efforts.push_back(0);
	efforts.push_back(0);
	while (q.size() != 1) {
		elems.push_back(q.top());
		efforts.push_back(elems[i / 2] + q.top() + efforts[i / 2]);
		q.pop();
		sol += efforts[i];
		++i;
	}
	elems.push_back(q.top());
	efforts.push_back(elems[i / 2] + q.top() + efforts[i / 2]);
	q.pop();
	sol += efforts[i];
	return sol;
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