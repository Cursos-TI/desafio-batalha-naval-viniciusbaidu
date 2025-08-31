#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Novato: Posicionamento dos Navios
// Este programa cria um tabuleiro 10x10, inicializa todas as posições como água (0),
// e posiciona dois navios de tamanho 3: um na horizontal e outro na vertical.
// As posições ocupadas pelos navios são marcadas com o valor 3.

int main() {
    // Definição do tamanho do tabuleiro e dos navios
    #define TAM 10
    #define TAM_NAVIO 3

    int tabuleiro[TAM][TAM]; // Matriz 10x10 representando o tabuleiro
    int i, j;

    // 1. Inicializar todas as posições do tabuleiro com 0 (água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Definir coordenadas iniciais dos navios (fixas no código para simplificação)
    int linha_horizontal = 2;   // Linha de início do navio horizontal
    int coluna_horizontal = 4;  // Coluna de início do navio horizontal

    int linha_vertical = 5;     // Linha de início do navio vertical
    int coluna_vertical = 7;    // Coluna de início do navio vertical

    // 3. Posicionar navio horizontal (3 posições na mesma linha)
    if (coluna_horizontal + TAM_NAVIO <= TAM) {
        for (j = 0; j < TAM_NAVIO; j++) {
            tabuleiro[linha_horizontal][coluna_horizontal + j] = 3;
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites!\n");
    }

    // 4. Posicionar navio vertical (3 posições na mesma coluna)
    if (linha_vertical + TAM_NAVIO <= TAM) {
        for (i = 0; i < TAM_NAVIO; i++) {
            // Verificação de sobreposição
            if (tabuleiro[linha_vertical + i][coluna_vertical] == 0) {
                tabuleiro[linha_vertical + i][coluna_vertical] = 3;
            } else {
                printf("Erro: Sobreposição detectada!\n");
            }
        }
    } else {
        printf("Erro: Navio vertical fora dos limites!\n");
    }

    // 5. Exibir o tabuleiro
    printf("\n--- Tabuleiro Batalha Naval (Nível Novato) ---\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
