#include "ram.h"

// Definição completa da struct RAM (ficará privada no .c)
struct RAM {
    int *memoria;
    int tamanho;
    int opcode;
    int pc;
};

RAM* criarRAM(int tamanho){
    RAM* ram = (RAM*) malloc(sizeof(RAM));
    ram->memoria = (int*) malloc(tamanho * sizeof(int));
    ram->tamanho = tamanho;
    ram->opcode = 0;
    ram->pc = 0;
    return ram;
}

RAM* criarRAM_vazia(int tamanho){
    RAM* ram = criarRAM(tamanho);
    for(int i = 0; i < tamanho; i++)
        ram->memoria[i] = 0;
    return ram;
}

RAM* criarRAM_aleatoria(int tamanho){
    RAM* ram = criarRAM(tamanho);
    srand(time(NULL));
    for(int i = 0; i < tamanho; i++)
        ram->memoria[i] = rand() % 100; // valores aleatórios de 0 a 99
    return ram;
}

void setDado(RAM* ram, int endereco, int conteudo){
    if(endereco < 0 || endereco >= ram->tamanho){
        printf("ERRO: Endereco %d invalido! Tamanho da RAM: %d\n", endereco, ram->tamanho);
        return;
    }
    ram->memoria[endereco] = conteudo;
}

int getDado(RAM* ram, int endereco){
    if(endereco < 0 || endereco >= ram->tamanho){
        printf("ERRO: Endereco %d invalido! Tamanho da RAM: %d\n", endereco, ram->tamanho);
        return -1;
    }
    return ram->memoria[endereco];
}

void imprimir(RAM* ram){
    printf("Conteudo da RAM:\n");
    for(int i = 0; i < ram->tamanho; i++)
        printf("%d, ", ram->memoria[i]);
    printf("\n");
}

void destruirRAM(RAM* ram){
    free(ram->memoria);
    free(ram);
}

// Grupo 10 - Otávio Enrique Lopes de Lima,Ana Gabriela Gomes Lopes Pereira e Heitor Novais Leite de Menezes