
/** 
 * @file:   encomenda.h
 * @author: Luis Oliveira <https://github.com/LuisCarlosOliveira>
 * @date 11 de fevereiro de 2022, 22:47
 * @brief Bibloteca com a estrutura da encomenda e estrutura das quantidades minimas do Fornecedor
 */

#ifndef ENCOMENDA_H
#define ENCOMENDA_H
#include "Stock.h"
#include "Input.h"
#include "Necessidades.h"

/** @struct Encomenda
 * @brief  Armazena informações relativas à encomenda de matérias-primas
 * @var Encomenda::codigoEncomenda 
 *  'necessidadesCouro' numero identificaçao da encomenda
 * @var Encomenda::encomendaCouro 
 *  'encomendaCouro' quantidade de couro a encomendar
 * @var Encomenda::encomendaTecido 
 *  'encomendaTecido' quantidade de tecido a encomendar
 * @var Encomenda::encomendaBorracha 
 *  'encomendaBorracha' quantidade de borracha a encomendar
 * @var Encomenda::encomendaCordoes 
 *  'encomendaCordoes' quantidade de cordoes a encomendar
 * @var Encomenda::encomendaPalmilhas 
 *  'encomendaPalmilhas' quantidade de palmilhas a encomendar
 */


typedef struct {
    int codigoEncomenda; //Unico
    int encomendaCouro;
    int encomendaTecido;
    int encomendaBorracha;
    int encomendaCordoes;
    int encomendaPalmilhas;
} Encomenda;


/** @struct MinimoEnc
 * @brief  Armazena informações relativas as quantidades minimas do Fornecedorde de matérias-primas
 * @var MinimoEnc::couro 
 *  'couro' quantidade de minima couro a encomendar
 * @var MinimoEnc::tecido 
 *  'tecido' quantidade de minima tecido a encomendar
 * @var MinimoEnc::borracha 
 *  'borracha' quantidade de minima borracha a encomendar
 * @var MinimoEnc::cordoes 
 *  'cordoes' quantidade de minima cordoes a encomendar
 * @var MinimoEnc::palmilhas 
 *  'palmilhas' quantidade de minima palmilhas a encomendar
 */
typedef struct {
    int couro;
    int tecido;
    int borracha;
    int cordoes;
    int palmilhas;
} MinimoEnc;

void criarMinimoEncomenda(MinimoEnc *minEnc);
void editarMinimoEncomenda(MinimoEnc *minEnc);
void criarEncomenda(Encomenda *enc, MinimoEnc minEnc, Stock *st, Necessidades *nec);
void imprimeEncomenda(Encomenda enc);
void guardarEncomenda(Encomenda *enc);
void guardarEncomendas(Encomenda *enc);

#endif /* ENCOMENDA_H */
