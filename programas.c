#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maquina.h"

/* OPCODES:
    -1 -> halt
     0 -> soma
     1 -> subtrai
     2 -> copia do registrador para RAM
     3 -> copia da RAM para o registrador
     4 -> salva conteudo externo no registrador
     5 -> obtem conteudo do registrador
*/

// Declaração das funções dos programas
void programaSoma(RAM *ram, CPU *cpu);
void programaSubtrai(RAM *ram, CPU *cpu);
void programaAleatorio(RAM *ram, CPU *cpu, int qdeInstrucoes);
void programaMultiplica(RAM *ram, CPU *cpu, int multiplicando, int multiplicador);
void programaDivide(RAM *ram, CPU *cpu, int dividendo, int divisor);
void programaRestoDivisao(RAM *ram, CPU *cpu, int dividendo, int divisor);
void programaRaizQuadrada(RAM *ram, CPU *cpu, int radicando);
void programaFatorial(RAM *ram, CPU *cpu, int numero);
void programaPotencia(RAM *ram, CPU *cpu, int base, int expoente);
void programaFibonacci(RAM *ram, CPU *cpu, int n);
void programaCapslock(RAM *ram, CPU *cpu, char *texto);
void programaMedia(RAM *ram, CPU *cpu, int tamanhoVetor);
void programaPorcentagem(RAM *ram, CPU *cpu, int valor, int porcentagem);
void programaMdc(RAM *ram, CPU *cpu, int a, int b);
void programaMmc(RAM *ram, CPU *cpu, int a, int b);
void programaBhaskara(RAM *ram, CPU *cpu, int a, int b, int c);
void programaSomaTres(RAM *ram, CPU *cpu, int a, int b, int c);
void programaFormulaHeron(RAM *ram, CPU *cpu, int a, int b, int c);
void programaOR(RAM *ram, CPU *cpu, int a, int b);

int main() {
    RAM ram;
    CPU cpu;

    printf("=== Execução dos programas CAVE Language ===\n\n");
    
    // Executa um exemplo de soma simples
    // programaSoma(&ram, &cpu);

    // Executa um exemplo de subtração simples
    // programaSubtrai(&ram, &cpu);

    // Executa um programa aleatório
    // programaAleatorio(&ram, &cpu, 10);

    // Executa um exemplo de multiplicação 
    // programaMultiplica(&ram, &cpu, 19, 23);

    // Executa um exemplo de divisão
    // programaDivide(&ram, &cpu, 500, 3);

    // Calcula resto de divisão
    // programaRestoDivisao(&ram, &cpu, 101, 5);

    // Executa um exemplo de raíz quadrada
    // programaRaizQuadrada(&ram, &cpu, 169);

    // Executa um exemplo de fatorial
    // programaFatorial(&ram, &cpu, 5);
    
    // Executa um exemplo de potencia
    //programaPotencia(&ram, &cpu, 3, 4);
    
    // Executa um exemplo de fibonacci
    //programaFibonacci(&ram, &cpu, 8);
    
    // Executa um exemplo de capslock
    // programaCapslock(&ram, &cpu, "eXemPLo");

    // Executa a média de valores gerados aleatoriamente em um vetor 
    // programaMedia(&ram, &cpu, 5);

    // Executa um exemplo de porcentagem
    // programaPorcentagem(&ram, &cpu, 200, 50);

    //Executa um exemplo de mdc
    // deu merda programaMdc(&ram,&cpu, 36,44);

    //Execute um exemplo de mmc
    // deu merda programaMmc(&ram,&cpu,36,44);

    //Execute um exemplo de bhaskara
    // programaBhaskara(&ram,&cpu, 2 ,3,-5);

    // Executa um exemplo de soma de três números
    // programaSomaTres(&ram, &cpu, 1, 2, 3);

    //Calcula a área de um triângulo a partir da fórmula de Heron a partir do comprimento dos lados
    programaFormulaHeron(&ram, &cpu, 3, 4, 5);

    // Executa um exemplo da função OR
    // programaOR(&ram, &cpu, 0, 1);

    free(ram.memoria);

    return 0;
}

// Programa de SOMA
void programaSoma(RAM *ram, CPU *cpu) {
    printf("Executando programaSoma()...\n");

    criarRAM_vazia(ram, 4); // Cria uma RAM com 4 posições

    // Valores iniciais na RAM
    setDado(ram, 0, 7);   // RAM[0] = 7
    setDado(ram, 1, 5);   // RAM[1] = 5
    setDado(ram, 2, 0);   // RAM[2] = resultado
    setDado(ram, 3, 10);  // RAM[3] = constante (não usada)

    Instrucao programa[3];

    // Instrução 1: COPIA RAM[0] -> REGISTRADOR1
    programa[0].opcode = 3;
    programa[0].add1 = 0;
    programa[0].add2 = 0;

    // Instrução 2: COPIA RAM[1] -> REGISTRADOR2
    programa[1].opcode = 3;
    programa[1].add1 = 1;
    programa[1].add2 = 1;

    // Instrução 3: SOMA REGISTRADOR1 + REGISTRADOR2 -> RAM[2]
    programa[2].opcode = 0;
    programa[2].add1 = 0;
    programa[2].add2 = 1;
    programa[2].add3 = 2;

    // Instrução 4: HALT
    programa[3].opcode = -1;
    programa[3].add1 = -1;
    programa[3].add2 = -1;
    programa[3].add3 = -1;

    // Define o programa e inicia a execução
    setPrograma(cpu, programa);
    iniciar(cpu, ram);

    printf("Resultado da soma: %d\n\n", getDado(ram, 2));
}

