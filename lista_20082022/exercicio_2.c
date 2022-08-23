#include<stdio.h>

float temp_informada;

int main(){

    // Este programa informa ao usuário se o tempo esta "Frio", "Agradável", "Quente"
    // ou "Muito Quente" com base na temperatura informda pela usuário

    printf("Informe a temperatura em °C. \n");
    scanf("%f", &temp_informada);

    if (temp_informada <= 20)
    {
        printf("O clima esta FRIO !. \n");
        printf("\n");

    } else if (temp_informada > 40)
    {
        printf("O clima esta MUITO QUENTE !. \n");
        printf("\n");

    } else if (temp_informada > 30)
    {
        printf("O clima esta QUENTE !. \n");
        printf("\n");

    } else if (temp_informada > 20)
    {
        printf("O clima esta AGRADÁVEL !. \n");
        printf("\n");

    } return 0;
}

