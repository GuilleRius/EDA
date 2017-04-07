#include<iostream>

using namespace std;


void Caucasico(int v[], bool &caucasico, int ini, int fin, int &pares) {

	if (!caucasico) return;

	if (fin - ini == 1) {

		if (v[ini] % 2 == 0) pares++;
		if (v[fin] % 2 == 0) pares++;
		return;
	}

	int mitad = ((fin - ini) / 2) + ini;
	int paresIzq = 0, paresDer = 0;

	Caucasico(v, caucasico, ini, mitad, paresIzq);
	Caucasico(v, caucasico, mitad+1, fin, paresDer);

	if (abs(paresIzq - paresDer) > 2) caucasico = false;
	else pares = paresIzq + paresDer;
}


int main() {

	int v[16] = {2,4,8,12,3,7,9,21,10,20,30,1,3,5,7,40};
	bool caucasico = true;
	int ini = 0, fin = 15, pares = 0;

	Caucasico(v, caucasico, ini, fin, pares);

	if (caucasico) cout << "caucasico" << endl;
	else cout << "no caucasico" << endl;

	system("PAUSE");
	return 0;
}