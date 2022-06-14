
/* 
 * @file:   main.c
 * @author: Luis Oliveira <https://github.com/LuisCarlosOliveira>
 *
 * @date 7 de fevereiro de 2022, 11:32
 * @brief Ficheiro que contém a função principal do programa e menu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEncomendas.h"
#include "Stock.h"
#include "Input.h"
#include "Necessidades.h"
#include "Encomenda.h"

/*
 * 
 */
int main(int argc, char** argv) {

    char *nomeFicheiro1 = "tabela_stocks.txt";
    char *nomeFicheiro2 = "OP_2022_02_01.txt";
    char *nomeFicheiro3 = "OP_2022_02_02.txt";

    ListaEncomendas lista = {.nrEncomendas = 0, .tamanho = 0};
    Encomenda enc = {.codigoEncomenda = 0};
    MinimoEnc minEnc;
    criarMinimoEncomenda(&minEnc);
    Stock stock;
    Necessidades necess;
    criarMinimoEncomenda(&minEnc);

    int op1, op2;

    do {
        op1 = -1;
        puts("***************************");
        puts("* Menu - Gestão de Stocks *");
        puts("***************************");
        puts("1 - Stocks");
        puts("2 - Necessidades");
        puts("3 - Encomendas");
        puts("4 - Listagens");
        puts("0 - Sair");
        op1 = obterInt(0, 4, "Selecionar opção: ");

        printf("\e[1;1H\e[2J"); //limpa consola
        if (op1 == 1) {
            do {
                op2 = -1;
                puts("***************************");
                puts("*         Stocks          *");
                puts("***************************");
                puts("1 - Inserir Stock ");
                puts("2 - Carregar Stock de Ficheiro ");
                puts("3 - Editar Stock");
                puts("4 - Imprimir Stock");
                puts("5 - Guardar Stock em ficheiro");
                puts("0 - Sair");
                op2 = obterInt(0, 5, "Selecionar opção: ");
                printf("\e[1;1H\e[2J");
                if (op2 == 1) {
                    criarStock(&stock);
                }
                if (op2 == 2) {
                    carregarStock(&stock, nomeFicheiro1);
                }
                if (op2 == 3) {
                    editarStock(&stock);
                }
                if (op2 == 4) {
                    mostrarStock(stock);
                }
                if (op2 == 5) {
                    guardarStock(&stock, nomeFicheiro1);
                }

            } while (op2 != 0);
        }
        if (op1 == 2) {
            do {
                op2 = -1;
                puts("***************************");
                puts("*      Necessidades       *");
                puts("***************************");
                puts("1 - Carregar Necessidades Ficheiro2");
                puts("2 - Carregar Necessidades Ficheiro3 ");
                puts("0 - Sair");

                op2 = obterInt(0, 2, "Selecionar opção: ");
                printf("\e[1;1H\e[2J");
                if (op2 == 1) {
                    carregarNecessidades(&necess, nomeFicheiro2);
                }
                if (op2 == 2) {
                    carregarNecessidades(&necess, nomeFicheiro3);
                }

            } while (op2 != 0);
        }
        if (op1 == 3) {
            do {
                op2 = -1;
                puts("***************************");
                puts("*      Encomendas         *");
                puts("***************************");
                puts("1 - Adicionar Encomenda");
                puts("2 - Mostrar Encomenda ");
                puts("3 - Exportar Encomenda para ficheiro");
                puts("4 - Exportar todas encomendas para ficheiro ");
                puts("5 - Editar quantidade minima de encomenda do Fornecedor ");
                puts("0 - Sair");

                op2 = obterInt(0, 6, "Selecionar opção: ");
                printf("\e[1;1H\e[2J");
                if (op2 == 1) {
                    if (lista.tamanho == 0) {
                        alocarMemoria(&lista);
                    }
                    adicionarEncomenda(&lista, &stock, &necess, minEnc);
                }
                if (op2 == 2) {
                    int nrEnc = obterInt(0, 100, "Inserir numero de encomenda a mostrar:");
                    mostraEncomenda(&lista, nrEnc);
                }
                if (op2 == 3) {
                    int nrEnc = obterInt(0, 100, "Inserir numero de encomenda a mostrar:");
                    guardarNrEncomenda(&lista, nrEnc);
                }

                if (op2 == 4) {
                    guardarListaEncomendas(&lista);
                }
                if (op2 == 5) {
                    editarMinimoEncomenda(&minEnc);
                }

            } while (op2 != 0);
        }
        if (op1 == 4) {
            do {
                op2 = -1;
                puts("***************************");
                puts("*        Listagens        *");
                puts("***************************");
                puts("1 - Media de Stock");
                puts("2 - Listar todoas Encomendas ");
                puts("3 - Média de quantidade de Encomenda");
                puts("0 - Sair");

                op2 = obterInt(0, 3, "Selecionar opção: ");
                printf("\e[1;1H\e[2J");
                if (op2 == 1) {
                    mediaStock(stock);
                }
                if (op2 == 2) {
                    listarEncomendas(&lista);
                }
                if (op2 == 3) {
                    mediaEncomendas(&lista);
                } 
            } while (op2 != 0);
        }
    } while (op1 != 0);

    if(lista.tamanho!=0){
        libertarMemoriaEncomendas(&lista);
    }

    return (EXIT_SUCCESS);
}

