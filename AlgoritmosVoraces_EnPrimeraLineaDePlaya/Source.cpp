// Gerardo Parra Rossignoli
// TAIS 20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

typedef struct {
	int W;
	int E;
}tBuilding;

bool GreatestToLeast(tBuilding a, tBuilding b) {
	return a.W > b.W;
}

//el coste de ordenar el vector es N log(N) y el coste de recorrerlo es N, siendo N el numero de edificios
//por tanto el coste de la funcion es N + N log(N)
int resolver(std::vector<tBuilding> & buildings) {
	std::sort(buildings.begin(), buildings.end(), GreatestToLeast);
	int tunels = 0;
	int b = 0;
	

	while (b < buildings.size()) {
		int tmp = b + 1;
		while (tmp < buildings.size() && buildings[b].W < buildings[tmp].E) {
			tmp++;
		}
		tunels++;
		b = tmp;
	}

	return tunels;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int B;
	std::cin >> B;
	if (B == 0)
		return false;

	std::vector<tBuilding> buildings(B);
	for (int i = 0; i < B; ++i) {
		std::cin >> buildings[i].W >> buildings[i].E;
	}

	std::cout << resolver(buildings) << '\n';

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