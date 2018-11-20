// Gerardo Parra Rossignoli
// TAIS 20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

bool greaterToLeast(const int i, const int j) {
	return i > j;
}

//el coste de la funcion es N log (N) donde N es el numero de partidos, matches.
int resolver(std::vector<int> & broncos, std::vector<int> & rivals,const int matches) {
	std::sort(rivals.begin(), rivals.end()); 
	std::sort(broncos.begin(), broncos.end(), greaterToLeast);

	int sol = 0;
	bool broncosIsGreater = true;
	int i = 0;

	while (i < matches && broncosIsGreater) {
		if (broncos[i] <= rivals[i])
			broncosIsGreater = false;
		else
			sol += (broncos[i] - rivals[i]);
		++i;
	}
	
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int matches;
	std::cin >> matches;
	if (matches == 0)
		return false;
	
	std::vector<int> rivals(matches);
	std::vector<int> broncos(matches);

	for (int i = 0; i < matches; ++i) {
		std::cin >> rivals[i];
	}

	for (int i = 0; i < matches; ++i) {
		std::cin >> broncos[i];
	}

	std::cout << resolver(broncos,rivals,matches) << '\n';

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