#include<stdio.h>
#define ano_atual 2022

int ano_nascimento;

int main(){

    // Este programa le o ano de nascimento do usuário e informa se ele
    // vai poder votar este ano

    printf("Informe o ano do seu nascimento no formato YYYY: \n");
    scanf("%d", &ano_nascimento);

    if ((ano_atual - ano_nascimento) >= 16)
    {
        printf("Você possui %d  anos e já pode votar !.", ano_atual - ano_nascimento);
        printf("\n");
    } else 
    {
        printf("Você não pode votar, ainda faltam %d anos para você ser elegível. \n", 16 - (ano_atual - ano_nascimento ));
        printf("\n");
    }

    return 0;
    
}