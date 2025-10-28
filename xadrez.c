#include <stdio.h>

/* ============================================================
   NÍVEL NOVATO
   Movimentos básicos usando estruturas de repetição simples
   ============================================================ */
void nivelNovato() {
    // Constantes de movimento
    const int BISPO_MOV = 5;
    const int TORRE_MOV = 5;
    const int RAINHA_MOV = 8;

    printf("\n=== NIVEL NOVATO ===\n\n");

    /* ----- BISPO -----
       Move 5 casas na diagonal superior direita
       (movimento: Cima + Direita) */
    printf("Movimento do Bispo:\n");
    for (int i = 1; i <= BISPO_MOV; i++) {
        printf("Cima\n");
        printf("Direita\n");
    }
    printf("\n");

    /* ----- TORRE -----
       Move 5 casas para a direita */
    printf("Movimento da Torre:\n");
    int j = 1;
    while (j <= TORRE_MOV) {
        printf("Direita\n");
        j++;
    }
    printf("\n");

    /* ----- RAINHA -----
       Move 8 casas para a esquerda */
    printf("Movimento da Rainha:\n");
    int k = 1;
    do {
        printf("Esquerda\n");
        k++;
    } while (k <= RAINHA_MOV);

    printf("\n");
}

/* ============================================================
   NÍVEL AVENTUREIRO
   Movimento do Cavalo em L (baixo e esquerda)
   Usando loops aninhados
   ============================================================ */
void nivelAventureiro() {
    printf("\n=== NIVEL AVENTUREIRO ===\n\n");
    printf("Movimento do Cavalo (em L - para Baixo e Esquerda):\n");

    // O cavalo se move em L: 2 casas para baixo e 1 para a esquerda
    for (int i = 1; i <= 2; i++) {   // 2 passos para baixo
        printf("Baixo\n");

        int j = 1;
        while (j <= 1) {             // 1 passo para a esquerda
            printf("Esquerda\n");
            j++;
        }
    }

    printf("\n");
}

/* ============================================================
   NÍVEL MESTRE
   Uso de funções recursivas e loops avançados
   ============================================================ */

/* ----- Funções recursivas para movimentação ----- */
void moverBispo(int passo, int total) {
    if (passo > total) return;        // condição de parada
    printf("Cima\n");
    printf("Direita\n");
    moverBispo(passo + 1, total);     // chamada recursiva
}

void moverTorre(int passo, int total) {
    if (passo > total) return;
    printf("Direita\n");
    moverTorre(passo + 1, total);
}

void moverRainha(int passo, int total) {
    if (passo > total) return;
    printf("Esquerda\n");
    moverRainha(passo + 1, total);
}

/* ----- Função principal do nível mestre ----- */
void nivelMestre() {
    const int BISPO_MOV = 5;
    const int TORRE_MOV = 5;
    const int RAINHA_MOV = 8;

    printf("\n=== NIVEL MESTRE ===\n\n");

    // BISPO - recursivo com loop aninhado simbólico
    printf("Movimento do Bispo (Recursivo + Loop Aninhado):\n");
    for (int i = 0; i < 1; i++) {
        moverBispo(1, BISPO_MOV);
    }
    printf("\n");

    // TORRE - recursiva
    printf("Movimento da Torre (Recursiva):\n");
    moverTorre(1, TORRE_MOV);
    printf("\n");

    // RAINHA - recursiva
    printf("Movimento da Rainha (Recursiva):\n");
    moverRainha(1, RAINHA_MOV);
    printf("\n");

    // CAVALO - com múltiplas variáveis, condições e uso de continue/break
    printf("Movimento do Cavalo (L - para Cima e Direita):\n");

    for (int i = 0, j = 0; i < 3 && j < 2; i++, j++) {
        if (i < 2) {
            printf("Cima\n");
            if (i == 1) continue;     // pula o restante do ciclo atual
        }

        if (j < 1) {
            printf("Direita\n");
        }

        if (i >= 2 && j >= 1) break;  // encerra quando o movimento L termina
    }

    printf("\n");
}

/* ============================================================
   FUNÇÃO PRINCIPAL
   Menu de seleção de níveis
   ============================================================ */
int main() {
    int opcao;

    printf("=====================================\n");
    printf("   DESAFIO DE XADREZ - MATECHECK\n");
    printf("=====================================\n");
    printf("Escolha o nível de desafio:\n");
    printf("1 - Nivel Novato\n");
    printf("2 - Nivel Aventureiro\n");
    printf("3 - Nivel Mestre\n");
    printf("0 - Sair\n");
    printf("=====================================\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            nivelNovato();
            break;

        case 2:
            nivelAventureiro();
            break;

        case 3:
            nivelMestre();
            break;

        case 0:
            printf("\nEncerrando o programa...\n");
            return 0;

        default:
            printf("\nOpção inválida!\n");
    }

    printf("\n=== Fim da Execução ===\n");
    return 0;
}
