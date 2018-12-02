// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Matriz.h"

typedef struct {
	int lenght;
	int cost;
}tRod;

// función que resuelve el problema
bool getRodIsPossible(std::vector<tRod> const& rods,const int L) {
	Matriz<int> m(rods.size(), L + 1,0);

	//coste = N^2, siendo N el numero de varillas
	for (int i = 0; i < rods.size(); ++i) {
		int lenght = 0;
		for (int r = i; r >= 0; --r) {
			lenght += rods[r].lenght;
			if (lenght <= L)
				m[i][lenght] = 1;
		}
	}
	
	bool possible = false;
	int i = 0;
	//coste = N, siendo N el numero de varillas
	while (i < m.numfils() && !possible) {
		if (m[i][L] == 1)
			possible = true;
		++i;
	}

	return possible;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N, L;
	std::cin >> N >> L;
	if (!std::cin)
		return false;

	std::vector<tRod> rods(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> rods[i].lenght >> rods[i].cost;
	}

	std::cout << getRodIsPossible(rods, L) << " ";

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