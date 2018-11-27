// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

bool greatestToLeast(int const& a, int const& b) {
	return a > b;
}

/* el coste de ordenar ambos vectores sera 2 (N log(N)) 
y el del bucle sera N, donde N es el numero de ciudades,
por tanto el coste del algortimo es N log(N)
*/
int calculateAssuredWins(const int cities,std::vector<int> & enemies,std::vector<int> & soldiers) {
	std::sort(enemies.begin(), enemies.end(),greatestToLeast);
	std::sort(soldiers.begin(), soldiers.end(),greatestToLeast);

	int assuredWins = 0;
	int i = 0;
	int j = 0;
	while (i < cities) {
		if (soldiers[j] >= enemies[i]) {
			++assuredWins;
			++j;
		}
		++i;
	}

	return assuredWins;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int cities;
	std::cin >> cities;
	if (!std::cin)
		return false;

	std::vector<int> enemiesInTheCity(cities);
	for (int i = 0; i < cities; ++i) {
		std::cin >> enemiesInTheCity[i];
	}

	std::vector<int> soldiersInUnit(cities);
	for (int i = 0; i < cities; ++i) {
		std::cin >> soldiersInUnit[i];
	}

	std::cout << calculateAssuredWins(cities, enemiesInTheCity, soldiersInUnit) << '\n';

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