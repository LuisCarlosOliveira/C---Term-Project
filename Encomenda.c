
/** 
 * @file:   encomenda.h
 * @author: Luis Oliveira <https://github.com/LuisCarlosOliveira>
 * @date 11 de fevereiro de 2022, 22:47
 * @brief Ficheiro c com funções para criar Encomenda e criar e estar quantidades minimas do Fornecedor
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stock.h"
#include "Input.h"
#include "Necessidades.h"
#include "Encomenda.h"


/**
 * Função que define as quantidades minimas do enunciado de encomenda do Fornecedor 
 * @param minEnc apontador para uma estrutura MinimoEnc que irá armazenar as quantidades minimas
 */

void criarMinimoEncomenda(MinimoEnc *minEnc) {
    minEnc->couro = 7; //1 rolo de 7m
    minEnc->borracha = 5; //1 saco de 5kg
    minEnc->cordoes = 10; //rolo 10 metros de cordões
    minEnc->palmilhas = 50; // saco de 50 palmilhas
    minEnc->tecido = 0; //sem minimo
}

/**
 * Função que altera as quantidades minimas do enunciado de encomenda do Fornecedor 
 * @param minEnc apontador para uma estrutura MinimoEnc que irá alterar as quantidades minimas
 */
void editarMinimoEncomenda(MinimoEnc *minEnc) {
    puts("======= Editar Quantidade Minima Possivel de Encomendar =======");
    minEnc->couro = obterInt(0, 10000, "Couro - minimo a encomendar: ");
    minEnc->borracha = obterInt(0, 10000, "Borracha - minimo a encomendar: ");
    minEnc->cordoes = obterInt(0, 10000, "Cordões - minimo a encomendar: ");
    minEnc->palmilhas = obterInt(0, 10000, "Palimilhas - minimo a encomendar: ");
    minEnc->tecido = obterInt(0, 10000, "Tecido - minimo a encomendar: ");
}

/**
 * Função que, tendo em conta as necessidades de OP, o stock, e a quantidade minima do Fornedor, cria a encomenda 
 * @param enc apontador para estrutura Encomenda que irá armazenar quantidades a armazenar
 * @param minEnc parametro que contem as quantidades minimas de encomenda do fornecdor
 * @param st apontador para estrutura Stock que irá actualizar o stock consuante as necessidades e encomenda
 * @param st apontador para a estrutura Necessidades para aceder à necessidade da OP
 */

