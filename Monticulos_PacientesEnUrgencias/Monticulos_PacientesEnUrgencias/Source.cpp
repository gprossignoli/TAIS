// Gerardo Parra Rossignoli
// TAIS 20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>
#include<string>

using tPatientInfo = struct {
	std::string name;
	int triage;
	int timeOfArrival;
};


bool operator<(tPatientInfo const& a, tPatientInfo const& b) {
	if (a.triage < b.triage)
		return true;

	if (a.triage == b.triage) {
		if (a.timeOfArrival > b.timeOfArrival)
			return true;
	}

	return false;
}





void newPatient(std::priority_queue<tPatientInfo> & p,const int time) {
	std::string name;
	int triage;
	std::cin >> name >> triage;
	p.push({ name,triage,time });
}

std::string treatPatient(std::priority_queue<tPatientInfo> & p) {
	std::string out = p.top().name;
	p.pop();
	return out;
}

bool resuelveCaso() {
	int nEvents;
	int time = 1;
	std::cin >> nEvents;
	if (nEvents == 0)
		return false;

	std::priority_queue<tPatientInfo> patientList;

	for (int i = 0; i < nEvents; ++i) {
		char event;
		std::cin >> event;
		if (event == 'I') {
			newPatient(patientList,time);
			++time;
		}
		else if (event == 'A') {
			std::cout << treatPatient(patientList) << '\n';
		}
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