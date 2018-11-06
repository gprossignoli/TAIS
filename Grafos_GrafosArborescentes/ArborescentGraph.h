#ifndef ArborescentGraph_h
#define ArborescenteGraph_h

#include <vector>
#include "GrafoDirigido.h"

class Arborescent {
private:
	std::vector<bool> marked;
	bool _arborescent;
	int _root;

	void dfs(GrafoDirigido const& G, const int v) {
		marked[v] = true;
		for (int w : G.ady(v)) {
			if (!marked[w])
				dfs(G, w);
		}
	}

public:
	Arborescent(GrafoDirigido const& G) : marked(G.V(),false), _arborescent(false), _root(-1) {
		
		for (int v = 0; v < G.V(); ++v) {
			bool hasCycle = false;
			for (int w : G.ady(v)) {
				if (!marked[w])
					marked[w] = true;
				else {
					hasCycle = true;
					break; 
					}
				}
			if (hasCycle)
				break;
		}
		
		int i = 0;
		while (!_arborescent && i < marked.size()) {
			if (!marked[i]) {
				_arborescent = true;
				_root = i;
			}
			++i;
		}
	}

	bool isArborescent() const {
		return _arborescent;
	}

	int root() {
		return _root;
	}

};

#endif
