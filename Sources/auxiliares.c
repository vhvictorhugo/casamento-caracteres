/*
*   Programa: CASAMENTO DE CADEIAS DE CARACTERES
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "../Headers/auxiliares.h"
#include "../Headers/algoritmos.h"

void leituraArquivo(TipoTexto T)
{
    FILE *arquivo = NULL;
    char nomeArquivoEntrada[30], nomeArquivo[30] = "./arquivos/";

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivoEntrada);

    strcat(nomeArquivo, nomeArquivoEntrada);
    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo.\n");
        return;
    }

    while (!feof(arquivo))
    {
        fscanf(arquivo, "%s", T);
    }

    for (int i = 0; i < MAXTAMTEXTO; i++)
    {
        printf("%c ", T[i]);
    }

    fclose(arquivo);

    return;
}