// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>

#include "bintree_eda.h"

// función que resuelve el problema
int resolver(bintree<int> const& t,bool & isAVL,const int root) {

	if (t.left().empty() && t.right().empty())
		return 1;

	else if(isAVL) {
		int left = 0;
		int right = 0;

		if (!t.left().empty()) {
			if (t.left().root() < t.root()) {
				if (t.root() > root) {
					isAVL = t.left().root() < root;
				}
				if(isAVL)
					left += resolver(t.left(), isAVL,root);
			}
			else 
				isAVL = false;
		}
		

		if (!t.right().empty()) {
			if (t.right().root() > t.root()) {
				if (t.root() < root)
					isAVL = t.right().root() < root;
				if(isAVL)
					right += resolver(t.right(), isAVL,root);
			}
			else
				isAVL = false;
		}

		if (isAVL)
			isAVL = std::abs(left - right) <= 1;

		return std::max(left, right) + 1;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int> tree;
	tree = leerArbol(-1);

	if (!tree.empty()) {
		int maxLeft = 0;
		int minRight = 2147483647;
		bool isAVL = true;
		resolver(tree, isAVL,tree.root());

		if (isAVL)
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