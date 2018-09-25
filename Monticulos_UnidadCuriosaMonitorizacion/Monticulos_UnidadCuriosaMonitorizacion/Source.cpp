// Gerardo Parra Rossignoli
// TAIS 20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include"PriorityQueue.h"

using tUserInfo = struct {
	int id;
	int period;
	int notificationMoment;
};

bool operator<(tUserInfo const& a, tUserInfo const& b) {
	if (a.notificationMoment < b.notificationMoment)
		return true;

	if (a.notificationMoment == b.notificationMoment) {
		return a.id < b.id;
	}

	return false;
}
// función que resuelve el problema
std::vector<int> executeMonitorizationUnit(PriorityQueue<tUserInfo> & m,const int nDeliveries) {
	std::vector<int> out;
	for (int i = 0; i < nDeliveries; ++i){
		tUserInfo aux = m.top();
		out.push_back(aux.id);
		aux.notificationMoment += aux.period;
		m.push(aux);
		m.pop();
	}
	return out;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int nElems;
	int nInformationDeliveries;

	std::cin >> nElems;
	if (nElems == 0)
		return false;

	PriorityQueue<tUserInfo> monitorizationUnit;
	for (int i = 0; i < nElems; ++i) {
		int id,period;
		std::cin >> id >> period;
		monitorizationUnit.push({ id,period,period });
	}
	std::cin >> nInformationDeliveries;
	

	std::vector<int> sol = executeMonitorizationUnit(monitorizationUnit,nInformationDeliveries);

	for (int i = 0; i < sol.size(); ++i) {
		std::cout << sol[i] << '\n';
	}
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