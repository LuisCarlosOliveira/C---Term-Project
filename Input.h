/**
 * @file:   input.h
 * @author: Luis Oliveira <https://github.com/LuisCarlosOliveira>
 * @date 29 de dezembro de 2021, 18:45
 * IMPORTANTE: grande parte do código aqui presente foi disponiblidade na UC de FP pelo Prof. Oscar Oliveira
 * @brief Biblioteca para operações de leitura
 */

#ifndef INPUT_H
#define INPUT_H

int obterInt(int minValor, int maxValor, char *msg);

float obterFloat(float minValor, float maxValor, char *msg);

double obterDouble(double minValor, double maxValor, char *msg);

char obterChar(char *msg);

void lerString(char *string, unsigned int tamanho, char *msg);

//Luís oLiveira
void imprimeLinha();
//Luís Oliveira
int nrLinhasFicheiro(char *filename);

#endif /* INPUT_H */
