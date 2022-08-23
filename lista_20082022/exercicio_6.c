#include<stdio.h>
#define senha_valida 1234

int senha_digitada;

int main(){

    // Este programa verifica a valida de uma senha fornecida pelo usuário
    
    printf("Informe a senha númerica de 4 digitos: **** \n");
    scanf("%d", &senha_digitada);

    if (senha_digitada == senha_valida)
    {
        printf("Acesso PERMITIDO. \n");
        printf("\n");
    } else 
    {
        printf("Acesso NEGADO. \n");
        printf("\n");
    }
    
    return 0;
    
}