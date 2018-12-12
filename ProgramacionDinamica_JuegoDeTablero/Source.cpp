// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Matriz.h"

/*
	game(0,col) = 0, col >= 0
	game(row,0) = 0, i >= 0
	game(row,col) = { max( game(row-1,col - 1), 
						   game(row-1,col), 
						   game(row-1,col+1) )
						   + game(row,col) if row < Matriz.rows() && col <= Matriz.columns()}				

*/


std::pair<int,int> resolver(Matriz<int> const& m) {
	Matriz<int> game(m.numfils() + 1, m.numcols() + 2, 0);
	
	for (int row = 1; row < game.numfils(); ++row) {
		for (int col = 1; col < game.numcols() -1; ++col) {
			game[row][col] = std::max(std::max(game[row - 1][col - 1], game[row - 1][col]),
							 game[row - 1][col + 1]) + m[row-1][col-1];
		}
	}
	int sol = 0;
	int pos = 0;
	for (int i = 1; i < game.numcols() - 1; ++i) {
		if (sol < game[game.numfils() - 1][i]) {
			sol = game[game.numfils() - 1][i];
			pos = i;
		}
	}

	return { sol,pos };
}


bool resuelveCaso() {
	int M;
	std::cin >> M;
	if (!std::cin)
		return false;

	Matriz<int> m(M, M, 0);
	for(int i = 0; i < M; ++i){
		for (int j = 0; j < M; ++j) {
			std::cin >> m[i][j];
		}	
	}

	std::pair<int, int> sol = resolver(m);
	std::cout << sol.first << " " << sol.second << '\n';

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