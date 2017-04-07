/*Un comerciante del desierto dispone de un camello para transportar sus mercancías.
El camello tiene dos alforjas cuya capacidad en peso, p1 y p2, son conocidas.El
comerciante quiere cargar el camello de tal forma que se maximice el valor de los objetos transportados,
teniendo en cuenta que los objetos no se pueden fraccionar.Sean vi y wi(ambos
positivos) el valor y el peso del objeto i respectivamente(0  i < n).Para poder viajar el
camello debe ir equilibrado, por lo que se exigirá que la diferencia de pesos entre las alforjas
no supere el 5 % del peso total.Implementar un algoritmo que le indique al comerciante cómo
cargar su camello.
*/

#include<iostream>

using namespace std;

const int p0 = 20; 
const int p1 = 20;

bool esValido(int p0Actual, int p1Actual) {

	return p0Actual <= p0 && p1Actual <= p1;
}

void transporta(int n, int v[], int w[], int p0Actual, int p1Actual, int sol[], int solMejor[], int &valorActual, int &MejorValor, int k) {

	if (k == n) return;
	
	for (int i = 0; i < 3; i++) {

		sol[k] = i;
		valorActual += v[k];

		if (i == 0) p0Actual += w[k]; // primera alforja
		else if(i==1)p1Actual += w[k]; // segunda alforja 
		// i == 2 no se coge ese objeto
		
		if (esValido(p0Actual, p1Actual)) {

			if (k == n - 1 && abs(p1Actual - p0Actual) <= 0.05 * (p1Actual + p0Actual)) {

				if (valorActual > MejorValor) {

					MejorValor = valorActual;
					for (int i = 0; i < n; i++) solMejor[i] = sol[i];
				}
			}
			// aqui hariamos un else if donde comprobariamos que el numero de objetos restantes por el valor del objeto actual más el valor actual sea mayor que el mejor valor. Sino es asi abandonamos esta rama y pasamos a la siguiente
			// else if( ((n-k) * v[k] + valorActual) > MejorValor) transporta(n, v, w, p0Actual, p1Actual, sol, solMejor, valorActual, MejorValor, k + 1); 
			else transporta(n, v, w, p0Actual, p1Actual, sol, solMejor, valorActual, MejorValor, k + 1);
		}

		valorActual -= v[k];

		if (i == 0) p0Actual -= w[k];
		else if (i == 1) p1Actual -= w[k];			
	}

}



int main() {

	const int n = 5;
	// para hacer una poda ordenamos los objetos por su valor con el algoritmo de quicksort nlog(n) 
	int v[] = {5, 4, 3 , 2, 1};
	int w[] = {20, 5, 5, 2, 2};
	int p0Actual = 0;
	int p1Actual = 0;
	int sol[n];
	int solMejor[n];
	int valorActual = 0;
	int MejorValor = 0;
	int k = 0;

	transporta(n, v, w, p0Actual, p1Actual, sol, solMejor, valorActual, MejorValor, k);

	for (int i = 0; i < n; i++) cout << solMejor[i] << " ";
	cout << endl << " Lo que suma un valor maximo de " << MejorValor << endl;

	system("pause");
	return 0;
}