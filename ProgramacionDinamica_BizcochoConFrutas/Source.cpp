// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

/*
	El problema consiste en maximar el numero de trozos con el mismo tipo de fruta que se pueden elegir cortando el bizcocho.
	Para ello tenemos tres casos a la hora de cortar el bizcocho:
	1) cortar un trozo de cada extremo
	2) cortar dos trozos del extremo derecho
	3) cortar dos trozos del extremo izquierdo

	Para representar todas las posibles combinaciones y obtener el resultado optimo utilizaremos una matriz que contenga
	N filas y N columnas.

	cortar(i,j) contendra el maximo de trozos del mismo tipo de fruta que podemos elegir
	cortar(i,j) => {
						Bizcocho(i) == Bizcocho(j) && Bizcocho(i) != 0 si i = j - 1
						max( cortar(i+2,j), cortar(i,j+2), 
						cortar(i+1,j-1) + Bizcocho(i) == Bizcocho(j) && Bizcocho(i)
						) si 0 <= i < j < N
					}

	El coste sera N^2 que es el coste de rellenar la matriz
*/


// función que resuelve el problema
const int resolve(std::vector<int> const& cake) {
	int N = cake.size();
	std::vector<std::vector<int>> M(N,std::vector<int>(N,0));

	//inicializo la diagonal
	for (int i = 0; i < cake.size()-1; i++) {
		int j = i + 1;
		M[i][j] = (cake[i] == cake[j] && cake[i] != 0);
	}

	for (int diagonal = 3; diagonal < cake.size(); diagonal+=2) {
		for (int i = 0; i < cake.size() - diagonal; i++) {
			int j = i + diagonal;
			M[i][j] = std::max(
				M[i+2][j],
				std::max(
					M[i][j-2],
					M[i+1][j-1] + (cake[i] == cake[j] && cake[i] != 0)
				)
			);
		}
	}

	return M[0][cake.size()-1];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int cakeChunks;

	std::cin >> cakeChunks;
	if (!std::cin)
		return false;
	
	std::vector<int> cake(cakeChunks);

	for (int i = 0; i < cake.size(); i++) {
		int fruit;
		std::cin >> fruit;
		cake[i] = fruit;
	}

	std::cout << resolve(cake) << '\n';

	


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