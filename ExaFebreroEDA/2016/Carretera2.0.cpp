#include<iostream>

using namespace std;

const int N = 3;

typedef struct casilla {

	int x;
	int y;

}tCasilla;

bool esValido(tCasilla destino, int M[N][N], int hMax, int k, tCasilla sol[], bool marcas[N][N]) {

	return !marcas[destino.x][destino.y] && abs(M[sol[k - 1].x][sol[k - 1].y] - M[destino.x][destino.y]) <= hMax && destino.x >= 0 && destino.x < N && destino.y >= 0 && destino.y < N;
}

void muevete(int i, tCasilla &destino) {

	switch (i) {

	case 0: destino.y++; break;
	case 1: destino.x++; break;
	case 2: destino.y--; break;
	case 3: destino.x--; break;
	}
}



void resuelve(int M[N][N], int hMax, tCasilla fin, int k, tCasilla sol[], int pasos, bool marcas[N][N], int prof, bool &exito) {

	if (exito) return;

	for (int i = 0; i < 4; i++) {

		tCasilla destino = sol[k - 1];
		muevete(i, destino);

		if (esValido(destino, M, hMax, k, sol, marcas)) {

			sol[k] = destino;
			marcas[destino.x][destino.y] = true;

			if (destino.x == fin.x && destino.y == fin.y) {
				exito = true;
				return;
			}

			else if (pasos < prof) resuelve(M, hMax, fin, k + 1, sol, pasos+1, marcas, prof, exito);

			marcas[destino.x][destino.y] = false;			
		}
	}
}





int main() {

	int M[N][N] = { { 0, 3, 4 },{ 1, 8, 3 },{ 1, 1, 1 } };
	int hMax =2;
	tCasilla fin, ini;
	ini.x = 0, ini.y = 1, fin.x = 0, fin.y = 0;
	int k = 1;
	tCasilla sol[N*N];
	sol[0] = ini;
	int pasos = 1;
	int prof = 1;
	bool exito = false;
	
	bool marcas[N][N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			marcas[i][j] = false;

	marcas[0][1] = true;

	while (!exito && prof < N*N) {
		resuelve(M, hMax, fin, k, sol, pasos, marcas, prof, exito);
		prof++;
	}

	for (int j = 0; j < prof; j++) cout << sol[j].x << " " <<  sol[j].y << endl;
		

	system("pause");
	return 0;
}