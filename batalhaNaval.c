// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
// => ** Nível Novato ** - Posicionamento dos Navios
// Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
// Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
// Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
#include <stdio.h>
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro (preenchendo com água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA; // Inicializa todas as posições com água (0)
        }
    }
}

// Função para verificar se é possível posicionar um navio
int verificarPosicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                     int linha, int coluna, int horizontal) {
    
    // Verifica se o navio está dentro dos limites do tabuleiro
    if (horizontal) {
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return 0; // Fora dos limites horizontais
        }
        
        // Verifica se há sobreposição com outro navio
        for (int j = 0; j < TAMANHO_NAVIO; j++) {
            if (tabuleiro[linha][coluna + j] == NAVIO) {
                return 0; // Sobreposição detectada
            }
        }
    } else { // Vertical
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            return 0; // Fora dos limites verticais
        }
        
        // Verifica se há sobreposição com outro navio
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] == NAVIO) {
                return 0; // Sobreposição detectada
            }
        }
    }
    
    return 1; // Posição válida
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                     int linha, int coluna, int horizontal) {
    
    if (verificarPosicao(tabuleiro, linha, coluna, horizontal)) {
        // Cria um vetor para representar o navio
        int navio[TAMANHO_NAVIO];
        
        // Inicializa o navio
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            navio[i] = NAVIO;
        }
        
        // Posiciona o navio no tabuleiro
        if (horizontal) {
            for (int j = 0; j < TAMANHO_NAVIO; j++) {
                tabuleiro[linha][coluna + j] = navio[j];
            }
            printf("Navio horizontal posicionado na linha %d, coluna %d\n", linha, coluna);
        } else { // Vertical
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha + i][coluna] = navio[i];
            }
            printf("Navio vertical posicionado na linha %d, coluna %d\n", linha, coluna);
        }
    } else {
        printf("Não foi possível posicionar o navio na posição (%d,%d)\n", linha, coluna);
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n  ");
    // Exibe os números das colunas
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");
    
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Exibe o número da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Declaração do tabuleiro (matriz 10x10)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicialização do tabuleiro
    inicializarTabuleiro(tabuleiro);
    
    // Coordenadas para o navio horizontal (linha 2, coluna 3)
    int linhaH = 2;
    int colunaH = 3;
    
    // Coordenadas para o navio vertical (linha 5, coluna 7)
    int linhaV = 5;
    int colunaV = 7;
    
    // Posiciona os navios no tabuleiro
    posicionarNavio(tabuleiro, linhaH, colunaH, 1); // Horizontal
    posicionarNavio(tabuleiro, linhaV, colunaV, 0); // Vertical
    
    // Exibe o tabuleiro
    printf("\nTabuleiro de Batalha Naval (0 = água, 3 = navio):\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}