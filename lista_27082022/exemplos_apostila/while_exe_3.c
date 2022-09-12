#include<stdio.h>


int main(){

    int num = 0;

    printf("Sequência dos números pares até 50. \n");
    printf("\n");
    printf("\n");

    while (num<=50)
        {
            printf("%d\n", num);
            num = num + 2;
        }

    printf("\n");
    printf("\n");
    printf("Sequência dos números ímpares até 50. \n");
    printf("\n");
    printf("\n");

    num = 1;

    while (num <= 50)
        {
            
            printf("%d\n", num);
            num = num + 2;
        }
        
    printf("\n");

    return 0;
}