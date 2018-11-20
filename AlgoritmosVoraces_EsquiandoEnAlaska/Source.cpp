// Gerardo Parra Rossignoli
// TAIS 20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>



// el coste de la funcion es N log (N), siendo N el numero de elementos en ambos vectores
int resolver(std::vector<int> & skierHeights, std::vector<int> & skisLengths,const int N) {
	std::sort(skierHeights.begin(),skierHeights.end());
	std::sort(skisLengths.begin(), skisLengths.end());
	int sol = 0;
	for (int i = 0; i < N; ++i) {
		sol += std::abs(skierHeights[i] - skisLengths[i]);
	}

	return sol;
}

bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (N == 0)
		return false;

	std::vector<int> skierHeights(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> skierHeights[i];
	}
	std::vector<int> skisLengths(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> skisLengths[i];
	}

	std::cout << resolver(skierHeights,skisLengths,N) << '\n';

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