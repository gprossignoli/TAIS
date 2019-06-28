#ifndef PathsToSchool_h
#define PathsToSchool_h

#include <vector>
#include "IndexPQ.h"
#include "GrafoValorado.h"

/* Para resolver el problema se debe aplicar el algoritmo de Dijsktra, que permitira calcular 
   los caminos minimos hasta el colegio desde la casa de Lucas.
   En esta version ademas de calcular el numero minimo, añadimos un vector que contendra cuantos caminos con la 
   misma distancia llegan hasta cada vertice, de esta forma sabremos el numero de alternativas que hay para llegar al
   colegio.
   El coste en tiempo es E * log(V)  donde E es el numero de Aristas y V el numero de vertices del grafo*/

class PathsToSchool {
private:
	std::vector<int> distTo;
	std::vector<int> paths; //calcula los caminos disponibles hasta cada vertice
	IndexPQ<int> pq;
	std::vector<bool> isInPQ;
	const int infinity = 1000000000;


	void relax(Arista<int> e, const int v)
	{
		int w = e.otro(v);
		if (distTo[w] > distTo[v] + e.valor()) //si encuentra un camino mas corto
		{
			distTo[w] = distTo[v] + e.valor();
			paths[w] = paths[v]; 
			if (isInPQ[w]) pq.update(w, distTo[w]);
			else {
				pq.push(w, distTo[w]);
				isInPQ[w] = true;
			}
		}
		else if (distTo[w] == distTo[v] + e.valor()) //si encuentra una alternativa
			paths[w] += paths[v];
	}

public:
	PathsToSchool(GrafoValorado<int> G, const int src) : distTo(G.V(),0), paths(G.V(),0), 
		pq(G.V()), isInPQ(G.V(),false) {

		for (int v = 0; v < G.V(); v++)
			distTo[v] = infinity;
		
		distTo[src] = 0;
		pq.push(src, 0);
		paths[src] = 1;
		
		while (!pq.empty())
		{
			int v = pq.top().elem;
			pq.pop();
			for (Arista<int> e : G.ady(v))
				relax(e,v);
		}

	}

	const int pathsTo(const int v) {
		return paths[v];
	}

};


#endif


