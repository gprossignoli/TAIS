#ifndef MinDistancePath_h
#define MinDistancePath_h

#include <vector>
#include "GrafoValorado.h"
#include "IndexPQ.h"

class MinDistancePath {
private:
	const int SRC;
	const int infinity = 1000000000;
	std::vector<int> edgeTo;
	std::vector<int> distTo;
	IndexPQ<int> pq;
	std::vector<bool> isInPQ;

	void relax(Arista<int> e,const int v)
	{
		int w = e.otro(v);
		if (distTo[w] > distTo[v] + e.valor())
		{
			distTo[w] = distTo[v] + e.valor();
			edgeTo[w] = v;
			if (isInPQ[w]) pq.update(w, distTo[w]);
			else { 
				pq.push(w, distTo[w]); 
				isInPQ[w] = true;
			}
		}
	}

public:
	MinDistancePath(GrafoValorado<int> const& G,const int s) : SRC(s), edgeTo(G.V()), distTo(G.V(),infinity), 
		pq(G.V()), isInPQ(G.V(),false) {
	
		for (int v = 0; v < G.V(); v++)
			distTo[v] = infinity;
		distTo[s] = 0;
		pq.push(s, 0);
		while (!pq.empty())
		{
			int v = pq.top().elem;
			pq.pop();
			for (Arista<int> e : G.ady(v))
				relax(e,v);
		}
	}

	const std::pair<int,int> getResults(const int dst) const{
		if (distTo[dst] == infinity)
			return { -1,-1 };
		int dist = distTo[dst];

		int nEdges = 0;
		int w = dst;
		do {
			++nEdges;
			w = edgeTo[w];
		} while (w != SRC);

		return { dist,nEdges };
	}
};

#endif
