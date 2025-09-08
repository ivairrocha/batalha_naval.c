/*
    Projeto Final - Batalha Naval com Habilidades Especiais
    Autor: Ivair Rocha
    Desafio: Nível Mestre

    Descrição:
        - Tabuleiro 10x10 (0 = água, 3 = navio)
        - Habilidades especiais com matrizes:
            Cone, Cruz e Octaedro
        - Sobreposição das áreas de efeito no tabuleiro
        - Áreas afetadas marcadas com valor 5
*/

#include <stdio.h>

#define TAM 10
#define HABIL 5 // tamanho fixo das matrizes de habilidade (5x5)

// ===================== Função para imprimir tabuleiro =====================
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("~ "); // água
            } else if (tabuleiro[i][j] == 3) {
                printf("N "); // navio
            } else if (tabuleiro[i][j] == 5) {
                printf("X "); // área de habilidade
            } else {
                printf("? "); // fallback
            }
        }
        printf("\n");
    }
    printf("\n");
}

// ===================== Matrizes de habilidades =====================
// Cone (expande de cima para baixo)
void criarCone(int cone[HABIL][HABIL]) {
    for (int i = 0; i < HABIL; i++) {
        for (int j = 0; j < HABIL; j++) {
            if (j >= HABIL/2 - i && j <= HABIL/2 + i) {
                cone[i][j] = 1; // dentro do cone
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

// Cruz (linha e coluna central)
void criarCruz(int cruz[HABIL][HABIL]) {
    for (int i = 0; i < HABIL; i++) {
        for (int j = 0; j < HABIL; j++) {
            if (i == HABIL/2 || j == HABIL/2) {
                cruz[i][j] = 1; // cruz
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// Octaedro (forma de losango)
void criarOctaedro(int oct[HABIL][HABIL]) {
    for (int i = 0; i < HABIL; i++) {
        for (int j = 0; j < HABIL; j++) {
            if (abs(i - HABIL/2) + abs(j - HABIL/2) <= HABIL/2) {
                oct[i][j] = 1; // dentro do octaedro
            } else {
                oct[i][j] = 0;
            }
        }
    }
}

// ===================== Aplicar habilidade no tabuleiro =====================
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[HABIL][HABIL], int origemX, int origemY) {
    int offset = HABIL / 2;
    for (int i = 0; i < HABIL; i++) {
        for (int j = 0; j < HABIL; j++) {
            if (habilidade[i][j] == 1) {
                int x = origemX + i - offset;
                int y = origemY + j - offset;
                // Verifica se está dentro do tabuleiro
                if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                    // Se não houver navio, marca como área de habilidade
                    if (tabuleiro[x][y] == 0) {
                        tabuleiro[x][y] = 5;
                    }
                }
            }
        }
    }
}

// ===================== MAIN =====================
int main() {
    int tabuleiro[TAM][TAM] = {0};

    // Colocar alguns navios fixos (3)
    tabuleiro[2][2] = 3;
    tabuleiro[5][5] = 3;
    tabuleiro[8][7] = 3;

    // Criar matrizes de habilidades
    int cone[HABIL][HABIL], cruz[HABIL][HABIL], oct[HABIL][HABIL];
    criarCone(cone);
    criarCruz(cruz);
    criarOctaedro(oct);

    printf("=== Tabuleiro Inicial ===\n");
    imprimirTabuleiro(tabuleiro);

    // Aplicar cone no centro superior
    aplicarHabilidade(tabuleiro, cone, 2, 5);
    printf("=== Tabuleiro com Habilidade: Cone ===\n");
    imprimirTabuleiro(tabuleiro);

    // Aplicar cruz no centro
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    printf("=== Tabuleiro com Habilidade: Cruz ===\n");
    imprimirTabuleiro(tabuleiro);

    // Aplicar octaedro na parte inferior
    aplicarHabilidade(tabuleiro, oct, 7, 3);
    printf("=== Tabuleiro com Habilidade: Octaedro ===\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
