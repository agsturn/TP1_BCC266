#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maquina.h"

struct RAM {
    int *memoria;
    int tamanho;
    int opcode;
    int pc;
};

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
void programaRaizQuadrada(RAM *ram, CPU *cpu, int radicando);
void programaMultiplica2(RAM *ram, CPU *cpu, int multiplicando, int multiplicador);
void programaDivide2(RAM *ram, CPU *cpu, int dividendo, int divisor);
void programaRestoDivisao(RAM *ram, CPU *cpu, int dividendo, int divisor);
void programaFatorial(RAM *ram, CPU *cpu, int numero);
void programaPotencia(RAM *ram, CPU *cpu, int base, int expoente);
void programaFibonacci(RAM *ram, CPU *cpu, int n);
void programaCapslock(RAM *ram, CPU *cpu, char *texto);
int programaMdc(RAM *ram, CPU *cpu, int numeroa, int numerob);
void programaMmc(RAM *ram, CPU *cpu, int numeroa, int numerob);
void programaBhaskara(RAM *ram, CPU *cpu, int a, int b, int c);

int main() {
    RAM *ram = criarRAM_vazia(100);

    CPU *cpu = malloc(sizeof(CPU)); // aloca CPU
    cpu->registrador1 = 0;
    cpu->registrador2 = 0;
    cpu->pc = 0;
    cpu->opcode = 0;
    cpu->programa = NULL;

    printf("=== Execução dos programas CAVE Language ===\n\n");

    // Exemplos de execução:
    // programaSoma(ram,cpu);
    // programaSubtrai(ram,cpu);
    // programaAleatorio(ram,cpu, 10);
    // programaRaizQuadrada(ram,cpu, 25);
    // programaMultiplica2(ram, cpu, 19, 23);
    // programaDivide2(ram,cpu, 101, 10);
    // programaRestoDivisao(ram, cpu, 101, 10);
    // programaFatorial(ram, cpu, 5);
    // programaPotencia(ram,cpu,3,4);
    // programaFibonacci(ram,cpu,8);
    // programaCapslock(ram,cpu, "eXemPLo");

    //programaMdc(ram,cpu, 8, 10);
    //programaMmc(ram,cpu, 2, 6);
    programaBhaskara(ram,cpu, 4, 6, 3);

    destruirRAM(ram);
    destruirCPU(cpu);

    return 0;
}

void programaSoma(RAM *ram, CPU *cpu) {
    printf("Executando programaSoma()...\n");

    // Zera os valores iniciais
    setDado(ram, 0, 7);   // RAM[0] = 7
    setDado(ram, 1, 5);   // RAM[1] = 5
    setDado(ram, 2, 0);   // RAM[2] = 0

    // Vetor de instruções
    Instrucao programa[2];

    // Soma RAM[0] + RAM[1] → RAM[2]
    programa[0].opcode = 0;
    programa[0].add1 = 0;
    programa[0].add2 = 1;
    programa[0].add3 = 2;

    // Fim do programa
    programa[1].opcode = -1;

    // Executa
    setPrograma(cpu, programa);
    iniciar(cpu, ram);

    printf("Resultado da soma: %d\n\n", getDado(ram, 2));
}

void programaSubtrai(RAM *ram, CPU *cpu) {
    printf("Executando programaSubtrai()...\n");

    // Zera valores da RAM
    setDado(ram, 0, 20); // RAM[0] = 20
    setDado(ram, 1, 8);  // RAM[1] = 8
    setDado(ram, 2, 0);  // RAM[2] = 0 (resultado)

    // Vetor de instruções
    Instrucao programa[2];

    // Subtração: RAM[0] - RAM[1] → RAM[2]
    programa[0].opcode = 1;
    programa[0].add1 = 0;
    programa[0].add2 = 1;
    programa[0].add3 = 2;

    // Fim do programa
    programa[1].opcode = -1;

    // Executa
    setPrograma(cpu, programa);
    iniciar(cpu, ram);

    printf("Resultado da subtração: %d\n\n", getDado(ram, 2));
}

