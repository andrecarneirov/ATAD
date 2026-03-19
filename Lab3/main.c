#include <stdio.h> 
#include <stdlib.h>
#include "input.h"
#include "etf.h"

#define MAX_ARRAY_SIZE 100

int main() {

    /* Exercício 1 e 2 - Criar e imprimir um único ETF */
    ETF etf = etfCreate("SXR8", "IE00B5BMR087", "iShares Core S&P 500 UCITS ETF USD (Acc)",
                        0.07, "Accumulating", "Full replication", 104545, 32.62);
    etfPrint(etf);

    /* Exercício 3 - Importar e imprimir todos os ETFs do ficheiro CSV */
    ETF etfs[MAX_ARRAY_SIZE];
    int etfsLength = etfImport("etfs.csv", etfs, MAX_ARRAY_SIZE);
    etfPrintTable(etfs, etfsLength);

    /* Exercício 4 - Pesquisar um ETF por ticker (introduzido pelo utilizador) */
    char ticker[5];
    printf("Search ETF by ticker: ");
    readString(ticker, sizeof(ticker));
    int idx = etfSearchByTicker(ticker, etfs, etfsLength);
    if (idx >= 0) etfPrint(etfs[idx]);
    else printf("(ETF nao encontrado)\n");

    /* Exercício 5 - Selecionar o ETF com melhor desempenho em 2024 */
    int best = etfSelectBest(etfs, etfsLength);
    printf("Best ETF in 2024:\n");
    etfPrint(etfs[best]);

    /* Exercício 6 - Ordenar ETFs por desempenho em 2024 (decrescente) */
    etfSortByPerformance(etfs, etfsLength);
    printf("Sorted by performance (descending):\n");
    etfPrintTable(etfs, etfsLength);

    /* Exercício 7 - Ordenar ETFs por ticker (A-Z) */
    etfSortByTicker(etfs, etfsLength);
    printf("Sorted by ticker (A-Z):\n");
    etfPrintTable(etfs, etfsLength);

    return EXIT_SUCCESS;
}