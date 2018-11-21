// Gerardo Parra Rossignoli
// TAIS20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

/*el coste de la funcion es N log (N) para ordenar el vector y N para recorrerlo despues, 
siendo N el numero de pilas que forman el vector, por tanto el coste es N + N log(N)
*/
int resolver(std::vector<int> & batteries,const int V) {
	std::sort(batteries.begin(), batteries.end());
	int b1 = 0;
	int b2 = batteries.size() - 1;
	int cars = 0;
	
	while (b1 < b2) {
		if (batteries[b1] + batteries[b2] < V)
			b1++;
		else {
			b1++;
			b2--;
			cars++;
		}
	}
	
	return cars;
}


void resuelveCaso() {
	int N, neededVoltage;
	std::cin >> N >> neededVoltage;

	std::vector<int> batteries(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> batteries[i];
	}

	std::cout << resolver(batteries,neededVoltage) << '\n';
	


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