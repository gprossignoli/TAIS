// Gerardo Parra Rossignoli
// TAIS 20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"


using checkOutLane = struct {
	int id;
	int endTimeOfTransaction;
};

bool operator<(checkOutLane const& a, checkOutLane const& b) {
	if (a.endTimeOfTransaction < b.endTimeOfTransaction)
		return true;

	if (a.endTimeOfTransaction == b.endTimeOfTransaction) {
		if (a.id < b.id) {
			return true;
		}
	}

	return false;
}

// función que resuelve el problema
int resolver(PriorityQueue<checkOutLane> q,int remainingClients) {
	int time = 0;
	while (remainingClients > 0) {
		if (q.top().endTimeOfTransaction == time) {
			int nextClient;
			std::cin >> nextClient;
			--remainingClients;
			checkOutLane tmp = q.top();
			q.pop();
			tmp.endTimeOfTransaction = time + nextClient;
			q.push(tmp);
		}
		else
			time = q.top().endTimeOfTransaction;
	}

	return q.top().id; 

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int checkOutLanes, clients;

	std::cin >> checkOutLanes >> clients;
	if (checkOutLanes == 0)
		return false;

	PriorityQueue<checkOutLane> queue;

	int sol = 1;
	if (clients >= checkOutLanes) {
		for (int i = 0; i < checkOutLanes; ++i) {
			int nextClient;
			std::cin >> nextClient;
			checkOutLane tmp = { i + 1,nextClient };
			queue.push(tmp);
		}
		sol = resolver(queue, (clients - checkOutLanes));
	}

	else if (clients > 0) {
		int i = 0;
		for (i; i < clients; ++i) {
			int nextClient;
			std::cin >> nextClient;
		}
		sol = i+1;
	}

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