#include<iostream>

using namespace std;

/*	Se dispone de una lista de n productos alimenticios entre los que se quiere escoger
	algunos para seguir una dieta adecuada.Para cada producto i(0  i < n) se conoce su precio
	pi  0, su contenido en proteinas qi  0 y su cantidad de calorías ci  0. Se desea seleccionar
	algunos de estos productos(a lo sumo uno de cada) de forma que el precio total no supere un
	presupuesto M, el contenido proteico total sea al menos de Q y el valor calórico sea lo menor
	posible.Diseñar un algoritmo de vuelta atrás para encontrar la selección óptima, es decir, la
	que minimiza la cantidad de calorías.Se valorarán las podas realizadas.
*/

void dieta(int n, int k,int p[], int q[], int c[], int M, int Q, bool sol[], int &qActual, int &cActual, int &ptotal, bool SolucionMejor[], int & cMejor) {

	if (k == n)
		return;
	//hijo Izq

	sol[k] = true;
	qActual += q[k];
	cActual += c[k];
	ptotal += p[k];

	// SOLUCION PARCIAL ES VALIDA
	if (ptotal <= M) {

		// ES POSIBLE SOLUCION
		if (qActual >= Q) {

			if (cActual < cMejor || cMejor == -1) {

				cMejor = cActual;
				for (int i = 0; i < n; i++) {
					SolucionMejor[i] = sol[i];
				}
			}
		}
		else 

			dieta(n, k + 1, p, q, c, M, Q, sol, qActual, cActual, ptotal, SolucionMejor, cMejor);

	}

	// hijo Der

	sol[k] = false;
	qActual -= q[k];
	cActual -= c[k];
	ptotal -= p[k];

	if (ptotal <= M) {

		// ES POSIBLE SOLUCION
		if (qActual >= Q) {

			if (cActual < cMejor || cMejor == -1) {

				cMejor = cActual;
				for (int i = 0; i < n; i++) {
					SolucionMejor[i] = sol[i];
				}
			}
		}
		
		else
			dieta(n, k + 1, p, q, c, M, Q, sol, qActual, cActual, ptotal, SolucionMejor, cMejor);
	}
}


int main() {

	int p[] = { 3, 3, 2, 2, 2 };
	int q[] = { 10, 10, 10, 10, 5 };
	int c[] = { 10, 10, 10, 10, 5 };
	int M = 5;
	int Q = 15;
	bool sol[] = { false, false, false, false, false };
	bool SolucionMejor[] = { false, false, false, false, false };
	int qActual = 0, cActual = 0, ptotal = 0, cMejor = -1;
	int k = 0;

	dieta(5, k, p, q, c, M, Q, sol, qActual, cActual, ptotal, SolucionMejor, cMejor);

	for (int i = 0; i < 5; i++) {

		if (SolucionMejor[i] == true)
			cout << i << endl;
	}

	system("PAUSE");
	return 0;
}