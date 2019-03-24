#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int fneuronio(double *entradas, double *pesos, double limiarT, int numMaxEnt);

int main(){

    double entradas[MAX], pesos[MAX], limiarT;

    printf("Digite 10 valores reais de ENTRADAS: \n");
    for(int i = 0; i < MAX; i++) {
        scanf(" %lf", entradas + i);
    }

    printf("Digite 10 valores reais de PESOS: \n");
    for(int i = 0; i < MAX; i++) {
        scanf(" %lf", pesos + i);
    }

    printf("Digite o valor do limiar T: \n");
    scanf(" %lf", &limiarT);

    //Chama a funcao
    int estado = fneuronio(entradas, pesos, limiarT, MAX);

    //Verifica o valor de retorno
    if(estado == 1) {
        printf("Neurônio ativado! \n");
    } else {
        printf("Neurônio inibido \n");
    }

    return 0;
}

int fneuronio(double *entradas, double *pesos, double limiarT, int numMaxEnt){


    double somap = 0;

    //Somatorio SOMAP para a analize do Neuronio
    for(int i = 0; i < numMaxEnt; i++) {
        somap = *(entradas + i) * *(pesos + i) + somap;
    }

    //Compara e  faz o retorno da funcao
    if(somap > limiarT) {
        return 1;
    } else {
        return 0;
    }
}