// Programa de SUBTRAÇÃO
void programaSubtrai(RAM *ram, CPU *cpu) {
    printf("Executando programaSubtrai()...\n");

    criarRAM_vazia(ram, 4);

    // Valores iniciais
    setDado(ram, 0, 20);  // RAM[0] = 20
    setDado(ram, 1, 8);   // RAM[1] = 8
    setDado(ram, 2, 0);   // RAM[2] = resultado

    Instrucao programa[4];

    // COPIA RAM[0] -> REGISTRADOR1
    programa[0].opcode = 3;
    programa[0].add1 = 0;
    programa[0].add2 = 0;

    // COPIA RAM[1] -> REGISTRADOR2
    programa[1].opcode = 3;
    programa[1].add1 = 1;
    programa[1].add2 = 1;

    // SUBTRAI REGISTRADOR1 - REGISTRADOR2 -> RAM[2]
    programa[2].opcode = 1;
    programa[2].add1 = 0;
    programa[2].add2 = 1;
    programa[2].add3 = 2;

    // HALT
    programa[3].opcode = -1;
    programa[3].add1 = -1;
    programa[3].add2 = -1;
    programa[3].add3 = -1;

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

//Programa que multiplica dois números inteiros
void programaMultiplica(RAM *ram, CPU *cpu, int multiplicando, int multiplicador){

    criarRAM_vazia(ram, 2);
    
    Instrucao trecho1[3];
    Instrucao inst1, inst2, inst3, inst4;

    inst1.opcode = 4;
    inst1.add1 = 0;
    inst1.add2 = multiplicando;
    inst1.add3 = -1;

    inst2.opcode = 2;
    inst2.add1 = 0;
    inst2.add2 = 0;
    inst2.add3 = -1;

    inst3.opcode = 2;
    inst3.add1 = 0;
    inst3.add2 = 1;
    inst3.add3 = -1;

    inst4.opcode = -1;
    inst4.add1 = -1;
    inst4.add2 = -1;
    inst4.add3 = -1;

    trecho1[0] = inst1;
    trecho1[1] = inst2;
    trecho1[2] = inst3;
    trecho1[3] = inst4;

    setPrograma(cpu, trecho1);
    iniciar(cpu, ram);

    Instrucao trecho2[2];
    Instrucao inst6, inst7;

    inst6.opcode = 0;
    inst6.add1 = 0;
    inst6.add2 = 1;
    inst6.add3 = 0;

    inst7.opcode = -1;
    inst7.add1 = -1;
    inst7.add2 = -1;
    inst7.add3 = -1;

    trecho2[0] = inst6;
    trecho2[1] = inst7;

    for(int i = 1; i < multiplicador; i++){
        setPrograma(cpu, trecho2);
        iniciar(cpu, ram);
    }

    Instrucao trecho3[3];
    Instrucao inst8, inst9, inst10;

    inst8.opcode = 4;
    inst8.add1 = 1;
    inst8.add2 = multiplicador;
    inst8.add3 = -1;

    inst9.opcode = 3;
    inst9.add1 = 0;
    inst9.add2 = 0;
    inst9.add3 = -1;

    inst10.opcode = -1;
    inst10.add1 = -1;
    inst10.add2 = -1;
    inst10.add3 = -1;

    trecho3[0] = inst8;
    trecho3[1] = inst9;
    trecho3[2] = inst10;

    setPrograma(cpu, trecho3);
    iniciar(cpu, ram);

    printf("\nResultado da multiplicacao: %d\n", cpu->registrador1);
}

//Programa que mostra a parte inteira da divisão de dois números inteiros
void programaDivide(RAM *ram, CPU *cpu, int dividendo, int divisor){

    criarRAM_vazia(ram, 4);

    Instrucao trecho1[9];
    Instrucao inst1, inst2, inst3, inst4, inst5, inst6, inst7, inst8, inst9;

    inst1.opcode = 4;
    inst1.add1 = 0;
    inst1.add2 = dividendo;
    inst1.add3 = -1;

    inst2.opcode = 4;
    inst2.add1 = 1;
    inst2.add2 = divisor;
    inst2.add3 = -1;

    inst3.opcode = 2;
    inst3.add1 = 0;
    inst3.add2 = 0;
    inst3.add3 = -1;

    inst4.opcode = 2;
    inst4.add1 = 1;
    inst4.add2 = 1;
    inst4.add3 = -1;

    inst5.opcode = 4;
    inst5.add1 = 0;
    inst5.add2 = 0;
    inst5.add3 = -1;

    inst6.opcode = 2;
    inst6.add1 = 0;
    inst6.add2 = 2;
    inst6.add3 = -1;

    inst7.opcode = 4;
    inst7.add1 = 1;
    inst7.add2 = 1;
    inst7.add3 = -1;

    inst8.opcode = 2;
    inst8.add1 = 1;
    inst8.add2 = 3;
    inst8.add3 = -1;
    
    inst9.opcode = -1;
    inst9.add1 = -1;
    inst9.add2 = -1;
    inst9.add3 = -1;

    trecho1[0] = inst1;
    trecho1[1] = inst2;
    trecho1[2] = inst3;
    trecho1[3] = inst4;
    trecho1[4] = inst5;
    trecho1[5] = inst6;
    trecho1[6] = inst7;
    trecho1[7] = inst8;
    trecho1[8] = inst9;

    setPrograma(cpu, trecho1);
    iniciar(cpu, ram);

    Instrucao trecho2[2];
    Instrucao inst10, inst11, inst12;

    inst10.opcode = 3;
    inst10.add1 = 0;
    inst10.add2 = 0;
    inst10.add3 = -1;

    inst11.opcode = 3;
    inst11.add1 = 1;
    inst11.add2 = 1;
    inst11.add3 = -1;

    inst12.opcode = -1;
    inst12.add1 = -1;
    inst12.add2 = -1;
    inst12.add3 = -1;

    trecho2[0] = inst10;
    trecho2[1] = inst11;
    trecho2[2] = inst12;

    setPrograma(cpu, trecho2);
    iniciar(cpu, ram);

    Instrucao trecho3[5];
    Instrucao inst13, inst14, inst15, inst16, inst17;

    inst13.opcode = 1;
    inst13.add1 = 0;
    inst13.add2 = 1;
    inst13.add3 = 0;

    inst14.opcode = 0;
    inst14.add1 = 2;
    inst14.add2 = 3;
    inst14.add3 = 2;
    
    inst15.opcode = 3;
    inst15.add1 = 0;
    inst15.add2 = 0;
    inst15.add3 = -1;

    inst16.opcode = 3;
    inst16.add1 = 1;
    inst16.add2 = 1;
    inst16.add3 = -1;

    inst17.opcode = -1;
    inst17.add1 = -1;
    inst17.add2 = -1;
    inst17.add3 = -1;

    trecho3[0] = inst13;
    trecho3[1] = inst14;
    trecho3[2] = inst15;
    trecho3[3] = inst16;
    trecho3[4] = inst17;

    while(cpu->registrador1 >= cpu->registrador2){
        setPrograma(cpu, trecho3);
        iniciar(cpu, ram);
    }
    
    Instrucao trecho4[2];
    Instrucao inst18, inst19;

    inst18.opcode = 3;
    inst18.add1 = 0;
    inst18.add2 = 2;
    inst18.add3 = -1;

    inst19.opcode = -1;
    inst19.add1 = -1;
    inst19.add2 = -1;
    inst19.add3 = -1;

    trecho4[0] = inst18;
    trecho4[1] = inst19;

    setPrograma(cpu, trecho4);
    iniciar(cpu, ram);

    printf("\nResultado da divisao: %d\n", cpu->registrador1);

}

//Programa que calcula o resto da divisão de dois números inteiros
void programaRestoDivisao(RAM *ram, CPU *cpu, int dividendo, int divisor){

    criarRAM_vazia(ram, 2);

    Instrucao trecho1[5];
    Instrucao inst1, inst2, inst3, inst4, inst5;

    inst1.opcode = 4;
    inst1.add1 = 0;
    inst1.add2 = dividendo;
    inst1.add3 = -1;

    inst2.opcode = 4;
    inst2.add1 = 1;
    inst2.add2 = divisor;
    inst2.add3 = -1;

    inst3.opcode = 2;
    inst3.add1 = 0;
    inst3.add2 = 0;
    inst3.add3 = -1;

    inst4.opcode = 2;
    inst4.add1 = 1;
    inst4.add2 = 1;
    inst4.add3 = -1;

    inst5.opcode = -1;
    inst5.add1 = -1;
    inst5.add2 = -1;
    inst5.add3 = -1;

    trecho1[0] = inst1;
    trecho1[1] = inst2;
    trecho1[2] = inst3;
    trecho1[3] = inst4;
    trecho1[4] = inst5;

    setPrograma(cpu, trecho1);
    iniciar(cpu, ram);

    Instrucao trecho2[2];
    Instrucao inst6, inst7, inst8;

    inst6.opcode = 3;
    inst6.add1 = 0;
    inst6.add2 = 0;
    inst6.add3 = -1;

    inst7.opcode = 3;
    inst7.add1 = 1;
    inst7.add2 = 1;
    inst7.add3 = -1;

    inst8.opcode = -1;
    inst8.add1 = -1;
    inst8.add2 = -1;
    inst8.add3 = -1;

    trecho2[0] = inst6;
    trecho2[1] = inst7;
    trecho2[2] = inst8;

    setPrograma(cpu, trecho2);
    iniciar(cpu, ram);

    Instrucao trecho3[4];
    Instrucao inst9, inst10, inst11, inst12;

    inst9.opcode = 1;
    inst9.add1 = 0;
    inst9.add2 = 1;
    inst9.add3 = 0;

    inst10.opcode = 3;
    inst10.add1 = 0;
    inst10.add2 = 0;
    inst10.add3 = -1;

    inst11.opcode = 3;
    inst11.add1 = 1;
    inst11.add2 = 1;
    inst11.add3 = -1;

    inst12.opcode = -1;
    inst12.add1 = -1;
    inst12.add2 = -1;
    inst12.add3 = -1;

    trecho3[0] = inst9;
    trecho3[1] = inst10;
    trecho3[2] = inst11;
    trecho3[3] = inst12;

    while(cpu->registrador1 >= cpu->registrador2){
        setPrograma(cpu, trecho3);
        iniciar(cpu, ram);
    }

    Instrucao trecho4[2];
    Instrucao inst13, inst14;

    inst13.opcode = 3;
    inst13.add1 = 0;
    inst13.add2 = 0;
    inst13.add3 = -1;

    inst14.opcode = -1;
    inst14.add1 = -1;
    inst14.add2 = -1;
    inst14.add3 = -1;

    trecho4[0] = inst13;
    trecho4[1] = inst14;

    setPrograma(cpu, trecho4);
    iniciar(cpu, ram);

    printf("\nResto da divisao: %d\n", cpu->registrador1);
}

//Calcula a raíz quadrada
void programaRaizQuadrada(RAM *ram, CPU *cpu, int radicando){

    criarRAM_vazia(ram, 1);

    Instrucao trecho1[3];
    Instrucao inst1, inst2, inst3;

    inst1.opcode = 4;
    inst1.add1 = 0;
    inst1.add2 = 0;
    inst1.add3 = -1;

    inst2.opcode = 4;
    inst2.add1 = 1;
    inst2.add2 = 1;
    inst2.add3 = -1;

    inst3.opcode = -1;
    inst3.add1 = -1;
    inst3.add2 = -1;
    inst3.add3 = -1;

    trecho1[0] = inst1;
    trecho1[1] = inst2;
    trecho1[2] = inst3;

    setPrograma(cpu, trecho1);
    iniciar(cpu, ram);

    free(ram->memoria);

    while(cpu->registrador1 <= radicando){

        programaMultiplica(ram, cpu, cpu->registrador2, cpu->registrador2);
        free(ram->memoria);

        criarRAM_vazia(ram, 3);

        Instrucao trecho2[6];
        Instrucao inst6, inst7, inst8, inst9, inst10;

        inst6.opcode = 2;
        inst6.add1 = 0;
        inst6.add2 = 0;
        inst6.add3 = -1;

        inst7.opcode = 2;
        inst7.add1 = 1;
        inst7.add2 = 1;
        inst7.add3 = -1;

        inst8.opcode = 4;
        inst8.add1 = 0;
        inst8.add2 = 1;
        inst8.add3 = -1;

        inst9.opcode = 2;
        inst9.add1 = 0;
        inst9.add2 = 2;
        inst9.add3 = -1;
        
        inst10.opcode = -1;
        inst10.add1 = -1;
        inst10.add2 = -1;
        inst10.add3 = -1;

        trecho2[0] = inst6;
        trecho2[1] = inst7;
        trecho2[2] = inst8;
        trecho2[3] = inst9;
        trecho2[4] = inst10;

        setPrograma(cpu, trecho2);
        iniciar(cpu, ram);

        Instrucao trecho3[5];
        Instrucao inst11, inst12, inst13, inst14;

        inst11.opcode = 0;
        inst11.add1 = 1;
        inst11.add2 = 2;
        inst11.add3 = 1;

        inst12.opcode = 3;
        inst12.add1 = 1;
        inst12.add2 = 1;
        inst12.add3 = -1;

        inst13.opcode = 3;
        inst13.add1 = 0;
        inst13.add2 = 0;
        inst13.add3 = -1;

        inst14.opcode = -1;
        inst14.add1 = -1;
        inst14.add2 = -1;
        inst14.add3 = -1;

        trecho3[0] = inst11;
        trecho3[1] = inst12;
        trecho3[2] = inst13;
        trecho3[3] = inst14;

        setPrograma(cpu, trecho3);
        iniciar(cpu, ram);

        free(ram->memoria);
    }
    
    criarRAM_vazia(ram, 2);

    Instrucao trecho4[7];
    Instrucao inst15, inst16, inst17, inst18, inst19, inst20, inst21;

    inst15.opcode = 2;
    inst15.add1 = 1;
    inst15.add2 = 0;
    inst15.add3 = -1;

    inst16.opcode = 4;
    inst16.add1 = 1;
    inst16.add2 = 1;
    inst16.add3 = -1;

    inst17.opcode = 2;
    inst17.add1 = 1;
    inst17.add2 = 1;
    inst17.add3 = -1;

    inst18.opcode = 1;
    inst18.add1 = 0;
    inst18.add2 = 1;
    inst18.add3 = 0;

    inst19.opcode = 1;
    inst19.add1 = 0;
    inst19.add2 = 1;
    inst19.add3 = 0;

    inst20.opcode = 3;
    inst20.add1 = 0;
    inst20.add2 = 0;
    inst20.add3 = -1;

    inst21.opcode = -1;
    inst21.add1 = -1;
    inst21.add2 = -1;
    inst21.add3 = -1;

    trecho4[0] = inst15;
    trecho4[1] = inst16;
    trecho4[2] = inst17;
    trecho4[3] = inst18;
    trecho4[4] = inst19;
    trecho4[5] = inst20;
    trecho4[6] = inst21;

    setPrograma(cpu, trecho4);
    iniciar(cpu, ram);
    
    printf("\nResultado da raiz quadrada: %d\n", cpu->registrador1);
}

// PROGRAMA DE FATORIAL
void programaFatorial(RAM *ram, CPU *cpu, int numero) {
    printf("Executando programaFatorial(%d)...\n", numero);

    criarRAM_vazia(ram, 6);
    // RAM[0] = número base
    // RAM[1] = contador
    // RAM[2] = resultado parcial
    // RAM[3] = auxiliar para multiplicação
    // RAM[4] = 1 (constante)
    // RAM[5] = temporário

    setDado(ram, 0, numero);
    setDado(ram, 1, 1);      // contador = 1
    setDado(ram, 2, 1);      // resultado = 1
    setDado(ram, 4, 1);      // constante 1

    Instrucao programa[8];

    // Enquanto contador <= número
    while (getDado(ram, 1) <= getDado(ram, 0)) {
        // Multiplica resultado * contador usando somas sucessivas
        setDado(ram, 3, 0); // Zera auxiliar
        
        // Loop de multiplicação (resultado * contador)
        for (int i = 0; i < getDado(ram, 1); i++) {
            // COPIA RAM[2] -> REGISTRADOR1
            programa[0].opcode = 3;
            programa[0].add1 = 0;
            programa[0].add2 = 2;
            
            // COPIA RAM[3] -> REGISTRADOR2
            programa[1].opcode = 3;
            programa[1].add1 = 1;
            programa[1].add2 = 3;
            
            // SOMA REGISTRADOR1 + REGISTRADOR2 -> RAM[3]
            programa[2].opcode = 0;
            programa[2].add1 = 0;
            programa[2].add2 = 1;
            programa[2].add3 = 3;
            
            // HALT
            programa[3].opcode = -1;
            
            setPrograma(cpu, programa);
            iniciar(cpu, ram);
        }

        // Atualiza resultado: RAM[2] = RAM[3]
        // COPIA RAM[3] -> REGISTRADOR1
        programa[0].opcode = 3;
        programa[0].add1 = 0;
        programa[0].add2 = 3;
        
        // COPIA REGISTRADOR1 -> RAM[2]
        programa[1].opcode = 2;
        programa[1].add1 = 0;
        programa[1].add2 = 2;
        
        programa[2].opcode = -1;
        setPrograma(cpu, programa);
        iniciar(cpu, ram);

        // Incrementa contador: RAM[1] = RAM[1] + 1
        // COPIA RAM[1] -> REGISTRADOR1
        programa[0].opcode = 3;
        programa[0].add1 = 0;
        programa[0].add2 = 1;
        
        // COPIA RAM[4] -> REGISTRADOR2
        programa[1].opcode = 3;
        programa[1].add1 = 1;
        programa[1].add2 = 4;
        
        // SOMA REGISTRADOR1 + REGISTRADOR2 -> RAM[1]
        programa[2].opcode = 0;
        programa[2].add1 = 0;
        programa[2].add2 = 1;
        programa[2].add3 = 1;
        
        programa[3].opcode = -1;
        
        setPrograma(cpu, programa);
        iniciar(cpu, ram);
    }

    printf("Fatorial de %d = %d\n", numero, getDado(ram, 2));
}

// PROGRAMA DE POTÊNCIA
void programaPotencia(RAM *ram, CPU *cpu, int base, int expoente) {
    printf("Executando programaPotencia(%d, %d)...\n", base, expoente);

    criarRAM_vazia(ram, 6);
    // RAM[0] = base
    // RAM[1] = expoente
    // RAM[2] = resultado parcial
    // RAM[3] = auxiliar para multiplicação
    // RAM[4] = 1 (constante)
    // RAM[5] = temporário

    setDado(ram, 0, base);
    setDado(ram, 1, expoente);
    setDado(ram, 2, 1); // resultado começa em 1
    setDado(ram, 4, 1); // constante 1

    Instrucao programa[8];

    // Enquanto expoente > 0
    while (getDado(ram, 1) > 0) {
        setDado(ram, 3, 0); // limpa auxiliar

        // Multiplica resultado * base (por somas sucessivas)
        for (int i = 0; i < getDado(ram, 0); i++) {
            // COPIA RAM[2] -> REGISTRADOR1
            programa[0].opcode = 3;
            programa[0].add1 = 0;
            programa[0].add2 = 2;
            
            // COPIA RAM[3] -> REGISTRADOR2
            programa[1].opcode = 3;
            programa[1].add1 = 1;
            programa[1].add2 = 3;
            
            // SOMA REGISTRADOR1 + REGISTRADOR2 -> RAM[3]
            programa[2].opcode = 0;
            programa[2].add1 = 0;
            programa[2].add2 = 1;
            programa[2].add3 = 3;
            
            programa[3].opcode = -1;
            
            setPrograma(cpu, programa);
            iniciar(cpu, ram);
        }

        // Atualiza resultado: RAM[2] = RAM[3]
        // COPIA RAM[3] -> REGISTRADOR1
        programa[0].opcode = 3;
        programa[0].add1 = 0;
        programa[0].add2 = 3;
        
        // COPIA REGISTRADOR1 -> RAM[2]
        programa[1].opcode = 2;
        programa[1].add1 = 0;
        programa[1].add2 = 2;
        
        programa[2].opcode = -1;
        setPrograma(cpu, programa);
        iniciar(cpu, ram);

        // Decrementa expoente: RAM[1] = RAM[1] - 1
        // COPIA RAM[1] -> REGISTRADOR1
        programa[0].opcode = 3;
        programa[0].add1 = 0;
        programa[0].add2 = 1;
        
        // COPIA RAM[4] -> REGISTRADOR2
        programa[1].opcode = 3;
        programa[1].add1 = 1;
        programa[1].add2 = 4;
        
        // SUBTRAI REGISTRADOR1 - REGISTRADOR2 -> RAM[1]
        programa[2].opcode = 1;
        programa[2].add1 = 0;
        programa[2].add2 = 1;
        programa[2].add3 = 1;
        
        programa[3].opcode = -1;
        
        setPrograma(cpu, programa);
        iniciar(cpu, ram);
    }

    printf("Resultado da potencia: %d^%d = %d\n", base, expoente, getDado(ram, 2));
}

// PROGRAMA DE FIBONACCI
void programaFibonacci(RAM *ram, CPU *cpu, int n) {
    printf("Executando programaFibonacci(%d)...\n", n);

    criarRAM_vazia(ram, 6);

    // RAM[0] = quantidade de termos
    // RAM[1] = termo anterior
    // RAM[2] = termo atual
    // RAM[3] = próximo termo
    // RAM[4] = contador
    // RAM[5] = constante 1

    setDado(ram, 0, n);
    setDado(ram, 1, 0); // termo 0
    setDado(ram, 2, 1); // termo 1
    setDado(ram, 4, 2); // contador
    setDado(ram, 5, 1);

    printf("Sequência de Fibonacci (%d termos):\n", n);
    printf("%d %d ", getDado(ram, 1), getDado(ram, 2));

    // Array fixo e seguro de instruções
    Instrucao prog[4];

    while (getDado(ram, 4) < n) {

        //próximo = anterior + atual
        prog[0] = (Instrucao){3, 0, 1, 0}; // RAM[1] -> R1
        prog[1] = (Instrucao){3, 1, 2, 0}; // RAM[2] -> R2
        prog[2] = (Instrucao){0, 0, 1, 3}; // soma -> RAM[3]
        prog[3] = (Instrucao){-1, 0, 0, 0};

        setPrograma(cpu, prog);
        iniciar(cpu, ram);

        printf("%d ", getDado(ram, 3));

        // anterior = atual
        // atual = próximo
        prog[0] = (Instrucao){3, 0, 2, 0}; // RAM[2] -> R1
        prog[1] = (Instrucao){2, 0, 1, 0}; // R1 -> RAM[1]
        prog[2] = (Instrucao){3, 0, 3, 0}; // RAM[3] -> R1
        prog[3] = (Instrucao){2, 0, 2, 0}; // R1 -> RAM[2]

        setPrograma(cpu, prog);
        iniciar(cpu, ram);

        //contador++
        prog[0] = (Instrucao){3, 0, 4, 0}; // RAM[4] -> R1
        prog[1] = (Instrucao){3, 1, 5, 0}; // RAM[5] -> R2
        prog[2] = (Instrucao){0, 0, 1, 4}; // soma -> RAM[4]
        prog[3] = (Instrucao){-1, 0, 0, 0};

        setPrograma(cpu, prog);
        iniciar(cpu, ram);
    }

    printf("\n");
}


// Executa a média de valores gerados aleatoriamente em um vetor 
void programaMedia(RAM *ram, CPU *cpu, int tamanhoVetor){
    criarRAM_aleatoria(ram, tamanhoVetor + 4);

    Instrucao trecho1[2], inst1, inst2;
    setDado(ram, 0, 0);
    
    inst2.opcode = -1;
    inst2.add1 = -1;
    inst2.add2 = -1;
    inst2.add3 = -1;
    trecho1[1] = inst2;

    for(int i = 4; i < tamanhoVetor + 4; i++){
        inst1.opcode = 0;
        inst1.add1 = 0;
        inst1.add2 = i;
        inst1.add3 = 0;
        trecho1[0] = inst1;
        setPrograma(cpu, trecho1);
        iniciar(cpu, ram);
    }

    setDado(ram, 1, tamanhoVetor);
    setDado(ram, 2, 0);
    setDado(ram, 3, 1);

    Instrucao trecho2[3];
    Instrucao inst3, inst4, inst5;

    inst3.opcode = 1;
    inst3.add1 = 0;
    inst3.add2 = 1;
    inst3.add3 = 0;

    inst4.opcode = 0;
    inst4.add1 = 2;
    inst4.add2 = 3;
    inst4.add3 = 2;

    inst5.opcode = -1;
    inst5.add1 = -1;
    inst5.add2 = -1;
    inst5.add3 = -1;

    trecho2[0] = inst3;
    trecho2[1] = inst4;
    trecho2[2] = inst5;

    while(getDado(ram, trecho2[0].add1) >= getDado(ram, trecho2[0].add2)){
        setPrograma(cpu, trecho2);
        iniciar(cpu, ram);
    }

    Instrucao inst6;
    inst6.add1 = getDado(ram, trecho2[1].add3);

    printf("\nA média eh: %d\n", inst6.add1);

}

void programaPorcentagem(RAM *ram, CPU *cpu, int valor, int porcentagem){

    criarRAM_vazia(ram, 5);

    Instrucao inst0;

    inst0.add1 = valor;
    
    setDado(ram, 0, 0);
    setDado(ram, 1, porcentagem);

    Instrucao trecho1[2];
    Instrucao inst1, inst2;

    inst1.opcode = 0;
    inst1.add1 = 0;
    inst1.add2 = 1;
    inst1.add3 = 0;

    inst2.opcode = -1;
    inst2.add1 = -1;
    inst2.add2 = -1;
    inst2.add3 = -1;

    trecho1[0] = inst1;
    trecho1[1] = inst2;

    for(int i = 0; i < valor; i++){
        setPrograma(cpu, trecho1);
        iniciar(cpu, ram);
    }

    printf("Multiplicação: %d", getDado(ram, inst1.add3));

    setDado(ram, 2, 100);
    setDado(ram, 3, 0);
    setDado(ram, 4, 1);

    Instrucao trecho2[3];
    Instrucao inst3, inst4, inst5;

    inst3.opcode = 1;
    inst3.add1 = 0;
    inst3.add2 = 2;
    inst3.add3 = 0;

    inst4.opcode = 0;
    inst4.add1 = 3;
    inst4.add2 = 4;
    inst4.add3 = 3;

    inst5.opcode = -1;
    inst5.add1 = -1;
    inst5.add2 = -1;
    inst5.add3 = -1;

    trecho2[0] = inst3;
    trecho2[1] = inst4;
    trecho2[2] = inst5;

    while(getDado(ram, trecho2[0].add1) >= getDado(ram, trecho2[0].add2)){
        setPrograma(cpu, trecho2);
        iniciar(cpu, ram);
    }

    Instrucao inst6, inst7;
    inst6.add1 = getDado(ram, trecho2[1].add3);
    inst7.add1 = getDado(ram, 1);

    printf("%d%% de %d é igual a %d", inst7.add1, inst0.add1, inst6.add1);

}

//PROGRAMA DE MDC
void programaMdc(RAM *ram, CPU *cpu, int a, int b) {
    printf("Executando programaMdc(%d, %d)...\n", a, b);

    criarRAM_vazia(ram, 4);
    // RAM[0] = a
    // RAM[1] = b
    // RAM[2] = resto
    // RAM[3] = temporário

    setDado(ram, 0, a);
    setDado(ram, 1, b);

    Instrucao programa[4];

    while (getDado(ram, 1) != 0) {

        // resto = a
        setDado(ram, 2, getDado(ram, 0));

        // while (resto >= b)
        while (getDado(ram, 2) >= getDado(ram, 1)) {

            // REG1 = RAM[2]  (resto)
            programa[0].opcode = 3;
            programa[0].add1   = 0;  // reg1
            programa[0].add2   = 2;

            // REG2 = RAM[1]  (b)
            programa[1].opcode = 3;
            programa[1].add1   = 1;  // reg2
            programa[1].add2   = 1;

            // RAM[2] = REG1 - REG2
            programa[2].opcode = 1;  // sub
            programa[2].add1   = 2;  // destino RAM[2]
            programa[2].add2   = 0;  // reg1
            programa[2].add3   = 1;  // reg2

            programa[3].opcode = -1;

            setPrograma(cpu, programa);
            iniciar(cpu, ram);
        }

        // troca a <- b
        setDado(ram, 0, getDado(ram, 1));

        // troca b <- resto
        setDado(ram, 1, getDado(ram, 2));
    }

    printf("MDC = %d\n", getDado(ram, 0));
}

// PROGRAMA DE MMC 
void programaMmc(RAM *ram, CPU *cpu, int a, int b) {
    printf("Executando programaMmc(%d, %d)...\n", a, b);

    criarRAM_vazia(ram, 6);

    setDado(ram, 0, a);
    setDado(ram, 1, b);

    //MDC
    programaMdc(ram, cpu, a, b);
    int mdc = getDado(ram, 0);
    setDado(ram, 2, mdc);

    //produto = a * b 
    setDado(ram, 3, 0);  

    for (int i = 0; i < b; i++) {
        Instrucao prog[4];

        // REG1 = RAM[3]
        prog[0].opcode = 3;
        prog[0].add1   = 0;
        prog[0].add2   = 3;

        // REG2 = RAM[0]
        prog[1].opcode = 3;
        prog[1].add1   = 1;
        prog[1].add2   = 0;

        // RAM[3] = REG1 + REG2
        prog[2].opcode = 0;
        prog[2].add1   = 3;
        prog[2].add2   = 0;
        prog[2].add3   = 1;

        prog[3].opcode = -1;

        setPrograma(cpu, prog);
        iniciar(cpu, ram);
    }

    //mmc = produto / mdc 
    setDado(ram, 4, 0);   // mmc
    setDado(ram, 5, mdc); // divisor

    while (getDado(ram, 3) >= getDado(ram, 5)) {
        Instrucao prog[4];

        // REG1 = produto
        prog[0].opcode = 3;
        prog[0].add1   = 0;
        prog[0].add2   = 3;

        // REG2 = divisor
        prog[1].opcode = 3;
        prog[1].add1   = 1;
        prog[1].add2   = 5;

        // produto -= divisor
        prog[2].opcode = 1; // sub
        prog[2].add1   = 3; // destino
        prog[2].add2   = 0; // reg1
        prog[2].add3   = 1; // reg2

        prog[3].opcode = -1;
        setPrograma(cpu, prog);
        iniciar(cpu, ram);

        // mmc++
        setDado(ram, 4, getDado(ram, 4) + 1);
    }

    printf("MMC(%d, %d) = %d\n", a, b, getDado(ram, 4));
}

//PROGRAMA DE BHASKARA
void programaBhaskara(RAM *ram, CPU *cpu, int a, int b, int c) {
    printf("Executando programaBhaskara(%d, %d, %d)...\n", a, b, c);

    criarRAM_vazia(ram, 10);
    // RAM[0] = a
    // RAM[1] = b
    // RAM[2] = c
    // RAM[3] = b²
    // RAM[4] = 4ac
    // RAM[5] = delta
    // RAM[6] = 4 (constante)
    // RAM[7] = 2 (constante)
    // RAM[8] = raiz delta
    // RAM[9] = temporário

    setDado(ram, 0, a);
    setDado(ram, 1, b);
    setDado(ram, 2, c);
    setDado(ram, 6, 4);
    setDado(ram, 7, 2);

    Instrucao programa[8];

    // Calcula b²
    setDado(ram, 3, 0);
    for (int i = 0; i < b; i++) {
        // COPIA RAM[3] -> REGISTRADOR1
        programa[0].opcode = 3;
        programa[0].add1 = 0;
        programa[0].add2 = 3;
        
        // COPIA RAM[1] -> REGISTRADOR2
        programa[1].opcode = 3;
        programa[1].add1 = 1;
        programa[1].add2 = 1;
        
        // SOMA REGISTRADOR1 + REGISTRADOR2 -> RAM[3]
        programa[2].opcode = 0;
        programa[2].add1 = 0;
        programa[2].add2 = 1;
        programa[2].add3 = 3;
        
        programa[3].opcode = -1;
        
        setPrograma(cpu, programa);
        iniciar(cpu, ram);
    }

    // Calcula 4ac
    setDado(ram, 4, 0);
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < c; j++) {
            // COPIA RAM[4] -> REGISTRADOR1
            programa[0].opcode = 3;
            programa[0].add1 = 0;
            programa[0].add2 = 4;
            
            // COPIA RAM[6] -> REGISTRADOR2 (4)
            programa[1].opcode = 3;
            programa[1].add1 = 1;
            programa[1].add2 = 6;
            
            // SOMA REGISTRADOR1 + REGISTRADOR2 -> RAM[4]
            programa[2].opcode = 0;
            programa[2].add1 = 0;
            programa[2].add2 = 1;
            programa[2].add3 = 4;
            
            programa[3].opcode = -1;
            
            setPrograma(cpu, programa);
            iniciar(cpu, ram);
        }
    }


    // Calcula delta = b² - 4ac
    // COPIA RAM[3] -> REGISTRADOR1 (b²)
    programa[0].opcode = 3;
    programa[0].add1 = 0;
    programa[0].add2 = 3;
    
    // COPIA RAM[4] -> REGISTRADOR2 (4ac)
    programa[1].opcode = 3;
    programa[1].add1 = 1;
    programa[1].add2 = 4;
    
    // SUBTRAI REGISTRADOR1 - REGISTRADOR2 -> RAM[5] (delta)
    programa[2].opcode = 1;
    programa[2].add1 = 0;
    programa[2].add2 = 1;
    programa[2].add3 = 5;
    
    programa[3].opcode = -1;
    
    setPrograma(cpu, programa);
    iniciar(cpu, ram);

    int delta = getDado(ram, 5);
    printf("Delta = %d\n", delta);

    if (delta < 0) {
        printf("Não existe raiz real.\n");
        return;
    }

    // Calcula raiz quadrada aproximada de delta
    int raiz = 0;
    while (raiz * raiz <= delta) {
        raiz++;
    }
    raiz--;

    printf("Raiz inteira aproximada = %d\n", raiz);

    // Calcula x1 = (-b + raiz) / (2a)
    int numerador1 = (-b + raiz);
    int denominador = 2 * a;
    
    // Divisão simples
    int x1 = 0;
    while (numerador1 >= denominador) {
        numerador1 -= denominador;
        x1++;
    }

    // Calcula x2 = (-b - raiz) / (2a)
    int numerador2 = (-b - raiz);
    int x2 = 0;
    while (numerador2 >= denominador) {
        numerador2 -= denominador;
        x2++;
    }

    printf("x1 = %d\nx2 = %d\n", x1, x2);
}

