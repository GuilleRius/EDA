#include<iostream>

using namespace std;


bool contenido(int v[], int w[], int n, int m) {

	bool ok = true;
	int i = 0, j = 0;

	while (i < n && j < m && ok) {

		if (w[j] == v[i]) {	j++; i++;}
		else if (w[j] > v[i]) i++;
		else ok = false;
	}

	if (i == n && j < m) ok = false;


	return ok;
}


int main() {

	int v[] = { 0,1,2,3,8,10 };
	int w[] = { 2,3,8,10 };
	int n = 6, m = 4;
	bool ok;

	ok = contenido(v, w, n, m);

	if (ok) cout << "contenido" << endl;
	else cout << "no contenido" << endl;

	system("PAUSE");
	return 0;
}