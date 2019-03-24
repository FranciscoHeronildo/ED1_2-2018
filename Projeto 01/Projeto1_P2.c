#include<stdio.h>
#include<stdlib.h>

#define MAX 10


void recebe_notas(float *NOTAS, int num_ele_vector, int *APR);
void conta_notas (int *APR, int num_ele_vector, int *num_aprovados, int *num_reprovados);
int percent_aprov(int num_aprovados, int num_reprovados, float *percentagem_reprovados, float *percentagem_aprovados);

int main(){

    float NOTAS[MAX], percentagem_aprovados, percentagem_reprovados;
    int APR[MAX], aprovados, reprovados, percent;

    //Vetor NOTAS de 10 posicoes
    printf("Por Favor, digite as 10 Notas correspondentes :\n");
	for(int i = 0; i < MAX; i++){
        scanf("%f", NOTAS + i);
        }

    //Funcao void recebe_notas
    recebe_notas(NOTAS, MAX, APR);

    //Funcao void conta_notas
    conta_notas(APR, MAX, &aprovados, &reprovados);

    //Funcao int percent_aprov que retorna para maioria
    percent = percent_aprov(aprovados, reprovados, &percentagem_reprovados, &percentagem_aprovados);

    printf("\n -Quantidade de aprovados: %d \n", aprovados);
    printf("-Quantidade de reprovados: %d \n", reprovados);

    printf("-Percentual de aprovados: %.f%% \n", percentagem_aprovados);
    printf("-Percentual de reprovados: %.f%% \n", percentagem_reprovados);

    //Verifica se a maioria da turma foi aprovada
    if(percent == 1){
        printf("\n Mais da metade da turma foi aprovada \n");
    } else {
        printf("\n Mais da metade da turma foi reprovada \n");
    }
    return 0;
}

//Recebe as notas e preenche o vetor APR com 1 e 0 para aprovados e reprovados
void recebe_notas(float *NOTAS, int num_ele_vector, int *APR){

	//Preenche o vetor APR com 1 ou 0 de acordo com a aprovacao do aluno
	for(int i = 0; i < num_ele_vector; i++){
		if(*(NOTAS + i) >= 6.0){
            *(APR + i) = 1;
        }else{
            *(APR + i) = 0;
		}
	}
}

//Conta quantos aprovados tem no vetor APR e atribui aos ponteiros de aprovados e reprovados
void conta_notas (int *APR, int num_ele_vector, int *num_aprovados, int *num_reprovados){

    int contar = 0;

    //Verifica se o aluno foi aprovado e incrementa o contador
    for(int i = 0; i < num_ele_vector; i++){
        if(*(APR + i) == 1){
        contar++;
        }
    }

    ////Calcula o numero de aprovados
    *num_aprovados = contar;

    //Calcula o numero de reprovados
    *num_reprovados = num_ele_vector - contar;
}

//Calcula a percentagem de aprovados e reprovados
int percent_aprov(int num_aprovados, int num_reprovados, float *percentagem_reprovados, float *percentagem_aprovados){

    float percent_reprovados;
    float percent_aprovados;

    //Calcula a percentagem de alunos aprovados e reprovados
    percent_reprovados = num_reprovados * MAX;
    percent_aprovados = num_aprovados * MAX;


    //Percentagem aos ponteiros
    *percentagem_reprovados = percent_reprovados;
    *percentagem_aprovados = percent_aprovados;


    //Verifica se mais da metade da turma foi aprovada
    if(percent_aprovados > percent_reprovados){
        return 1;
    } else {
        return 0;
    }
}
