#ifndef CPU_H
#define CPU_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "instrucao.h"
#include "ram.h"

typedef struct {
    int registrador1;
    int registrador2;
    int pc;             // Contador de programa
    int opcode;         // Último opcode executado
    Instrucao *programa; // Ponteiro para o conjunto de instruções
} CPU;

void setPrograma(CPU *cpu, Instrucao *programaAux);
void iniciar(CPU *cpu, RAM *ram);

#endif

// Grupo 10 - Otávio Enrique Lopes de Lima, Ana Gabriela Gomes Lopes Pereira e Heitor Novais Leite de Menezes
