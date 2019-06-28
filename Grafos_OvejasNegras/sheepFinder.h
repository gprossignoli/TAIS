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

	std::vector<std::pair<int,int>> dirs = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
	bool validPos(int i, int j) const {
		return 0 <= i && i < R && 0 <= j && j < C;
	}

	void dfs(image const& img, int r, int c) {
		marked[r][c] = true;
		for (auto d : dirs) {
			int nr = r + d.first, nc = c + d.second;
			if (validPos(nr, nc) && img[nr][nc] == '.' && !marked[nr][nc]) {
				dfs(img, nr, nc);
			}
		}
	}

public:

	SheepFinder(image const& img, const int rows, const int columns) : R(rows), C(columns), marked(R, std::vector<bool>(C, false)), whiteSheeps(0) {
		for (int r = 1; r < R - 1; ++r){
			for (int c = 1; c < C - 1; ++c) {
				if (img[r][c] == '.' && !marked[r][c]) {
					dfs(img, r, c);
					++whiteSheeps;
				}
			}
		}
	}
	
	int getWhiteSheeps() const{
		return whiteSheeps-1;
	}
};


#endif
