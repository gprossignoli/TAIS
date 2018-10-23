#ifndef SeaMap_h
#define SeaMap_h

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using map = std::vector<char>; //implicit graph from input

class seaMap {
private:

	int R, C; //map size
	std::vector<std::vector<bool>> marked; //marked[i][j] = is visited <i,j> ?
	int slicks;
	int biggerSlickSize;

	bool correct(int i, int j) const {
		return 0 <= i && i < R && 0 <= j && j < C;
	}

	const std::vector<std::pair<int, int>> dirs = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };

	void dfs(map const& M, int i, int j, int & size) {
		marked[i][j] = true;
		++size;
		for (auto d : dirs){
			int ni = i + d.first;
			int nj = j + d.second;
			if (correct(ni, nj) && M[ni][nj] == '#' && !marked[ni][nj])
				dfs(M, ni, nj, size);
		}
	}

public:

	seaMap(map const& M) : R(M.size()), C(M[0].size()), 
		marked(R, std::vector<bool>(C, false)), slicks(0), biggerSlickSize(0) {

		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (M[i][j] == '#' && !marked[i][j]) {
					//new slick
					int newSize = 0;

					dfs(M, i, j, newSize);

					biggerSlickSize = std::max(biggerSlickSize, newSize);
					++slicks;
				}
			}
		}
	}

	int addSlick(map const& M, const int r, const int c) {
		int newSize = 0;

		dfs(M, r, c, newSize);

		biggerSlickSize = std::max(biggerSlickSize, newSize);
		
		if(newSize > 1) //new slick
			++slicks;

		return biggerSlickSize;
	}

	int getSlicksNumber() const{
		return slicks;
	}

	int getBiggerSlickSize() const {
		return biggerSlickSize;
	}

};

#endif
