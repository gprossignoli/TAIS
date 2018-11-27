// Gerardo Parra Rossignoli
// TAIS 20


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>


using Activity = struct {
	int ini, end;
};

bool leastToGreatest(Activity const& a, Activity const& b) {
	return a.ini < b.ini;
}

// el coste de ordenar es N log(N) y el de recorrer el vector en el peor caso es N^2 por tanto el coste total es N^2
int resolver(std::vector<Activity> & schedule) {
	//N log(N)
	std::sort(schedule.begin(), schedule.end(), leastToGreatest);
	//so many persons as activities would be necessary in the worst case
	std::vector<std::pair<bool,Activity>> persons(schedule.size()); 

	for (int i = 0; i < schedule.size(); ++i) {
		bool personAvailable = false;
		int p = 0;
		while (!personAvailable) {
			if (persons[p].first && persons[p].second.end <= schedule[i].ini) { 
				//the person is available at this time
				persons[p].first = false;
			}

			if(!persons[p].first){
				persons[p].first = true;
				persons[p].second.ini = schedule[i].ini;
				persons[p].second.end = schedule[i].end;
				personAvailable = true;
			}
			
			++p;
		}
	}

	int friendsNeeded = 0;
	int i = 0;
	while (i < persons.size() && persons[i].first) {
		++friendsNeeded;
		++i;
	}	

	return --friendsNeeded; //persons include me
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int activities;
	std::cin >> activities;
	if (activities == 0)
		return false;

	std::vector<Activity> schedule;
	for (int i = 0; i < activities; ++i) {
		int ini, end;
		std::cin >> ini >> end;
		schedule.push_back({ini,end});
	}

	std::cout << resolver(schedule) << '\n';

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