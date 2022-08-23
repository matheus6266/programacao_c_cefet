#include<stdio.h>


float num_a, num_b;

int main(){

    // Este programa le dois valores reais diferentes e informa qual
    // deles é o maior

    printf("Escreva dois números reais diferentes: \n");
    scanf("%f" "%f", &num_a, &num_b);

    if (num_a > num_b)
    {
        printf("O número %.2f é maior que %.2f. \n", num_a, num_b);
        printf("\n");
    } else

    {
        printf("O número %.2f é maior que o número %.2f. \n", num_b, num_a);
        printf("\n");
    }
    
    return 0;
    
}