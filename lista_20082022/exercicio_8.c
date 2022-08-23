#include<stdio.h>

float altura_informada;
int sexo_informado;


int main(){

    // Este programa calcula o peso ideal do usuario baseado em seu sexo 
    // e sua altura
    
    printf("Informe a sua altura em m: \n");
    scanf("%f", &altura_informada);

    printf("Informe o seu sexo: \n");
    printf("1: Feminino\n""2: Masculino\n");
    scanf("%d", &sexo_informado);

    if (sexo_informado == 1)
    {
        printf("O seu peso ideal é %.2f kg. \n", (62.1*altura_informada) - 44.7);
        printf("\n");
    } else 
    {
        printf("O seu peso ideal é %.2f kg. \n", (72.7*altura_informada) - 5);
        printf("\n");
    }
    
    return 0;
}