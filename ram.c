#include <ram.h>

void criarRAM(RAM* ram, int tamanho){
 ram->memoria = (int*)malloc(tamanho * sizeof(int));
 ram->tamanho = tamanho;
}

void criarRAM_vazia(RAM* ram, int tamanho){ // zera a ram
    criarRAM(ram,tamanho);

    for(int i = 0;i<tamanho;i++){
        ram->memoria[i] = 0;
    }
}

void criarRAM_aleatoria(RAM* ram, int tamanho){
    srand(time(NULL));

    criarRAM(ram,tamanho);

    for(int i = 0;i<tamanho;i++){
        ram->mamoria[i] = rand();
    }
}

void setDado(RAM* ram, int endereco, int conteudo){
    if(endereco>= 0 && endereco<ram->tamanho){ // verifica se eh valido o endereco
        ram->memoria[endereco] = conteudo;
    }
}

int getDado(RAM* ram, int endereco){
    if(endereco>= 0 && endereco < ram->tamanho){
        return ram->memoria[endereco];
    }
    return 0;
}

void imprimir(RAM* ram){
    printf("Conteudo da RAM \n");

    for(int i = 0;i < ram->tamanho;i++){
        printf("%d",ram->tamanho[i]);
    }
    printf("\n");
}

// Grupo 10 - Otávio Enrique Lopes de Lima,Ana Gabriela Gomes Lopes Pereira e Heitor Novais Leite de Menezes
