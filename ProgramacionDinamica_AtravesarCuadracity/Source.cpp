// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

/*
	El problema pide cuantos caminos llegan a la casilla (N-1) + (M-1). Para averiguarlo crearemos una matriz de
	dimensiones N x M y tendremos la siguiente recursion:

	caminos(i,j) guarda el numero de caminos hasta esa posicion
	caminos(i,j) = {
						caminos(i-1,j) + caminos(i,j-1) si 0 < i < N y 0 < j < M
						0 si Posicion(i,j) == pasadizo
						1 si i == 0 y j == 0 -> Posicion de salida
					}

	el coste es N * M  siendo N x M las dimensiones de la matriz
*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N, M;
	std::cin >> N >> M;
	if (!std::cin)
		return false;

	std::vector<std::vector<int>> Cuadracity(N,std::vector<int>(M,0));

	char tmp;
	 
	//primera fila
	Cuadracity[0][0] = 1;
	std::cin >> tmp; //ignora la primera posicion
	for (int j = 1; j < M; ++j) {
		std::cin >> tmp;
		if (tmp == 'P')
			Cuadracity[0][j] = 0;
		else
			Cuadracity[0][j] = Cuadracity[0][j-1];
	}
	
	for (int i = 1; i < N; ++i) { //desde la segunda fila
		std::cin >> tmp; //descartar la primera j
		if (tmp == 'P')
			Cuadracity[i][0] = 0;
		else
			Cuadracity[i][0] = Cuadracity[i-1][0];

		for (int j = 1; j < M; ++j) {
			std::cin >> tmp;
			if (tmp == '.') {
				Cuadracity[i][j] = Cuadracity[i - 1][j] + Cuadracity[i][j - 1];
			}
			else if (tmp == 'P')
				Cuadracity[i][j] = 0;
		}
	}

	std::cout << Cuadracity[N - 1][M - 1] << '\n';

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