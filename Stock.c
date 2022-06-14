
/** 
 * @file:   stock.c
 * @author Luis Oliveira <https://github.com/LuisCarlosOliveira>
 * @date  on 7 de fevereiro de 2022, 11:35
 * @brief Ficheiro c que contém as funções para criar/carregar/editar/guardar/mostrar stock 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stock.h"
#include "Input.h"
#define MSG_ERRO_LER_FICHEIRO "Erro a abrir o ficheiro!"

/**
 * Lê stock da consola
 * @param stock apontador para a estrutura Stock que permite armazenar todos os dados do stock
 */
void criarStock(Stock *stock){
    
    puts("===== Inserir dados de stock: =====\n");
    imprimeLinha(36);
    stock->couroStock = obterInt(0,MAX_STOCK, "Quantidade de couro em stock (metros): ");
    stock->minStockCouro = obterInt(0,stock->couroStock, "Quantidade minima de stock de couro (metros): ");
    stock->tecidoStock = obterInt(0,MAX_STOCK, "Quantidade de tecido em stock (metros): ");
    stock->minStockTecido = obterInt(0,stock->tecidoStock, "Quantidade minima de stock de tecido (metros): ");
    stock->borrachaStock = obterInt(0,MAX_STOCK, "Quantidade de borracha em stock (Kg): ");
    stock->minStockBorracha = obterInt(0,stock->borrachaStock, "Quantidade minima de stock de borracha (Kg): ");
    stock->cordoesStock = obterInt(0,MAX_STOCK, "Quantidade de cordoes em stock (metros): ");
    stock->minStockCordoes = obterInt(0,stock->cordoesStock, "Quantidade minima de stock de cordoes (metros): ");
    stock->palmilhasStock = obterInt(0,MAX_STOCK, "Quantidade de palmilhas em stock (pares): ");
    stock->minStockPalmilhas = obterInt(0,stock->palmilhasStock, "Quantidade minima de stock de palmilhas (pares): ");
    
}

/**  Imprime na consola as informações do stock
 * @param stock  parâmetro que contém todos os dados referentes ao stock.
 */
void mostrarStock(Stock stock){
    puts("==============  Stock : =============\n");
    puts("Codigo | Produto | Stock Minimo | Stock Atual\n");
    printf("1\tCouro\t\t%d\t\t%d\n", stock.minStockCouro, stock.couroStock);
    printf("2\tTecido\t\t%d\t\t%d\n", stock.minStockTecido, stock.tecidoStock);
    printf("3\tBorracha\t%d\t\t%d\n", stock.minStockBorracha, stock.borrachaStock);
    printf("4\tCordões\t\t%d\t\t%d\n", stock.minStockCordoes, stock.cordoesStock);
    printf("5\tPalmilhas\t%d\t\t%d\n", stock.minStockPalmilhas, stock.palmilhasStock);

}   

/**
 * Editar stock
 * @param stock apontador para a estrutura Stock que permite alterar todos os dados do stock
 */
void editarStock(Stock *stock){
    
    int op = -1;
    
    do{
       
        
        puts("1 - Stock actual de couro");
        puts("2 - Stock minimo de couro a ter");
        puts("3 - Stock actual de tecido");
        puts("4 - Stock minimo de tecido a ter");
        puts("5 - Stock actual de borracha");
        puts("6 - Stock minimo de borracha a ter");
        puts("7 - Stock actual de cordões");
        puts("8 - Stock minimo de cordões a ter");
        puts("9 - Stock actual de palmilhas");
        puts("10 - Stock minimo de palmilhas a ter");
        puts("0 - Sair");
        op = obterInt(0, 10, "=== Qual valor pretende alterar: ===\n");
        
        if(op==1){
            stock->couroStock = obterInt(stock->minStockCouro, MAX_STOCK,"Novo stock couro: ");
        }if(op == 2){
            stock->minStockCouro = obterInt(0,stock->couroStock, "Novo stock minimo couro: ");
        }if(op == 3){
            stock->tecidoStock = obterInt(stock->minStockTecido, MAX_STOCK,"Novo stock tecido: ");
        }if(op == 4){
            stock->minStockTecido = obterInt(0,stock->tecidoStock , "Novo stock minimo tecido: ");
        }if(op == 5){
            stock->cordoesStock = obterInt(stock->minStockCordoes, MAX_STOCK,"Novo stock cordoes: ");
        }if(op == 6){
            stock->minStockCordoes = obterInt(0,stock->cordoesStock  , "Novo stock minimo cordoes: ");
        }if(op == 7){
            stock->borrachaStock = obterInt(stock->minStockBorracha, MAX_STOCK,"Novo stock borracha: ");
        }if(op == 8){
            stock->minStockBorracha = obterInt(0,stock->borrachaStock  , "Novo stock minimo borracha: ");
        }if(op == 9){
            stock->palmilhasStock = obterInt(stock->minStockPalmilhas, MAX_STOCK,"Novo stock palmilhas : ");
        }if(op == 10){
            stock->minStockPalmilhas = obterInt(0,stock->palmilhasStock  , "Novo stock minimo palmilhas: ");
        }
        
    }while(op != 0);
    
    
}

