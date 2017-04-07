#include<iostream>

using namespace std; 

const int n = 5;
const int m = 6; 

// pre: 0 <= N <= M && ord(v, n) && ord(v, m)
//   con ord(a, n) ::= ParaTodo i, j : 0<=i<j<n : v[i] < v[j]

bool resuelve(int A[], int B[]) {

	int j = 0;
	int i = 0;
	bool ok = true;
	
	while(i < n && j < m && ok ){

		if (A[i] == B[j]) {
			i++;
			j++;
		}

		else if (A[i] > B[j]) j++;

		else ok = false;
	}

	if (i < n) ok = false;

	return ok; 
}

 // post b = ParaTodo x: 0 <= x < N : Exista z: x <= z < M : A[x] == B[z]

// INV: 0 <= n < N && N <= M && b = ParaTodo x: 0 <= x < N : Exista z: x <= z < M : A[x] == B[z]

int main() {

	int A[n] = {1,2,4,5,7};
	int B[m] = { 1,2,3,4,5,6 };

	if (resuelve(A, B)) cout << "correcto" << endl; 
	else  cout << "no correcto " << endl; 

	system("PAUSE");
	return 0; 
}