// Programa ALEATÓRIO
void programaAleatorio(RAM *ram, CPU *cpu, int qdeInstrucoes) {
    printf("Executando programaAleatorio() com %d instruções...\n", qdeInstrucoes);

    criarRAM_aleatoria(100); // Cria uma RAM com 100 valores aleatórios

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

    // Inicializa CPU
    cpu->registrador1 = 0;
    cpu->registrador2 = 0;
    cpu->pc = 0;
    cpu->opcode = 0;

    // Executa o programa
    setPrograma(cpu, programa);
    iniciar(cpu, ram);

    free(programa);
}
// Calcula a raíz quadrada
void programaRaizQuadrada(RAM *ram, CPU *cpu, int radicando) {
    criarRAM_vazia(2);     // RAM com 2 posições
    setDado(ram, 0, radicando); // radicando
    cpu->registrador1 = 0;

    RAM* ram2 = criarRAM_vazia(2); // RAM auxiliar para multiplicação

    for (setDado(ram, 1, 1); cpu->registrador1 <= getDado(ram, 0); setDado(ram, 1, getDado(ram, 1) + 1)) {
        criarRAM_vazia(2);
        programaMultiplica2(ram2, cpu, getDado(ram, 1), getDado(ram, 1));
        free(ram2->memoria);
    }

    printf("Resultado da raiz quadrada: %d\n", getDado(ram, 1) - 2);
}

// Programa que multiplica dois números inteiros
void programaMultiplica2(RAM *ram, CPU *cpu, int multiplicando, int multiplicador) {
    criarRAM_vazia(2);
    setDado(ram, 0, 0);          // acumulador
    setDado(ram, 1, multiplicando);

    Instrucao trecho1[2];
    // instrução de soma: RAM[0] += RAM[1]
    trecho1[0].opcode = 0;
    trecho1[0].add1 = 0;
    trecho1[0].add2 = 1;
    trecho1[0].add3 = 0;

    // instrução de halt
    trecho1[1].opcode = -1;
    trecho1[1].add1 = -1;
    trecho1[1].add2 = -1;
    trecho1[1].add3 = -1;

    // inicializa CPU
    cpu->registrador1 = 0;
    cpu->registrador2 = 0;
    cpu->pc = 0;
    cpu->opcode = 0;

    // repete a soma multiplicador vezes
    for (int i = 0; i < multiplicador; i++) {
        setPrograma(cpu, trecho1);
        iniciar(cpu, ram);
    }

    cpu->registrador1 = getDado(ram, 0);
    printf("Resultado da multiplicação: %d\n", cpu->registrador1);
}
// Programa que realiza divisão inteira
void programaDivide2(RAM *ram, CPU *cpu, int dividendo, int divisor) {
    criarRAM_vazia(3);
    setDado(ram, 0, dividendo); // dividendo
    setDado(ram, 1, divisor);   // divisor
    setDado(ram, 2, 0);         // quociente

    Instrucao trecho1[3];

    // Subtrai divisor do dividendo e guarda em dividendo
    trecho1[0].opcode = 1;
    trecho1[0].add1 = 0; // dividendo
    trecho1[0].add2 = 1; // divisor
    trecho1[0].add3 = 0; // resultado no dividendo

    // Incrementa quociente
    trecho1[1].opcode = 0;
    trecho1[1].add1 = 2; // quociente
    trecho1[1].add2 = 3; // RAM[3] será 1
    trecho1[1].add3 = 2; // salva quociente

    // HALT
    trecho1[2].opcode = -1;
    trecho1[2].add1 = -1;
    trecho1[2].add2 = -1;
    trecho1[2].add3 = -1;

    setDado(ram, 3, 1); // RAM[3] = 1 temporário para incrementar

    cpu->registrador1 = 0;
    cpu->registrador2 = 0;
    cpu->pc = 0;
    cpu->opcode = 0;

    while (getDado(ram, 0) >= getDado(ram, 1)) {
        setPrograma(cpu, trecho1);
        iniciar(cpu, ram);
    }

    cpu->registrador1 = getDado(ram, 2);
    printf("Resultado da divisão: %d\n", cpu->registrador1);
}

