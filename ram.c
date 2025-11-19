#include <stdio.h>
#include <stdlib.h>
#include "ram.h"

RAM* criarRAM(RAM *ram, int tamanho){
    ram->tamanho = tamanho;
    ram->memoria = (int*) malloc(sizeof(int) * tamanho);

    for(int i = 0; i < tamanho; i++){
        ram->memoria[i] = 0;
    }

    return ram;
}

RAM* criarRAM_vazia(RAM *ram, int tamanho){
    return criarRAM(ram, tamanho);
}

RAM* criarRAM_aleatoria(RAM *ram, int tamanho){
    criarRAM(ram, tamanho);

    for(int i = 0; i < tamanho; i++){
        ram->memoria[i] = rand() % 100;
    }

    return ram;
}

int getDado(RAM *ram, int pos){
    if(pos < 0 || pos >= ram->tamanho){
        printf("ERRO: Endereco %d invalido! Tamanho da RAM: %d\n", pos, ram->tamanho);
        return 0;
    }

    return ram->memoria[pos];
}

void setDado(RAM *ram, int pos, int valor){
    if(pos < 0 || pos >= ram->tamanho){
        printf("ERRO: Endereco %d invalido! Tamanho da RAM: %d\n", pos, ram->tamanho);
        return;
    }

    ram->memoria[pos] = valor;
}

void imprimir(RAM *ram){
    printf("Conteudo da RAM:\n");
    for(int i = 0; i < ram->tamanho; i++){
        printf("%d ", ram->memoria[i]);
    }
    printf("\n");
}


// Grupo 10 - Otávio Enrique Lopes de Lima,Ana Gabriela Gomes Lopes Pereira e Heitor Novais Leite de Menezes