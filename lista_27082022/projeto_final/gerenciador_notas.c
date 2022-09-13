#include<stdio.h>

char nomes_alunos[5][20];
float notas_alunos[15];
float media_individual[5];


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

void calculo_media(){

    float soma_notas_acumuladas, media_tuma, acumulado_notas_aluno;
    int indice_auxiliar_aluno = 1;
    int indice_auxiliar_menor, indice_auxiliar_maior;
    float menor_nota_media = 999; // Variável para realizar a comparação das notas
    float maior_nota_media = 0; // Variável para realizar a comparação das notas

    // Cálculo média geral da turma

    printf("-------------------------------------------\n");

    for (int i = 1; i <= 15; i++)
    {
        soma_notas_acumuladas = soma_notas_acumuladas + notas_alunos[i];
    }

    printf("A média geral das notas da turma foi: %.2f.\n", (soma_notas_acumuladas / 15));
    printf("-------------------------------------------\n");

    // Cálculo média individual

    for (int i = 1; i <= 5; i++)
    {
        acumulado_notas_aluno = 0;

        for (int x = 1; x <= 3; x++)
        {
            acumulado_notas_aluno = acumulado_notas_aluno + notas_alunos[indice_auxiliar_aluno];
            indice_auxiliar_aluno = indice_auxiliar_aluno + 1;
        }
        
        media_individual[i] = (acumulado_notas_aluno / 3);
        printf("A médida das notas do aluno %s foi: %.2f.\n", nomes_alunos[i], media_individual[i]);
        

    }

    printf("-------------------------------------------\n");

    // Verificação das maiores e menores médias

    indice_auxiliar_aluno = 1;

    for (int i = 1; i <= 5; i++)
    {
        if (media_individual[i] > maior_nota_media)
        {
            maior_nota_media = media_individual[i];
            indice_auxiliar_maior = i;

        } 
        if (media_individual[i] < menor_nota_media)
        {
            menor_nota_media = media_individual[i];
            indice_auxiliar_menor = i;
        }        
        
    }

    printf("A maior média foi do aluno %s com o valor de %.2f.\n", nomes_alunos[indice_auxiliar_maior], maior_nota_media);
    printf("A menor média foi do aluno %s com o valor de %.2f.\n", nomes_alunos[indice_auxiliar_menor], menor_nota_media);
    
}

void calculo_recuperacao(){

    char alunos_aprovados[5][20];
    char aluno_reprovados[5][20];

    printf("-------------------------------------------\n");

    

}

    
int main(){

    cadastro_nome_notas_alunos();
    calculo_media();

    return 0;
}