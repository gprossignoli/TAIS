// Gerardo Parra Rossignoli
// TAIS 20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Hora.h"


typedef struct film{
	int start;
	int end;
	int duration;
};

bool greatestToLeast(film const& a, film const& b) {
	return a.start > b.start;
}

//la ordenacion del vector cuesta N log(N) y recorrer el vector el  cuesta N,
//donde N es el numero de peliculas 
int resolver(std::vector<film> & films,const int nFilms) {
	std::sort(films.begin(), films.end(), greatestToLeast);
	int f = 0;
	int filmsReproducedAtSameTime = 0;

	while (f < nFilms) {
		int tmp = f + 1;
		while (tmp < nFilms && films[f].start <= films[tmp].end) {
			tmp++;
			filmsReproducedAtSameTime++;
		}
		f = tmp;
	}

	return nFilms - filmsReproducedAtSameTime;
}

bool resuelveCaso() {
	int nFilms;
	std::cin >> nFilms;
	if (nFilms == 0)
		return false;

	std::vector<film> films(nFilms);
	for (int i = 0; i < nFilms; ++i) {
		std::string h;
		int duration;
		std::cin >> h >> duration;
		hour t(h);

		film f;
		f.start = t.getHourInMinutes();
		f.duration = duration;
		f.end = f.start + duration;
		films[i] = f;
	}

	std::cout << resolver(films, nFilms) << '\n';

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