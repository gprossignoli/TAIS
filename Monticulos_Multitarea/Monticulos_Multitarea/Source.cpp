// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"

using tTask = struct {
	int ini;
	int end;
	int period;
	bool simpleTask;
};


bool operator<(tTask const& a, tTask const& b) {
	return a.ini < b.ini;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int nSimpleTasks, nPeriodicTasks, time;
	PriorityQueue<tTask> tasks;

	std::cin >> nSimpleTasks >> nPeriodicTasks >> time;
	if (!std::cin)
		return false;

	if (time > 0) {

		for (int i = 0; i < nSimpleTasks; ++i) {
			int ini, end;
			std::cin >> ini >> end;
			tasks.push({ ini,end,0,true });
		}
		for (int i = 0; i < nPeriodicTasks; ++i) {
			int ini, end, period;
			std::cin >> ini >> end >> period;
			tasks.push({ ini,end,period,false });
		}

		int t = tasks.top().ini;
		bool conflict = false;

		while(t < time && !conflict && tasks.size() > 1) {
			tTask aux = tasks.top();
			
			tasks.pop();
			if (tasks.top().ini < time && tasks.top().ini < aux.end)
				conflict = true;

			else if (!aux.simpleTask) {
				aux.ini += aux.period;
				aux.end += aux.period;
				tasks.push(aux);
			}
			
			t = tasks.top().ini;
		}

		if(conflict)
			std::cout << "SI\n";
		else
			std::cout << "NO\n";
	}
	else
		std::cout << "NO\n";
	
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