#ifndef MaxConnectedComponent_h 
#define MaxConnectedComponent_h 

#include <vector>
#include <algorithm>
#include "Grafo.h"

class bipartiteGraph {
public:
	bipartiteGraph(const Grafo G) : marked(G.V(), { false,'n' }) {
		auto v = 0;
		while(v < G.V() && _bipartito) {
			if (!marked[v].first) { // se recorre una nueva componente conexa
				if (!dfs(G, v, 'a'))
					_bipartito = false;
			}
			++v;
		}
	}

	bool isBipartite() {
		return _bipartito;
	}

private:
	std::vector<std::pair<bool,char>> marked; // marked[v] = se ha visitado el vértice v?
	bool _bipartito = true;
	// recorrido en profundidad de la componente de v
	bool dfs(Grafo const& G,const int v, const char type) {
		marked[v].first = true;
		marked[v].second = type;
		bool bipartite = true;

		for(int w : G.ady(v)) {
			if (!bipartite)
				return false;

			if (!marked[w].first) {
				if(type == 'a')
					bipartite = dfs(G, w, 'b');
				else
					bipartite = dfs(G, w, 'a');
			}

			else if (marked[w].second == type)
					return false;
		}

		return bipartite;
	}
};

#endif
