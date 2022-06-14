
/**
 * @file:   necessidades.c
 * @author: Luis Oliveira <https://github.com/LuisCarlosOliveira>
 * @date 10 de fevereiro de 2022, 16:17
 * @brief Ficheiro c com função necessária para a leitura das necessidades da OP do ficheiro para a struct
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stock.h"
#include "Input.h"
#include "Necessidades.h"
#define MSG_ERRO_LER_FICHEIRO "Erro a abrir o ficheiro!"


/**
 * Lê dados de um ficheiro (caso exista) e preenche dados das necessidades
 * @param necessidades apontador para a estrutura Necessidades que terá valores das variaveis lidas do ficheiro
 * @param nomeFicheiro nome do ficheiro do qual as necessidades são carregadas
 */

void carregarNecessidades(Necessidades *necessidades, char *nomeFicheiro) {

    int i = 0, op, nrLinhasOP, materiaPrima,quantidade; 
    char stringAux[50]; //variavel "fake" para amazenar linhas desnecessarias
    
    necessidades->necessidadesCouro = 0;
    necessidades->necessidadesTecido = 0;
    necessidades->necessidadesBorracha = 0;
    necessidades->necessidadesCordoes = 0;
    necessidades->necessidadesPalmilhas = 0;
    
    FILE *fp = fopen(nomeFicheiro, "r");

    int numeroLinhas = nrLinhasFicheiro(nomeFicheiro);
    if (fp != NULL) {
        if (numeroLinhas > 0) {
            fscanf(fp, "%d %*[^\n]", &nrLinhasOP);//non-capturing scan
          
            while(i<nrLinhasOP+8){ //8= valor para contornar espaços existentes no ficheiro
                fscanf(fp, "%s", stringAux);
                i++;
            }
            while (i < numeroLinhas+6){ //6 = valor para contornar espaços existentes no ficheiro
                fscanf(fp, "%d,%d,%d", &op, &materiaPrima, &quantidade);
               
                if (materiaPrima == 1) {
                    necessidades->necessidadesCouro += quantidade;
                } else if (materiaPrima == 2) {
                    necessidades->necessidadesTecido += quantidade;
                } else if (materiaPrima == 3) {
                    necessidades->necessidadesBorracha += quantidade;
                } else if (materiaPrima == 4) {
                    necessidades->necessidadesCordoes += quantidade;
                } else if (materiaPrima == 5) {
                    necessidades->necessidadesPalmilhas += quantidade;
                }
                i++;
            }
            printf("1 - Couro - %d\n", necessidades->necessidadesCouro);
            printf("2 - Tecido - %d\n", necessidades->necessidadesTecido);
            printf("3 - Borracha - %d\n", necessidades->necessidadesBorracha);
            printf("4 - Cordoes - %d\n", necessidades->necessidadesCordoes);
            printf("5 - Palmilhas - %d\n", necessidades->necessidadesPalmilhas);
        } else {
            puts("Error");
        }
    } else {
        puts(MSG_ERRO_LER_FICHEIRO);
    }
    fclose(fp);
}