#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maquina.h"

/* OPCODES:
    //-1 -> halt
    // 0 -> soma
    // 1 -> subtrai
    // 2 -> copia do registrador para RAM
    // 3 -> copia da RAM para o registrador
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
    // programaDivide(&ram, &cpu, 500, 19);

    // Calcula resto de divisão
    // programaRestoDivisao(&ram, &cpu, 101, 5);

    // Executa um exemplo de raíz quadrada
    // programaRaizQuadrada(&ram, &cpu, 25);

    // Executa um exemplo de fatorial
    // programaFatorial(&ram, &cpu, 5);
    
    // Executa um exemplo de potencia
    // programaPotencia(&ram, &cpu, 3, 4);
    
    // Executa um exemplo de fibonacci
    // programaFibonacci(&ram, &cpu, 8);
    
    // Executa um exemplo de capslock
    // pogramaCapslock(&ram, &cpu, "eXemPLo");

    // Executa a média de valores gerados aleatoriamente em um vetor 
    // programaMedia(&ram, &cpu, 5);

    // Executa um exemplo de porcentagem
    // programaPorcentagem(&ram, &cpu, 200, 50);

    //Executa um exemplo de mdc
    //programaMdc(&ram,&cpu, 36,44);

    //Execute um exemplo de mmc
    //programaMmc(&ram,&cpu,36,44);

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

//Programa que multiplica dois números inteiros
void programaMultiplica(RAM *ram, CPU *cpu, int multiplicando, int multiplicador){

    criarRAM_vazia(ram, 2);
    
    setDado(ram, 0, multiplicando);
    setDado(ram, 1, multiplicando);

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

    for(int i = 1; i < multiplicador; i++){
        setPrograma(cpu, trecho1);
        iniciar(cpu, ram);
    }

    Instrucao inst3;

    inst3.add1 = getDado(ram, trecho1[0].add1);

    printf("\nResultado da multiplicacao: %d\n", inst3.add1);
}

//Programa que mostra a parte inteira da divisão de dois números inteiros
void programaDivide(RAM *ram, CPU *cpu, int dividendo, int divisor){

    criarRAM_vazia(ram, 4);
    
    setDado(ram, 0, dividendo);
    setDado(ram, 1, divisor);
    setDado(ram, 2, 0);
    setDado(ram, 3, 1);

    Instrucao trecho1[3];
    Instrucao inst1, inst2, inst3;

    inst1.opcode = 1;
    inst1.add1 = 0;
    inst1.add2 = 1;
    inst1.add3 = 0;

    inst2.opcode = 0;
    inst2.add1 = 2;
    inst2.add2 = 3;
    inst2.add3 = 2;

    inst3.opcode = -1;
    inst3.add1 = -1;
    inst3.add2 = -1;
    inst3.add3 = -1;

    trecho1[0] = inst1;
    trecho1[1] = inst2;
    trecho1[2] = inst3;

    while(getDado(ram, trecho1[0].add1) >= getDado(ram, trecho1[0].add2)){
        setPrograma(cpu, trecho1);
        iniciar(cpu, ram);
    }
    
    Instrucao inst4;
    inst4.add1 = getDado(ram, trecho1[1].add3);

    printf("\nResultado da divisao: %d\n", inst4.add1);

}

//Programa que calcula o resto da divisão de dois números inteiros
void programaRestoDivisao(RAM *ram, CPU *cpu, int dividendo, int divisor){

    criarRAM_vazia(ram, 2);
    setDado(ram, 0, dividendo);
    setDado(ram, 1, divisor);

    Instrucao trecho1[2];
    Instrucao inst1, inst2;

    inst1.opcode = 1;
    inst1.add1 = 0;
    inst1.add2 = 1;
    inst1.add3 = 0;

    inst2.opcode = -1;
    inst2.add1 = -1;
    inst2.add2 = -1;
    inst2.add3 = -1;

    trecho1[0] = inst1;
    trecho1[1] = inst2;

    while(getDado(ram, trecho1[0].add1) >= getDado(ram, trecho1[0].add2)){
        setPrograma(cpu, trecho1);
        iniciar(cpu, ram);
    }

    Instrucao inst3;
    inst3.add1 = getDado(ram, trecho1[0].add1);

    printf("\nResto da divisao: %d\n", inst3.add1);
}

//Calcula a raíz quadrada
void programaRaizQuadrada(RAM *ram, CPU *cpu, int radicando){

    Instrucao inst1, inst2;
    inst1.add1 = 0;
    inst2.add1 = 1;

    while(inst1.add1 <= radicando){
        Instrucao trecho1[3];
        Instrucao inst3, inst4;
        programaMultiplica(ram, cpu, inst2.add1, inst2.add1);
        
        inst1.add1 = getDado(ram, 0);
        setDado(ram, 0, inst2.add1);
        setDado(ram, 1, 1);

        inst3.opcode = 0;
        inst3.add1 = 0;
        inst3.add2 = 1;
        inst3.add3 = 0;

        inst4.opcode = -1;
        inst4.add1 = -1;
        inst4.add2 = -1;
        inst4.add3 = -1;

        trecho1[0] = inst3;
        trecho1[1] = inst4;

        setPrograma(cpu, trecho1);
        iniciar(cpu, ram);

        inst2.add1 = getDado(ram, 0);
    }

    
    Instrucao trecho2[3];
    Instrucao inst5, inst6, inst7;

    inst5.opcode = 1;
    inst5.add1 = 0;
    inst5.add2 = 1;
    inst5.add3 = 0;

    inst6.opcode = 1;
    inst6.add1 = 0;
    inst6.add2 = 1;
    inst6.add3 = 0;

    inst7.opcode = -1;
    inst7.add1 = -1;
    inst7.add2 = -1;
    inst7.add3 = -1;

    trecho2[0] = inst5;
    trecho2[1] = inst6;
    trecho2[2] = inst7;

    setPrograma(cpu, trecho2);
    iniciar(cpu, ram);

    
    Instrucao inst8;
    inst8.add1 = getDado(ram, 0);
    

    printf("\nResultado da raiz quadrada: %d\n", inst8.add1);
}

// PROGRAMA DE FATORIAL
void programaFatorial(RAM *ram, CPU *cpu, int numero) {

    printf("Executando programaFatorial(%d)...\n", numero);

    criarRAM_vazia(ram, 4);
    // RAM[0] = número base
    // RAM[1] = contador
    // RAM[2] = resultado parcial
    // RAM[3] = auxiliar

    setDado(ram, 0, numero); // número
    setDado(ram, 1, 1);      // contador = 1
    setDado(ram, 2, 1);      // resultado = 1

    // Enquanto contador <= número
    while (getDado(ram, 1) <= getDado(ram, 0)) {
        setDado(ram, 3, 0); // Zera auxiliar

        // Multiplica resultado * contador 
        for (int i = 0; i < getDado(ram, 1); i++) {
            Instrucao soma[2];
            soma[0].opcode = 0;  // soma
            soma[0].add1 = 3;    // RAM[3] += RAM[2]
            soma[0].add2 = 2;
            soma[0].add3 = 3;
            soma[1].opcode = -1;

            setPrograma(cpu, soma);
            iniciar(cpu, ram);
        }

        // Atualiza o resultado com o valor de RAM[3]
        setDado(ram, 2, getDado(ram, 3));

        // Incrementa contador (contador = contador + 1)
        Instrucao somaContador[2];
        somaContador[0].opcode = 0;
        somaContador[0].add1 = 1; // contador
        somaContador[0].add2 = 3; // RAM[3] = 1
        somaContador[0].add3 = 1; // salva contador
        somaContador[1].opcode = -1;

        setDado(ram, 3, 1); // RAM[3] = 1
        setPrograma(cpu, somaContador);
        iniciar(cpu, ram);
    }

    printf("Fatorial de %d = %d\n", numero, getDado(ram, 2));
}

// PROGRAMA DE POTÊNCIA
void programaPotencia(RAM *ram, CPU *cpu, int base, int expoente) {

    printf("Executando programaPotencia(%d, %d)...\n", base, expoente);

    criarRAM_vazia(ram, 4);
    // RAM[0] = base
    // RAM[1] = expoente
    // RAM[2] = resultado parcial
    // RAM[3] = auxiliar

    setDado(ram, 0, base);
    setDado(ram, 1, expoente);
    setDado(ram, 2, 1); // resultado começa em 1

    // Enquanto expoente > 0
    while (getDado(ram, 1) > 0) {
        setDado(ram, 3, 0); // limpa auxiliar

        // Multiplica resultado * base (por somas sucessivas)
        for (int i = 0; i < getDado(ram, 0); i++) {
            Instrucao soma[2];
            soma[0].opcode = 0; // soma
            soma[0].add1 = 3;   // RAM[3] += RAM[2]
            soma[0].add2 = 2;
            soma[0].add3 = 3;
            soma[1].opcode = -1;

            setPrograma(cpu, soma);
            iniciar(cpu, ram);
        }

        // Atualiza resultado
        setDado(ram, 2, getDado(ram, 3));

        // Decrementa expoente (expoente = expoente - 1)
        Instrucao subtrai[2];
        subtrai[0].opcode = 1; // subtração
        subtrai[0].add1 = 1;   // RAM[1] = expoente
        subtrai[0].add2 = 3;   // usa RAM[3] = 1
        subtrai[0].add3 = 1;   // salva de volta
        subtrai[1].opcode = -1;

        setDado(ram, 3, 1); // RAM[3] = 1 temporário
        setPrograma(cpu, subtrai);
        iniciar(cpu, ram);
    }

    printf("Resultado da potencia: %d^%d = %d\n", base, expoente, getDado(ram, 2));
}

// PROGRAMA DE FIBONACCI
void programaFibonacci(RAM *ram, CPU *cpu, int n) {
    printf("Executando programaFibonacci(%d)...\n", n);

    criarRAM_vazia(ram, 4);
    // RAM[0] = quantidade de termos
    // RAM[1] = termo anterior
    // RAM[2] = termo atual
    // RAM[3] = próximo termo

    setDado(ram, 0, n);
    setDado(ram, 1, 0); // primeiro termo
    setDado(ram, 2, 1); // segundo termo

    printf("Sequência de Fibonacci (%d termos):\n", n);
    printf("%d %d ", getDado(ram, 1), getDado(ram, 2));

    // gera os próximos termos
    for (int i = 3; i <= getDado(ram, 0); i++) {
        Instrucao soma[2];
        soma[0].opcode = 0;  // soma (RAM[3] = RAM[1] + RAM[2])
        soma[0].add1 = 1;
        soma[0].add2 = 2;
        soma[0].add3 = 3;
        soma[1].opcode = -1;

        setPrograma(cpu, soma);
        iniciar(cpu, ram);

        printf("%d ", getDado(ram, 3));

        // Atualiza os termos:
        setDado(ram, 1, getDado(ram, 2)); // anterior = atual
        setDado(ram, 2, getDado(ram, 3)); // atual = próximo
    }

    printf("\n");
}

// Recebe uma string e a converte em letras maiúsculas
void programaCapslock(RAM *ram, CPU *cpu, char *texto) {

    int n = strlen(texto);

    // RAM:
    // [0..n-1] -> caracteres
    // [n]      -> valor 32 (para subtrair)
    criarRAM_vazia(ram, n + 1);

    // copia string para RAM 
    for (int i = 0; i < n; i++) {
        ram->memoria[i] = (int)texto[i];
    }

    // armazena o valor 32 (diferença entre 'a' e 'A')
    ram->memoria[n] = 32;

    // uma instrução fixa: subtrai RAM[i] - RAM[n] -> RAM[i]
    Instrucao inst[2];
    inst[0].opcode = 1;   // SUBTRAI
    inst[0].add2 = n;     // subtrair 32
    inst[1].opcode = -1;  // HALT

    // percorre cada caractere
    for (int i = 0; i < n; i++) {

        int c = ram->memoria[i];

        // só altera se for letra minúscula
        if (c >= 'a' && c <= 'z') {

            inst[0].add1 = i;  
            inst[0].add3 = i;

            setPrograma(cpu, inst);
            iniciar(cpu, ram);
        }
    }

    // mostra o resultado
    printf("String convertida para CAPSLOCK: ");
    for (int i = 0; i < n; i++) {
        printf("%c", (char)ram->memoria[i]);
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

void programaMdc(RAM *ram, CPU *cpu, int a, int b) {

    printf("Executando programaMdc(%d, %d)...\n", a, b);

    criarRAM_vazia(ram, 3);
    // RAM[0] = a
    // RAM[1] = b
    // RAM[2] = resto temporário

    setDado(ram, 0, a);
    setDado(ram, 1, b);

    while (getDado(ram, 1) != 0) {

        // Calcula resto por subtrações sucessivas
        setDado(ram, 2, getDado(ram, 0)); // resto = a

        Instrucao sub[2];
        sub[0].opcode = 1;  // sub
        sub[0].add1 = 2;    // resto = resto - b
        sub[0].add2 = 1;
        sub[0].add3 = 2;
        sub[1].opcode = -1;

        while (getDado(ram, 2) >= getDado(ram, 1)) {
            setPrograma(cpu, sub);
            iniciar(cpu, ram);
        }

        // Atualiza: a = b / b = resto
        setDado(ram, 0, getDado(ram, 1));
        setDado(ram, 1, getDado(ram, 2));
    }

    printf("MDC = %d\n", getDado(ram, 0));
}

void programaMmc(RAM *ram, CPU *cpu, int a, int b) {

    printf("Executando programaMmc(%d, %d)...\n", a, b);

    RAM ramAux;

    //calcula o MDC
    programaMdc(ram, cpu, a, b);
    int mdc = getDado(ram, 0);

    //Multiplica a * b 
    programaMultiplica(&ramAux, cpu, a, b);
    int produto = ramAux.memoria[0];
    free(ramAux.memoria);

    //Divide produto / mdc 
    programaDivide(ram, cpu, produto, mdc);

    printf("\nMMC = %d\n", getDado(ram, 2));
}

void programaBhaskara(RAM *ram, CPU *cpu, int a, int b, int c) {

    printf("Executando programaBhaskara(%d, %d, %d)...\n", a, b, c);

    // b^2
    programaMultiplica(ram, cpu, b, b);
    int b2 = getDado(ram, 0);

    //  4ac 
    programaMultiplica(ram, cpu, a, c);
    int ac = getDado(ram, 0);

    programaMultiplica(ram, cpu, ac, 4);
    int quatro_ac = getDado(ram, 0);

    //delta = b² - 4ac 
    criarRAM_vazia(ram, 3);
    setDado(ram, 0, b2);
    setDado(ram, 1, quatro_ac);

    Instrucao sub[2];
    sub[0].opcode = 1;  // subtrai
    sub[0].add1 = 0;
    sub[0].add2 = 1;
    sub[0].add3 = 0;
    sub[1].opcode = -1;

    setPrograma(cpu, sub);
    iniciar(cpu, ram);

    int delta = getDado(ram, 0);
    printf("Delta = %d\n", delta);

    if (delta < 0) {
        printf("Não existe raiz real.\n");
        return;
    }

    // raiz inteira de delta
    int raiz = 0;
    while (raiz * raiz <= delta)
        raiz++;

    raiz--;  // último valor válido

    printf("Raiz inteira aproximada = %d\n", raiz);

    // x1 = (-b + raiz) / (2a)
    int numerador1 = (-b + raiz);
    programaDivide(ram, cpu, numerador1, 2 * a);
    int x1 = getDado(ram, 0);

    //x2 = (-b - raiz) / (2a)
    int numerador2 = (-b - raiz);
    programaDivide(ram, cpu, numerador2, 2 * a);
    int x2 = getDado(ram, 0);

    printf("x1 = %d\nx2 = %d\n", x1, x2);
}

void programaSomaTres(RAM *ram, CPU *cpu, int a, int b, int c){

    Instrucao trecho1[3];
    Instrucao inst1, inst2, inst3;

    criarRAM_vazia(ram, 3);
    setDado(ram, 0, a);
    setDado(ram, 1, b);
    setDado(ram, 2, c);

    inst1.opcode = 0;
    inst1.add1 = 0;
    inst1.add2 = 1;
    inst1.add3 = 0;

    inst2.opcode = 0;
    inst2.add1 = 0;
    inst2.add2 = 2;
    inst2.add3 = 0;

    inst3.opcode = -1;
    inst3.add1 = -1;
    inst3.add2 = -1;
    inst3.add3 = -1;

    trecho1[0] = inst1;
    trecho1[1] = inst2;
    trecho1[2] = inst3;

    setPrograma(cpu, trecho1);
    iniciar(cpu, ram);

    Instrucao inst4;
    inst4.add1 = getDado(ram, 0);

    printf("\nO resultado da soma eh: %d\n", inst4.add1);
}

void programaFormulaHeron(RAM *ram, CPU *cpu, int a, int b, int c){

    Instrucao inst1, inst2;

    //Calculando o semi-perímetro
    programaSomaTres(ram, cpu, a, b, c);

    inst1.add1 = getDado(ram, 0);
    free(ram->memoria);

    programaDivide(ram, cpu, inst1.add1, 2);

    inst2.add1 = getDado(ram, 2);

    setDado(ram, 0, inst2.add1);
    setDado(ram, 1, a);
    setDado(ram, 2, b);
    setDado(ram, 3, c);

    Instrucao trecho1[4];
    Instrucao  inst3, inst4, inst5, inst6;
    inst3.opcode = 1;
    inst3.add1 = 0;
    inst3.add2 = 1;
    inst3.add3 = 1;

    inst4.opcode = 1;
    inst4.add1 = 0;
    inst4.add2 = 2;
    inst4.add3 = 2;

    inst5.opcode = 1;
    inst5.add1 = 0;
    inst5.add2 = 3;
    inst5.add3 = 3;

    inst6.opcode = -1;
    inst6.add1 = -1;
    inst6.add2 = -1;
    inst6.add3 = -1;

    trecho1[0] = inst3;
    trecho1[1] = inst4;
    trecho1[2] = inst5;
    trecho1[3] = inst6;

    setPrograma(cpu, trecho1);
    iniciar(cpu, ram);

    Instrucao inst7, inst8, inst9;

    inst7.add1 = getDado(ram, 1);
    inst8.add1 = getDado(ram, 2);
    inst9.add1 = getDado(ram, 3);

    free(ram->memoria);

    programaMultiplica(ram, cpu, inst2.add1, inst7.add1);

    Instrucao inst10;
    inst10.add1 = getDado(ram, 0);

    free(ram->memoria);

    programaMultiplica(ram, cpu, inst10.add1, inst8.add1);

    Instrucao inst11;
    inst11.add1 = getDado(ram, 0);

    free(ram->memoria);

    programaMultiplica(ram, cpu, inst11.add1, inst9.add1);

    Instrucao inst12;
    inst12.add1 = getDado(ram, 0);
    free(ram->memoria);

    programaRaizQuadrada(ram, cpu, inst12.add1);

    Instrucao inst13;
    inst13.add1 = getDado(ram, 0);

    printf("\nA area do triangulo eh: %d\n", inst13.add1);

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


