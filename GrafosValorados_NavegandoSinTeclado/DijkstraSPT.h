#ifndef DijkstraSPT_h
#define DijkstraSPT_h

#include <limits>
#include <vector>
#include <stdexcept>
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

const int POSITIVE_INFINITE = 1000000000;

class DijkstraSP {
private:
	
	std::vector<AristaDirigida<int>> edgeTo;
	std::vector<int> distTo;
	std::vector<bool> containedInPQ;
	IndexPQ<int> pq;

	void relax(AristaDirigida<int> const& e) {
		int v = e.from();
		int w = e.to();
		if (distTo[w] > distTo[v] + e.valor()) {
			distTo[w] = distTo[v] + e.valor();
			edgeTo[w] = e;
			
			if (containedInPQ[w]) 
				pq.update(w, distTo[w]);
			else {
				pq.push(w, distTo[w]);
				containedInPQ[w] = true;
			}

		}
	}
	
public:

	DijkstraSP(GrafoDirigidoValorado<int> const& G, const int src) 
		: edgeTo(G.V()), distTo(G.V()), pq(G.V()), containedInPQ(G.V(),false) 
	{
		for (int v = 0; v < G.V(); ++v) {
			distTo[v] = POSITIVE_INFINITE;
		}
		distTo[src] = 0;
		pq.push(src, 0);
		containedInPQ[src] = true;
		while (!pq.empty()) {
			int v = pq.top().elem;
			pq.pop();
			containedInPQ[src] = false;

			for (AristaDirigida<int> e : G.ady(v))
				relax(e);
		}

	}

	int getDisTo(const int dst) const {
		if (distTo[dst] != POSITIVE_INFINITE)
			return distTo[dst];
		else
			throw std::domain_error("IMPOSIBLE");
	}

};
#endif