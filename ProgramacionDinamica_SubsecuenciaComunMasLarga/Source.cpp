// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


const int findLongestCommonSubsequence(const std::string & word1, const std::string & word2) {
	std::vector<std::vector<int>> M(word1.size() + 1, std::vector<int>(word2.size()+1, 0));

	for (int i = 1; i <= word1.size(); ++i) {
		for (int j = 1; j <= word2.size(); ++j) {
			if (word1[i - 1] != word2[j - 1])
				M[i][j] = std::max(M[i - 1][j], M[i][j - 1]);
			else
				M[i][j] = M[i - 1][j - 1] + 1;
		}
	}

	return M[word1.size()][word2.size()];
}


bool resuelveCaso() {
	std::string word1,word2;
	std::cin >> word1 >> word2;
	if (!std::cin)
		return false;

	std::cout << findLongestCommonSubsequence(word1, word2) << '\n';


	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}