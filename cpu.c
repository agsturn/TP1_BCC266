#include <stdio.h>
#include "instrucao.h"
#include "cpu.h"
#include "ram.h"

void setPrograma(CPU *cpu, Instrucao *programaAux) {
    cpu->programa = programaAux;
}

// Simula a execução das instruções da CPU
void iniciar(CPU *cpu, RAM *ram) {
    cpu->pc = 0;
    cpu->opcode = 0;

    while (1) {
        Instrucao inst = cpu->programa[cpu->pc];
        cpu->opcode = inst.opcode;

        switch (cpu->opcode) {
            case -1: // Fim do programa
                printf("\nFim do programa.\n");
                imprimir(ram);
                return;

            case 0: // SOMA
                setDado(ram, inst.add3, getDado(ram, inst.add1) + getDado(ram, inst.add2));
                break;

            case 1: // SUBTRAÇÃO
                setDado(ram, inst.add3, getDado(ram, inst.add1) - getDado(ram, inst.add2));
                break;
                

            default:
                printf("Opcode desconhecido: %d\n", cpu->opcode);
                return;
        }

        cpu->pc++; // Vai para a próxima instrução
    }
}

// Grupo 10 - Otávio Enrique Lopes de Lima, Ana Gabriela Gomes Lopes Pereira e Heitor Novais Leite de Menezes
