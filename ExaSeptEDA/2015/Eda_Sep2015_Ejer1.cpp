#include<iostream>

using namespace std;


int Jacobsthal(int n) {

	int ant = 1, ant2 = 0, actual=0;

	for (int i = 0; i < n; i++) {

		actual = ant + 2 * ant2;
		ant2 = ant;
		ant = actual;
	}

	return actual; 
}



int main() {

	int n = 10;

	cout << Jacobsthal(n) << endl;

	system("PAUSE");
	return 0;
}