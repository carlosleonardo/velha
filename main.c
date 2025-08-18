#include <stdio.h>
#include <stdbool.h>

char tabuleiro[3][3];

// Verifica qual é o vencedor do jogo
bool verifica_vencedor(char jogador)
{
    // Verifica linhas
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador)
            return true;
    }

    // Verifica colunas
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)
            return true;
    }

    // Verifica diagonais
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador)
        return true;
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)
        return true;

    return false;
}

// Desenha um tabuleiro de jogo da velha
void desenha_tabuleiro()
{
    printf("  0 1 2\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < 3; j++)
        {
            printf(tabuleiro[i][j] == 0 ? ". " : "%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    bool jogando = true;

    // Limpar a tela
    int rodada = 0;
    do
    {
        printf("\033[H\033[J");
        printf("Jogo da Velha!\n");
        desenha_tabuleiro();
        int linha, coluna;
        char jogador = (rodada % 2 == 0) ? 'X' : 'O';
        printf("Jogador %c, digite a linha e a coluna (0-2): ", jogador);
        int lidos = scanf("%d %d", &linha, &coluna);
        if (lidos != 2)
        {
            printf("Entrada inválida. Tente novamente.\n");
            while (getchar() != '\n')
                ;      // Limpa o buffer
            getchar(); // Espera por uma tecla
            continue;
        }
        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != 0)
        {
            printf("Jogada inválida. Tente novamente.\n");
            while (getchar() != '\n')
                ;      // Limpa o buffer
            getchar(); // Espera por uma tecla
            continue;
        }
        if (verifica_vencedor('X'))
        {
            printf("Jogador X venceu!\n");
            jogando = false;
        }
        else if (verifica_vencedor('O'))
        {
            printf("Jogador O venceu!\n");
            jogando = false;
        }
        else
        {
            tabuleiro[linha][coluna] = jogador;
            rodada++;
        }
    } while (jogando && rodada < 9);
    if (rodada == 9)
    {
        printf("Empate!\n");
    }
    return 0;
}
