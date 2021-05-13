/*
*   Programa: CASAMENTO DE CADEIAS DE CARACTERES
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "./Headers/auxiliares.h"

//gcc -o exec main.c ./Sources/algoritmos.c ./Sources/auxiliares.c
//mingw32-make exec

int main(int argc, char **argv)
{
    TipoTexto texto;
    TipoPadrao padrao;

    int escolhaMenu, k;

    clock_t tempo;

    leituraArquivo(texto);
    printf("Digite o nome do padrao: ");
    scanf("%s", padrao);

    do
    {

        escolhaMenu = menu();
        switch (escolhaMenu)
        {

        case 1:

            puts("Execucao Forca Bruta:");

            tempo = clock();
            ForcaBruta(texto, strlen(texto), padrao, strlen(padrao));

            tempo = clock() - tempo;

            if (MODO_DEBUG)
                printf("Tempo de execucao: %lf\n", ((double)tempo) / ((CLOCKS_PER_SEC / 1000)));

            system("pause");
            break;

        case 2:

            puts("Execucao Shift-And Exato:");

            tempo = clock();
            ShiftAndExato(texto, strlen(texto), padrao, strlen(padrao));

            tempo = clock() - tempo;

            if (MODO_DEBUG)
                printf("Tempo de execucao: %lf\n", ((double)tempo) / ((CLOCKS_PER_SEC / 1000)));

            system("pause");
            break;

        case 3:

            puts("Execucao Shift-And Aproximado:");
            printf("Digite a Distancia de Edicao (valor de k): ");
            scanf("%d", &k);

            tempo = clock();
            ShiftAndAproximado(texto, strlen(texto), padrao, strlen(padrao), k);

            tempo = clock() - tempo;

            if (MODO_DEBUG)
                printf("Tempo de execucao: %lf\n", ((double)tempo) / ((CLOCKS_PER_SEC / 1000)));

            system("pause");
            break;

        case 0:
            puts("Obrigado por utilizar!");
            system("pause");
            break;

        default:
            puts("Valor invalido! Poderia inserir outro?!");
            system("pause");
            break;
        }

        system("clear");
    } while (escolhaMenu != 0);

    return 0;
}