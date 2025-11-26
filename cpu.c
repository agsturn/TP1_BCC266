#include "cpu.h"
#include "ram.h"
#include "instrucao.h"
#include <stdio.h>

/* OPCODES:
    -1 -> halt
     0 -> soma
     1 -> subtrai
     2 -> copia do registrador para RAM
     3 -> copia da RAM para o registrador
     4 -> salva conteudo externo no registrador
     5 -> obtem conteudo do registrador para RAM
*/

// Define o programa da CPU
void setPrograma(CPU *cpu, Instrucao *programaAux) {
    cpu->programa = programaAux;
}

// Simula a execução das instruções da CPU
void iniciar(CPU *cpu, RAM *ram) {
    cpu->pc = 0;
    cpu->opcode = 0;

    while (1) {
        Instrucao *inst = &cpu->programa[cpu->pc]; // ponteiro para a instrução atual
        cpu->opcode = inst->opcode;

        switch (cpu->opcode) {
            case -1: // Fim do programa
                printf("\nFim do programa.\n");
                imprimir(ram);
                return;

            case 0: // SOMA
                cpu->registrador1 = getDado(ram, inst->add1);
                cpu->registrador2 = getDado(ram, inst->add2);
                cpu->registrador1 += cpu->registrador2;
                setDado(ram, inst->add3, cpu->registrador1);
                printf("SOMA: RAM[%d] = RAM[%d] + RAM[%d] -> %d\n",
                       inst->add3, inst->add1, inst->add2, getDado(ram, inst->add3));
                break;

            case 1: // SUBTRAÇÃO
                cpu->registrador1 = getDado(ram, inst->add1);
                cpu->registrador2 = getDado(ram, inst->add2);
                cpu->registrador1 -= cpu->registrador2;
                setDado(ram, inst->add3, cpu->registrador1);
                printf("SUB: RAM[%d] = RAM[%d] - RAM[%d] -> %d\n",
                       inst->add3, inst->add1, inst->add2, getDado(ram, inst->add3));
                break;

            case 2: // COPIA REGISTRADOR -> RAM
                if (inst->add1 == 0) {
                    setDado(ram, inst->add2, cpu->registrador1);
                    printf("COPY_REG_RAM: RAM[%d] = Registrador1 -> %d\n", inst->add2, cpu->registrador1);
                } else if (inst->add1 == 1) {
                    setDado(ram, inst->add2, cpu->registrador2);
                    printf("COPY_REG_RAM: RAM[%d] = Registrador2 -> %d\n", inst->add2, cpu->registrador2);
                }
                break;

            case 3: // COPIA RAM -> REGISTRADOR
                if (inst->add1 == 0) {
                    cpu->registrador1 = getDado(ram, inst->add2);
                    printf("COPY_RAM_REG: Registrador1 = RAM[%d] -> %d\n", inst->add2, cpu->registrador1);
                } else if (inst->add1 == 1) {
                    cpu->registrador2 = getDado(ram, inst->add2);
                    printf("COPY_RAM_REG: Registrador2 = RAM[%d] -> %d\n", inst->add2, cpu->registrador2);
                }
                break;
            
            case 4: // COPIA VALOR EXTERNO -> REGISTRADOR
                if (inst->add1 == 0) {
                    cpu->registrador1 = inst->add2;
                    printf("COPY_EXT_REG: Registrador1 = %d\n", cpu->registrador1);
                } else if (inst->add1 == 1) {
                    cpu->registrador2 = inst->add2;
                    printf("COPY_EXT_REG: Registrador2 = %d\n", cpu->registrador2);
                }
                break;

            case 5: // OBTER REGISTRADOR -> RAM
                if (inst->add1 == 0) {
                    setDado(ram, inst->add2, cpu->registrador1);
                    printf("OBTAIN_REG: RAM[%d] = Registrador1 -> %d\n", inst->add2, cpu->registrador1);
                } else if (inst->add1 == 1) {
                    setDado(ram, inst->add2, cpu->registrador2);
                    printf("OBTAIN_REG: RAM[%d] = Registrador2 -> %d\n", inst->add2, cpu->registrador2);
                }
                break;

            default:
                printf("Opcode desconhecido: %d\n", cpu->opcode);
                return;
        }

        cpu->pc++; // Próxima instrução
    }
}

void destruirCPU(CPU* cpu){
    free(cpu);
}

// Grupo 10 - Otávio Enrique Lopes de Lima, Ana Gabriela Gomes Lopes Pereira e Heitor Novais Leite de Menezes
