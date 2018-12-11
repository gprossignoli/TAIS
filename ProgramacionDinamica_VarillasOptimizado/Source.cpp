// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

typedef struct {
	int lenght;
	int cost;
}tRod;



/*
PARTE 1:

	posible(0,l) = false, l > 0
	posible(i,0) = true, i >= 0	
	posible(i,l) = { posible(i-1, l) si l[i] > l		 
				    posible(i-1,l-l[i]) || posible(i-1,l) }

*/

bool isPossible(std::vector<tRod> const& rods, int L) {
	std::vector<bool> v(L + 1, false);
	v[0] = true;
	for (int i = 1; i < rods.size(); ++i) {
		for (int j = L; j >= rods[i].lenght; --j) {
			v[j] = v[j - rods[i].lenght] || v[j];
		}
	}

	return v[L];
}

/*
PARTE 2:

	posible(0,l) = 0, l > 0
	posible(i,0) = 1, i >= 0
	posible(i,l) = { posible(i-1, l) si l[i] > l
					 posible(i-1,l-l[i]) + posible(i-1,l) }
*/


int countPossibles(std::vector<tRod> const& rods, int L) {
	std::vector<int> v(L + 1, 0);
	
	v[0] = 1;
	for (int i = 1; i < rods.size(); ++i) {
		for (int l = L; l >= rods[i].lenght; --l) {
			v[l] = v[l - rods[i].lenght] + v[l];
		}
	}

	return v[L];
}

/*
PARTE 3:

	posible(0,l) = inf, l > 0 <-- ??
	posible(i,0) = 0, i >= 0
	posible(i,l) = { posible(i-1, l) si l[i] > l
					 min(posible(i-1,l-l[i]) + 1,posible(i-1,l)) }
*/

int minimumRodsNecessary(std::vector<tRod> const& rods, int L,const int infinite) {
	std::vector<int> v(L + 1, infinite);

	v[0] = 0;
	for (int i = 1; i < rods.size(); ++i) {
		for (int l = L; l >= rods[i].lenght; --l) {
			v[l] = std::min(v[l - rods[i].lenght]+1, v[l]);
		}
	}

	return v[L];
}

/*
PARTE 4:

	posible(0,l) = inf, l > 0
	posible(i,0) = 0, i >= 0
	posible(i,l) = { posible(i-1, l) si l[i] > l
					 min(posible(i-1,l-l[i]) + i.coste,posible(i-1,l)) }
*/

int minimumCostNecessary(std::vector<tRod> const& rods, int L,const int infinite) {
	std::vector<int> v(L + 1, infinite);

	v[0] = 0;
	for (int i = 1; i < rods.size(); ++i) {
		for (int l = L; l >= rods[i].lenght; --l) {
			v[l] = std::min(v[l - rods[i].lenght] + rods[i].cost, v[l]);
		}
	}


	return v[L];
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

	if (isPossible(rods, L)) {
		std::cout << "SI " << countPossibles(rods, L) << " " 
			<< minimumRodsNecessary(rods,L, 1000000000) << " " << minimumCostNecessary(rods,L,1000000000) << '\n';
	}
	else
		std::cout << "NO \n";

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