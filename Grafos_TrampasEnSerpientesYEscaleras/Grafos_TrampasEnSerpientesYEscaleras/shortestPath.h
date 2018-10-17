#ifndef shortestPath_h
#define shortestPath_h

#include <vector>
#include <queue>
#include "GrafoDirigido.h"


class shortestPath {

private:
	
	


public:
	shortestPath(GrafoDirigido const& g, int & bestPath) : marked(g.V(),false) , distTo(g.V()) {
		bfs(g,0);
		bestPath = distTo.back();
	}

};
#endif
