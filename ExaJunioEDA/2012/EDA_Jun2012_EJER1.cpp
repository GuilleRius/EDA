#include<iostream>

using namespace std;

// pre 0< N <= long(v)
int longitud(int n, int v[]) {

	int logActual = 0;
	int logMejor = 0;
	int ultimo = 0; 

	for (int i = 0; i < n; i++) {

		if (v[i] >= ultimo) {
			logActual++;
			if (logActual > logMejor) logMejor = logActual;
		}

		else logActual = 0;

		ultimo = v[i];
	}

	return logMejor;
}
// pos b= #i : 0<=i<N : existe j: j = i+1: v[i] <= v[j] 

// Inv 0< n <= N ^ b= #i : n<=i<N : existe j: j = i+1: v[i] <= v[j] 

int main() {

	const int n = 6;
	int v[n] = { 6,5,4,3,2,1 };

	cout << longitud(n, v) << endl;

	system("Pause");
	return 0;
}