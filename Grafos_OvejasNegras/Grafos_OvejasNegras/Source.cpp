// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "sheepFinder.h"

// función que resuelve el problema
TipoSolucion resolver(TipoDatos datos) {


}


bool resuelveCaso() {
	int R, C;
	std::cin >> R >> C;
	if (!std::cin)
		return false;

	image img(R);
	for (std::string & input : img) {
		img.push_back(input);
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