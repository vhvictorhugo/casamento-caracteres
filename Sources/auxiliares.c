/*
*   Programa: CASAMENTO DE CADEIAS DE CARACTERES
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#include "../Headers/auxiliares.h"

void leituraArquivo(TipoTexto texto)
{
    FILE *arquivo = NULL;
    char nomeArquivoEntrada[30], nomeArquivo[30] = "./arquivos/";
    char palavra[30];

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivoEntrada);
    printf("nome do arquivo lido: %s\n",nomeArquivoEntrada);

    strcat(nomeArquivo, nomeArquivoEntrada);
    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo.\n");
        return;
    }

    while (!feof(arquivo))
    {
        fscanf(arquivo,"%s", palavra);

        strcat(texto,palavra);
        strcat(texto," ");
    }

    printf("%s ",texto);

    fclose(arquivo);

    return;
}