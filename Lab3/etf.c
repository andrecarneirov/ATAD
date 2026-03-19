#include "etf.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


ETF etfCreate(const char ticker[], const char isin[], const char name[], double ter,
    const char distribution[], const char replication[], int fundSize, double var2024) {

    ETF etf = {};
    strncpy(etf.ticker, ticker, 4);              etf.ticker[4] = '\0';
    strncpy(etf.isin, isin, 12);                 etf.isin[12] = '\0';
    strncpy(etf.name, name, 80);                 etf.name[80] = '\0';
    etf.ter = ter;
    strncpy(etf.distribution, distribution, 20); etf.distribution[20] = '\0';
    strncpy(etf.replication, replication, 20);   etf.replication[20] = '\0';
    etf.fundSize = fundSize;
    etf.var2024 = var2024;
    return etf;
}

void etfPrint(ETF etf) {
    printf("%-5s %-13s %-45s %.2f %-15s %-20s %-8d %.2f\n",
        etf.ticker, etf.isin, etf.name, etf.ter,
        etf.distribution, etf.replication, etf.fundSize, etf.var2024);
}

void etfPrintTable(ETF arr[], int arrLength) {
    if(arrLength <= 0) {
        printf("(Empty ETF data)\n");
        return;
    }
   
    for(int i=0; i < arrLength; i++) {
        etfPrint(arr[i]);
    }
    
    printf("---\n");
    printf("Total ETF count: %d \n\n", arrLength);
}

int etfImport(const char* filename, ETF arr[], int arrLength) {
    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        perror(filename);
        return -1; // documented error value
    }
    
    int count = 0;
    char line[1024];
    
    // Read and ignore header
    fgets(line, 1024, file);
    
    // Iterate over each line
    while (fgets(line, 1024, file))
    {
        if(count >= arrLength) break; // no more space

        char* tmp = strdup(line);
        
        char** tokens = splitString(tmp, 8, ";");
        
        // 'tokens' is an array[8] of strings, each position containing
        // a column from the CSV file

        double ter = atof(tokens[3]);
        int size = atoi(tokens[6]);
        double var2024 = atof(tokens[7]);

        arr[count++] = etfCreate(tokens[0], tokens[1], tokens[2], ter,
            tokens[4], tokens[5], size, var2024);

	    free(tokens);
        free(tmp);
    }

    fclose(file);

    return count;
}

int etfSearchByTicker(const char ticker[], ETF arr[], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        if (strcmp(arr[i].ticker, ticker) == 0) return i;
    }
    return -1;
}

int etfSelectBest(ETF arr[], int arrLength) {
    if (arrLength <= 0) return -1;
    int best = 0;
    for (int i = 1; i < arrLength; i++) {
        if (arr[i].var2024 > arr[best].var2024) best = i;
    }
    return best;
}

void etfSortByPerformance(ETF arr[], int arrLength) {
    for (int i = 0; i < arrLength - 1; i++) {
        for (int j = i + 1; j < arrLength; j++) {
            if (arr[j].var2024 > arr[i].var2024) {
                ETF temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void etfSortByTicker(ETF arr[], int arrLength) {
    for (int i = 0; i < arrLength - 1; i++) {
        for (int j = i + 1; j < arrLength; j++) {
            if (strcmp(arr[j].ticker, arr[i].ticker) < 0) {
                ETF temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}