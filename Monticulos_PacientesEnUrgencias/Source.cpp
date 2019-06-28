// Gerardo Parra Rossignoli
// TAIS 20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <queue>

/*
	Explicacion: Para resolver el problema respresentare a cada paciente como un struct que contendrá
	el nombre, la gravedad y el momento de la llegada, que será igual al número de evento de la entrada.
	Para representar la gestión de los pacientes utilizaré una cola de prioridad de máximos 
	usando como prioridad la gravedad de los pacientes, en caso de que sea igual, 
	la prioridad se establece por quién ha llegado antes siendo el momento de ingreso menor.

	Coste: el coste es E * log(N) siendo N el número de pacientes en la cola y E el número de eventos de la entrada, 
	ya que tanto si se introduce un paciente como si se elimina el coste será logarítmico sobre el tamaño de la cola.
*/
typedef struct tPatient {
	std::string name;
	int severity;
	int entryTime;
};

bool operator<(tPatient const& a, tPatient const& b) {
	if (a.severity == b.severity)
		return a.entryTime > b.entryTime;

	return a.severity < b.severity;
}

void getPatient(std::priority_queue<tPatient> & patients,int entryTime) {
	std::string name;
	int patientSeverity;
	std::cin >> name >> patientSeverity;
	patients.push({ name,patientSeverity,entryTime });
}

void treatPatient(std::priority_queue<tPatient> & patients) {
	std::cout << patients.top().name << '\n';
	patients.pop();
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int events; char eventID;

	std::cin >> events;
	if (events == 0)
		return false;

	std::priority_queue<tPatient> patients;

	for (int i = 0; i < events; ++i) {
		std::cin >> eventID;

		if (eventID == 'I')
			getPatient(patients,i);

		if (eventID == 'A') {
			treatPatient(patients);
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