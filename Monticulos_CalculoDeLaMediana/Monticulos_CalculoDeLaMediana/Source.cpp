// Gerardo Parra Rossignoli
// TAIS 20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue> 
#include "PriorityQueue.h"

int resolver(std::priority_queue<int> & left, PriorityQueue<int> & right) {
	
	if (right.size() > left.size()) {
		int sol = right.top() * 2;
		left.push(right.top());
		right.pop();
		return sol;
	}
	
	else if (left.size() > right.size()) {
		return left.top() * 2;	
	}
	
	else {
		int sol = left.top() + right.top();
		left.push(right.top());
		right.pop();
		return sol;
	}

	
}

bool resuelveCaso() {
	int nElems;
	std::cin >> nElems;
	if (nElems == 0)
		return false;

	PriorityQueue<int> right;
	std::priority_queue<int> left;

	for (int i = 0; i < nElems; ++i) {
		int elem;
		std::cin >> elem;
		right.push(elem);
		int sol = resolver(left,right);
		std::cout << sol;
		if (i < nElems - 1)
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