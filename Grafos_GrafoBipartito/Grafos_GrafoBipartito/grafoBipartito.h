#ifndef grafoBipartito_h
#define grafoBipartito_h

#include <vector>
#include "Grafo.h"

class grafoBipartito {
	typedef char color;
private:
	std::vector<std::pair<bool, char>> marked;
	
	bool dfs(Grafo const& g,int v, const color c, bool bipartite) {
		marked[v] = { true,c };
		int w;
		for (int w : g.ady(v)) {
			if (bipartite) {
				if (!marked[w].first) {
					if (c == 'b')
						bipartite = dfs(g, w, 'r',bipartite);
					else
						bipartite = dfs(g, w, 'b',bipartite);
				}
				else if (marked[w].second == c) {
					bipartite = false;
				}
			}
			else
				return false;
		}
		return bipartite;
	}

public:
	grafoBipartito(Grafo const& g, bool & bipartiteGraph) : marked(g.V(),{ false,' '}) {
		for (int v = 0; v < g.V(); ++v) {
			if (!marked[v].first) {
				color c = 'b';
				bipartiteGraph = dfs(g, v, c,true);
			}
		}
	}
};

#endif

