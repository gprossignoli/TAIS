// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>

#include "bintree_eda.h"

using tINodeInfo = struct 
{
	int minR;
	int maxL;
	int height;
	bool isAVL;
};

// función que resuelve el problema
tINodeInfo resolver(bintree<int> const& t) {
	tINodeInfo info;

	if (t.left().empty() && t.right().empty()) {
		info.isAVL = true;
		info.height = 1;
		info.maxL = t.root();
		info.minR = t.root();
		return info;
	}

	else {
		tINodeInfo left, right;
		if (!t.left().empty()) {
			if (t.left().root() < t.root()) {
				left = resolver(t.left());
				info.isAVL = left.isAVL && left.minR < t.root() && left.maxL < t.root();

				if (left.maxL < t.root())
					info.maxL = t.root();
				else
					info.maxL = left.maxL;
			}
			else
				info.isAVL = false;
		}
		else {
			info.maxL = t.root();
			left.height = 0;
			info.isAVL = true;
		}

		if (info.isAVL) {
			if (!t.right().empty()) {
				if (t.right().root() > t.root()) {
					right = resolver(t.right());
					info.isAVL = right.isAVL && right.minR > t.root() && right.maxL > t.root();

					if (right.minR > t.root())
						info.minR = t.root();
					else
						info.minR = right.minR;
				}
				else
					info.isAVL = false;
			}
			else {
				info.minR = t.root();
				right.height = 0;
			}
		}
		
		if (info.isAVL)
			info.isAVL = !(std::abs(left.height - right.height) > 1);
		info.height = std::max(left.height, right.height) + 1;

		return info;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int> tree;
	tree = leerArbol(-1);

	if (!tree.empty()) {

		tINodeInfo sol = resolver(tree);

		if (sol.isAVL)
			std::cout << "SI\n";
		else
			std::cout << "NO\n";
	}
	else
		std::cout << "SI\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}