// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>


int resolver(const int pesoMax, std::vector<int> & cola) {
	std::sort(cola.begin(), cola.end(), std::greater<int>()); 
	int i = 0;
	int j = cola.size() - 1;
	int viajes = 0;
	while (i <= j) {
		if (cola[i] + cola[j] <= pesoMax) {
			++i;
			--j;
		}
		else
			++i;

		++viajes;
	}

	return viajes;
}


bool resuelveCaso() {
	int pesoMax, personas;
	std::cin >> pesoMax >> personas;
	if (!std::cin)
		return false;

	std::vector<int> cola(personas);
	for (int i = 0; i < personas; ++i) {
		std::cin >> cola[i];
	}


	int sol = resolver(pesoMax,cola);

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