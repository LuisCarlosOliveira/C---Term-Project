
/** 
 * @file:   input.h
 * @author: Luis Oliveira <https://github.com/LuisCarlosOliveira>
 * @date 29 de dezembro de 2021, 18:45
 * IMPORTANTE: grande parte do código aqui presente foi disponiblidade na UC de FP pelo Prof. Oscar Oliveira
 * @brief Ficheiro c para operações de leitura
 */

#include "Input.h"
#include <stdio.h>
#include <string.h>


#define VALOR_INVALIDO "O valor inserido é inválido."
#define NOME_INVALIDO "O nome é inválido"

/**
 * Limpar o Buffer do teclado
 */
void cleanInputBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

/**
 * Função para obter tipo integer
 * @return retorna o valor tipo integer inserido pelo utilizador ou mensagem de erro
 */
int obterInt(int minValor, int maxValor, char *msg) {
    int valor;
    printf(msg);
    while (scanf("%d", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(VALOR_INVALIDO);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return valor;
}

/**
 * Função para obter tipo float
 * @return retorna o valor float inserido pelo utilizador ou mensagem de erro
 */
float obterFloat(float minValor, float maxValor, char *msg) {
    float valor;
    printf(msg);
    while (scanf("%f", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(VALOR_INVALIDO);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return valor;
}

/**
 * Função para obter tipo double
 * @return retorna o valor double inserido pelo utilizador ou mensagem de erro
 */
double obterDouble(double minValor, double maxValor, char *msg) {
    double valor;
    printf(msg);
    while (scanf("%lf", &valor) != 1 || valor < minValor || valor > maxValor) {
        puts(VALOR_INVALIDO);
        cleanInputBuffer();
        printf(msg);
    }
    cleanInputBuffer();
    return valor;
}

/**
 * Função para obter tipo character
 * @return retorna o valor character inserido pelo utilizador ou mensagem de erro
 */
char obterChar(char *msg) {
    char valor;
    printf(msg);
    valor = getchar();
    cleanInputBuffer();
    return valor;
}

/**
 * Procedimento para ler da consola uma string
 */

void lerString(char *string, unsigned int tamanho, char *msg) {
    printf(msg);
    if (fgets(string, tamanho, stdin) != NULL) {
        unsigned int len = strlen(string) - 1;
        if (string[len] == '\n') {
            string[len] = '\0';
        } else {
            cleanInputBuffer();
        }
    }
}


// @Luís Oliveira
/**
 * Procedimento para imprimir linha
 */
void imprimeLinha(int n){
    for( int i = 0; i < n; i++){
        printf("-");
    }
    puts(" ");
}

/**
 * Caso exista, obtêm o número de linhas do ficheiro
 * @param filename nome do ficheiro
 * @return o número de linhas do ficheiro
 */
int nrLinhasFicheiro(char *filename){
    char ch;
    FILE *file;
    file = fopen(filename, "r");
    int linhas = 0;
    
    if (file != NULL) {
         for (ch = getc(file); ch != EOF; ch = getc(file)) 
        if (ch == '\n')  
            linhas = linhas + 1; 
    }
 
    fclose(file);
   
    return linhas - 1;
}

