/*
*   Programa: CASAMENTO DE CADEIAS DE CARACTERES
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
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

void ShiftAndAproximado(TipoTexto T, long n, TipoPadrao P, long m, long k)
{
    long Masc[MAXCHAR], i, j, Ri, Rant, Rnovo;
    long R[NUMMAXERROS + 1];

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
            Rnovo = ((((unsigned long)R[j]) >> 1) & Masc[T[i] + 127]) | Rant | (((unsigned long)(Rant | Rnovo)) >> 1);
            Rant = R[j];
            R[j] = Rnovo | Ri;
        }

        if ((Rnovo & 1) != 0)
            printf("Casamento aproximado na posicao %12ld\n", i + 1);
    }
}