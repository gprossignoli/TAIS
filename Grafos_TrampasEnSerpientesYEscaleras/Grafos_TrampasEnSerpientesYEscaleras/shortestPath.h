#ifndef shortestPath_h
#define shortestPath_h

#include <vector>
#include <queue>
#include "GrafoDirigido.h"


class shortestPath {

private:
	std::vector<bool> marked;
	std::vector<int> distTo;
	
	void bfs(GrafoDirigido const& g, int s) {
		std::queue<int> q;
		distTo[s] = 0;
		marked[s] = true;
		q.push(s);
		
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			
			for (int w : g.ady(v)) {
				if (!marked[w]) {
					distTo[w] = distTo[v] + 1;
					marked[w] = true;
					q.push(w);
				}
			}
		}
	}

public:
	shortestPath(GrafoDirigido const& g, int & bestPath) : marked(g.V(),false) , distTo(g.V()) {
		bfs(g,0);
		bestPath = distTo.back();
	}

};
#endif
