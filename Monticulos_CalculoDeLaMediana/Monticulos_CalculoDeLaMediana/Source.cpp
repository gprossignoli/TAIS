// Gerardo Parra Rossignoli
// TAIS 20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue> 
#include "PriorityQueue.h"

int resolver(PriorityQueue<int> q) {
	
	if (q.size() == 1) {
		return 2 * q.top();
	}

	if (q.size() == 2) {
		int sol = q.top();
		q.pop();
		return sol + q.top();
	}
	else {
		const int size = q.size();
		std::priority_queue<int> left;
		PriorityQueue<int> right;
		//divide the tail where the left is a maximum tail and the right is a minimum tail, so the looked values are left.top() and right.top()
		int mid = (q.size() / 2);
		int i = 0;
		while (i < mid) {
			left.push(q.top());
			q.pop();
			++i;
		}
		/*while (!q.empty()) {
			right.push(q.top());
			q.pop();
		}*/

		if (size % 2 == 0) {
			return left.top() + q.top();
		}

		else
			return 2 * q.top();
	}

}

bool resuelveCaso() {
	int nElems;
	std::cin >> nElems;
	if (nElems == 0)
		return false;

	PriorityQueue<int> queue;

	for (int i = 0; i < nElems; ++i) {
		int elem;
		std::cin >> elem;
		queue.push(elem);
		int sol = resolver(queue);
		std::cout << sol;
		if (i < nElems - 1)
			std::cout << ' ';
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