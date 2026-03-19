#include <stdio.h> 
#include <stdlib.h>
#include "input.h"
#include "etf.h"

#define MAX_ARRAY_SIZE 100

int main() {

    ETF etf = etfCreate("SXR8", "IE00B5BMR087", "iShares Core S&P 500 UCITS ETF USD (Acc)",
                        0.07, "Accumulating", "Full replication", 104545, 32.62);
    etfPrint(etf);

    ETF etfs[MAX_ARRAY_SIZE];
    int etfsLength = etfImport("etfs.csv", etfs, MAX_ARRAY_SIZE);
    etfPrintTable(etfs, etfsLength);

    return EXIT_SUCCESS;
}
