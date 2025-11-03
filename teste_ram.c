#include <stdio.h>
#include "ram.h"

void teste_ram_vazia() {
    printf("=== TESTE 1: RAM VAZIA ===\n");
    RAM ram;
    criarRAM_vazia(&ram, 5);
    imprimir(&ram);  // Deve mostrar: 0,0,0,0,0
    free(ram.memoria);
}

void teste_escrever_ler() {
    printf("\n=== TESTE 2: ESCREVER E LER ===\n");
    RAM ram;
    criarRAM_vazia(&ram, 5);
    
    setDado(&ram, 0, 100);
    setDado(&ram, 2, 200);
    setDado(&ram, 4, 300);
    
    printf("Posicao 0: %d (esperado: 100)\n", getDado(&ram, 0));
    printf("Posicao 2: %d (esperado: 200)\n", getDado(&ram, 2));
    printf("Posicao 4: %d (esperado: 300)\n", getDado(&ram, 4));
    
    free(ram.memoria);
}

void teste_acesso_invalido() {
    printf("\n=== TESTE 3: ACESSO INVALIDO ===\n");
    RAM ram;
    criarRAM_vazia(&ram, 3);
    
    printf("Posicao -1: %d (esperado: 0)\n", getDado(&ram, -1));
    printf("Posicao 10: %d (esperado: 0)\n", getDado(&ram, 10));
    
    free(ram.memoria);
}

void teste_ram_aleatoria() {
    printf("\n=== TESTE 4: RAM ALEATORIA ===\n");
    RAM ram;
    criarRAM_aleatoria(&ram, 4);
    imprimir(&ram);  // Deve mostrar 4 números aleatórios
    free(ram.memoria);
}

int main() {
    teste_ram_vazia();
    teste_escrever_ler();
    teste_acesso_invalido();
    teste_ram_aleatoria();
    
    printf("\n✅ TODOS OS TESTES CONCLUIDOS!\n");
    return 0;

}
