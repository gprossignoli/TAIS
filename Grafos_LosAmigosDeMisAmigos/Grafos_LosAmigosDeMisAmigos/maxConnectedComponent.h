#ifndef maxConnectedComponent_h
#define maxConnectedComponent_h

#include <algorithm>
#include "Grafo.h"

class mcc {
private:
	int _max;
	std::vector<bool> marked;

	void dfs(Grafo const& g, const int v, int & tam) {
		marked[v] = true;
		++tam;
		for (int w : g.ady(v)) {
			if (!marked[w]) {
				dfs(g, w, tam);
			}
		}
	}
public:

	mcc(Grafo const& g) : marked(g.V(),false), _max(0) {
		
		for (int v = 0; v < g.V(); ++v) {
			if(!marked[v]){
				int tam = 0;
				dfs(g, v, tam);
				this->_max = std::max(_max, tam);
			}
		}
	}

	int getMCC() const{
		return _max;
	}
};

#endif

