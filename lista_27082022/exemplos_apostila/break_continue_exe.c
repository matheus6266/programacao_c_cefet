#include<stdio.h>

float numero_informado;
float soma_acumulada = 0;



int main(){

    do
    {
        printf("Informe um número: \n");
        scanf("%f", &numero_informado);
        soma_acumulada = soma_acumulada + numero_informado;

        printf("O valor acumulado é: %f", soma_acumulada);
        printf("\n");


    } while (numero_informado != 0);
    
    printf("Fim do programa. \n");
    return 0;

}