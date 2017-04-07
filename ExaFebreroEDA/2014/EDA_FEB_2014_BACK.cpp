#include<iostream>

using namespace std;

/*Deseamos organizar un festival de rock al aire libre para lo cual vamos a contratar
	exactamente a N artistas de entre M disponibles(N < M).No todos los artistas aceptan
	tocar juntos en el festival.Los “vetos” entre artistas son conocidos de antemano.Para cada
	artista i 2 f1::Mg conocemos el beneficio o pérdida generado por dicho artista B[i], es decir
	si B[i] > 0, dicho artista genera beneficio mientras que si B[i] < 0 genera pérdida.Diseñar
	un algoritmo de vuelta atrás que resuelva el problema de planificar el festival que maximice la
	suma de los beneficios / pérdidas de los artistas participantes.*/


const int M = 5;

bool esValido(bool v[M][M], bool sol[], int k) {

	bool ok = true; 
	int i = 0;

	while(i < k && ok == true) {
		if (sol[i] && sol[k] && v[i][k]) ok = false;
		i++;
	}
	return ok;
}

void festival(int k, int n, bool v[M][M], int b[], bool sol[], bool solMejor[], int benfActual, int &benfMejor, int &cont) {

	if(k == M) return;

	sol[k] = true; 
	benfActual += b[k];
	cont++;

	if (esValido(v, sol, k)) {

		if (cont == n) {

			if (benfActual > benfMejor || benfMejor == -1) {

				for (int i = 0; i < M; i++) solMejor[i] = sol[i];
				benfMejor = benfActual;
			}
		}

		else festival(k+1, n, v, b, sol, solMejor, benfActual, benfMejor, cont);
	}

	sol[k] = false;
	benfActual -= b[k];
	cont--;

	//if (esValido(v, sol, k)) { NO HACE FALTA PORQUE SI HABIA SIDO VALIDO HASTA AHORA LO SEGUIRA SIENDO CUANDO QUITEMOS EL ULTIMO 
		if (cont == n) {

			if (benfActual > benfMejor || benfMejor == -1) {

				for (int i = 0; i < M; i++) solMejor[i] = sol[i];
				benfMejor = benfActual;
			}
		}

		else festival(k+1, n, v, b, sol, solMejor, benfActual, benfMejor, cont);
	//}
}



int main() {

	int k = 0;
	int n = 3;
	bool v[M][M] = { { false, false, false, false, false }, { false, false, false, false, false }, { false, false, false, false, false }, { false, false, false, false, false }, { false, false, false, false, false } };
	int b[M] = { 2, 3, 4, 5, 6 };
	bool sol[M] = { false, false, false, false, false };
	bool solMejor[M] = { false, false, false, false, false };
	int benfActual = 0;
	int benfMejor = -1;
	int cont = 0;

	festival(k, n, v, b, sol, solMejor, benfActual, benfMejor, cont);

	for (int i = 0; i < M; i++) 
		if (solMejor[i]) cout << i+1 << endl;

	cout << benfMejor << endl;

	system("Pause");
	return 0; 
}