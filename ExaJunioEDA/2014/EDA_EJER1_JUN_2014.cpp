#include<iostream>

using namespace std;


const int n = 6;
const int m = 2;
const int maxProd = 3;

bool esValido(int contProd[m], int i) {

	return contProd[i] <= maxProd;
}

void copiaSol(int solActual[n], int solMejor[n]) {

	for (int i = 0; i < n; i++) solMejor[i] = solActual[i];
}

void compra(int p[n][m], int solActual[n], int solMejor[n], int  &costeActual, int &costeMejor, int k, int contProd[m]) {

	if (k == n) return;

	for (int i = 0; i < m; i++) {

		solActual[k] = i;
		costeActual += p[k][i];
		contProd[i]++;

		if (esValido(contProd, i)) {

			if (k == n - 1 && (costeActual < costeMejor || costeMejor == -1)) {
				copiaSol(solActual, solMejor);
				costeMejor = costeActual;
			}

			else 
				compra(p, solActual, solMejor, costeActual, costeMejor, k + 1, contProd);
		}

		costeActual -= p[k][i];
		contProd[i]--;
		
	}
}





int main() {

	int p[n][m] = { {3,500}, {3,500}, {3,500}, {3,5}, {100,5}, {0,5} }; 
	int solActual[n];
	int solMejor[n];
	int costeActual = 0;
	int costeMejor = -1;
	int k = 0;
	int contProd[m] = { 0 , 0 };

	compra(p, solActual, solMejor, costeActual, costeMejor, k, contProd);

	for (int i = 0; i < n; i++) cout << solMejor[i] << " ";
	cout << endl;

	system("PAUSE");
	return 0;
}