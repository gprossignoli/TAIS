#ifndef ForestMap_h
#define ForestMap_h

#include <vector>
#include "ConjuntosDisjuntos.h"


using Map = std::vector<std::vector<char>>;

class forest {
private:
	
	bool travelIsPossible;
	const int maxJumpDist;
	ConjuntosDisjuntos trees;

	bool validPos(const int x, const int  y) {
		const std::pair<int, int> maxDist(x + maxJumpDist, y + maxJumpDist);
		if (x <= maxDist.first && y <= maxDist.second)
			return true;

		return false;
	}

public:

	forest(Map const& M, const int & MaxJumpDist, const int & R, const int & C) : maxJumpDist(MaxJumpDist), trees(R*C), travelIsPossible(true) {
		trees.unir(0, (R*C) - 1);
		for (int r; r < R; ++r) {
			for (int c; c < C; ++c) {
				if (M[r][c] == '#' && validPos(r,c)) {
					int pos = r * C + c;
					trees.unir(0, pos);
				}
			}
		}
	}

	bool isPossible() {
		if (trees.num_cjtos == 1)
			return true;

		return false;
	}
};


#endif