// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>

#include "bintree_eda.h"

using tNodeInfo = struct 
{
	int min;
	int max;
	int height;
	bool isAVL;
};

// función que resuelve el problema
tNodeInfo resolver(bintree<int> const& t) {
	tNodeInfo info;

	if (t.empty()) {
		info.height = 0;
		info.isAVL = true;
	}

	else {
		tNodeInfo left, right;
		left = resolver(t.left());
		right = resolver(t.right());
		info.isAVL = left.isAVL && right.isAVL && (t.left().empty() || left.max < t.root()) && (t.right().empty() || right.min > t.root()) && std::abs(left.height - right.height) <= 1;
		if (info.isAVL) {
			if (!t.left().empty())
				info.min = left.min;
			else
				info.min = t.root();
			if (!t.right().empty())
				info.max = right.max;
			else
				info.max = t.root();
			info.height = std::max(left.height, right.height) + 1;
		}
	}
	return info;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int> tree;
	tree = leerArbol(-1);

	if (!tree.empty()) {

		tNodeInfo sol = resolver(tree);

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