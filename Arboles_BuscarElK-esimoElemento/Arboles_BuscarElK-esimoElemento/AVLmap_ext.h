#ifndef AVLmap_ext_h
#define AVLmap_ext_h

#include "TreeMap_AVL.h"

template <class Clave,class Valor, class Comparador = std::less<Clave>>
class map_ext : map<Clave, Valor, Comparador> {
	using super = typename map<Clave, Valor, Comparador>::map_t;
	using Link = typename super::Link;
	using clave_valor = typename super::clave_valor;
protected:
	struct TreeNode;
	using Link = TreeNode * ;
	struct TreeNode {
		clave_valor cv;
		Link iz, dr;
		int altura;
		int tam_i;
		TreeNode(clave_valor const& e, Link i = nullptr, Link d = nullptr,
			int alt = 1,int t_i = 1) : cv(e), iz(i), dr(d), altura(alt),tam_i(t_i) {}
	};
public:
	map_ext() : super() {}



};

#endif