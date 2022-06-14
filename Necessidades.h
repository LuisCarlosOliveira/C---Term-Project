
/**
 * @file:   necessidades.h
 * @author: Luis Oliveira <https://github.com/LuisCarlosOliveira>
 * @date 10 de fevereiro de 2022, 16:17
 * @brief Biblioteca com estrutura Necessidades que irá armazenar as necessidades do ficheiro da OP
 */

#ifndef NECESSIDADES_H
#define NECESSIDADES_H

/** @struct Necessidades
 * @brief  Armazena informações relativas às necessidades da OP
 * @var Necessidades::necessidadesCouro 
 *  'necessidadesCouro' quantidade de couro da OP
 * @var Necessidades::necessidadesTecido 
 *  'necessidadesTecido' quantidade de tecido da OP
 * @var Necessidades::necessidadesBorracha 
 *  'necessidadesBorracha' quantidade de borracha da OP
 * @var Necessidades::necessidadesCordoes 
 *  'necessidadesCordoes' quantidade de cordoes da OP
 * @var Necessidades::necessidadesPalmilhas 
 *  'necessidadesPalmilhas' quantidade de palmilhas da OP
 */

typedef struct {
    int necessidadesCouro;
    int necessidadesTecido;
    int necessidadesBorracha;
    int necessidadesCordoes;
    int necessidadesPalmilhas;
} Necessidades;

void carregarNecessidades(Necessidades *necessidades, char *nomeFicheiro);


#endif /* NECESSIDADES_H */
