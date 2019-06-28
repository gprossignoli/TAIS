// Gerardo Parra Rossignoli
// TAIS 20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"

/*
  Explicacion: Para resolver el problema utilizare un strut que representara la informacion de cada usuario, 
	su id, su periodo y el momento en el que debe recibir la notificacion.
	Para representar la simulacion utilizare una cola de prioridad de minimos que contendra a los usuarios, 
	y estara ordenada por los momentos de notificacion de los usuarios, de tal forma que el elemento de mayor prioridad
	es el siguiente usuario que ha de ser notificado.
  Coste: el coste sera S * 2log(U) donde S es el numero de pasos de simulacion y U el numero de usuarios,
		 por cada paso de simulacion se hace una insercion y un borrado en la cola.
*/
typedef struct tUser {
	int id;
	int time;
	int noticeTime;
};

bool operator<(tUser const& a, tUser const& b) {
	if (a.noticeTime == b.noticeTime) {
		return a.id < b.id;
	}

	return a.noticeTime < b.noticeTime;
}

void startSensors(const int steps, PriorityQueue<tUser> & noticesQueue) {
	int currentTime = noticesQueue.top().noticeTime;
	int step = 0;
	while (step < steps) {
		std::cout << noticesQueue.top().id << '\n';
		int nextNoticeTime = noticesQueue.top().noticeTime + noticesQueue.top().time;
		noticesQueue.push({ noticesQueue.top().id, noticesQueue.top().time, nextNoticeTime });
		noticesQueue.pop();
		++step;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int users;
	std::cin >> users;
	if (users == 0)
		return false;

	PriorityQueue<tUser> noticesQueue;
	for (int i = 0; i < users; ++i) {
		int id, time;
		std::cin >> id >> time;
		noticesQueue.push({id,time,time });
	}
	int simulationSteps;
	std::cin >> simulationSteps;

	startSensors(simulationSteps,noticesQueue);

	std::cout << "----\n";

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