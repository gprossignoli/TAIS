// Gerardo Parra Rossignoli
// TAIS 20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>

void bfs(std::vector<std::vector<int>> const& g, int s,std::vector<bool> & marked,std::vector<int> & distTo) {
	std::queue<int> q;
	distTo[s] = 0;
	marked[s] = true;
	q.push(s);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int w : g[v]) {
			if (!marked[w]) {
				distTo[w] = distTo[v] + 1;
				marked[w] = true;
				q.push(w);
			}
		}
	}
}

bool resuelveCaso() {
	int N, nDice, snakes, stairs; // nDice <= N

	std::cin >> N >> nDice >> snakes >> stairs;
	if (N == 0)
		return false;

	const int boardSize = N * N;
	
	std::vector<std::vector<int>> implicitGraph(boardSize);

	for (int i = 0; i < (snakes + stairs); ++i) {
		int s, d;
		std::cin >> s >> d;
		implicitGraph[s-1].push_back(d-1);
	}
	
	for (int i = 0; i < boardSize; ++i) {
		if (implicitGraph[i].empty()) {
			for (int j = i+1; j < implicitGraph.size() && j <= (nDice + i); ++j) {
				if (implicitGraph[j].empty()) {
					implicitGraph[i].push_back(j);
				}
				else
					implicitGraph[i].push_back(implicitGraph[j][0]);
			}
		}
	}

	std::vector<bool> marked(boardSize, false);

	std::vector<int> distTo(implicitGraph.size());

	bfs(implicitGraph, 0, marked, distTo);

	std::cout << distTo[implicitGraph.size()-1] << '\n';

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