#include <iostream>

using namespace std;

typedef struct {
	int ci;
	int fi;
}tCitas;

bool esValida(tCitas v[], bool sol[], int k) {

	int i = k-1;

	while (i != 0 && sol[i] == false) i--;
	
	return v[k].ci >= v[i].fi;
}

void tratarSolucion(int n, tCitas v[], bool sol[]) {

	for (int i = 0; i < n; i++) {
		if (sol[i])
			cout << v[i].ci << " " << v[i].fi << endl;
	}	
	cout << " -------------- " << endl;
}

void agendaCitas(int n, tCitas v[], int r, bool sol[], int k, int &cont) {

	if (k == n) return;

	sol[k] = true;
	cont++;

	if (k == 0 || esValida(v, sol, k)) {
		
		if (k == n-1 && cont >= r)
			tratarSolucion(n, v, sol);
		
		else {
			agendaCitas(n, v, r, sol, k + 1, cont);
		}
	}

	sol[k] = false;
	cont--;

	if (k == n - 1 && cont >= r)
		tratarSolucion(n, v, sol);

	else {
		agendaCitas(n, v, r, sol, k + 1, cont);
	}
}




int main() {

	const int n = 6;
	tCitas v[n] = { {1,3}, {3,5 }, {4,7}, {5,7}, {6,7},{7,9} };
	int r = 3; 
	int k = 0;
	int cont = 0;
	bool sol[n] = { false, false, false, false, false, false };

	agendaCitas(n, v, r, sol, k, cont);

	system("pause");
	return 0;
}