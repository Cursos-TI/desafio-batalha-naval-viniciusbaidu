#include <stdio.h>

#define TAM 10      // tamanho fixo do tabuleiro 10x10
#define TAM_NAVIO 3 // tamanho fixo dos navios

int main() {
    int tabuleiro[TAM][TAM]; // matriz 10x10 representando o tabuleiro
    int i, j;

    // 1. Inicializa o tabuleiro com 0 (representando água)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // 2. Definindo as coordenadas iniciais dos navios
    // Coordenadas fixas no código (simplificação do enunciado)
    int linha_horizontal = 2; // linha onde o navio horizontal começa
    int coluna_horizontal = 4; // coluna inicial
    int linha_vertical = 5;   // linha inicial do navio vertical
    int coluna_vertical = 7;  // coluna onde o navio vertical está

    // 3. Posicionar navio horizontal (3 posições na mesma linha)
    // Validação simples para não ultrapassar os limites
    if (coluna_horizontal + TAM_NAVIO <= TAM) {
        for (j = 0; j < TAM_NAVIO; j++) {
            tabuleiro[linha_horizontal][coluna_horizontal + j] = 3;
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites!\n");
    }

    // 4. Posicionar navio vertical (3 posições na mesma coluna)
    // Validação simples para não ultrapassar os limites
    if (linha_vertical + TAM_NAVIO <= TAM) {
        for (i = 0; i < TAM_NAVIO; i++) {
            // Verifica se não há sobreposição
            if (tabuleiro[linha_vertical + i][coluna_vertical] == 0) {
                tabuleiro[linha_vertical + i][coluna_vertical] = 3;
            } else {
                printf("Erro: Sobreposição detectada!\n");
            }
        }
    } else {
        printf("Erro: Navio vertical fora dos limites!\n");
    }

    // 5. Exibir o tabuleiro na tela
    printf("\n--- Tabuleiro Batalha Naval ---\n\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
