#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// --- Funções Auxiliares ---

/**
 * @brief Inicializa o tabuleiro 10x10 preenchendo todas as posições com 0 (Água).
 * @param tabuleiro A matriz 10x10.
 */
void inicializarTabuleiro(int tabuleiro[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0; // 0 é ÁGUA
        }
    }
}

/**
 * @brief Exibe o tabuleiro 10x10 no console com rótulos de linha e coluna (A-J, 1-10).
 * @param tabuleiro A matriz 10x10.
 */
void exibirTabuleiro(int tabuleiro[10][10]) {
    
    // 1. CABEÇALHO E RÓTULOS DE COLUNA (A B C D E F G H I J)
    printf("   TABULEIRO BATALHA NAVAL\n");
    printf("   "); 
    
    // Loop para imprimir as letras das colunas (A a J)
    for (int j = 0; j < 10; j++) {
        printf("%c ", 'A' + j); 
    }
    printf("\n");
    
    // 2. IMPRESSÃO DAS LINHAS E CÉLULAS
    // Loop externo: Linhas (i)
    for (int i = 0; i < 10; i++) {
        
        // RÓTULO DE LINHA (1, 2, ..., 10)
        // %2d garante o alinhamento de números de 1 e 2 dígitos
        printf("%2d ", i + 1); 
        
        // Loop interno: Colunas (j)
        for (int j = 0; j < 10; j++) {
            // Imprime o valor da célula (0 ou 3) seguido de um espaço
            printf("%d ", tabuleiro[i][j]); 
        }
        
        printf("\n"); // Quebra de linha no final de cada linha da matriz
    }
}

int main() {
   
    printf("TABULEIRO MVP\n");
    // Nível Novato - Posicionamento dos Navios
    
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
       
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    // 1. DECLARAR O TABULEIRO: Matriz bidimensional 10x10.
    int tabuleiro[10][10];
    
    // 2. INICIALIZAR O TABULEIRO com 0 (ÁGUA).
    inicializarTabuleiro(tabuleiro);
    
    printf("🗺️ Tabuleiro inicializado (10x10 com 0s - água).\n\n");
    
    // --- 3. POSICIONAMENTO DOS NAVIOS ---
    
    // Navio Horizontal (Tamanho 3)
    // Coordenadas Iniciais: Linha 2, Coluna 1. Ocupará (2,1), (2,2), (2,3)
    int linha_h = 2;   
    int coluna_h = 1;  
    
    printf("⚓ Posicionando Navio Horizontal em Linha %d, Coluna %d...\n", linha_h, coluna_h);
    
    // Loop para desenhar o navio horizontal (mantém a linha, varia a coluna)
    for (int j = 0; j < 3; j++) {
        tabuleiro[linha_h][coluna_h + j] = 3; // 3 é o NAVIO
    }

    // Navio Vertical (Tamanho 3)
    // Coordenadas Iniciais: Linha 5, Coluna 7. Ocupará (5,7), (6,7), (7,7)
    int linha_v = 5;   
    int coluna_v = 7;  
    
    printf("⚓ Posicionando Navio Vertical em Linha %d, Coluna %d...\n", linha_v, coluna_v);
    
    // Loop para desenhar o navio vertical (mantém a coluna, varia a linha)
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha_v + i][coluna_v] = 3; // 3 é o NAVIO
    }
    
    printf("Navios posicionados com sucesso!\n\n");
    
    // --- 4. EXIBIR O TABULEIRO ---
    exibirTabuleiro(tabuleiro);
    
    printf("\nLegenda: 0 = Água | 3 = Navio\n");


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

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
