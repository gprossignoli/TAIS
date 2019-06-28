#ifndef mazeExperiment_h
#define mazeExperiment_h

#include <vector>
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

/*
	Para el problema debemos encontrar todos los nodos que se encuentran a una distancia <= Time. Para resolverlo utilizaremos
	el algoritmo de dijsktra modificandolo para que solo compute la sub-componente minima dentro de la distancia permitida, de
	tal forma que los nodos que esten a una distancia mayor quedaran a distancia infinita.
	Por ultimo para recuperar la cantidad de nodos validos, recorreremos los vertices del grafo y si la distancia es <= Time
	entonces el nodo sera valido por lo que la variable cont, que es el nº de nodos validos, aumenta en 1.

	El coste del algoritmo es: E * log(V) + V siendo E el numero de aristas y V el numero de vertices.
*/

class Maze {
private:
	std::vector<int> distTo;
	std::vector<bool> isInPq;
	IndexPQ<int> pq;
	const int infinity = 100000000;
	const int Time;

	void relax(AristaDirigida<int> const& e)
	{
		int v =e.from(), w = e.to();
		
		const int betterDistance = distTo[v] + e.valor();
		if (distTo[w] > betterDistance && betterDistance <= Time)
		{
			distTo[w] = distTo[v] + e.valor();
					
			if (isInPq[w]) pq.update(w, distTo[w]);
			else { 
				pq.push(w, distTo[w]); 
				isInPq[w] = true;
			}
		}

	}

public:
	Maze(GrafoDirigidoValorado<int> const&  G,const int s,const int T) : distTo(G.V(),0), isInPq(G.V(),false),
		pq(G.V()), Time(T) {
		for (int v = 0; v < G.V(); v++)
			distTo[v] = infinity;

		distTo[s] = 0;
		pq.push(s, 0);

		while (!pq.empty())
		{
			int v = pq.top().elem; 
			pq.pop();
			
			for (AristaDirigida<int> e : G.ady(v))
				relax(e);
		}
	}


	const int getNumberMousesThatReachTheExit() {
		int cont = 0;
		for (int d = 0; d < distTo.size(); ++d) {
			if (distTo[d] <= Time)
				++cont;
		}

		return --cont;
	}

};

#endif