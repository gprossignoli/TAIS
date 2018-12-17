// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Matriz.h"

/*
	subsecuencia(i,j) = 	{subsecuencia(i-1,j-1)+1 i == j
							max(subsecuencia(i-1,j),subsecuencia(i,j-1)) i != j }
							
*/


int subsequence(std::string const& w1, std::string const& w2) {
	Matriz<int> m(w1.size()+1, w2.size()+1, 0);
	
	for (int i = 1; i < m.numfils(); ++i) {
		for (int j = 1; j < m.numcols(); ++j) {
			if (w1[i-1] == w2[j-1])
				m[i][j] = m[i - 1][j - 1] + 1;
			else
				m[i][j] = std::max(m[i - 1][j], m[i][j - 1]);
		}
	}

	return m[w1.size()][w2.size()];
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	std::string line;
	std::getline(std::cin, line);
	if (!std::cin)
		return false;
	
	std::string firstWord, secondWord;

	int i = 0;
	while (line[i] != ' ') {
		++i;
	}
	firstWord = line.substr(0, i);
	secondWord = line.substr(i + 1, line.length() - (i + 1));
	
	std::cout << subsequence(firstWord, secondWord) << '\n';

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