void programaSomaTres(RAM * ram, CPU *cpu, int a, int b, int c){

    Instrucao trecho1[7];
    Instrucao inst1, inst2, inst3, inst4, inst5, inst6, inst7;

    criarRAM_vazia(ram, 3);

    inst1.opcode = 4;
    inst1.add1 = 0;
    inst1.add2 = a;
    inst1.add3 = -1;

    inst2.opcode = 4;
    inst2.add1 = 1;
    inst2.add2 = b;
    inst2.add3 = -1;

    inst3.opcode = 2;
    inst3.add1 = 0;
    inst3.add2 = 0;
    inst3.add3 = -1;

    inst4.opcode = 2;
    inst4.add1 = 1;
    inst4.add2 = 1;
    inst4.add3 = -1;

    inst5.opcode = 4;
    inst5.add1 = 0;
    inst5.add2 = c;
    inst5.add3 = -1;

    inst6.opcode = 2;
    inst6.add1 = 0;
    inst6.add2 = 2;
    inst6.add3 = -1;

    inst7.opcode = -1;
    inst7.add1 = -1;
    inst7.add2 = -1;
    inst7.add3 = -1;

    trecho1[0] = inst1;
    trecho1[1] = inst2;
    trecho1[2] = inst3;
    trecho1[3] = inst4;
    trecho1[4] = inst5;
    trecho1[5] = inst6;
    trecho1[6] = inst7;

    setPrograma(cpu, trecho1);
    iniciar(cpu, ram);

    Instrucao trecho2[3];
    Instrucao inst8, inst9, inst10;

    inst8.opcode = 0;
    inst8.add1 = 0;
    inst8.add2 = 1;
    inst8.add3 = 0;

    inst9.opcode = 0;
    inst9.add1 = 0;
    inst9.add2 = 2;
    inst9.add3 = 0;

    inst10.opcode = -1;
    inst10.add1 = -1;
    inst10.add2 = -1;
    inst10.add3 = -1;

    trecho2[0] = inst8;
    trecho2[1] = inst9;
    trecho2[2] = inst10;

    setPrograma(cpu, trecho2);
    iniciar(cpu, ram);

    Instrucao trecho3[2];
    Instrucao inst11, inst12;

    inst11.opcode = 3;
    inst11.add1 = 0;
    inst11.add2 = 0;
    inst11.add3 = -1;

    inst12.opcode = -1;
    inst12.add1 = -1;
    inst12.add2 = -1;
    inst12.add3 = -1;

    trecho3[0] = inst11;
    trecho3[1] = inst12;

    setPrograma(cpu, trecho3);
    iniciar(cpu, ram);

    printf("\nO resultado da soma eh: %d\n", cpu->registrador1);
}

