//verificar se o jogador da vez possui jogada valida
//solicitar jogada
//criar "interface"
//tabuleiro 8xH
//exemplo de input de jogada: D6

#include <stdio.h>
#include <string.h>

int verificaEstilo()
{
    int estilo;
    scanf("%d", &estilo);
    if (estilo == 1)
    {
        return 1;
    }
    else if (estilo == 2)
    {
        return 2;
    }
    else
    {
        printf("Insira um valor válido!\n");
        verificaEstilo();
    }
}

int jogadorxjogador()
{
    char nome1[10];
    char nome2[10];
    printf("Insira o nome do Jogador 1: ");
    scanf("%s", nome1);
    printf("Insira o nome do Jogador 2: ");
    scanf("%s", nome1);
}

int estabeleceEstiloDeJogo()
{
    int estilo;
    printf("Escolha o estilo do jogo:\n 1 - Jogador x Jogador\n 2 - Jogador x Computador\n");
    estilo = verificaEstilo();
    if (estilo = 1)
    {
        jogadorxjogador();
    }
    else if (estilo = 2)
    {
        //jogadorxpc();
    }
}

int main()
{
    estabeleceEstiloDeJogo();
    printf("\n");
}