// Programa que calcula o resto da divisão
void programaRestoDivisao(RAM *ram, CPU *cpu, int dividendo, int divisor) {
    criarRAM_vazia(2);
    setDado(ram, 0, dividendo); // dividendo
    setDado(ram, 1, divisor);   // divisor

    Instrucao trecho1[2];

    // Subtrai divisor do dividendo
    trecho1[0].opcode = 1;
    trecho1[0].add1 = 0; // dividendo
    trecho1[0].add2 = 1; // divisor
    trecho1[0].add3 = 0; // resultado no dividendo

    // HALT
    trecho1[1].opcode = -1;
    trecho1[1].add1 = -1;
    trecho1[1].add2 = -1;
    trecho1[1].add3 = -1;

    cpu->registrador1 = 0;
    cpu->registrador2 = 0;
    cpu->pc = 0;
    cpu->opcode = 0;

    while (getDado(ram, 0) >= getDado(ram, 1)) {
        setPrograma(cpu, trecho1);
        iniciar(cpu, ram);
    }

    cpu->registrador1 = getDado(ram, 0); // resto
    printf("Resto da divisão: %d\n", cpu->registrador1);
}

// PROGRAMA DE FATORIAL
void programaFatorial(RAM *ram, CPU *cpu, int numero) {
    printf("Executando programaFatorial(%d)...\n", numero);

    criarRAM_vazia(4);
    // RAM[0] = número base
    // RAM[1] = contador
    // RAM[2] = resultado parcial
    // RAM[3] = auxiliar

    setDado(ram, 0, numero); // número
    setDado(ram, 1, 1);      // contador = 1
    setDado(ram, 2, 1);      // resultado = 1
    setDado(ram, 3, 0);      // auxiliar

    cpu->registrador1 = 0;
    cpu->registrador2 = 0;
    cpu->pc = 0;

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
            soma[1].add1 = soma[1].add2 = soma[1].add3 = -1;

            setPrograma(cpu, soma);
            iniciar(cpu, ram);
        }

        // Atualiza o resultado com o valor de RAM[3]
        setDado(ram, 2, getDado(ram, 3));

        // Incrementa contador (contador = contador + 1)
        setDado(ram, 3, 1); // RAM[3] = 1 temporário
        Instrucao somaContador[2];
        somaContador[0].opcode = 0;
        somaContador[0].add1 = 1; // contador
        somaContador[0].add2 = 3; // RAM[3] = 1
        somaContador[0].add3 = 1; // salva contador
        somaContador[1].opcode = -1;
        somaContador[1].add1 = somaContador[1].add2 = somaContador[1].add3 = -1;

        setPrograma(cpu, somaContador);
        iniciar(cpu, ram);
    }

    printf("Fatorial de %d = %d\n", numero, getDado(ram, 2));
}

// PROGRAMA DE POTÊNCIA
void programaPotencia(RAM *ram, CPU *cpu, int base, int expoente) {
    printf("Executando programaPotencia(%d, %d)...\n", base, expoente);

    criarRAM_vazia(4);
    // RAM[0] = base
    // RAM[1] = expoente
    // RAM[2] = resultado parcial
    // RAM[3] = auxiliar

    setDado(ram, 0, base);
    setDado(ram, 1, expoente);
    setDado(ram, 2, 1); // resultado começa em 1
    setDado(ram, 3, 0); // auxiliar

    cpu->registrador1 = 0;
    cpu->registrador2 = 0;
    cpu->pc = 0;

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
            soma[1].add1 = soma[1].add2 = soma[1].add3 = -1;

            setPrograma(cpu, soma);
            iniciar(cpu, ram);
        }

        setDado(ram, 2, getDado(ram, 3)); // Atualiza resultado

        // Decrementa expoente
        setDado(ram, 3, 1); // RAM[3] = 1 temporário
        Instrucao subtrai[2];
        subtrai[0].opcode = 1; // subtração
        subtrai[0].add1 = 1;   // RAM[1] = expoente
        subtrai[0].add2 = 3;   // RAM[3] = 1
        subtrai[0].add3 = 1;   // salva de volta
        subtrai[1].opcode = -1;
        subtrai[1].add1 = subtrai[1].add2 = subtrai[1].add3 = -1;

        setPrograma(cpu, subtrai);
        iniciar(cpu, ram);
    }

    printf("Resultado da potencia: %d^%d = %d\n", base, expoente, getDado(ram, 2));
}

