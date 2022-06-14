
/** 
 * @file:   stock.h
 * @author Luis Oliveira <https://github.com/LuisCarlosOliveira>
 * @date  on 7 de fevereiro de 2022, 11:35
 * @brief Bibloteca com a estrutura do stock e respectivas funções 
 * 
 */

#ifndef STOCK_H
#define STOCK_H
#define MAX_STOCK 10000000


/** @struct Stock
 * @brief  Armazena informações relativas ao stock
 * @var Stock::couroStock 
 *  'couroStock' quantidade de couro em stock
 * @var Stock::minStockCouro 
 *  'minStockCouro' quantidade minima de couro a ter em stock
 * @var Stock::tecidoStock 
 *  'tecidoStock' quantidade de tecido em stock
 * @var Stock::minStockTecido 
 *  'minStockTecido' quantidade minima de tecido a ter em stock
 *  * @var Stock::cordoesStock 
 *  'cordoesStock' quantidade de cordoes em stock
  * @var Stock::minStockCordoes 
 *  'minStockCordoes' quantidade minima de cordoes a ter em stock
 * @var Stock::palmilhasStock 
 *  'palmilhaStock' quantidade de palmilhas em stock
  * @var Stock::minStockPalmilhas 
 *  'minStockPalmilhas' quantidade minima de palmilhas a ter em stock
 * @var Stock::borrachaStock 
 *  'borrachaStock' quantidade de borracha em stock
  * @var Stock::minStockBorracha 
 *  'minStockBorracha' quantidade minima de borracha  a ter em stock
 */
typedef struct {
    int couroStock;
    int minStockCouro;
    int tecidoStock;
    int minStockTecido;
    int borrachaStock;
    int minStockBorracha;
    int cordoesStock;
    int minStockCordoes;
    int palmilhasStock;
    int minStockPalmilhas;

} Stock;

void criarStock(Stock *stock);
void mostrarStock(Stock stock);
void editarStock(Stock *stock);
void carregarStock(Stock *stock, char *nomeFicheiro);
void guardarStock(Stock *stock, char *nomeFicheiro);
void mediaStock( Stock stock);

#endif /* STOCK_H */
