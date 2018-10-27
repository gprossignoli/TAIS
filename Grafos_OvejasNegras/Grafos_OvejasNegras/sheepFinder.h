#ifndef sheepFinder_h
#define sheepFinder_h

#include <vector>
#include <string>

using image = std::vector<std::string>;

class SheepFinder {
private:
	int R, C;
	std::vector<std::vector<bool>> marked;
	int whiteSheeps;
	int sheeps;

	std::vector<std::pair<int,int>> dirs = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
	bool validPos(int i, int j) const {
		return 0 <= i && i < R && 0 <= j && j < C;
	}

	void dfs(image const& img, int r, int c) {
		marked[r][c] = true;
		for (auto d : dirs) {
			int nr = r + d.first, nc = c + d.second;
			if (validPos(nr, nc) && img[nr][nc] == '#' && !marked[nr][nc]) {
				dfs(img, nr, nc);
			}
		}
	}

	bool isWhiteSheep(const int r,const int c){
		if (marked[r + 1][c] == '.') {
			if (marked[r][c + 1] == '#' && marked[r+1][c-1] == '#') {

			}
			else if (marked[r][c + 1] == '.') {

			}
		}
	}

public:

	SheepFinder(image const& img, const int rows, const int columns) : R(rows), C(columns), marked(R, std::vector<bool>(C, false)), sheeps(0), whiteSheeps(0) {
		for (int r = 0; r < R; ++r){
			for (int c = 0; c < C; ++c) {
				if (img[r][c] == '#' && !marked[r][c]) {
					dfs(img, r, c);
					++sheeps;
					if (isWhiteSheep(r,c))
						++whiteSheeps;
				}
			}
		}
	}
	
	int getWhiteSheeps() const{
		return whiteSheeps;
	}
};


#endif
