#include <stdio.h>
#include <stdlib.h>
#include "maquina.h"

/* OPCODES:
		//-1 -> halt
		// 0 -> soma
		// 1 -> subtrai
		// 2 -> copia do registrador para RAM
		// 3 -> copia da RAM para o registrador
		// 4 -> salva conteudo externo no registrador
		// 5 -> obtem conteudo externo do registrador
*/

// Declaração das funções dos programas
void programaSoma(RAM *ram, CPU *cpu);
void programaSubtrai(RAM *ram, CPU *cpu);
void programaAleatorio(RAM *ram, CPU *cpu, int qdeInstrucoes);
void programaMultiplica(RAM *ram, CPU *cpu);
void programaDivide(RAM *ram, CPU *cpu);

int main() {
    RAM ram;
    CPU cpu;

    printf("=== Execução dos programas CAVE Language ===\n\n");

    // Executa um exemplo de soma simples
    programaSoma(&ram, &cpu);

    // Executa um exemplo de subtração simples
    programaSubtrai(&ram, &cpu);

    // Executa um programa aleatório
    // programaAleatorio(&ram, &cpu, 10);

    //Executa um exemplo de multiplicacao
    //programaMultiplica(&ram,&cpu);

    //Executa um exemplo de divisao
    //programaDivide(&ram,&cpu);

    return 0;
}


// Programa de SOMA
void programaSoma(RAM *ram, CPU *cpu) {
    printf("Executando programaSoma()...\n");

    criarRAM_vazia(ram, 3); // Cria uma RAM com 3 posições, todas zeradas

    Instrucao programa[3];  // Vetor de instruções

    // Instrução 1: soma RAM[0] + RAM[1] → RAM[2]
    programa[0].opcode = 0;  
    programa[0].add1 = 0;
    programa[0].add2 = 1;
    programa[0].add3 = 2;

    // Instrução 2: fim do programa
    programa[1].opcode = -1;
    programa[1].add1 = -1;
    programa[1].add2 = -1;
    programa[1].add3 = -1;

    // Valores iniciais na RAM
    setDado(ram, 0, 7);   // RAM[0] = 7
    setDado(ram, 1, 5);   // RAM[1] = 5

    // Define o programa e inicia a execução
    setPrograma(cpu, programa);
    iniciar(cpu, ram);

    printf("Resultado da soma: %d\n\n", getDado(ram, 2));
}


// Programa de SUBTRAÇÃO
void programaSubtrai(RAM *ram, CPU *cpu) {
    printf("Executando programaSubtrai()...\n");

    criarRAM_vazia(ram, 3);

    Instrucao programa[3];

    // Instrução: RAM[0] - RAM[1] → RAM[2]
    programa[0].opcode = 1;
    programa[0].add1 = 0;
    programa[0].add2 = 1;
    programa[0].add3 = 2;

    // Fim
    programa[1].opcode = -1;
    programa[1].add1 = -1;
    programa[1].add2 = -1;
    programa[1].add3 = -1;

    setDado(ram, 0, 20);  // RAM[0] = 20
    setDado(ram, 1, 8);   // RAM[1] = 8

    setPrograma(cpu, programa);
    iniciar(cpu, ram);

    printf("Resultado da subtração: %d\n\n", getDado(ram, 2));
}

// Programa ALEATÓRIO
void programaAleatorio(RAM *ram, CPU *cpu, int qdeInstrucoes) {
    printf("Executando programaAleatorio() com %d instruções...\n", qdeInstrucoes);

    criarRAM_aleatoria(ram, 100); // Cria uma RAM com 100 valores aleatórios

    Instrucao *programa = malloc(sizeof(Instrucao) * qdeInstrucoes);
    if (!programa) return;

    // Cria instruções aleatórias de soma ou subtração
    for (int i = 0; i < qdeInstrucoes - 1; i++) {
        programa[i].opcode = rand() % 2; // 0 = soma, 1 = subtrai
        programa[i].add1 = rand() % 100;
        programa[i].add2 = rand() % 100;
        programa[i].add3 = rand() % 100;
    }

    // Última instrução = PARAR
    programa[qdeInstrucoes - 1].opcode = -1;
    programa[qdeInstrucoes - 1].add1 = -1;
    programa[qdeInstrucoes - 1].add2 = -1;
    programa[qdeInstrucoes - 1].add3 = -1;

    setPrograma(cpu, programa);
    iniciar(cpu, ram);

    free(programa);
}

//Programa MULTIPLICACAO
void programaMultiplica(RAM *ram, CPU *cpu) {
    printf("Executando programaMultiplica()...\n");

    criarRAM_vazia(ram, 3);

    Instrucao programa[3];

    // RAM[0] * RAM[1] -> RAM[2]
    programa[0].opcode = 6;// olhar se pode criar novos opcodes
    programa[0].add1 = 0;
    programa[0].add2 = 1;
    programa[0].add3 = 2;

    programa[1].opcode = -1;

    setDado(ram, 0, 4);
    setDado(ram, 1, 3);

    setPrograma(cpu, programa);
    iniciar(cpu, ram);

    printf("Resultado da multiplicação: %d\n\n", getDado(ram, 2));
}

//Programa DIVISAO
void programaDivide(RAM *ram, CPU *cpu) {
    printf("Executando programaDivide()...\n");

    criarRAM_vazia(ram, 3);

    Instrucao programa[3];

    // RAM[0] / RAM[1] -> RAM[2]
    programa[0].opcode = 7;//olhar isso
    programa[0].add1 = 0;
    programa[0].add2 = 1;
    programa[0].add3 = 2;

    programa[1].opcode = -1;

    setDado(ram, 0, 12);
    setDado(ram, 1, 3);

    setPrograma(cpu, programa);
    iniciar(cpu, ram);

    printf("Resultado da divisao: %d\n\n", getDado(ram, 2));
}


// Grupo 10 - Otávio Enrique Lopes de Lima,Ana Gabriela Gomes Lopes Pereira e Heitor Novais Leite de Menezes
