// Gerardo Parra Rossignoli
//TAIS 20

#ifndef AVLtree_ext_h
#define AVLtree_ext_h

#include <vector>
#include "TreeMap_AVL.h"

template <class Clave, class Valor, class Comparador = std::less<Clave>>
class map_ext : map<Clave,Valor,Comparador> {
	using raiz = map<Clave, Valor, Comparador>::raiz;
protected:
	
	void findKeyInRank(Clave const& r, Clave const& k1, Clave const& k2, std::vector<int>& v) {
		if (r.raiz->cv.clave != nullptr) {
			if (menor(r.raiz->cv.clave, k1)) {
				findKeyInRank(r.raiz->dr, k1, k2, v);
			}

			else if (k1 == r.raiz->cv.clave) {
				v.push_back(r.raiz->cv.clave);
				findKeyInRank(r.raiz->dr, k1, k2, v);
			}
			else if (menor(k1, r.raiz->cv.clave)) {
				if (menor(r.raiz->cv.clave, k2)) {
					v.push_back(r.raiz->cv.clave, v);
					findKeyInRank(r.raiz->dr, k1, k2, v);
				}
				else
					findKeyInRank(r.raiz->iz, k1, k2, v);
			}
		}
	}
public:
	map_ext(Comparador c = Comparador()) : raiz(nullptr), nelems(0), menor(c) {}
	

	std::vector<int> findKeysInRank(Clave const& k1,Clave const& k2) {
		std::vector<int> out;
		findKeyInRank(raiz->cv.clave, k1, k2, out);
		return out;
	}

	void operator[](Clave const& c) {
		map<Clave,Valor,Comparador>::corchete(c, raiz);
	}

};

#endif