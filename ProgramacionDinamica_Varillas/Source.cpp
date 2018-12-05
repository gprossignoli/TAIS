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

/*
	posible(0,l) = false, l > 0
	posible(i,0) = true, i >= 0	
	posible(i,l) = { posible(i-1, l) si l[i] > l		 
				    posible(i-1,l-l[i]) || posible(i-1,l) }

*/

bool isPossible(std::vector<tRod> const& rods, int L) {
	std::vector<std::vector<bool>> m(rods.size(), std::vector<bool>(L + 1, false));
	m[0][0] = true;
	for (int i = 1; i < rods.size(); ++i) {
		m[i][0] = true;
		for (int l = 1; l <= L; ++l) {
			if (rods[i].lenght <= l) m[i][l] = (m[i - 1][l - rods[i].lenght] || m[i - 1][l]);
			else m[i][l] = m[i - 1][l];
		}
	}


	return m[rods.size()-1][L];
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N, L;
	std::cin >> N >> L;
	if (!std::cin)
		return false;

	std::vector<tRod> rods(N+1);
	rods[0] = { 0,0 };
	for (int i = 1; i <= N; ++i) {
		std::cin >> rods[i].lenght >> rods[i].cost;
	}

	if (isPossible(rods, L))
		std::cout << "SI ";
	else
		std::cout << "NO ";

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