void programaFormulaHeron(RAM *ram, CPU *cpu, int a, int b, int c){

    //Calculando o semi-perímetro
    programaSomaTres(ram, cpu, a, b, c);
    free(ram->memoria);

    programaDivide(ram, cpu, cpu->registrador1, 2);

    Instrucao trecho1[8];
    Instrucao inst1, inst2, inst3, inst4, inst5, inst6, inst7, inst8;

    inst1.opcode = 2;
    inst1.add1 = 0;
    inst1.add2 = 0;
    inst1.add3 = -1;

    inst2.opcode = 4;
    inst2.add1 = 0;
    inst2.add2 = a;
    inst2.add3 = -1;

    inst3.opcode = 4;
    inst3.add1 = 1;
    inst3.add2 = b;
    inst3.add3 = -1;

    inst4.opcode = 2;
    inst4.add1 = 0;
    inst4.add2 = 1;
    inst4.add3 = -1;

    inst5.opcode = 2;
    inst5.add1 = 1;
    inst5.add2 = 2;
    inst5.add3 = -1;

    inst6.opcode = 4;
    inst6.add1 = 0;
    inst6.add2 = c;
    inst6.add3 = -1;

    inst7.opcode = 2;
    inst7.add1 = 0;
    inst7.add2 = 3;
    inst7.add3 = -1;

    inst8.opcode = -1;
    inst8.add1 = -1;
    inst8.add2 = -1;
    inst8.add3 = -1;

    trecho1[0] = inst1;
    trecho1[1] = inst2;
    trecho1[2] = inst3;
    trecho1[3] = inst4;
    trecho1[4] = inst5;
    trecho1[5] = inst6;
    trecho1[6] = inst7;
    trecho1[7] = inst8;

    setPrograma(cpu, trecho1);
    iniciar(cpu, ram);

    Instrucao trecho2[4];
    Instrucao  inst9, inst10, inst11, inst12;

    inst9.opcode = 1;
    inst9.add1 = 0;
    inst9.add2 = 1;
    inst9.add3 = 1;

    inst10.opcode = 1;
    inst10.add1 = 0;
    inst10.add2 = 2;
    inst10.add3 = 2;

    inst11.opcode = 1;
    inst11.add1 = 0;
    inst11.add2 = 3;
    inst11.add3 = 3;

    inst12.opcode = -1;
    inst12.add1 = -1;
    inst12.add2 = -1;
    inst12.add3 = -1;

    trecho2[0] = inst9;
    trecho2[1] = inst10;
    trecho2[2] = inst11;
    trecho2[3] = inst12;

    setPrograma(cpu, trecho2);
    iniciar(cpu, ram);

    Instrucao trecho3[9];
    Instrucao inst13, inst14, inst15, inst16, inst17, inst18, inst19, inst20, inst21;

    inst13.opcode = 3;
    inst13.add1 = 0;
    inst13.add2 = 0;
    inst13.add3 = -1;

    inst14.opcode = 5;
    inst14.add1 = 0;
    inst14.add2 = -1;
    inst14.add3 = -1;

    inst15.opcode = 3;
    inst15.add1 = 0;
    inst15.add2 = 1;
    inst15.add3 = -1;

    inst16.opcode = 5;
    inst16.add1 = 0;
    inst16.add2 = -1;
    inst16.add3 = -1;

    inst17.opcode = 3;
    inst17.add1 = 0;
    inst17.add2 = 2;
    inst17.add3 = -1;

    inst18.opcode = 5;
    inst18.add1 = 0;
    inst18.add2 = -1;
    inst18.add3 = -1;

    inst19.opcode = 3;
    inst19.add1 = 0;
    inst19.add2 = 3;
    inst19.add3 = -1;

    inst20.opcode = 5;
    inst20.add1 = 0;
    inst20.add2 = -1;
    inst20.add3 = -1;

    inst21.opcode = -1;
    inst21.add1 = -1;
    inst21.add2 = -1;
    inst21.add3 = -1;

    trecho3[0] = inst13;
    trecho3[1] = inst14;
    trecho3[2] = inst15;
    trecho3[3] = inst16;
    trecho3[4] = inst17;
    trecho3[5] = inst18;
    trecho3[6] = inst19;
    trecho3[7] = inst20;
    trecho3[8] = inst21;

    setPrograma(cpu, trecho3);
    iniciar(cpu, ram);

    Instrucao inst22, inst23, inst24, inst25;

    inst22.add2 = cpu->programa[1].add2;
    inst23.add2 = cpu->programa[3].add2;
    inst24.add2 = cpu->programa[5].add2;
    inst25.add2 = cpu->programa[7].add2;

    free(ram->memoria);

    programaMultiplica(ram, cpu, inst23.add2, inst22.add2);

    Instrucao trecho4[3];
    Instrucao inst26, inst27, inst28;

    inst26.opcode = 3;
    inst26.add1 = 0;
    inst26.add2 = 0;
    inst26.add3 = -1;

    inst27.opcode = 5;
    inst27.add1 = 0;
    inst27.add2 = -1;
    inst27.add3 = -1;

    inst28.opcode = -1;
    inst28.add1 = -1;
    inst28.add2 = -1;
    inst28.add3 = -1;

    trecho4[0] = inst26;
    trecho4[1] = inst27;
    trecho4[2] = inst28;

    setPrograma(cpu, trecho4);
    iniciar(cpu, ram);

    Instrucao inst29;
    inst29.add2 = cpu->programa[1].add2;

    free(ram->memoria);

    programaMultiplica(ram, cpu, inst29.add2, inst24.add2);

    Instrucao trecho5[3];
    Instrucao inst30, inst31, inst32;

    inst30.opcode = 3;
    inst30.add1 = 0;
    inst30.add2 = 0;
    inst30.add3 = -1;

    inst31.opcode = 5;
    inst31.add1 = 0;
    inst31.add2 = -1;
    inst31.add3 = -1;

    inst32.opcode = -1;
    inst32.add1 = -1;
    inst32.add2 = -1;
    inst32.add3 = -1;

    trecho5[0] = inst30;
    trecho5[1] = inst31;
    trecho5[2] = inst32;

    setPrograma(cpu, trecho5);
    iniciar(cpu, ram);

    Instrucao inst33;
    inst33.add2 = cpu->programa[1].add2;

    free(ram->memoria);

    programaMultiplica(ram, cpu, inst33.add2, inst25.add2);

    Instrucao trecho6[3];
    Instrucao inst34, inst35, inst36;

    inst34.opcode = 3;
    inst34.add1 = 0;
    inst34.add2 = 0;
    inst34.add3 = -1;

    inst35.opcode = 5;
    inst35.add1 = 0;
    inst35.add2 = -1;
    inst35.add3 = -1;

    inst30.opcode = -1;
    inst36.add1 = -1;
    inst36.add2 = -1;
    inst36.add3 = -1;

    trecho6[0] = inst34;
    trecho6[1] = inst35;
    trecho6[2] = inst36;

    setPrograma(cpu, trecho6);
    iniciar(cpu, ram);

    Instrucao inst37;
    inst37.add2 = cpu->programa[1].add2;

    free(ram->memoria);

    programaRaizQuadrada(ram, cpu, inst37.add2);

    Instrucao trecho7[2];
    Instrucao inst38, inst39;

    inst38.opcode = 3;
    inst38.add1 = 0;
    inst38.add2 = 0;
    inst38.add3 = -1;

    inst39.opcode = -1;
    inst39.add1 = -1;
    inst39.add2 = -1;
    inst39.add3 = -1;

    trecho7[0] = inst38;
    trecho7[1] = inst39;

    setPrograma(cpu, trecho7);
    iniciar(cpu, ram);

    printf("\nA area do triangulo eh: %d\n", cpu->registrador1);

}


