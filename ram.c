#include "ram.h"

void criarRAM(RAM* ram, int tamanho){// Cria a RAM com o tamanho especificado
    ram->memoria = (int*)malloc(tamanho * sizeof(int));
    ram->tamanho = tamanho;
}

void criarRAM_vazia(RAM* ram, int tamanho){// Cria uma RAM zerada
    criarRAM(ram, tamanho);
    for(int i = 0; i < tamanho; i++){
        ram->memoria[i] = 0;
    }
}

void criarRAM_aleatoria(RAM* ram, int tamanho){// Cria uma RAM com valores aleatórios
    srand(time(NULL));
    criarRAM(ram, tamanho);
    for(int i = 0; i < tamanho; i++){
        ram->memoria[i] = rand();  
    }
}

void setDado(RAM* ram, int endereco, int conteudo){// Define um valor em um endereço da RAM
    if(endereco >= 0 && endereco < ram->tamanho){
        ram->memoria[endereco] = conteudo;
    }
}

int getDado(RAM* ram, int endereco){//Retorna o valor de um endereço da RAM
    if(endereco >= 0 && endereco < ram->tamanho){
        return ram->memoria[endereco];
    }
    return 0;
}

void imprimir(RAM* ram){// Mostra todo o conteúdo da RAM
    printf("Conteudo da RAM\n");
    for(int i = 0; i < ram->tamanho; i++){
        printf("%d,", ram->memoria[i]);  
    }
    printf("\n");
}
// Grupo 10 - Otávio Enrique Lopes de Lima,Ana Gabriela Gomes Lopes Pereira e Heitor Novais Leite de Menezes
