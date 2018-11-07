#ifndef truckRoutes_h
#define truckRoutes_h

#include <vector>
#include <queue>
#include "GrafoValorado.h"

class TruckRoute {
private:
	std::vector<int> distTo;
	std::vector<bool> marked;

	void bfs(GrafoValorado<int> const& G,const int s,const int truckWidth){
		std::queue<int> q;
		distTo[s] = 0;
		marked[s] = true;
		q.push(s);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto w : G.ady(v)) {
				if (!marked[w.otro(v)] && truckWidth <= w.valor()) {
					distTo[w.otro(v)] = distTo[v] + 1;
					marked[w.otro(v)] = true;
					q.push(w.otro(v));
				}
			}
		}
	}

public:

	TruckRoute(GrafoValorado<int> const& G,const int src,const int truckWidth) : marked(G.V(), false), distTo(G.V(), 0) {
		bfs(G, src,truckWidth);
	}

	bool existPath(const int dst) const {
		return marked[dst];
	}
};

#endif