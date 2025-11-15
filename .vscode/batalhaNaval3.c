#include <stdio.h>
#include <math.h> // Necessário para a função abs()
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

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
// --- Definições de Tamanho e Valores ---
// Tabuleiro: 10x10. Navio: Tamanho 3. Valor: 3
// Habilidade: 7x7. Valor: 1 (Afetado), 5 (No Tabuleiro)
#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 7
#define CENTRO_HABILIDADE 3 // O centro da matriz 7x7 é o índice 3 (Linha 3, Coluna 3)
#define VALOR_AFETADO 5     // Valor usado no tabuleiro para marcar a área de efeito

// --- Funções Auxiliares de Nível Novato/Aventureiro ---

void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Para este desafio, simplificaremos a validação e o posicionamento de navios para focar nas Habilidades.

void posicionarNavios(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Navio Horizontal: (2, 1)
    for (int j = 0; j < 3; j++) tabuleiro[2][1 + j] = 3;
    // Navio Vertical: (5, 7)
    for (int i = 0; i < 3; i++) tabuleiro[5 + i][7] = 3;
    // Navio Diagonal Crescente: (0, 0)
    for (int i = 0; i < 3; i++) tabuleiro[0 + i][0 + i] = 3;
    // Navio Diagonal Decrescente: (6, 9)
    for (int i = 0; i < 3; i++) tabuleiro[6 + i][9 - i] = 3;
}

// --- Funções de Geração das Matrizes de Habilidade ---

/**
 * @brief Gera a matriz de habilidade Cone (ponta no topo, expande para baixo).
 */
void gerarMatrizCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    // O cone aponta para baixo, centrado em (3, 3).
    // O número de células afetadas em cada linha (i) é proporcional à distância do topo.
    // O raio 'r' na linha 'i' é aproximadamente 'i'.
    
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            
            // Distância horizontal (j) do centro (3)
            int dist_j = abs(j - CENTRO_HABILIDADE); 
            
            // O cone se expande linearmente com a linha. 
            // Na linha i, o raio é (i), mas ajustamos para a forma.
            
            // Condicional: Se a distância horizontal for menor ou igual à linha atual, é afetado (1).
            // Ex: Linha 0 (i=0): só afeta o centro (j=3, dist_j=0).
            // Ex: Linha 3 (i=3): afeta j=0, 1, 2, 3, 4, 5, 6 (dist_j <= 3).
            if (dist_j <= i && i < 5) { // Limita o cone para uma forma triangular mais clara
                 matriz[i][j] = 1;
            } else {
                 matriz[i][j] = 0;
            }
        }
    }
}

/**
 * @brief Gera a matriz de habilidade Cruz (centro e linhas/colunas adjacentes).
 */
void gerarMatrizCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Condicional: Atinge se a linha for o centro OU a coluna for o centro.
            if (i == CENTRO_HABILIDADE || j == CENTRO_HABILIDADE) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

/**
 * @brief Gera a matriz de habilidade Octaedro (Losango, baseado na Distância de Manhattan).
 */
void gerarMatrizOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    // O octaedro (losango) é definido pela Distância de Manhattan: |i - centro| + |j - centro|.
    // Queremos afetar posições onde a soma das distâncias ao centro é menor ou igual a um raio (R=3).
    int raio = 3; // Metade do tamanho da matriz (7/2 = 3.5, arredondado para 3)
    
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            
            // Condicional: Se a Distância de Manhattan for menor ou igual ao raio, é afetado (1).
            // abs(i - 3) + abs(j - 3) <= 3
            if (abs(i - CENTRO_HABILIDADE) + abs(j - CENTRO_HABILIDADE) <= raio) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// --- Função de Sobreposição ---

/**
 * @brief Sobrepõe a matriz de habilidade ao tabuleiro principal no ponto de origem.
 * @param origem_i Linha do centro da habilidade no tabuleiro 10x10.
 * @param origem_j Coluna do centro da habilidade no tabuleiro 10x10.
 */
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], 
                       int origem_i, int origem_j) {
                           
    // Calcula o deslocamento da matriz de habilidade em relação ao centro do tabuleiro.
    // Ex: Se o centro da habilidade (7x7) é (3,3) e o ponto de origem é (5,5) no tabuleiro 10x10.
    // O canto superior esquerdo da habilidade começará em (5-3, 5-3) = (2, 2).
    int inicio_i = origem_i - CENTRO_HABILIDADE;
    int inicio_j = origem_j - CENTRO_HABILIDADE;

    // Loops aninhados para percorrer a matriz de habilidade (7x7)
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            
            // 1. Calcula a posição correspondente no tabuleiro 10x10
            int tab_i = inicio_i + i;
            int tab_j = inicio_j + j;
            
            // 2. Condicional para manter a área de efeito dentro dos limites do tabuleiro.
            if (tab_i >= 0 && tab_i < TAM_TABULEIRO && tab_j >= 0 && tab_j < TAM_TABULEIRO) {
                
                // 3. Condicional para aplicar o efeito (somente onde o valor na matriz de habilidade é 1)
                if (habilidade[i][j] == 1) {
                    
                    // Condicional de Sobrescrita: Se já houver um navio (3), não sobrescreve.
                    // Caso contrário, marca a área afetada com 5.
                    if (tabuleiro[tab_i][tab_j] != 3) {
                        tabuleiro[tab_i][tab_j] = VALOR_AFETADO; // 5
                    }
                }
            }
        }
    }
}

// --- Função de Exibição Formatada para Nível Mestre ---

void exibirTabuleiroMestre(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("   TABULEIRO MESTRE (0=Água, 3=Navio, 5=Habilidade)\n");
    printf("   "); 
    for (int j = 0; j < TAM_TABULEIRO; j++) printf("%c ", 'A' + j);
    printf("\n");
    
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d ", i + 1); 
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            // Usa caracteres diferentes para visualização aprimorada:
            if (tabuleiro[i][j] == 0)      printf("~ "); // Água
            else if (tabuleiro[i][j] == 3) printf("# "); // Navio
            else if (tabuleiro[i][j] == VALOR_AFETADO) printf("* "); // Habilidade (5)
            else                           printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


// --- Função Principal ---

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    
    // 1. Matrizes de Habilidade (7x7)
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    // 2. Geração das Matrizes de Efeito (Com Condicionais)
    gerarMatrizCone(cone);
    gerarMatrizCruz(cruz);
    gerarMatrizOctaedro(octaedro);
    
    // 3. Aplicação das Habilidades no Tabuleiro (Com Sobrescrita e Limites)
    printf("Aplicando Habilidades Especiais...\n");
    
    // Habilidade 1: Cone (Ponto de Origem: Linha 1, Coluna 5)
    aplicarHabilidade(tabuleiro, cone, 1, 5); 
    
    // Habilidade 2: Cruz (Ponto de Origem: Linha 6, Coluna 2)
    aplicarHabilidade(tabuleiro, cruz, 6, 2); 

    // Habilidade 3: Octaedro (Ponto de Origem: Linha 8, Coluna 8)
    aplicarHabilidade(tabuleiro, octaedro, 8, 8); 

    printf("Habilidades aplicadas com sucesso.\n\n");
    
    // 4. Exibição do Tabuleiro com Efeitos
    exibirTabuleiroMestre(tabuleiro);


    

    return 0;
}