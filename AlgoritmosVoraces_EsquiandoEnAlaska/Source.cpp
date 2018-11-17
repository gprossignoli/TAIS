// Gerardo Parra Rossignoli
// TAIS 20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector<int> const& skierHeights, const int skisLengths) {
	int sol = skisLengths;
	for (int i = 0; i < skierHeights.size(); ++i) {
		sol = std::abs(sol - skierHeights[i]);
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
	int SkisLengths = 0;
	for (int i = 0; i < N; ++i) {
		int skiLength;
		std::cin >> skiLength;
		SkisLengths += skiLength;
	}

	std::cout << resolver(skierHeights,SkisLengths) << '\n';

	// escribir sol

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