// PROGRAMA DE FIBONACCI
void programaFibonacci(RAM *ram, CPU *cpu, int n) {
    printf("Executando programaFibonacci(%d)...\n", n);

    criarRAM_vazia(4);
    // RAM[0] = quantidade de termos
    // RAM[1] = termo anterior
    // RAM[2] = termo atual
    // RAM[3] = próximo termo

    setDado(ram, 0, n);
    setDado(ram, 1, 0);
    setDado(ram, 2, 1);
    setDado(ram, 3, 0);

    cpu->registrador1 = 0;
    cpu->registrador2 = 0;
    cpu->pc = 0;

    printf("Sequência de Fibonacci (%d termos):\n", n);
    if(n >= 1) printf("%d ", getDado(ram, 1));
    if(n >= 2) printf("%d ", getDado(ram, 2));

    // gera os próximos termos
    for (int i = 3; i <= getDado(ram, 0); i++) {
        Instrucao soma[2];
        soma[0].opcode = 0;  // soma (RAM[3] = RAM[1] + RAM[2])
        soma[0].add1 = 1;
        soma[0].add2 = 2;
        soma[0].add3 = 3;
        soma[1].opcode = -1;
        soma[1].add1 = soma[1].add2 = soma[1].add3 = -1;

        setPrograma(cpu, soma);
        iniciar(cpu, ram);

        printf("%d ", getDado(ram, 3));

        // Atualiza os termos
        setDado(ram, 1, getDado(ram, 2));
        setDado(ram, 2, getDado(ram, 3));
    }
    printf("\n");
}

void programaCapslock(RAM *ram, CPU *cpu, char *texto) {

    int n = strlen(texto);

    criarRAM_vazia(n + 1);
    cpu->registrador1 = 0;
    cpu->registrador2 = 0;
    cpu->pc = 0;

    // copia string para RAM
    for (int i = 0; i < n; i++) {
        ram->memoria[i] = (int)texto[i];
    }

    // armazena o valor 32 (diferença entre 'a' e 'A')
    ram->memoria[n] = 32;

    Instrucao inst[2];
    inst[0].opcode = 1;   // SUBTRAI
    inst[0].add2 = n;     // subtrair 32
    inst[1].opcode = -1;  // HALT
    inst[1].add1 = inst[1].add2 = inst[1].add3 = -1;

    for (int i = 0; i < n; i++) {
        int c = ram->memoria[i];
        if (c >= 'a' && c <= 'z') {
            inst[0].add1 = i;
            inst[0].add3 = i;

            setPrograma(cpu, inst);
            iniciar(cpu, ram);
        }
    }

    printf("String convertida para CAPSLOCK: ");
    for (int i = 0; i < n; i++) {
        printf("%c", (char)ram->memoria[i]);
    }
    printf("\n");
}

