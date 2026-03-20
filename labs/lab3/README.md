## Lab 3 - Linguagem C | Tipos compostos, pesquisa, seleção e ordenação


> [!IMPORTANT]
> Este laboratório deverá ser executado com base neste repositório inicial de código, através de `git clone` (ou *download de zip*).
> - O repositório foi criado a partir de [`CProgram_Template`](https://github.com/estsetubal-atad/CProgram_Template).
>  - Consulte o respetivo *README* para compreender a estrutura do projeto e módulos incluídos.

🎯 **Objetivos**:

- Definição de tipos de dados compostos;

- Importação de dados;

- Pesquisa, seleção e ordenação sobre tipos de dados compostos;

- Produção de documentação *Doxygen*.

📖 **Referências**:

- *"Linguagem C"*, *e-book* disponível no Moodle.

- Slides das aulas TP (algoritmos de pesquisa, seleção e ordenação).

---

### Descrição do problema

O objetivo geral do laboratório será o de importar dados relativamente a *Exchange Traded Funds* (ETFs) - fundos de investimento negociados em bolsa que replicam a performance de um índice, setor, *commodity* ou outra classe de ativos, combinando diversificação com liquidez. Os ETFs oferecem aos investidores de longo-prazo exposição diversificada a um conjunto de ativos sem necessidade de os comprar individualmente.


No final do enunciado, será possível **pesquisar, selecionar e ordenar ETFs por critérios específicos**.

Os dados com que vamos trabalhar encontram-se no ficheiro `etfs.csv`, incluído neste projeto. 

> [!TIP]
> Abra o ficheiro `etfs.csv` e veja o seu conteúdo. Um ficheiro CSV (do inglês *Comma-Separated Values*) é um ficheiro de texto simples usado para armazenar dados em forma de tabela, onde cada linha representa um registo e cada valor é separado por um delimitador, neste caso um ponto e vírgula (`;`).


Cada linha descreve um ETF e as colunas representam a informação específica sobre esse ETF, nomeadamente:

- `Ticker`: Sigla do ETF (valor único);

- `ISIN`: (*International Securities Identification Number*) é um código único de 12 caracteres usado para identificar valores mobiliários, como ações, obrigações e ETFs, em nível global. 

- `Name`: Nome descritivo do ETF;

- `TER (%)`: (*Total Expense Ratio*) Representa o custo anual de gestão do fundo, expresso como uma percentagem dos ativos do fundo.

- `Distribution`: Indica se o ETF distribui dividendos aos investidores ("Distributing") ou se os reinveste no fundo ("Accumulating").

- `Replication`: Especifica o método utilizado pelo ETF para replicar o desempenho do seu índice de referência, como "Full replication" (detendo os ativos) ou "Swap based" (utilizando derivados).

- `Fund size (in m €)`: Representa o total de ativos líquidos sob gestão do ETF, expresso em milhões de EUR.

- `2024 (+/- %)`: Indica a variação de valorização do ETF durante o ano de 2024.


#### Tipo composto `ETF`

No módulo `etf` encontra definido o tipo composto `ETF` que irá permitir guardar informação de um ETF individual:

```cpp
typedef struct etf
{
    char ticker[4 + 1];
    char isin[12 + 1];
    char name[255 + 1];
    double ter;
    char distribution[50 + 1];
    char replication[50 + 1];
    int fundSize;
    double var2024;
} ETF;
```

Neste módulo iremos incluir todas as funções relativas ao manuseamento de ETFs.

### 1 | Importação e visualização de informação

1. Implemente a função `etfPrint`, já declarada e documentada no *header file*, por forma a imprimir na consola a informação de um ETF numa única linha, e.g.:

	```console
	SXR8  IE00B5BMR087 iShares Core S&P 500 UCITS ETF USD (Acc)    0.07 Accumulating    Full replication   104545 32.62
	```

	- Compile e execute o programa, verificando que é mostrada informação do ETF declarado no `main`.

2. Implemente a função `etfCreate`, já declarada e comentada no *header file*. O propósito desta função é o de servir de inicializador de variáveis do tipo `ETF`.

	- Teste esta função, substituindo a declaração existente no `main` pela que utiliza este inicializador. Compile e execute o programa; não deverá haver alterações no *output*, relativamente à execução anterior.

3. Descomente o bloco de código presente no `main`, responsável por importar e imprimir todos os ETFs contidos no ficheiro `etfs.csv`.

	- Compile e execute o programa, verificando que é impressa uma listagem dos 50 ETFs importados.

	- Ajuste a sua função `etfPrint` por forma à informação ser impressa de forma "tabulada", onde os campos ocupam uma largura fixa. Pesquise de que forma a função `printf` permite imprimir uma *string* com uma largura fixa.

> [!TIP]
> Note que a função `etfCreate` é utilizada dentro da função `etfImport` para criar as instâncias relativas à informação de cada linha do ficheiro.

### 2 | Pesquisa e seleção

4. Declare, documente e implemente a função:

	```cpp
	int etfSearchByTicker(const char ticker[], ETF arr[], int arrLength);
	```

	que pesquisa em `arr` um ETF com o `ticker` recebido por parâmetro, devolvendo o índice onde foi encontrado; devolve `-1` caso não exista.

	- Teste esta função no programa principal com um ETF **solicitado ao utilizador**, e.g., "H4ZJ". 
		- Obtenha um índice através da invocação da função de pesquisa;
		- Se o índice for válido, imprima o ETF no índice respetivo; caso contrário, imprima "(ETF não encontrado)".

5. Declare, documente e implemente a função:

	```cpp
	int etfSelectBest(ETF arr[], int arrLength);
	```

	que seleciona em `arr` o ETF com a melhor/maior variação em 2024, devolvendo o índice onde foi encontrado; devolve `-1` caso não exista (neste caso só faz sentido se o array for vazio).

	- Teste esta função no programa principal, mostrando o ETF que obteve a melhor *performance* no ano 2024. 
		- O resultado esperado é o ETF copm o *ticker* `QDVE` com `45.92%`.

### 3 | Ordenação de informação

6. Declare, documente e implemente a função:

	```cpp
	void etfSortByPerformance(ETF arr[], int arrLength);
	```

	que ordena **descrescentemente** os ETF em `arr` pela *performance* no ano 2024 (do melhor para o pior).

	- Teste esta função no programa principal, invocando a função e imprimindo novamente o array já ordenado.
	- Verifique visualmente que a informação ordenada se manteve consistente, i.e., que não houve alteração dos dados relativos a cada ETF. Isto pode acontecer se não fizer as trocas corretamente durante o processo de ordenação.

7. Declare, documente e implemente a função:

	```cpp
	void etfSortByTicker(ETF arr[], int arrLength);
	```

	que ordena os ETF em `arr` pelo seu *ticker* (de A a Z).

	- Teste esta função no programa principal, invocando a função e imprimindo novamente o array já ordenado.

---

<bruno.silva@estsetubal.ips.pt>





