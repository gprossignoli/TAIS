#ifndef MinEdgesPath_h
#define MinEdgesPath_h

#include <vector>
#include <queue>
#include "GrafoValorado.h"

class MinEdgesPath {
private:
	std::vector<bool> marked; // marked[v] = ¿hay camino de s a v?
	std::vector<int> distTo; // distTo[v] = aristas en el camino s-v más corto

	void bfs(GrafoValorado<int> const& G,const int s) {
		std::queue<int> q;
		distTo[s] = 0;
		marked[s] = true;
		q.push(s);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (Arista<int> edge : G.ady(v)) {
				const int w = edge.otro(v);
				if (!marked[w]) {
					distTo[w] = distTo[v] + 1;
					marked[w] = true;
					q.push(w);
				}
			}
		}
	}

public:
	MinEdgesPath(GrafoValorado<int> const& G,const int s)
		: marked(G.V(), false), distTo(G.V()) {
		bfs(G, s);
	}

	// ¿Hay camino del origen a v?
	bool hayCamino(int v) const {
		return marked[v];
	}

	// número de aristas entre s y v
	int distancia(int v) const {
		return distTo[v];
	}
};

#endif
