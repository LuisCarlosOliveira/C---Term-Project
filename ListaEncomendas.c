
/**
 * @file:   ListaEncomendas.c
 * @author : Luis Oliveira <https://github.com/LuisCarlosOliveira>
 * 
 * @dateCreated on 12 de fevereiro de 2022, 19:20
 * @brief Ficheiro c que contém a implementação das funções de gestão da lista de encomendas
 */

#include <stdio.h>
#include <stdlib.h>
#include "ListaEncomendas.h"
#include "Stock.h"
#include "Input.h"
#include "Necessidades.h"
#include "Encomenda.h"

/**
 * Realocação da memória, duplicando o tamanho
 * @param lista apontador para lista de encomendas
 */
void expandirMemoria(ListaEncomendas *lista){
    Encomenda *enc = (Encomenda*) realloc(lista->listaEncomendas, sizeof(Encomenda) * (lista->tamanho * 2));
    lista->listaEncomendas= enc;
    lista->tamanho *= 2;
    
}

/**
 * Liberta a memória alocada para a lista de encomendas
 * @param lista apontador para lista de encomendas
 */
void libertarMemoriaEncomendas(ListaEncomendas *lista){
    free(lista->listaEncomendas);
    lista->listaEncomendas = NULL;
}

/**
 * Alocação de memória incial de acordo com TAMANHO_MAX
 * @param lista apontador para a lista de encomendas
 */
void alocarMemoria(ListaEncomendas *lista){
    lista->listaEncomendas = (Encomenda*) malloc (TAMANHO_MAX * sizeof(Encomenda));
    lista->listaEncomendas == NULL ? puts("Erro na alocação de memória"): printf("Sucesso na alocação de Memória de Lista Encomendas! \n"); 
    lista->tamanho= TAMANHO_MAX;
    lista->nrEncomendas=0;    
}

/**
 * Adiciona uma encomenda à lista  de encomendas
 * @param lista apontador para uma lista de encomendas
 * @return 1 se encomenda é adicionada com sucesso / 0  se encomenda já existe, não adiciona
 * 
 */

/**
 * Se possivel, adiciona encomenda à lista  de encomendas
 * @param lista apontador para a lista de encomendas
 * @return 1 se o encomenda foi adicionada com sucesso / 0 não inserida (numero encomenda já existe na lista)
 * 
 */

int adicionarEncomenda(ListaEncomendas *lista, Stock *st, Necessidades *nec, MinimoEnc minEnc){
    Encomenda enc;
    enc.codigoEncomenda = lista->nrEncomendas + 1;
    criarEncomenda(&enc, minEnc, st, nec);
    //verifica se  codigo da encomenda já existe 
    for (int i = 0; i < lista->nrEncomendas; i++) {
        if (lista->listaEncomendas[i].codigoEncomenda == enc.codigoEncomenda){
            return 0;
        }
    }
    //lista cheia
    if (lista->nrEncomendas == lista->tamanho) {
        expandirMemoria(lista);
    }
    
    // adiciona e incrimenta o nr de funcionários
    lista->listaEncomendas[lista->nrEncomendas] = enc;
    lista->nrEncomendas++;
    return 1;
}

/**
 * Caso exista, devolve um apontador para uma encomenda
 * @param lista apontador para lista de funcionários
 * @param nrEnc número de encomenda
 * @return apontador para a encomenda / -1 caso não exista
 */

Encomenda* obterEncomenda(ListaEncomendas *lista, int nrEnc) {
    if (nrEnc <= 0 && nrEnc > lista->nrEncomendas) {
        puts("Número de encomenda Inválido");
        return NULL;
    } else {
        return &lista->listaEncomendas[nrEnc-1];
    }
}

/**
 * Caso exista, mostra info da encomenda
 * @param lista apontador para lista de funcionários
 * @param nrEnc número de encomenda
 */
void mostraEncomenda(ListaEncomendas *lista, int nrEnc) {
    Encomenda *enc;
    enc = obterEncomenda(lista, nrEnc);
    if (enc != NULL) {
        imprimeEncomenda(*enc);
    } else {
        puts("Encomenda não encontrada");
    }
}

/**
 * Imprime a lista de encomendas
 * @param lista aponador lista de funcionários
 *  Caso a lista esteja vazia imprime "Sem encomendas!"
 */

void listarEncomendas(ListaEncomendas *lista) {
    if (lista->nrEncomendas == 0) {
        puts("\nSem encomendas!\n");
    } else {
        for (int i = 0; i < lista->nrEncomendas; i++) {
            puts("");
            printf("Encomenda nª %d\n", lista->listaEncomendas[i].codigoEncomenda);
            imprimeEncomenda(lista->listaEncomendas[i]);
            puts("");
        }
    }
}

/**
 * Caso exista, guarda info da encomenda num ficheiro
 * @param lista apontador para lista de funcionários
 * @param nrEnc número de encomenda
 */
void guardarNrEncomenda(ListaEncomendas *lista, int nrEnc) {
    Encomenda *enc;
    enc = obterEncomenda(lista, nrEnc);
    if (enc != NULL) {
        guardarEncomenda(enc);
    } else {
        puts("Encomenda não encontrada");
    }
}
/**
 * Guarda todas as encomendas num ficheiro
 * @param lista apontador para lista de funcionários
 * 
 */

void guardarListaEncomendas(ListaEncomendas *lista) {
    if (lista->nrEncomendas == 0) {
        puts("\nSem encomendas!\n");
    } else {
        for (int i = 0; i < lista->nrEncomendas; i++) {
            guardarEncomendas(&lista->listaEncomendas[i]);
            puts("");
        }
    }
}

/**
 * Media da quantidade de cada matéria prima por encomenda
 * @param lista apontador para lista de funcionários
 */
void mediaEncomendas(ListaEncomendas *lista){
    int encomendaCouro = 0;
    int encomendaTecido = 0;
    int encomendaBorracha = 0;
    int encomendaCordoes = 0;
    int encomendaPalmilhas = 0;

    for (int i = 0; i < lista->nrEncomendas; i++) {
        encomendaCouro += lista->listaEncomendas[i].encomendaCouro;
        encomendaTecido += lista->listaEncomendas[i].encomendaTecido;
        encomendaBorracha += lista->listaEncomendas[i].encomendaBorracha;
        encomendaCordoes += lista->listaEncomendas[i].encomendaCordoes; 
        encomendaPalmilhas += lista->listaEncomendas[i].encomendaPalmilhas; 
    }
    printf("Cada encomenda em média possui de Couro %.1f \n", (encomendaCouro /(float)lista->nrEncomendas));
    printf("Cada encomenda em média possui de Tecido %.1f \n", (encomendaTecido /(float)lista->nrEncomendas));
    printf("Cada encomenda em média possui de Borracha %.1f \n", (encomendaBorracha /(float)lista->nrEncomendas));
    printf("Cada encomenda em média possui de cordões %.1f \n", (encomendaCordoes /(float)lista->nrEncomendas));
    printf("Cada encomenda em média possui de Palmilhas %.1f \n\n\n", (encomendaPalmilhas /(float)lista->nrEncomendas));
}
