#include<iostream>
#include <stdlib.h>

using namespace std;


/*Consideremos una matriz, M, de numeros reales de dimensiones N N.Supongamos
que esta matriz nos sirve para cartograar cierto terreno que se ha dividido en forma de
cuadrcula, de forma que M[i][j] es la altura media de la casilla(i; j).
Se desea construir una carretera entre dos puntos dados.Para que una carretera pueda unir
dos casillas adyacentes(no en diagonal) es necesario que la diferencia entre sus alturas medias
no supere cierto valor, hmax, es decir :
|M[a][b] - M[c][d] j<= hmax|
donde las casillas(a; b) y(c; d) son adyacentes.
Dada una matriz M, una altura maxima hmax y dos casillas del terreno distintas entre s, dise~na
un algoritmo de vuelta atras que calcule la carretera de menor longitud(si es que existe) que
resuelva el problema.Se considera que la longitud de la carretera es el numero de casillas por
las que pasa, incluyendo tanto el origen como el destino.
Por ejemplo, si la matriz M de alturas es la siguiente y hmax = 2:

0 3 4
1 2 3
1 1 1


la carretera de menor longitud para ir desde la casilla(0; 1) hasta la(0; 0) es de longitud 4 y
pasa por las casillas(0; 1), (1; 1), (1; 0), (0; 0).Hay otras carreteras validas pero no optimas,
como por ejemplo la que recorre las casillas(0; 1), (1; 1), (2; 1), (2; 0), (1; 0), (0; 0), que es de
longitud 6. Una carretera no valida sera la que va directamente de(0; 1) a(0; 0) al contener
una diferencia de alturas entre casillas adyacentes superior al maximo permitido.

*/

typedef struct casilla {

	int x;
	int y;
}tCasilla;

const int N = 3;

bool esValido(int M[N][N], int hMax, tCasilla aux, bool marcas[N][N], tCasilla &posActual) {

	return aux.x >= 0 && aux.x < N && aux.y >= 0 && aux.y < N && !marcas[aux.x][aux.y] && abs(M[aux.x][aux.y] - M[posActual.x][posActual.y] <= hMax);
}

void muevete(tCasilla posActual, int dir, tCasilla &aux) {

	switch (dir) {

	case 0: aux.y++; break;
	case 1: aux.x++; break;
	case 2: aux.y--; break;
	case 3: aux.x--; break;

	}
}


void carretera(int M[N][N], int hMax, tCasilla destino, tCasilla sol[], tCasilla solMejor[], int pasosActual, int &pasosMejor, bool marcas[N][N], int k) {

	for (int i = 0; i < 4; i++) {

		tCasilla aux;
		aux = sol[k-1];
		muevete(sol[k-1], i, aux);

		if (esValido(M, hMax, aux, marcas, sol[k-1])) {

			pasosActual++;
			sol[k] = aux;
			marcas[aux.x][aux.y] = true;

			// si llegamos a destino
			if (sol[k].x == destino.x && sol[k].y == destino.y) {
				i = 4;
				if (pasosActual < pasosMejor || pasosMejor == -1) {

					pasosMejor = pasosActual;
					for (int i = 0; i < N*N; i++)
						solMejor[i] = sol[i];
				}
			}
			// si nos hemos podido mover pero no llegamos a destino
			else {
				carretera(M, hMax, destino, sol, solMejor, pasosActual, pasosMejor, marcas, k + 1);
			}
			marcas[sol[k].x][sol[k].y] = false;
		}
	}
}





int main() {

	int M[N][N] = { { 0, 3, 4 },{ 1, 2, 3 },{ 1, 1, 1 } };
	int hMax = 2;
	tCasilla posActual;
	posActual.x = 0;
	posActual.y = 1;
	tCasilla destino;
	destino.x = 0;
	destino.y = 0;
	tCasilla sol[N*N];
	sol[0] = posActual;
	tCasilla solMejor[N*N];
	int pasosActual = 0;
	int pasosMejor = -1;
	bool marcas[N][N];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			marcas[i][j] = false;

	marcas[0][1] = true;
	int k = 1;

	carretera(M, hMax, destino, sol, solMejor, pasosActual, pasosMejor, marcas, k);

	for (int i = 0; i < pasosMejor; i++) {

		cout << solMejor[i].x << "  " << solMejor[i].y << endl;
	}

	cout << pasosMejor << endl;
	system("PAUSE");
	return 0;
}