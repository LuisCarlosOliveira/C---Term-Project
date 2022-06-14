
/**
 * @file:   ListaEncomendas.h
 * @author : Luis Oliveira <https://github.com/LuisCarlosOliveira>
 * 
 * @dateCreated on 12 de fevereiro de 2022, 19:20
 * @brief Biblioteca que contém a estrutura da lista de encomendas e respectivas funções para gestão da mesma
 */

#ifndef LISTAENCOMENDAS_H
#define LISTAENCOMENDAS_H
#include "Encomenda.h"
#define TAMANHO_MAX 5

/** @struct ListaEncomendas
 * @brief Armazena uma lista de encomendas
 * @var ListaEncomendas::nrEncomendas
 *  'nrEncomendas' número de encomendas da lista
 * @var ListaEncomendas::tamanho
 *  'tamanho' tamanho da lista de encomendas
 * @var ListaEncomendas::listaEncomendas
 *  'listaEncomendas' apontador para a estrutura Encomenda
 */

typedef struct {
    int nrEncomendas;
    int tamanho;
    Encomenda *listaEncomendas;
} ListaEncomendas;

void expandirMemoria(ListaEncomendas *lista);
void libertarMemoriaEncomendas(ListaEncomendas *lista);
void alocarMemoria(ListaEncomendas *lista);
int adicionarEncomenda(ListaEncomendas *lista, Stock *st, Necessidades *nec, MinimoEnc minEnc);
Encomenda* obterEncomenda(ListaEncomendas *lista, int nrEnc);
void mostraEncomenda(ListaEncomendas *lista, int nrEnc);
void listarEncomendas(ListaEncomendas *lista);
void guardarNrEncomenda(ListaEncomendas *lista, int nrEnc) ;
void guardarListaEncomendas(ListaEncomendas *lista);
void mediaEncomendas(ListaEncomendas *lista);

#endif /* LISTAENCOMENDAS_H */
