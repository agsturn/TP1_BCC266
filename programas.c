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
void programaPorcentagem(RAM *ram, CPU *cpu, int porcentagem, int valor);
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
    // programaPorcentagem(&ram, &cpu, 10, 100);

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

    criarRAM_vazia(ram, 4); 

    setDado(ram, 0, 7);   
    setDado(ram, 1, 5);   
    setDado(ram, 2, 0);   
    setDado(ram, 3, 10);  

    Instrucao programa[3];

    programa[0].opcode = 3;
    programa[0].add1 = 0;
    programa[0].add2 = 0;

    programa[1].opcode = 3;
    programa[1].add1 = 1;
    programa[1].add2 = 1;

    programa[2].opcode = 0;
    programa[2].add1 = 0;
    programa[2].add2 = 1;
    programa[2].add3 = 2;

    programa[3].opcode = -1;
    programa[3].add1 = -1;
    programa[3].add2 = -1;
    programa[3].add3 = -1;

    setPrograma(cpu, programa);
    iniciar(cpu, ram);

    printf("Resultado da soma: %d\n\n", getDado(ram, 2));
}

// Programa de SUBTRAÇÃO
void programaSubtrai(RAM *ram, CPU *cpu) {
    printf("Executando programaSubtrai()...\n");

    criarRAM_vazia(ram, 4);

    setDado(ram, 0, 20);  
    setDado(ram, 1, 8);   
    setDado(ram, 2, 0);   

    Instrucao programa[4];

    programa[0].opcode = 3;
    programa[0].add1 = 0;
    programa[0].add2 = 0;

    programa[1].opcode = 3;
    programa[1].add1 = 1;
    programa[1].add2 = 1;

    programa[2].opcode = 1;
    programa[2].add1 = 0;
    programa[2].add2 = 1;
    programa[2].add3 = 2;

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
  

    setDado(ram, 0, numero);
    setDado(ram, 1, 1);      
    setDado(ram, 2, 1);      
    setDado(ram, 4, 1);    

    Instrucao programa[8];

    while (getDado(ram, 1) <= getDado(ram, 0)) {
        setDado(ram, 3, 0); 
        
        for (int i = 0; i < getDado(ram, 1); i++) {
            
            programa[0].opcode = 3;
            programa[0].add1 = 0;
            programa[0].add2 = 2;
            
            programa[1].opcode = 3;
            programa[1].add1 = 1;
            programa[1].add2 = 3;
            
            programa[2].opcode = 0;
            programa[2].add1 = 0;
            programa[2].add2 = 1;
            programa[2].add3 = 3;
            
            programa[3].opcode = -1;
            
            setPrograma(cpu, programa);
            iniciar(cpu, ram);
        }

        programa[0].opcode = 3;
        programa[0].add1 = 0;
        programa[0].add2 = 3;
        
        programa[1].opcode = 2;
        programa[1].add1 = 0;
        programa[1].add2 = 2;
        
        programa[2].opcode = -1;
        setPrograma(cpu, programa);
        iniciar(cpu, ram);

        programa[0].opcode = 3;
        programa[0].add1 = 0;
        programa[0].add2 = 1;
        
        programa[1].opcode = 3;
        programa[1].add1 = 1;
        programa[1].add2 = 4;
        
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

    setDado(ram, 0, base);
    setDado(ram, 1, expoente);
    setDado(ram, 2, 1);
    setDado(ram, 4, 1);

    Instrucao programa[8];

    while (getDado(ram, 1) > 0) {
        setDado(ram, 3, 0); 

        for (int i = 0; i < getDado(ram, 0); i++) {
            programa[0].opcode = 3;
            programa[0].add1 = 0;
            programa[0].add2 = 2;
            
            programa[1].opcode = 3;
            programa[1].add1 = 1;
            programa[1].add2 = 3;
            
            programa[2].opcode = 0;
            programa[2].add1 = 0;
            programa[2].add2 = 1;
            programa[2].add3 = 3;
            
            programa[3].opcode = -1;
            
            setPrograma(cpu, programa);
            iniciar(cpu, ram);
        }

        programa[0].opcode = 3;
        programa[0].add1 = 0;
        programa[0].add2 = 3;
        
        programa[1].opcode = 2;
        programa[1].add1 = 0;
        programa[1].add2 = 2;
        
        programa[2].opcode = -1;
        setPrograma(cpu, programa);
        iniciar(cpu, ram);

        programa[0].opcode = 3;
        programa[0].add1 = 0;
        programa[0].add2 = 1;
        
        programa[1].opcode = 3;
        programa[1].add1 = 1;
        programa[1].add2 = 4;
    
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

    setDado(ram, 0, n);
    setDado(ram, 1, 0); 
    setDado(ram, 2, 1);
    setDado(ram, 4, 2); 
    setDado(ram, 5, 1);

    printf("Sequência de Fibonacci (%d termos):\n", n);
    printf("%d %d ", getDado(ram, 1), getDado(ram, 2));

    Instrucao prog[4];

    while (getDado(ram, 4) < n) {

        prog[0] = (Instrucao){3, 0, 1, 0}; 
        prog[1] = (Instrucao){3, 1, 2, 0};  
        prog[2] = (Instrucao){0, 0, 1, 3}; 
        prog[3] = (Instrucao){-1, 0, 0, 0};

        setPrograma(cpu, prog);
        iniciar(cpu, ram);

        printf("%d ", getDado(ram, 3));

        prog[0] = (Instrucao){3, 0, 2, 0}; 
        prog[1] = (Instrucao){2, 0, 1, 0}; 
        prog[2] = (Instrucao){3, 0, 3, 0}; 
        prog[3] = (Instrucao){2, 0, 2, 0}; 

        setPrograma(cpu, prog);
        iniciar(cpu, ram);

        prog[0] = (Instrucao){3, 0, 4, 0}; 
        prog[1] = (Instrucao){3, 1, 5, 0}; 
        prog[2] = (Instrucao){0, 0, 1, 4}; 
        prog[3] = (Instrucao){-1, 0, 0, 0};

        setPrograma(cpu, prog);
        iniciar(cpu, ram);
    }

    printf("\n");
}

// converte uma string para letras maiúsculas usando opcode sub
void programaCapslock(RAM *ram, CPU *cpu, char *texto) {

    int n = strlen(texto);

    // ram layout:
    // [0 .. n-1] -> texto original
    // [n]        -> valor 32 (diferença entre 'a' e 'a')

    criarRAM_vazia(ram, n + 1);

    // copiar string para a ram usando setDado
    for (int i = 0; i < n; i++) {
        setDado(ram, i, (int)texto[i]);
    }

    // guardar valor fixo 32
    setDado(ram, n, 32);

    // criar instruções
    Instrucao inst[2];

    inst[0].opcode = 1;   // sub opcode
    inst[1].opcode = -1;  // halt (ajuste conforme seu cpu)

    // percorrer ram em busca de letras minúsculas
    for (int i = 0; i < n; i++) {

        int c = getDado(ram, i);

        // se for minúscula, converte
        if (c >= 'a' && c <= 'z') {

            inst[0].add1 = i;  // endereço do caractere
            inst[0].add2 = n;  // endereço contendo 32
            inst[0].add3 = i;  // resultado volta no mesmo endereço

            setPrograma(cpu, inst);
            iniciar(cpu, ram);
        }
    }

    // exibe resultado
    printf("string convertida para capslock: ");
    for (int i = 0; i < n; i++) {
        printf("%c", (char)getDado(ram, i));
    }
    printf("\n");
}

// Executa a média de valores gerados aleatoriamente em um vetor 
void programaMedia(RAM *ram, CPU *cpu, int tamanhoVetor){
    criarRAM_aleatoria(ram, tamanhoVetor);

    Instrucao trecho1[2];
    Instrucao inst1, inst2;
    
    inst2.opcode = -1;
    inst2.add1 = -1;
    inst2.add2 = -1;
    inst2.add3 = -1;
    trecho1[1] = inst2;

    for(int i = 1; i < tamanhoVetor; i++){
        inst1.opcode = 0;
        inst1.add1 = 0;
        inst1.add2 = i;
        inst1.add3 = 0;
        trecho1[0] = inst1;
        setPrograma(cpu, trecho1);
        iniciar(cpu, ram);
    }

    Instrucao trecho2[3];
    Instrucao inst3, inst4;

    inst3.opcode = 5;
    inst3.add1 = 0;
    inst3.add2 = 0;
    inst3.add3 = -1;

    inst4.opcode = -1;
    inst4.add1 = -1;
    inst4.add2 = -1;
    inst4.add3 = -1;

    trecho2[0] = inst3;
    trecho2[1] = inst4;

    setPrograma(cpu, trecho2);
    iniciar(cpu, ram);

    free(ram->memoria);

    Instrucao inst5;

    inst5.add2 = cpu->programa[0].add2;

    programaDivide(ram, cpu, inst5.add2, tamanhoVetor);

    printf("\nA media eh: %d\n", cpu->registrador1);

}

void programaPorcentagem(RAM *ram, CPU *cpu, int porcentagem, int valor){

    programaMultiplica(ram, cpu, porcentagem, valor);
    free(ram->memoria);

    Instrucao trecho1[2];
    Instrucao inst1, inst2;

    inst1.opcode = 5;
    inst1.add1 = 0;
    inst1.add2 = -1;
    inst1.add3 = -1;

    inst2.opcode = -1;
    inst2.add1 = -1;
    inst2.add2 = -1;
    inst2.add3 = -1;

    trecho1[0] = inst1;
    trecho1[1] = inst2;

    setPrograma(cpu, trecho1);
    iniciar(cpu, ram);

    Instrucao inst3;

    inst3.add2 = cpu->programa[0].add2;

    programaDivide(ram, cpu, inst3.add2, 100);

    printf("%d%% de %d eh igual a %d", porcentagem, valor, cpu->registrador1);

}

//PROGRAMA DE MDC
void programaMdc(RAM *ram, CPU *cpu, int a, int b) {
    printf("Executando programaMdc(%d, %d)...\n", a, b);

    criarRAM_vazia(ram, 4);

    setDado(ram, 0, a);
    setDado(ram, 1, b);

    Instrucao programa[4];

    while (getDado(ram, 1) != 0) {

        setDado(ram, 2, getDado(ram, 0));

        while (getDado(ram, 2) >= getDado(ram, 1)) {

            programa[0].opcode = 3;
            programa[0].add1   = 0;  
            programa[0].add2   = 2;

            programa[1].opcode = 3;
            programa[1].add1   = 1;  
            programa[1].add2   = 1;

            programa[2].opcode = 1; 
            programa[2].add1   = 2;  
            programa[2].add2   = 0; 
            programa[2].add3   = 1; 

            programa[3].opcode = -1;

            setPrograma(cpu, programa);
            iniciar(cpu, ram);
        }

        setDado(ram, 0, getDado(ram, 1));

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

    programaMdc(ram, cpu, a, b);
    int mdc = getDado(ram, 0);
    setDado(ram, 2, mdc);

    setDado(ram, 3, 0);  

    for (int i = 0; i < b; i++) {
        Instrucao prog[4];

        prog[0].opcode = 3;
        prog[0].add1   = 0;
        prog[0].add2   = 3;

        prog[1].opcode = 3;
        prog[1].add1   = 1;
        prog[1].add2   = 0;

        prog[2].opcode = 0;
        prog[2].add1   = 3;
        prog[2].add2   = 0;
        prog[2].add3   = 1;

        prog[3].opcode = -1;

        setPrograma(cpu, prog);
        iniciar(cpu, ram);
    }

    setDado(ram, 4, 0);  
    setDado(ram, 5, mdc); 

    while (getDado(ram, 3) >= getDado(ram, 5)) {
        Instrucao prog[4];

        prog[0].opcode = 3;
        prog[0].add1   = 0;
        prog[0].add2   = 3;

        prog[1].opcode = 3;
        prog[1].add1   = 1;
        prog[1].add2   = 5;

        prog[2].opcode = 1; 
        prog[2].add1   = 3; 
        prog[2].add2   = 0; 
        prog[2].add3   = 1; 

        prog[3].opcode = -1;
        setPrograma(cpu, prog);
        iniciar(cpu, ram);

        setDado(ram, 4, getDado(ram, 4) + 1);
    }

    printf("MMC(%d, %d) = %d\n", a, b, getDado(ram, 4));
}

//PROGRAMA DE BHASKARA
void programaBhaskara(RAM *ram, CPU *cpu, int a, int b, int c) {
    printf("Executando programaBhaskara(%d, %d, %d)...\n", a, b, c);

    criarRAM_vazia(ram, 10);

    setDado(ram, 0, a);
    setDado(ram, 1, b);
    setDado(ram, 2, c);
    setDado(ram, 6, 4);
    setDado(ram, 7, 2);

    Instrucao programa[8];

    setDado(ram, 3, 0);
    for (int i = 0; i < b; i++) {
        programa[0].opcode = 3;
        programa[0].add1 = 0;
        programa[0].add2 = 3;
        
        programa[1].opcode = 3;
        programa[1].add1 = 1;
        programa[1].add2 = 1;
        
        programa[2].opcode = 0;
        programa[2].add1 = 0;
        programa[2].add2 = 1;
        programa[2].add3 = 3;
        
        programa[3].opcode = -1;
        
        setPrograma(cpu, programa);
        iniciar(cpu, ram);
    }

    setDado(ram, 4, 0);
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < c; j++) {
            programa[0].opcode = 3;
            programa[0].add1 = 0;
            programa[0].add2 = 4;
            
            programa[1].opcode = 3;
            programa[1].add1 = 1;
            programa[1].add2 = 6;
            
            programa[2].opcode = 0;
            programa[2].add1 = 0;
            programa[2].add2 = 1;
            programa[2].add3 = 4;
            
            programa[3].opcode = -1;
            
            setPrograma(cpu, programa);
            iniciar(cpu, ram);
        }
    }

    programa[0].opcode = 3;
    programa[0].add1 = 0;
    programa[0].add2 = 3;
    
    programa[1].opcode = 3;
    programa[1].add1 = 1;
    programa[1].add2 = 4;
    
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

    int raiz = 0;
    while (raiz * raiz <= delta) {
        raiz++;
    }
    raiz--;

    printf("Raiz inteira aproximada = %d\n", raiz);

    int numerador1 = (-b + raiz);
    int denominador = 2 * a;
    
    int x1 = 0;
    while (numerador1 >= denominador) {
        numerador1 -= denominador;
        x1++;
    }

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

    // Calculando o perímetro
    programaSomaTres(ram, cpu, a, b, c);
    free(ram->memoria);

    // Calculando o semi-perímetro
    programaDivide(ram, cpu, cpu->registrador1, 2);

    Instrucao trecho1[8];
    Instrucao inst1, inst2, inst3, inst4, inst5, inst6, inst7, inst8;

    // Passando para a ram os valores do semi-perímetro e dos lados
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

    // Calculando (p - a), (p - b) e (p - c)
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

    // Copiando os valores p, (p - a), (p - b) e (p - c)
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

    // Fazendo p * (p - a)
    programaMultiplica(ram, cpu, inst22.add2, inst23.add2);

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

    // Fazendo resultado anterior * (p - b)
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

    // Fazendo resultado anterior * (p - c)
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

    // Calculando a raiz quadrada
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