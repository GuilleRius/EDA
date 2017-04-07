//SEPTIEMBRE 2016
typedef struct{
	float valor;
	float peso;
}objeto;
//desnivel = 0,05
void mercader(vector<obj> const &v, float p1, float p2, vector<int>&sol, float valor, int k, float pesoIz, float pesoDr,
			vetor<int>&solMejo, float &mejorValor ){
			//suponemos izquierda
			sol[k]=1;
			valor+=v[k].valor;
			pesoIz+=v[k].peso;
			if(pesoIz <= p1){//es valida
				if(k==sol.size()-1){//es solucion
					if(abs(pesoIz-pesoDr) <= (pesoIz+pesoDr)*desnivel){//solucion valida
						if(valor >mejorValor) {
							solmejor=sol;
							mejorValor=valor;
						}
					}
					
				}else{
					if(estimacion() > mejorValor) mercader(.k+1..);
				}
			}
			//suponemos derecha
			sol[k]=2;
			//valor+=v[k].valor;//el valor no cambia
			pesoIz-=v[k].peso
			pesoDr+=v[k].peso;
			if(pesoDr <= p2){//es valida
				if(k==sol.size()-1){//es solucion
					if(abs(pesoIz-pesoDr) <= (pesoIz+pesoDr)*desnivel){//solucion valida
						if(valor >mejorValor) {
							solmejor=sol;
							mejorValor=valor;
						}
					}
					
				}else{
					if(estimacion() > mejorValor) mercader(..k+1..);
				}
			}
			//suponemos que no lo ponemos
			sol[k]=3;
			valor-=v[k].valor;
			pesoDr-=v[k].peso;
			//siempre es valida
			if(k==sol.size()-1){//es solucion
				if(abs(pesoIz-pesoDr) <= (pesoIz+pesoDr)*desnivel){//solucion valida
					if(valor >mejorValor) {
						solmejor=sol;
						mejorValor=valor;
					}
				}
					
			}else{
				if(estimacion() > mejorValor) mercader(..k+1..);//Hay que estimar seguro.
			}			
}
//La estimacion en el caso 1 no es necesaria 