void criarEncomenda(Encomenda *enc, MinimoEnc minEnc, Stock *st, Necessidades *nec) {

    int calculaQuantidade, temp;
    
    calculaQuantidade = nec->necessidadesCouro - st->couroStock + st->minStockCouro;

    if (calculaQuantidade > 0) {
        if (minEnc.couro != 0) {
            if (calculaQuantidade % minEnc.couro != 0) {
                enc->encomendaCouro = calculaQuantidade / minEnc.couro + 1;
            } else {
                enc->encomendaCouro = calculaQuantidade / minEnc.couro;
            }
            temp = enc->encomendaCouro * minEnc.couro;
            temp = temp - calculaQuantidade;
            st->couroStock = temp + st->minStockCouro;
        } else {
            enc->encomendaCouro = calculaQuantidade;
            st->couroStock = st->minStockCouro;
        }
    } else if (calculaQuantidade < 0) {
        if ((-1) * calculaQuantidade > st->minStockCouro) {
            enc->encomendaCouro = 0;
            st->couroStock -= nec->necessidadesCouro;
        } else {
            enc->encomendaCouro = 0;
            st->couroStock += calculaQuantidade;
        }
    } else {
        enc->encomendaCouro = 0;
        st->couroStock -= nec->necessidadesCouro;
    }


    calculaQuantidade = nec->necessidadesTecido - st->tecidoStock + st->minStockTecido;
    
    if (calculaQuantidade > 0) {
        if (minEnc.tecido != 0) {
            if (calculaQuantidade % minEnc.tecido != 0) {
                enc->encomendaTecido = calculaQuantidade / minEnc.tecido + 1;
            } else {
                enc->encomendaTecido = calculaQuantidade / minEnc.tecido;
            }
            temp = enc->encomendaTecido * minEnc.tecido;
            temp = temp - calculaQuantidade;
            st->tecidoStock = temp + st->minStockTecido;
        } else {
            enc->encomendaTecido = calculaQuantidade;
            st->tecidoStock = st->minStockTecido;
        }
    } else if (calculaQuantidade < 0) {
        if ((-1) * calculaQuantidade > st->minStockTecido) {
            enc->encomendaTecido = 0;
            st->tecidoStock -= nec->necessidadesTecido ;
        } else {
            enc->encomendaTecido = 0;
            st->tecidoStock += calculaQuantidade;
        }
    } else {
        enc->encomendaTecido = 0;
        st->tecidoStock -= nec->necessidadesTecido;    
    }

    calculaQuantidade = nec->necessidadesBorracha - st->borrachaStock + st->minStockBorracha;

    if (calculaQuantidade > 0) {
        if (minEnc.borracha != 0) {
            if (calculaQuantidade % minEnc.borracha != 0) {
                enc->encomendaBorracha = calculaQuantidade / minEnc.borracha + 1;
            } else {
                enc->encomendaBorracha = calculaQuantidade / minEnc.borracha;
            }
            temp = enc->encomendaBorracha * minEnc.borracha;
            temp = temp - calculaQuantidade;
            st->borrachaStock = temp + st->minStockBorracha;
        } else {
            enc->encomendaBorracha = calculaQuantidade;
            st->borrachaStock = st->minStockBorracha;
        }
    } else if (calculaQuantidade < 0) {
        if ((-1) * calculaQuantidade > st->minStockBorracha) {
            enc->encomendaBorracha = 0;
            st->borrachaStock -= nec->necessidadesBorracha ;
        } else {
            enc->encomendaBorracha = 0;
            st->borrachaStock += calculaQuantidade;
        }
    } else {
        enc->encomendaBorracha = 0;
        st->borrachaStock -= nec->necessidadesBorracha;    
    }
    
    calculaQuantidade = nec->necessidadesCordoes - st->cordoesStock + st->minStockCordoes;

    if (calculaQuantidade > 0) {
        if (minEnc.cordoes != 0) {
            if (calculaQuantidade % minEnc.cordoes != 0) {
                enc->encomendaCordoes = calculaQuantidade / minEnc.cordoes + 1;
            } else {
                enc->encomendaCordoes = calculaQuantidade / minEnc.cordoes;
            }
            temp = enc->encomendaCordoes * minEnc.cordoes;
            temp = temp - calculaQuantidade;
            st->cordoesStock = temp + st->minStockCordoes;
        } else {
            enc->encomendaCordoes = calculaQuantidade;
            st->cordoesStock = st->minStockCordoes;
        }
    } else if (calculaQuantidade < 0) {
        if ((-1) * calculaQuantidade > st->minStockCordoes) {
            enc->encomendaCordoes = 0;
            st->cordoesStock -= nec->necessidadesCordoes ;
        } else {
            enc->encomendaCordoes = 0;
            st->cordoesStock += calculaQuantidade;
        }
    } else {
        enc->encomendaCordoes = 0;
        st->cordoesStock -= nec->necessidadesCordoes;    
    }
    
    calculaQuantidade = nec->necessidadesPalmilhas - st->palmilhasStock + st->minStockPalmilhas;

    if (calculaQuantidade > 0) {
        if (minEnc.palmilhas != 0) {
            if (calculaQuantidade % minEnc.palmilhas != 0) {
                enc->encomendaPalmilhas = calculaQuantidade / minEnc.palmilhas + 1;
            } else {
                enc->encomendaPalmilhas = calculaQuantidade / minEnc.palmilhas;
            }
            temp = enc->encomendaPalmilhas * minEnc.palmilhas;
            temp = temp - calculaQuantidade;
            st->palmilhasStock = temp + st->minStockCordoes;
        } else {
            enc->encomendaPalmilhas = calculaQuantidade;
            st->palmilhasStock = st->minStockPalmilhas;
        }
    } else if (calculaQuantidade < 0) {
        if ((-1) * calculaQuantidade > st->minStockPalmilhas) {
            enc->encomendaPalmilhas = 0;
            st->palmilhasStock -= nec->necessidadesPalmilhas  ;
        } else {
            enc->encomendaPalmilhas = 0;
            st->palmilhasStock += calculaQuantidade;
        }
    } else {
        enc->encomendaPalmilhas = 0;
        st->palmilhasStock -= nec->necessidadesPalmilhas ;    
    }
    

    imprimeEncomenda(*enc);
}

