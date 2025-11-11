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
void programaRaizQuadrada(RAM *ram, CPU *cpu, int radicando);
void programaMultiplica2(RAM *ram, CPU *cpu, int multiplicando, int multiplicador);
void programaDivide2(RAM *ram, CPU *cpu, int dividendo, int divisor);
void programaRestoDivisao(RAM *ram, CPU *cpu, int dividendo, int divisor);
void programaFatorial(RAM *ram, CPU *cpu, int numero);
void programaPotencia(RAM *ram, CPU *cpu, int base, int expoente);
void programaFibonacci(RAM *ram, CPU *cpu, int n);

int main() {
    RAM ram;
    CPU cpu;

    printf("=== Execução dos programas CAVE Language ===\n\n");

    // Executa um exemplo de soma simples
    //programaSoma(&ram, &cpu);

    // Executa um exemplo de subtração simples
    //programaSubtrai(&ram, &cpu);

    // Executa um programa aleatório
    //programaAleatorio(&ram, &cpu, 10);

    //Executa um exemplo de multiplicacao
    //programaMultiplica(&ram,&cpu);

    //Executa um exemplo de divisao
    //programaDivide(&ram,&cpu);

    //Executa um exemplo de raíz quadrada
    //programaRaizQuadrada(&ram, &cpu, 25);

    //Outro programa de multiplicação 
    //programaMultiplica2(&ram, &cpu, 19, 23);

    //Outro programa de divisao
    //programaDivide2(&ram, &cpu, 101, 10);

    //Calcula resto de divisão
    //programaRestoDivisao(&ram, &cpu, 101, 10);

    //Executa um exemplo de fatorial
    //programaFatorial(&ram, &cpu, 5);

    //Executa um exemplo de potencia
   // programaPotencia(&ram,&cpu,3,4);

   //Executa um exemplo de fibonacci
   programaFibonacci(&ram, &cpu,8);


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

//Programa MULTIPLICACAO
void programaMultiplica(RAM *ram, CPU *cpu) {
    printf("Executando programaMultiplica()...\n");

   criarRAM_vazia(ram, 3);

    setDado(ram,0,4);//multiplicando
    setDado(ram,1,3);//multiplicador
    setDado(ram,2,0);//resultado

    Instrucao programa[3];

    for(int i=0;i<getDado(ram,1);i++){    
    programa[0].opcode = 0;//soma
    programa[0].add1 = 2;//acumulador
    programa[0].add2 = 1;//valor do multiplicando
    programa[0].add3 = 2;//guarda o resultado
    }

    programa[1].opcode = -1;//halt

    setPrograma(cpu, programa);
    iniciar(cpu, ram);

    printf("Resultado da multiplicação: %d\n\n", getDado(ram, 2));
}

//Programa DIVISAO
void programaDivide(RAM *ram, CPU *cpu) {
    printf("Executando programaDivide()...\n");

    criarRAM_vazia(ram, 3);

    setDado(ram,0,4);//dividendo
    setDado(ram,1,3);//divisor
    setDado(ram,2,0);//quociente
    setDado(ram,3,0);//resto

    while (getDado(ram,0)>= getDado(ram,1)){
        Instrucao subtrai[2];

        subtrai[0].opcode = 1;
        subtrai[0].add1 = 0;//dividendo
        subtrai[0].add2 = 1;//divisor
        subtrai[0].opcode = 0;//resultado
        subtrai[0].opcode = -1;//halt
    
        setPrograma(cpu,subtrai);
        iniciar(cpu,ram);

        //soma 1 ao quociente
        Instrucao soma[2];
        soma[0].opcode =0;//soma
        soma[0].add1 = 2;//quociente
        soma[0].add2 = 3;//valor 0
        soma[0].add3 = 2;// guarda em 2
        soma[1].opcode = -1;

        setDado(ram,3,1);
        setPrograma(cpu,soma);
        iniciar(cpu, ram);
        setDado(ram,3,0);
    }

    printf("Resultado da divisao: %d\n\n", getDado(ram, 2));
}

//Calcula a raíz quadrada
void programaRaizQuadrada(RAM *ram, CPU *cpu, int radicando){

    RAM ram2;
    criarRAM_vazia(ram, 2);
    ram->memoria[0] = radicando;
    cpu->registrador1 = 0;


    for(ram->memoria[1] = 1; cpu->registrador1 <= ram->memoria[0]; ram->memoria[1]++){
        programaMultiplica2(&ram2, cpu, ram->memoria[1], ram->memoria[1]);
        free(ram2.memoria);
    }
    
    printf("Resultado da raiz quadrada: %d", ram->memoria[1] - 2);
}

//Programa que multiplica dois números inteiros
void programaMultiplica2(RAM *ram, CPU *cpu, int multiplicando, int multiplicador){

    criarRAM_vazia(ram, 2);
    ram->memoria[0] = 0;
    ram->memoria[1] = multiplicando;

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

    for(int i = 0; i < multiplicador; i++){
        setPrograma(cpu, trecho1);
        iniciar(cpu, ram);
    }

    cpu->registrador1 = ram->memoria[trecho1[0].add1];

    printf("\nResultado da multiplicação: %d\n", cpu->registrador1);
}

void programaDivide2(RAM *ram, CPU *cpu, int dividendo, int divisor){

    criarRAM_vazia(ram, 3);
    ram->memoria[0] = dividendo;
    ram->memoria[1] = divisor;
    ram->memoria[2] = 0;

    Instrucao trecho1[3];
    Instrucao inst1, inst2, inst3;

    inst1.opcode = 1;
    inst1.add1 = 0;
    inst1.add2 = 1;
    inst1.add3 = 0;

    inst2.opcode = 0;
    inst2.add1 = 1;
    inst2.add2 = 2;
    inst2.add3 = 2;

    inst3.opcode = -1;
    inst3.add1 = -1;
    inst3.add2 = -1;
    inst3.add3 = -1;

    trecho1[0] = inst1;
    trecho1[1] = inst2;
    trecho1[2] = inst3;

    while(ram->memoria[trecho1[0].add1] >= ram->memoria[trecho1[0].add2]){
        setPrograma(cpu, trecho1);
        iniciar(cpu, ram);
    }

    cpu->registrador1 = ram->memoria[trecho1[1].add3];
    printf("Resultado da divisão: %d", cpu->registrador1);

}

//Programa que divide dois números inteiros
void programaRestoDivisao(RAM *ram, CPU *cpu, int dividendo, int divisor){

    criarRAM_vazia(ram, 2);
    ram->memoria[0] = dividendo;
    ram->memoria[1] = divisor;

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

    while(ram->memoria[trecho1[0].add1] >= ram->memoria[trecho1[0].add2]){
        setPrograma(cpu, trecho1);
        iniciar(cpu, ram);
    }

    cpu->registrador1 = ram->memoria[trecho1[0].add1];
    printf("Resto da divisão: %d", cpu->registrador1);
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

        // Multiplica resultado * contador (por somas sucessivas)
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

//PROGRAMA DE POTENCIA
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

//PROGRAMA DE FIBONACCI
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

// Grupo 10 - Otávio Enrique Lopes de Lima,Ana Gabriela Gomes Lopes Pereira e Heitor Novais Leite de Menezes
