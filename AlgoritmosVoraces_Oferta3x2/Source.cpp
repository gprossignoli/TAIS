// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

//coste (N/3) + N*log(N) donde N es el numero de libros
int obtenerDescuentoMax(std::vector<int> & libros) {
	std::sort(libros.begin(), libros.end(), std::less<int>());

	
	int descuento = 0;
	int menor = libros.size() - 3;

	while (menor >= 0) {
		descuento += libros[menor];
		menor -= 3;
	}

	return descuento;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int L;
	std::cin >> L;
	if (!std::cin)
		return false;

	std::vector<int> libros(L);
	for (int & l : libros) {
		std::cin >> l;
	}
	int descuento = 0;
	
	if(L > 2)
	descuento = obtenerDescuentoMax(libros);

	std::cout << descuento << '\n';
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