// Gerardo Parra Rossignoli
// TAIS 20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Matriz.h"


/*
-Explicacion: por cada turno comparo los cubos en los extremos y, selecciono el max entre los dos que, 
	ademas conocen de forma recursiva todas las posibles elecciones posibles teniendo en cuenta tambien a la otra vaca.
	
	buckets(i,j) = { max ( Bi + { buckets(i + 2,j) si Bi+1 > Bj 
								  buckets(i + 1, j - 1) si Bj > Bi+1 } si Bi > Bj
							, Bj + {buckets(i + 1, j - 1) si Bi > Bj-1
									buckets(i, j - 2) si Bj-1 > Bi } si Bj > Bi) }
	*/

int timeToEat(std::vector<int> const& buckets) {
	Matriz<int> m(buckets.size() + 1, buckets.size() + 1, 0);	

	for (int i = 1; i < buckets.size()-1; ++i) {
		m[i][i + 1] = std::max(buckets[i], buckets[i + 1]);
	}

	for (int d = 3; d < buckets.size(); ++d) {
		for (int k = 1; k < buckets.size() - d; ++k) {
			int j = k + d;
			int c1, c2;
			if (buckets[j] > buckets[k + 1]) c1 = m[k + 1][j - 1];
			else c1 = m[k + 2][j];

			if (buckets[k] > buckets[j - 1]) c2 = m[k + 1][j - 1];
			else c2 = m[k][j - 2];

			m[k][j] = std::max(buckets[k] + c1, buckets[j] + c2);
		}
	}

	return m[1][buckets.size()];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int B;
	std::cin >> B;
	if (B == 0)
		return false;

	std::vector<int> buckets(B+1);
	buckets[0] = 0;
	for (int i = 1; i < B+1; ++i) {
		std::cin >> buckets[i];
	}


	std::cout << timeToEat(buckets);

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