int programaMdc(RAM *ram, CPU *cpu, int numeroa, int numerob) {
    printf("Executando programaMdc(%d, %d)...\n", numeroa, numerob);

    // Casos especiais
    if (numeroa == 0 && numerob == 0) {
        printf("MDC(0,0) não definido.\n\n");
        return 0;
    }

    if (numeroa == 0) {
        int resultado = numeroa;
        if (numerob < 0) {
            resultado = -numerob;
        } else {
            resultado = numerob;
        }
        printf("MDC(%d,%d) = %d\n\n", numeroa, numerob, resultado);
        return resultado;
    }

    if (numerob == 0) {
        int resultado = numeroa;
        if (numeroa < 0) {
            resultado = -numeroa;
        }
        printf("MDC(%d,%d) = %d\n\n", numeroa, numerob, resultado);
        return resultado;
    }

    // Valores absolutos
    int a = numeroa;
    int b = numerob;
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    cpu->registrador1 = 0;
    cpu->registrador2 = 0;
    cpu->pc = 0;

    while (b != 0) {
        int temp = b;
        programaRestoDivisao(ram, cpu, a, b);
        b = cpu->registrador1; // resto
        a = temp;
    }

    printf("MDC(%d,%d) = %d\n\n", numeroa, numerob, a);
    return a;
}

void programaMmc(RAM *ram, CPU *cpu, int numeroa, int numerob) {
    printf("Executando programaMmc(%d, %d)...\n", numeroa, numerob);

    if (numeroa == 0 || numerob == 0) {
        printf("MMC(%d,%d) = 0\n\n", numeroa, numerob);
        return;
    }

    int a_abs = numeroa;
    int b_abs = numerob;
    if (a_abs < 0) a_abs = -a_abs;
    if (b_abs < 0) b_abs = -b_abs;

    cpu->registrador1 = 0;
    cpu->registrador2 = 0;
    cpu->pc = 0;

    int mdc = programaMdc(ram, cpu, a_abs, b_abs);

    programaMultiplica2(ram, cpu, a_abs, b_abs);
    int produto = cpu->registrador1;

    programaDivide2(ram, cpu, produto, mdc);
    int mmc = cpu->registrador1;

    printf("MMC(%d,%d) = %d\n\n", numeroa, numerob, mmc);
}

void programaBhaskara(RAM *ram, CPU *cpu, int a, int b, int c) {
    printf("Executando programaBhaskara(%d, %d, %d)...\n", a, b, c);
    printf("Resolvendo: %dx² + %dx + %d = 0\n", a, b, c);

    cpu->registrador1 = 0;
    cpu->registrador2 = 0;
    cpu->pc = 0;

    // Equação linear
    if (a == 0) {
        if (b == 0) {
            printf("Não é uma equação válida.\n\n");
        } else {
            programaDivide2(ram, cpu, -c, b);
            printf("Equação linear: x = %d\n\n", cpu->registrador1);
        }
        return;
    }

    // Calculando delta
    programaMultiplica2(ram, cpu, b, b);
    int b2 = cpu->registrador1;

    programaMultiplica2(ram, cpu, 4, a);
    int quatro_a = cpu->registrador1;

    programaMultiplica2(ram, cpu, quatro_a, c);
    int quatro_ac = cpu->registrador1;

    int delta = b2 - quatro_ac;
    printf("Delta = %d\n", delta);

    if (delta < 0) {
        printf("Não existem raízes reais (Δ < 0).\n\n");
        return;
    }

    if (delta == 0) {
        programaDivide2(ram, cpu, -b, 2 * a);
        printf("Raiz única: x = %d\n\n", cpu->registrador1);
        return;
    }

    // Raízes distintas
    int raiz_delta = 0;
    while (raiz_delta * raiz_delta <= delta) {
        raiz_delta++;
    }
    raiz_delta--;

    programaDivide2(ram, cpu, -b + raiz_delta, 2 * a);
    int x1 = cpu->registrador1;

    programaDivide2(ram, cpu, -b - raiz_delta, 2 * a);
    int x2 = cpu->registrador1;

    printf("Duas raízes reais:\n");
    printf("x₁ = %d\n", x1);
    printf("x₂ = %d\n\n", x2);
}

// Grupo 10 - Otávio Enrique Lopes de Lima,Ana Gabriela Gomes Lopes Pereira e Heitor Novais Leite de Menezes