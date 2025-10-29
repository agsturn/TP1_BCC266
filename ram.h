#ifndef RAM_H
#define RAM_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ram {
    int *memoria;
    int tamanho;
};

void criarRAM(RAM* ram, int tamanho);

void criarRAM_vazia(RAM* ram, int tamanho);

void criarRAM_aleatoria(RAM* ram, int tamanho);

void setDado(RAM* ram, int endereco, int conteudo);

int getDado(RAM* ram, int endereco);

void imprimir(RAM* ram);

#endif
// Grupo 10 - Otávio Enrique Lopes de Lima,Ana Gabriela Gomes Lopes Pereira e Heitor Novais Leite de Menezes
