/*
*   Programa: CASAMENTO DE CADEIAS DE CARACTERES
*   Autor: Roniel Nunes Barbosa e Victor Hugo Santos
*   Matéria: Projeto e Análise de Algoritmos
*   Professor: Daniel Mendes Barbosa
*/

#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <windows.h> //remover

#define MAXTAMTEXTO 5000
#define MAXTAMPADRAO 30
//#define MAXCHAR 256

typedef char TipoTexto[MAXTAMTEXTO];
typedef char TipoPadrao[MAXTAMPADRAO];

//void ShiftAndExato(TipoTexto T, long n, TipoPadrao P, long m);
void ForcaBruta(TipoTexto T, long n, TipoPadrao P, long m);

#endif