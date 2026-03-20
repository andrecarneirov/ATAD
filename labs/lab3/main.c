#include <stdio.h> 
#include <stdlib.h>
#include "input.h"
#include "etf.h"

#define MAX_ARRAY_SIZE 100

int main() {
    ETF etfs[MAX_ARRAY_SIZE];
    int etfsLength = etfImport("etfs.csv", etfs, MAX_ARRAY_SIZE);
    int option;

    do {
        printf("\n======== MENU ========\n");
        printf("1. Criar e imprimir um único ETF\n");
        printf("2. Importar e imprimir todos os ETFs\n");
        printf("3. Pesquisar um ETF por ticker\n");
        printf("4. Selecionar o ETF com melhor desempenho em 2024\n");
        printf("5. Ordenar ETFs por desempenho em 2024\n");
        printf("6. Ordenar ETFs por ticker\n");
        printf("7. Sair\n");
        printf("\nChoose an option:\n");
        scanf("%d", &option);

        switch(option) {
            case 1: {
                /* Exercício 1 e 2 - Criar e imprimir um único ETF */
                ETF etf = etfCreate("SXR8", "IE00B5BMR087", "iShares Core S&P 500 UCITS ETF USD (Acc)",
                                    0.07, "Accumulating", "Full replication", 104545, 32.62);
                etfPrint(etf);
                break;
            }
            case 2: {
                /* Exercício 3 - Importar e imprimir todos os ETFs do ficheiro CSV */
                etfPrintTable(etfs, etfsLength);
                break;
            }
            case 3: {
                /* Exercício 4 - Pesquisar um ETF por ticker */
                char ticker[5];
                printf("\nSearch ETF by ticker: ");
                while (getchar() != '\n');  // flush leftover newline from scanf
                readString(ticker, sizeof(ticker));
                int idx = etfSearchByTicker(ticker, etfs, etfsLength);
                if (idx >= 0) {
                    etfPrint(etfs[idx]);
                } else {
                    printf("(ETF nao encontrado)\n");
                }
                break;
            }
            case 4: {
                /* Exercício 5 - Selecionar o ETF com melhor desempenho em 2024 */
                int best = etfSelectBest(etfs, etfsLength);
                printf("\nBest ETF in 2024:\n");
                etfPrint(etfs[best]);
                break;
            }
            case 5: {
                /* Exercício 6 - Ordenar ETFs por desempenho em 2024 (decrescente) */
                etfSortByPerformance(etfs, etfsLength);
                printf("\nSorted by performance (descending):\n");
                etfPrintTable(etfs, etfsLength);
                break;
            }
            case 6: {
                /* Exercício 7 - Ordenar ETFs por ticker (A-Z) */
                etfSortByTicker(etfs, etfsLength);
                printf("\nSorted by ticker (A-Z):\n");
                etfPrintTable(etfs, etfsLength);
                break;
            }
            case 7: {
                printf("\nExiting...\n");
                break;
            }
            default:
                printf("\nInvalid option.\n");
        }
    } while (option != 7);

    return EXIT_SUCCESS;
}