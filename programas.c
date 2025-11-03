// Grupo 10 - Otávio Enrique Lopes de Lima,Ana Gabriela Gomes Lopes Pereira e Heitor Novais Leite de Menezes

#include <stdio.h>
#include <stdlib.h>
#include "maquina.h"  
/* OPCODES:
   0 : SOMAR (RAM[add3] = RAM[add1] + RAM[add2])
   1 : SUBTRAIR (RAM[add3] = RAM[add1] - RAM[add2])
   2 : LEVAR PARA MEMÓRIA (RAM[add2] = REG[add1])
   3 : TRAZER DA MEMÓRIA (REG[add1] = RAM[add2])
  -1 : PARAR
 */

void programaSoma(RAM *ram, CPU *cpu);
void programaSubtrai(RAM *ram, CPU *cpu);
void programaAleatorio(RAM *ram, CPU *cpu, int qdeInstrucoes);

int main() {
    RAM ram;
    CPU cpu;

    printf("=== Execução dos programas CAVE Language ===\n\n");

    // Executa um exemplo de soma simples
    programaSoma(&ram, &cpu);

    // Executa um exemplo de subtração simples
    programaSubtrai(&ram, &cpu);

    // Executa um programa aleatório (opcional)
    // programaAleatorio(&ram, &cpu, 10);

    return 0;
}

void programaSoma(RAM *ram, CPU *cpu) {
    printf("Executando programaSoma()...\n");

    // cria uma RAM com 3 posições
    ram_criar_vazia(ram, 3);

    Instrucao programa[3];

  programa[0].opcode = 0;  // soma
    programa[0].add1 = 0;
    programa[0].add2 = 1;
    programa[0].add3 = 2;

    programa[1].opcode = -1;
    programa[1].add1 = -1;
    programa[1].add2 = -1;
    programa[1].add3 = -1;

    ram_escrever(ram, 0, 7);   // RAM[0] = 7
    ram_escrever(ram, 1, 5);   // RAM[1] = 5

    cpu_set_programa(cpu, programa, 2);
    cpu_iniciar(cpu, ram);

    printf("Resultado da soma: %d\n\n", ram_ler(ram, 2));
}

void programaSubtrai(RAM *ram, CPU *cpu) {
    printf("Executando programaSubtrai()...\n");

    ram_criar_vazia(ram, 3);

    Instrucao programa[3];

    programa[0].opcode = 1;
    programa[0].add1 = 0;
    programa[0].add2 = 1;
    programa[0].add3 = 2;

    programa[1].opcode = -1;
    programa[1].add1 = -1;
    programa[1].add2 = -1;
    programa[1].add3 = -1;

    ram_escrever(ram, 0, 20);  // RAM[0] = 20
    ram_escrever(ram, 1, 8);   // RAM[1] = 8

    cpu_set_programa(cpu, programa, 2);
    cpu_iniciar(cpu, ram);

    printf("Resultado da subtração: %d\n\n", ram_ler(ram, 2));
}

/* programa aleatório: cria instruções SOMAR/SUBTRAIR com endereços aleatório */
void programaAleatorio(RAM *ram, CPU *cpu, int qdeInstrucoes) {
    printf("Executando programaAleatorio() com %d instruções...\n", qdeInstrucoes);

    ram_criar_aleatoria(ram, 100);

    Instrucao *programa = malloc(sizeof(Instrucao) * qdeInstrucoes);
    if (!programa) return;

    for (int i = 0; i < qdeInstrucoes - 1; i++) {
        programa[i].opcode = rand() % 2; // 0 ou 1
        programa[i].add1 = rand() % 100;
        programa[i].add2 = rand() % 100;
        programa[i].add3 = rand() % 100;
    }

    // Última instrução = PARAR
    programa[qdeInstrucoes - 1].opcode = -1;
    programa[qdeInstrucoes - 1].add1 = -1;
    programa[qdeInstrucoes - 1].add2 = -1;
    programa[qdeInstrucoes - 1].add3 = -1;

    cpu_set_programa(cpu, programa, qdeInstrucoes);
    cpu_iniciar(cpu, ram);

    free(programa);
}


