// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>

using tGroup = struct {
	int initMusicians; 
	int currentMusicians; //musicians per music score
	int musicScores;
};

bool operator<(tGroup const& a, tGroup const& b) {
	return a.currentMusicians < b.currentMusicians;
}


int resolver(std::priority_queue<tGroup> & o,const int musicScores) {
	int i = musicScores;
	while (i > 0) {
		tGroup tmp = o.top();
		++tmp.musicScores;
		o.pop();
		if (tmp.musicScores > 1) {
			tmp.currentMusicians = (tmp.initMusicians / tmp.musicScores) + (tmp.initMusicians % tmp.musicScores > 0);
		}
		o.push(tmp);
		--i;
	}
	return o.top().currentMusicians;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int musicScores, groups;

	std::cin >> musicScores >> groups;
	if (!std::cin)
		return false;
	std::priority_queue<tGroup> orchestra;
	for (int i = 0; i < groups; ++i) {
		int aux;
		std::cin >> aux;
		orchestra.push({ aux,aux,1 });
	}

	int sol = orchestra.top().currentMusicians;
	if(musicScores > groups)
		sol = resolver(orchestra,(musicScores - groups));
	std::cout << sol << '\n';


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