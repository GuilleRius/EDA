#include<iostream>
using namespace std;


// pre 0 < n < long(v)
int resuelve(int v[], int n){

	int cont = 1; 
	int min = v[0];

	for (int i = 1; i < n; i++) {

		if (v[i] == min) cont++;

		else if (v[i] < min) {

			min = v[i];
			cont = 1;
		}
	}

	return cont;
}
// pos: #x: 0 <= x < n : ParaTodo z: 0 <= z < n: v[x] < = v[z] 

// INV: pre 0 <= w < n &&  #x: w <= x < n : ParaTodo z: w <= z < n: v[x] < = v[z] 


int main() {

	const int n = 1; 
	int v[n] = { 2 };

	cout << resuelve(v, n) << endl; 

	system("Pause");
	return 0;
}