#ifndef RAM_H
#define RAM_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct RAM RAM;

// Funções para criar a RAM
RAM* criarRAM(int tamanho);             
RAM* criarRAM_vazia(int tamanho);       
RAM* criarRAM_aleatoria(int tamanho);   

// Funções para acessar/modificar memória
void setDado(RAM* ram, int endereco, int conteudo);
int getDado(RAM* ram, int endereco);

// Função para imprimir a RAM
void imprimir(RAM* ram);

// Função para liberar a memória da RAM
void destruirRAM(RAM* ram);

#endif
// Grupo 10 - Otávio Enrique Lopes de Lima,Ana Gabriela Gomes Lopes Pereira e Heitor Novais Leite de Menezes