void programaOR(RAM *ram, CPU *cpu, int a, int b)
{
    printf("Executando OR(%d, %d)...\n", a, b);

    // RAM:
    // 0 = A
    // 1 = B
    // 2 = R
    // 3 = temp
    // 4 = constante 1

    criarRAM_vazia(ram, 5);
    setDado(ram, 0, a);
    setDado(ram, 1, b);
    setDado(ram, 2, 0);
    setDado(ram, 4, 1); // constante 1
    
    // Teste: se A != 0 → R = 1
    setDado(ram, 3, getDado(ram, 0)); // temp = A

    Instrucao diminuiA[2];
    diminuiA[0].opcode = 1;   // temp = temp - 1
    diminuiA[0].add1 = 3;
    diminuiA[0].add2 = 4;
    diminuiA[0].add3 = 3;
    diminuiA[1].opcode = -1;

    while (getDado(ram, 3) > 0) {
        setPrograma(cpu, diminuiA);
        iniciar(cpu, ram);
    }

    if (getDado(ram, 3) == 0 && getDado(ram, 0) > 0) {
        setDado(ram, 2, 1);
        printf("Resultado OR = 1\n");
        return;
    }

    // Teste: se B != 0 → R = 1

    setDado(ram, 3, getDado(ram, 1)); // temp = B

    Instrucao diminuiB[2];
    diminuiB[0].opcode = 1;   // temp = temp - 1
    diminuiB[0].add1 = 3;
    diminuiB[0].add2 = 4;
    diminuiB[0].add3 = 3;
    diminuiB[1].opcode = -1;

    while (getDado(ram, 3) > 0) {
        setPrograma(cpu, diminuiB);
        iniciar(cpu, ram);
    }

    if (getDado(ram, 3) == 0 && getDado(ram, 1) > 0) {
        setDado(ram, 2, 1);
        printf("Resultado OR = 1\n");
        return;
    }

    // Se chegou aqui nenhum é > 0
    
    setDado(ram, 2, 0);
    printf("Resultado OR = 0\n");
}

// Grupo 10 - Otávio Enrique Lopes de Lima, Ana Gabriela Gomes Lopes Pereira e Heitor Novais Leite de Menezes

