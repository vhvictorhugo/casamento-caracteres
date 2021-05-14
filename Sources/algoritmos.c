/*
*   Programa: CASAMENTO DE CADEIAS DE CARACTERES
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa

Referências dos algoritmos de casamento de cadeias:

AUTOR: Professor Nivio Ziviani do DCC da UFMG
LINK: http://www2.dcc.ufmg.br/livros/algoritmos/cap8/codigo/c/8.1a8.6e8.8-pesquisacadeia.c
*/

#include "../Headers/algoritmos.h"

void ShiftAndExato(TipoTexto T, long n, TipoPadrao P, long m)
{
    int contCasamento = 0;

    long Masc[MAXCHAR], i, R = 0;

    for (i = 0; i < MAXCHAR; i++)
        Masc[i] = 0;

    for (i = 1; i <= m; i++)
        Masc[P[i - 1] + 127] |= 1 << (m - i);

    for (i = 0; i < n; i++)
    {
        R = ((((unsigned long)R) >> 1) |
             (1 << (m - 1))) &
            Masc[T[i] + 127];
        if ((R & 1) != 0)
        {
            //printf("Casamento na posicao %3ld\n", i - m + 2); // remover
            contCasamento++;
        }
    }

    if (!MODO_DEBUG)
        printf("Quantidade de casamentos: %d\n", contCasamento);
}

void ForcaBruta(TipoTexto T, long n, TipoPadrao P, long m)
{
    int contCasamento = 0;
    long i, j, k;

    for (i = 1; i <= (n - m + 1); i++)
    {
        k = i;
        j = 1;

        while (T[k - 1] == P[j - 1] && j <= m)
        {
            j++;
            k++;
        }

        if (j > m)
        {
            //printf("Casamento na posicao: %3ld\n", i); //remover
            contCasamento++;
        }
    }

    if (!MODO_DEBUG)
        printf("Quantidade de casamentos: %d\n", contCasamento);
}

void ShiftAndAproximado(TipoTexto T, long n, TipoPadrao P, long m, long k, int permissao)
{
    long Masc[MAXCHAR], i, j, Ri, Rant, Rnovo;
    long R[NUMMAXERROS + 1];
    if (permissao > 0 && permissao < 5)
    {
        for (i = 0; i < MAXCHAR; i++)
            Masc[i] = 0;

        for (i = 1; i <= m; i++)
        {
            Masc[P[i - 1] + 127] |= 1 << (m - i);
        }

        R[0] = 0;
        Ri = 1 << (m - 1);

        for (j = 1; j <= k; j++)
            R[j] = (1 << (m - j)) | R[j - 1];

        for (i = 0; i < n; i++)
        {
            Rant = R[0];
            Rnovo = ((((unsigned long)Rant) >> 1) | Ri) & Masc[T[i] + 127];
            R[0] = Rnovo;

            for (j = 1; j <= k; j++)
            {
                if (permissao == 1)
                {
                    Rnovo = ((((unsigned long)R[j]) >> 1) & Masc[T[i] + 127]) | Rant; //Somente inserção
                }
                else if (permissao == 2)
                {
                    Rnovo = ((((unsigned long)R[j]) >> 1) & Masc[T[i] + 127]) | (((unsigned long)Rant) >> 1); //Somente substituição
                }
                else if (permissao == 3)
                {
                    Rnovo = ((((unsigned long)R[j]) >> 1) & Masc[T[i] + 127]) | (((unsigned long)Rnovo) >> 1); //Somente retirada
                }
                else if (permissao == 4)
                {
                    Rnovo = ((((unsigned long)R[j]) >> 1) & Masc[T[i] + 127]) | Rant | (((unsigned long)(Rant | Rnovo)) >> 1); //Todas as operações permitidas
                }

                Rant = R[j]; //
                R[j] = Rnovo | Ri;
            }

            if ((Rnovo & 1) != 0)
                printf("Casamento aproximado na posicao %12ld\n", i + 1);
        }
    }
    else
    {
        printf("Operacao nao eh permitida.\n");
    }
}