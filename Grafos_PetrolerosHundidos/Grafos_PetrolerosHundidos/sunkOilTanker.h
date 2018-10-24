#ifndef sunkOilTanker_h
#define sunkOilTanker_h

#include <algorithm>
#include "ConjuntosDisjuntos.h"

using Map = std::vector<std::vector<char>>;

class sunkOilTanker {
private:
	int R;
	int C;
	int biggerSlick;
	ConjuntosDisjuntos seaMap;

	bool validPos(int i, int j) const {
		return 0 <= i && i < R && 0 <= j && j < C;
	}
	
	const std::vector<std::pair<int, int>> dirs = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 }, {-1,-1}, {-1,1},{1,-1},{1,1} };

	int checkPos(Map const& M,int r, int c,ConjuntosDisjuntos & map) {
		const int src = r * R + c;
		int idSrc;

		for (auto d : dirs) {	
			const int nr = r + d.first;
			const int nc = c + d.second;
			const int dst = nr * R + nc;
			if (validPos(nr, nc) && M[nr][nc] == '#') {
				const int idDst = map.buscar(dst);
				idSrc = map.buscar(src);
				map.unir(idSrc, idDst);
			}
		}

		idSrc = map.buscar(src);
		return map.tam(idSrc);
	}

public:

	sunkOilTanker(Map const& M) : R(M.size()), C(M[0].size()), biggerSlick(0), seaMap(R*C) {
		
		for (int r = 0; r < R; ++r){
			for (int c = 0; c < C; ++c) {
				if (M[r][c] == '#')
					biggerSlick = std::max(checkPos(M,r, c, seaMap),biggerSlick);
			}
		}
	}

	void addSlick(Map const& M,const int r,const int c) {
		biggerSlick = std::max(checkPos(M, r, c, seaMap), biggerSlick);
	}


	int getBiggerSlick() {
		return biggerSlick;
	}
};


#endif
