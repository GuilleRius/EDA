#include<iostream>

using namespace std;


int perdido(int v[], int ini, int fin, int d) {

	int mitad = (ini + fin) / 2;

	if (v[mitad] == (mitad + 1)*d) return perdido(v, mitad + 1, fin, d);

	else {

		if ((v[mitad - 1] == (mitad)*d)) return (mitad + 1)*d;
		else return perdido(v, ini, mitad, d);
	}
}


int main() {

	int v[] = { 2,4,6,8,12,14 };
	int ini = 0,  fin = 5,  d = 2;

	cout << perdido(v, ini, fin , d) << endl;

	system("pause");
	return 0;
}