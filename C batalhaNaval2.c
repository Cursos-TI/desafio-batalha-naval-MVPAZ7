#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
   // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
   // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
   // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.
   // Tamanho do tabuleiro e do navio fixos
   // Não usaremos #define, mas estes são os valores fixos do desafio:
   // Tabuleiro: 10x10
   // Navio: Tamanho 3
   // Valores: 0 (Água), 3 (Navio)

// --- Funções Auxiliares ---

void inicializarTabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // 0 é ÁGUA
        }
    }
}

void exibirTabuleiro(int tabuleiro[10][10]) {
    printf("   TABULEIRO BATALHA NAVAL\n");
    printf("   "); 
    
    for (int j = 0; j < 10; j++) {
        printf("%c ", 'A' + j); 
    }
    printf("\n");
    
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1); 
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]); 
        }
        printf("\n");
    }
}

// --- Funções de Validação) ---

// Retorna 1 se for válido, 0 se for inválido
int validarPosicaoHorizontal(int tabuleiro[10][10], int linha, int coluna) {
    // 1. Limites: (Linha deve ser < 10 e Coluna + 3 deve ser <= 10)
    if (linha < 0 || linha >= 10 || coluna < 0 || coluna + 3 > 10) {
        printf("ERRO: Horizontal fora dos limites.\n");
        return 0;
    }

    // 2. Sobreposição
    for (int j = 0; j < 3; j++) {
        if (tabuleiro[linha][coluna + j] == 3) {
            printf("ERRO: Horizontal sobreposto.\n");
            return 0;
        }
    }
    return 1;
}

// Retorna 1 se for válido, 0 se for inválido
int validarPosicaoVertical(int tabuleiro[10][10], int linha, int coluna) {
    // 1. Limites: (Coluna deve ser < 10 e Linha + 3 deve ser <= 10)
    if (coluna < 0 || coluna >= 10 || linha < 0 || linha + 3 > 10) {
        printf("ERRO: Vertical fora dos limites.\n");
        return 0;
    }

    // 2. Sobreposição
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linha + i][coluna] == 3) {
            printf("ERRO: Vertical sobreposto.\n");
            return 0;
        }
    }
    return 1;
}

// --- Funções para Navios Diagonais ---

/**
 * @brief Verifica um navio Diagonal Crescente (Linha e Coluna aumentam: \ ).
 * @param linha_inicial Linha de partida.
 * @param coluna_inicial Coluna de partida.
 * @return 1 se for válido, 0 se for inválido.
 */
int validarPosicaoDiagonalCrescente(int tabuleiro[10][10], int linha, int coluna) {
    // 1. Limites: (Linha + 3 <= 10 E Coluna + 3 <= 10)
    if (linha < 0 || linha + 3 > 10 || coluna < 0 || coluna + 3 > 10) {
        printf("ERRO: Diagonal Crescente fora dos limites.\n");
        return 0;
    }

    // 2. Sobreposição: Verifica as 3 posições (i=0, 1, 2)
    for (int i = 0; i < 3; i++) {
        // A posição verificada é tabuleiro[linha + i][coluna + i]
        if (tabuleiro[linha + i][coluna + i] == 3) {
            printf("ERRO: Diagonal Crescente sobreposto.\n");
            return 0;
        }
    }
    return 1;
}

/**
 * @brief Verifica um navio Diagonal Decrescente (Linha aumenta, Coluna diminui: / ).
 * @param linha_inicial Linha de partida.
 * @param coluna_inicial Coluna de partida.
 * @return 1 se for válido, 0 se for inválido.
 */
int validarPosicaoDiagonalDecrescente(int tabuleiro[10][10], int linha, int coluna) {
    // 1. Limites: 
    // Linha: deve ter espaço para 3 para baixo (linha + 3 <= 10)
    // Coluna: deve ter espaço para 3 para a esquerda (coluna - 3 + 1 >= 0)
    if (linha < 0 || linha + 3 > 10 || coluna < 2 || coluna >= 10) {
        // A coluna deve ser pelo menos 2 (para ter colunas 2, 1, 0)
        printf("ERRO: Diagonal Decrescente fora dos limites.\n");
        return 0;
    }

    // 2. Sobreposição: Verifica as 3 posições (i=0, 1, 2)
    for (int i = 0; i < 3; i++) {
        // A posição verificada é tabuleiro[linha + i][coluna - i]
        if (tabuleiro[linha + i][coluna - i] == 3) {
            printf("ERRO: Diagonal Decrescente sobreposto.\n");
            return 0;
        }
    }
    return 1;
}

// --- Função Principal ---

int main() {
    int tabuleiro[10][10];
    inicializarTabuleiro(tabuleiro);
    
    printf("🗺️ Tabuleiro inicializado (10x10 com 0s - água).\n\n");
    
    int posicionado_sucesso;

    // --- 1. NAVIO HORIZONTAL (Linha 2, Coluna 1) ---
    int linha_h = 2;   
    int coluna_h = 1;  
    
    posicionado_sucesso = validarPosicaoHorizontal(tabuleiro, linha_h, coluna_h);
    if (posicionado_sucesso == 1) {
        printf("⚓ H1: OK. Posicionando em (%d, %d)...\n", linha_h, coluna_h);
        for (int j = 0; j < 3; j++) {
            tabuleiro[linha_h][coluna_h + j] = 3;
        }
    } else {
        printf("❌ H1: Posicionamento falhou.\n");
    }

    // --- 2. NAVIO VERTICAL (Linha 5, Coluna 7) ---
    int linha_v = 5;   
    int coluna_v = 7;  
    
    posicionado_sucesso = validarPosicaoVertical(tabuleiro, linha_v, coluna_v);
    if (posicionado_sucesso == 1) {
        printf("⚓ V1: OK. Posicionando em (%d, %d)...\n", linha_v, coluna_v);
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha_v + i][coluna_v] = 3;
        }
    } else {
        printf("❌ V1: Posicionamento falhou.\n");
    }
    
    // --- 3. NAVIO DIAGONAL CRESCENTE (\) (Linha 0, Coluna 0) ---
    // Ocupará (0,0), (1,1), (2,2)
    int linha_dc = 0; 
    int coluna_dc = 0; 

    posicionado_sucesso = validarPosicaoDiagonalCrescente(tabuleiro, linha_dc, coluna_dc);
    if (posicionado_sucesso == 1) {
        printf("⚓ DC1: OK. Posicionando em (%d, %d)...\n", linha_dc, coluna_dc);
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha_dc + i][coluna_dc + i] = 3; // Linha e Coluna aumentam
        }
    } else {
        printf("❌ DC1: Posicionamento falhou.\n");
    }
    
    // --- 4. NAVIO DIAGONAL DECRESCENTE (/) (Linha 6, Coluna 9) ---
    // Ocupará (6,9), (7,8), (8,7)
    int linha_dd = 6; 
    int coluna_dd = 9; 

    posicionado_sucesso = validarPosicaoDiagonalDecrescente(tabuleiro, linha_dd, coluna_dd);
    if (posicionado_sucesso == 1) {
        printf("⚓ DD1: OK. Posicionando em (%d, %d)...\n", linha_dd, coluna_dd);
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha_dd + i][coluna_dd - i] = 3; // Linha aumenta, Coluna diminui
        }
    } else {
        printf("❌ DD1: Posicionamento falhou.\n");
    }

    printf("\n--- 🚢 Tabuleiro com 4 Navios Posicionados --- \n");
    exibirTabuleiro(tabuleiro);
    printf("\nLegenda: 0 = Água | 3 = Navio\n");


    
    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
