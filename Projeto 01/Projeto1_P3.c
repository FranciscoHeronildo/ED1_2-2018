#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char A, char B, char C);

int main(){

    int n;

    printf("Digite a quantidade de discos posicionados na Torre A: ");
    scanf("%d", &n);

    hanoi(n, 'A', 'B', 'C');

    return 0;
}


void hanoi(int n, char A, char B, char C){

    //Lógica mais simples um unico disco n move de A para C
    if(n == 1){
        printf("Mover disco %d da Torre %c para %c\n", n, A, C);
    } else {

        //Move o disco n-1 de A para B usando C como auxiliar
        hanoi(n - 1, A, C, B);

        //Move os discso restantes
        printf("Mover disco %d da Torre %c para %c\n", n, A, C);

        //Move o disco n-1 de B para C usando A como auxiliar
        hanoi(n - 1, B, A, C);
    }
}
