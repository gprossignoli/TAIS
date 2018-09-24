#ifndef AVL_ext_h
#define AVL_ext_h

#include <vector>
#include "TreeMap_AVL.h"

template <class Clave,class Valor,class Comparador = std::less<Clave>>
class AVLtree_ext : public map<Clave, Valor, Comparador> {
	using clave_valor = typename map<map_t>::clave_valor;
	using map_t = typename map<Clave, Valor, Comparador>::map_t;
	using Link = typename map<map_t>::Link;
	using raiz = typename map<map_t>::raiz;
	using menor = typename map<map_t>::menor;

protected:
	void generateOut(Clave const& k1, Clave const& k2, std::vector<Clave> & v,Link const& c) {
	
	}
public:

	AVLtree_ext() : map<map_t>() {}

	std::vector<Clave> findKeysInRange(Clave const& k1, Clave const& k2) {
		std::vector<Clave> out;
		generateOut(k1, k2, out,raiz);
		return out;
	}

	bool insert(clave_valor const& cv) {
		map<map_t>::insert(cv);
	}
};

#endif
