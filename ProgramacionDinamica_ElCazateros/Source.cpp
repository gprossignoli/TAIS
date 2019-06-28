// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Matriz.h"



using loot = int;
using depth = int;
using pickedChests = std::vector<std::pair<depth, loot>>;
// función que resuelve el problema
/*const data dive(int chest, int oxigenTime, Matriz<data> & M, std::vector<std::pair<depth, loot>> const& chests) {
	
	while (oxigenTime > 0) {
		while (chest <= M.numcols()) {
			const data a = dive(chest - 1, oxigenTime, M, chests);
			const data b = dive(chest - 1, oxigenTime - (3 * chests[chest].first), M, chests);

			if (std::max(a.first, b.first) == a.first) {
				M[oxigenTime][chest] = a;
			}
			else { //if the chest it's picked then you store his position on the chests vector to using it on the output
				M[oxigenTime][chest] = b;
				M[oxigenTime][chest].second.push_back(chest);
			}
		}
	}

}*/

const std::pair<loot, pickedChests> resolve(const int oxigenTime, const int nChests, 
												std::vector<std::pair<depth, loot>> const& chests) {

	std::vector<std::vector<int>>M(nChests+1);
	for (int i = 0; i < M.size(); ++i) {
		for (int j = 0; j <= oxigenTime; ++j) {
			M[i].push_back(0);
		}
	}

	for (int chest = 1; chest <= nChests; chest++) {
		for (int t = oxigenTime; t > 0; t--) {
			if (3 * chests[chest-1].first > t) {
				M[chest][t] = M[chest - 1][t];
			}
			else {
				const int a = M[chest - 1][t];
				const int b = M[chest - 1][t - (3 * chests[chest-1].first)] + chests[chest-1].second;
				if (std::max(a, b) == a) {
					M[chest][t] = a;
				}
				else {
					M[chest][t] = b;
				}
			}
		}
	}

	pickedChests pc;
	int oxigen = oxigenTime;

	for (int c = nChests; c > 0; c--) {
		if (M[c][oxigen] > M[c - 1][oxigen]) {
			pc.push_back(chests[c-1]);
			oxigen -= 3 * chests[c - 1].first;
		}
		
	}
	
	return { M[nChests][oxigenTime],pc};
}

bool resuelveCaso() {

	int oxigenTime, nChests;

	std::cin >> oxigenTime>>nChests;
	if (!std::cin)
		return false;

	std::vector <std::pair<depth, loot>> chests(nChests);
	for (int i = 0; i < nChests; ++i) {
		std::cin >> chests[i].first >> chests[i].second;
	}

	if ((oxigenTime || nChests) == 0) {
		std::cout << "0\n0\n----\n";
		return true;
	}

	

	std::pair<loot, pickedChests> sol = resolve(oxigenTime,nChests,chests);
	std::cout << sol.first << '\n' << sol.second.size() << '\n';
	for (int i = sol.second.size()-1; i >= 0; i--)
		std::cout << sol.second[i].first << " " << sol.second[i].second << '\n';
	std::cout << "----\n";

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