/**
 * Lê dados de um ficheiro (caso exista) e preenche dados do stock
 * @param stock apontador para a estrutura Stock que terá valores das variaveis lidas do ficheiro
 * @param nomeFicheiro nome do ficheiro do qual Stock será carregado
 */
void carregarStock(Stock *stock, char *nomeFicheiro){
    int i = 0;
    int codigo; //variavel para armazenar o codigo
    char stringAux[40]; //variavel "fake" para amazenar nome
    int minimo, quantidade;
    
    FILE *fp = fopen(nomeFicheiro, "r");
    
    int numeroLinhas = nrLinhasFicheiro(nomeFicheiro);
    
    if (fp != NULL){
       
        if(numeroLinhas >0){
            fscanf(fp, "%s",stringAux);//skip first line
            
            while(i< numeroLinhas){
                fscanf(fp, "%d, %*[^,],%d,%d", &codigo, &minimo, &quantidade);
                
                if(codigo==1){
                    stock->minStockCouro = minimo;
                    stock->couroStock = quantidade;
                }else if(codigo==2){
                    stock->minStockTecido = minimo;
                    stock->tecidoStock = quantidade;
                }else if(codigo==3){
                    stock->minStockBorracha = minimo;
                    stock->borrachaStock = quantidade;
                }else if(codigo==4){
                    stock->minStockCordoes = minimo;
                    stock->cordoesStock = quantidade;
                }else if(codigo==5){
                    stock->minStockPalmilhas = minimo;
                    stock->palmilhasStock = quantidade;
                }   
                i++;
            }
             
        }else{
            puts("Error");          
        }
        puts("\n!Stock carregado com sucesso do ficheiro!\n\n");
    }else{
        puts(MSG_ERRO_LER_FICHEIRO);
    }
    fclose(fp);
}

/**
 * Escreve o conteúdo do stock em ficheiro 
 * @param stock apontador para a estrutura Stock que será escrita em ficheiro
 * @param nomeFicheiro nome do ficheiro no qual a estrutura será escrita
 */
void guardarStock(Stock *stock, char *nomeFicheiro){
    
    FILE *fp = fopen(nomeFicheiro, "w");
    
    if (fp != NULL){
    fprintf(fp,"Codigo,Produto,StockMinimo,StockAtual\n");
    fprintf(fp,"1,Couro,%d,%d\n", stock->minStockCouro,stock->couroStock );
    fprintf(fp,"2,Tecido,%d,%d\n", stock->minStockTecido, stock->tecidoStock);
    fprintf(fp,"3,Borracha,%d,%d\n", stock->minStockBorracha, stock->borrachaStock );
    fprintf(fp,"4,Cordões,%d,%d\n", stock->minStockCordoes, stock->cordoesStock );
    fprintf(fp,"5,Palmilhas,%d,%d\n", stock->minStockPalmilhas, stock->palmilhasStock);
    }else{
        puts("ERRO NA ESCRITA DO FICHEIRO");
    }
}

/**
 * Listagem que permite saber, caso de falha de fornecimento, que pode se gastar sem prejudicar o stock minim 
 * @param stock parâmetro que contém todos os dados referentes ao stock.
 * @param nomeFicheiro nome do ficheiro no qual a estrutura será escrita
 */

void mediaStock( Stock stock){
    int total = stock.borrachaStock + stock.cordoesStock + stock.palmilhasStock + stock.tecidoStock + stock.couroStock;
    printf("A media de stock de cada matéria prima é  %.2f\n", (total /(float) 5));

    
    printf("Podemos gastar [ %d ] de couro sem afetar o minimo de stock \n",stock.couroStock-stock.minStockCouro );
    printf("Podemos gastar [ %d ] de Tecido sem afetar o minimo de stock \n", stock.tecidoStock-stock.minStockTecido);
    printf("Podemos gastar [ %d ] de Borracha sem afetar o minimo de stock \n", stock.borrachaStock-stock.minStockBorracha);
    printf("Podemos gastar [ %d ] de cordões sem afetar o minimo de stock \n", stock.cordoesStock-stock.minStockCordoes);
    printf("Podemos gastar [ %d ] de Palmilhas sem afetar o minimo de stock \n", stock.palmilhasStock-stock.minStockPalmilhas);
}