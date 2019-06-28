// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


/*
	siendo tablero la matriz que contiene la informacion
	ecuaciones recursivas: sumar(i,j) { tablero(i,j) + max(tablero(i-1,j-1),tablero(i-1,j),tablero(i-1,j+1)) para 1 <= i <= N 
																												  1 <= j <= N
*/	
const std::pair<int,int> resolve(const int N) {
	std::vector<std::vector<int>>M(N);

	for (int i = 0; i < N; ++i) {
		M[i].push_back(0);
		for(int j = 1; j <= N; ++j){
			int n;
			std::cin >> n;
			M[i].push_back(n);
		}
		M[i].push_back(0);
	}

	for (int i = 1; i < N; ++i) {
		for (int j = 1; j <= N; ++j) {
			M[i][j] += std::max(std::max(M[i - 1][j - 1], M[i - 1][j]), M[i - 1][j + 1]);
		}
	}

	std::pair<int, int> sol = { 0, 0};
	int j = 1;
	for (j; j <= N; ++j) {
		if (sol.first < M[N - 1][j]) {
			sol.first = M[N - 1][j];
			sol.second = j;
		}
	}

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N;
	std::cin >> N;
	if (!std::cin)
		return false;

	if (N == 0) {
		std::cout << "0 0\n";
		return true;
	}
	

	const std::pair<int, int> sol = resolve(N);
	std::cout << sol.first << " " << sol.second << '\n';
	


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