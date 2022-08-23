#include<stdio.h>



float num_a, num_b, num_c;


int main(){

    // Este programa lê três números fornecidos pelo usuário e informa
    // qual deles é o menor
    
    printf("Escreva três números reais e diferentes. \n");
    scanf("%f""%f""%f",&num_a, &num_b, &num_c);

    if ((num_a < num_b) && (num_a < num_c))
    {
        printf("O número %.2f é o menor número digitado. \n", num_a);
        printf("\n");

    } else if ((num_b < num_a) && (num_b < num_c))
    {
        printf("O número %.2f é o menor número digitado. \n", num_b);
        printf("\n");
    } else
    {
        printf("O número %.2f é o menor número digitado. \n", num_c);
        printf("\n");
    }
    
    return 0;
    
}