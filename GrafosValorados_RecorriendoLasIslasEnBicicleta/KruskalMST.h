#ifndef KruskalMST_h
#define KruskalMST_h

#include <vector>
#include <queue>
#include "PriorityQueue.h"
#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"

using edgesList = std::vector<Arista<int>>;

class kruskalMST {
private:
	std::queue<Arista<int>> mst;
	int MSTCost;
	bool existsMST;

	void loadEdges(PriorityQueue<Arista<int>> & pq, edgesList const & edges){
		for (int i = 0; i < edges.size(); ++i) { 
			pq.push(edges[i]);
		}
	}

public:

	kruskalMST(GrafoValorado<int> const & G, edgesList const & eList) : MSTCost(0), existsMST(false) {
		PriorityQueue<Arista<int>> pq;//min pq
		loadEdges(pq,eList);
		ConjuntosDisjuntos uf(G.V()); //Union-Find

		while (!pq.empty() && mst.size() < G.V() - 1) {
			Arista<int> e = pq.top(); //greedily add edges to MST
			pq.pop();
			int v = e.uno(); 
			int w = e.otro(v); 

			if (!uf.unidos(v, w)) { //if edge v–w doesn't create cycle
				uf.unir(v, w); //merge connected components
				mst.push(e); //add edge e to MST
				MSTCost += e.valor();
			}
		}
		if (mst.size() == G.V() - 1)
			existsMST = true;
	}

	std::queue<Arista<int>> edges() const{
		return mst;
	}

	int getMSTCost() const {
		return MSTCost;
	}

	bool exists() const {
		return existsMST;
	}
};

#endif


