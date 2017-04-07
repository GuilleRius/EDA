#include<iostream>

using namespace std;


const int N = 6;

int main() {

	int v[N] = {6,2,5,9,1,2};
	int sum = 0, result = 0;

	for (int i = N-1; i > 0; i--) {

		sum += v[i];
		result += sum * v[i - 1];
	}

	cout << result << endl;

	system("PAUSE");
	return 0;
}

// pre: 0<=n<= longuitud(v)
// pos: sum i: 0<= i < n-1 : paraTodo j 0<= i < j < n: v[i]*v[j]
