#include<iostream>

using namespace std;

const int N = 6;

// pre : 0<= n < long(v) && ParaTodo i : 0<= i < n : v[i] = 0 v v[i] = 1 
bool resuelve(int v[]) {

	bool ok = true;
	bool cambio = false;

	for (int i = 0; i < N; i++) {

		if (i == 0 && v[i] == 0) cambio = true;

		if (v[i] == 0 && i > 0 && v[i - 1] == 1) cambio = true;

		if (cambio && v[i] == 1) ok = false;
	}
	return ok;
}
// pos: b = (Existe c : 0<=c<n: (ParaTodo i: 0<=i<c: v[i]=1 && ParaTodo j: c< j < n: v[j] = 0))


int main() {

	int v[N] = { 1,1,0,0,0,0 };

	cout << resuelve(v) << endl;

	system("pause");
	return 0;
}