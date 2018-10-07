#ifndef grafoBipartito_h
#define grafoBipartito_h

#include <vector>
#include "Grafo.h"

class grafoBipartito {
	typedef char color;
private:
	std::vector<std::pair<bool, char>> marked;
	
	bool dfs(Grafo const& g,int v, const color c) {
		marked[v] = { true,c };
		for (int w : g.ady(v)) {
			if (!marked[w].first) {
				if (c == 'b')
					dfs(g, w, 'r');
				else
					dfs(g, w, 'b');
			}
			else if (marked[w].second == c) {
				return false;
			}
		}
		return true;
	}

public:
	grafoBipartito(Grafo const& g, bool & bipartiteGraph) : marked(g.V(),{ false,' '}) {
		for (int v = 0; v < g.V(); ++v) {
			if (!marked[v].first) {
				color c = 'b';
				bipartiteGraph = dfs(g, v, c);
			}
		}
	}
};

#endif

