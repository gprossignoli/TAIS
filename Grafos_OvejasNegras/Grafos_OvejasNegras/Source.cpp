// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "sheepFinder.h"

bool resuelveCaso() {
	int R, C;
	std::cin >> C >> R;
	if (!std::cin)
		return false;

	image img(R);
	for (int r = 0; r < R; ++r){
		std::string line;
		std::cin >> line;
		img[r] = line;
	}

	SheepFinder sf(img,R,C);

	std::cout << sf.getWhiteSheeps() << '\n';
	
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