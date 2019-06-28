#ifndef Guards_h
#define Guards_h

#include <vector>
#include <algorithm>
#include "Grafo.h"

/*
	El problema se puede dividir en dos cuestiones. La primera se trata de averiguar si se trata de un grafo bipartito,
	la segunda, de averiguar, en caso de que sea bipartito, que grupo tiene menos elementos.
	Para resolver ambas preguntas usaremos un algoritmo de busqueda en profundidad al que le añadiremos un contador de 
	elementos para cada grupo.

	El coste en tiempo es E + V siendo E el nº de aristas y V el nº de vertices
*/

class Guards {
private:
	std::vector<std::pair<bool, char>> marked;
	int necessaryGuards;
	bool isBipartite;
	const bool dfs(Grafo const& G, const int v, const char option,int & nNecessaryGuardsA, int & nNecessaryGuardsB)
	{
		marked[v].first = true;
		marked[v].second = option;
		if(option == 'A')
			++nNecessaryGuardsA;
		else if(option == 'B')
			++nNecessaryGuardsB;

		bool bipartite = true;
		for (int w : G.ady(v)) {
			if (!bipartite)
				return false;

			if (!marked[w].first)
			{
				if (option == 'A') {
					bipartite = dfs(G, w, 'B',nNecessaryGuardsA,nNecessaryGuardsB);
					
				}
				else if(option == 'B'){					
					bipartite = dfs(G, w, 'A', nNecessaryGuardsA, nNecessaryGuardsB);
					
				}
			}

			else if (option == marked[w].second){
					return false;
			}
		}

		return bipartite;
	}

public:

	Guards(Grafo const& G) : marked(G.V(), { false,'n' }), necessaryGuards(0), isBipartite(true){
		if (G.V() == 1) {
			necessaryGuards = 0;
		}

		auto v = 0;
		while(v < G.V() && isBipartite) {
			if (!marked[v].first) { // se recorre una nueva componente conexa
				int nNeccesaryGuardsA = 0;
				int nNeccesaryGuardsB = 0;
				isBipartite = dfs(G, v,'A', nNeccesaryGuardsA,nNeccesaryGuardsB);
				necessaryGuards += std::min(nNeccesaryGuardsA, nNeccesaryGuardsB);
			}
			++v;
		}
	}

	const int minimumNecessaryNumberOfGuards() const{
		return necessaryGuards;
	}

	const bool isImpossible() const {
		if (isBipartite)
			return false; //if the graph is bipartite is NOT impossible
		
		return true;
	}

};

#endif
