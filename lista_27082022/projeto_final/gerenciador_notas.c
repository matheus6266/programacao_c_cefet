#include<stdio.h>

char nomes_alunos[5][20];
float notas_alunos[15];


void cadastro_nome_notas_alunos(){

    int indice_alunos = 1;

    for (int i = 1; i <= 5; i++)
    {
        printf("Escreva o nome do %d° aluno. \n", i);
        scanf("%s", &nomes_alunos[i]);


        for (int x = 1; x <= 3; x++)
        {

        printf("Informe a %d° nota do aluno %s. \n",x, nomes_alunos[i]);
        scanf("%f", &notas_alunos[indice_alunos]);
        indice_alunos = indice_alunos + 1;

        }

    }
}

float calculo_media(){

    float soma_notas_acumuladas, media_tuma, acumulado_notas_aluno;
    float media_individual[5];
    int indice_auxiliar_aluno = 1;

    // Cálculo média geral da turma

    for (int i = 1; i <= 15; i++)
    {
        soma_notas_acumuladas = soma_notas_acumuladas + notas_alunos[i];
    }

    // Cálculo média individual

    for (int i = 1; i <= 5; i++)
    {
        acumulado_notas_aluno = 0;

        for (int x = 1; x <= 3; x++)
        {
            acumulado_notas_aluno = acumulado_notas_aluno + notas_alunos[indice_auxiliar_aluno];
            indice_auxiliar_aluno = indice_auxiliar_aluno + 1;
        }
        
        media_individual[i] = acumulado_notas_aluno / 3;
    }
    
    return media_individual[2];

}

// Parei no item C
    
int main(){

    cadastro_nome_notas_alunos();

    printf("%f",calculo_media());

    return 0;
}