/**  Imprime na consola as informações da encomenda
 * @param enc  parâmetro que contém todos os dados da encomenda
 */

void imprimeEncomenda(Encomenda enc){
    printf("==============  Encomenda nr: %d : =============\n", enc.codigoEncomenda);
    puts("Codigo | Produto | Quantidade\n");
    printf("1\tCouro\t\t%d rolos\n", enc.encomendaCouro);
    printf("2\tTecido\t\t%d metros\n", enc.encomendaTecido);
    printf("3\tBorracha\t%d sacos\n", enc.encomendaBorracha);
    printf("4\tCordões\t\t%d metros\n", enc.encomendaCordoes);
    printf("5\tPalmilhas\t%d sacos\n\n\n", enc.encomendaPalmilhas);
}

/**
 * Gera documento com encomenda
 * @param enc apontador para a estrutura Encomenda que será escrita em ficheiro Encomenda.txt
 * 
 */

void guardarEncomenda(Encomenda *enc){
    
    FILE *fp = fopen("Encomenda.txt", "w");
    if (fp != NULL){
        fprintf(fp,"==============  Encomenda nr: %d : =============\n", enc->codigoEncomenda );
        fprintf(fp,"Codigo | Produto | Quantidade\n");
        if(enc->encomendaCouro>0){
            fprintf(fp,"1\tCouro\t\t%d rolos\n", enc->encomendaCouro);
        }
        if(enc->encomendaTecido>0){
            fprintf(fp,"2\tTecido\t\t%d metros\n", enc->encomendaTecido);
        }
        if(enc->encomendaBorracha>0){
            fprintf(fp,"3\tBorracha\t%d sacos\n", enc->encomendaBorracha);
        }
        if(enc->encomendaCordoes>0){
            fprintf(fp,"4\tCordões\t\t%d metros\n", enc->encomendaCordoes);
        }
        if(enc->encomendaPalmilhas>0){
            fprintf(fp,"5\tPalmilhas\t%d sacos\n", enc->encomendaPalmilhas);
        }
    }else{
        puts("ERRO NA ESCRITA DO FICHEIRO");
    }
}

/**
 * Gera documento com todas encomenda
 * @param enc apontador para a estrutura Encomenda que será escrita em ficheiro Encomenda.txt
 * 
 */

void guardarEncomendas(Encomenda *enc){
    
    FILE *fp = fopen("ListadeEncomendas.txt", "a+");
    if (fp != NULL){
        fprintf(fp,"==============  Encomenda nr: %d : =============\n", enc->codigoEncomenda );
        fprintf(fp,"Codigo | Produto | Quantidade\n");
        if(enc->encomendaCouro>0){
            fprintf(fp,"1\tCouro\t\t%d rolos\n", enc->encomendaCouro);
        }
        if(enc->encomendaTecido>0){
            fprintf(fp,"2\tTecido\t\t%d metros\n", enc->encomendaTecido);
        }
        if(enc->encomendaBorracha>0){
            fprintf(fp,"3\tBorracha\t%d sacos\n", enc->encomendaBorracha);
        }
        if(enc->encomendaCordoes>0){
            fprintf(fp,"4\tCordões\t\t%d metros\n", enc->encomendaCordoes);
        }
        if(enc->encomendaPalmilhas>0){
            fprintf(fp,"5\tPalmilhas\t%d sacos\n", enc->encomendaPalmilhas);
        }
    }else{
        puts("ERRO NA ESCRITA DO FICHEIRO");
    }
}


