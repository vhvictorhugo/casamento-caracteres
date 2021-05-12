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
    int marcaPosicao = 0;
    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivoEntrada);

    strcat(nomeArquivo, nomeArquivoEntrada);
    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo.\n");
        exit(0);
    }
    strcmp(texto, " ");

    while (!feof(arquivo))
    {
        fscanf(arquivo, "%s", palavra);
        //[0][1][2][' '][]
        for (int i = 0; i < strlen(palavra); i++)
        {
            texto[marcaPosicao + i] = palavra[i];
        }
        marcaPosicao += strlen(palavra);
        if (!feof(arquivo))
        {
            texto[marcaPosicao] = ' ';
            marcaPosicao++;
        }
    }

    fclose(arquivo);

    return;
}

void linha()
{
    for (int i = 0; i < 40; i++)
        printf("=");
    puts("");
}

int menu()
{
    int escolha;

    puts("Escolha uma das opcoes abaixo:");
    linha();
    puts("1 - Forca Bruta\n2 - Shift-And Exato\n3 - Shift-And Aproximado\n0 - Finalizar o Programa\n");
    linha();
    printf("Sua escolha: ");
    scanf("%d", &escolha);

    return escolha;
}