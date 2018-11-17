// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<bool> const& hose, std::vector<int> const& holes,const int patchLength) {
	int pos = 0;
	int patches = 0;
	int h = 0;
	while (pos < hose.size()) {
		if (hose[pos]) {
			patches++;
			pos += patchLength+1;
		}
		else if (pos > holes[h]) {
			h++;
		}
		else
			pos = holes[h];

	}

	return patches;
}


bool resuelveCaso() {
	int nHoles, patchLength;
	std::cin >> nHoles >> patchLength;

	if (!std::cin)
		return false;

	std::vector<int> holes(nHoles);
	for (int i = 0; i < nHoles;++i) {
		std::cin >> holes[i];
		holes[i]--;
	}

	std::vector<bool> hose(holes.back()+1,false);
	int h = 0;
	for (int i = 0; i < nHoles; ++i) {
		hose[holes[h]] = true;
		h++;
	}

	int necessaryPatches = resolver(hose,holes,patchLength);
	
	std::cout << necessaryPatches << '\n';

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