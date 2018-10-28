//verificar se o jogador da vez possui jogada valida
//solicitar jogada
//criar "interface"
//tabuleiro 8xH
//exemplo de input de jogada: D6

#include <stdio.h>
#include <string.h>

char nome1[10], nome2[10];
int modo;

int verificaModo()
{
    scanf("%d", &modo);
    if (modo == 1)
    {
        return 1;
    }
    else if (modo == 2)
    {
        return 2;
    }
    else
    {
        printf("Insira um valor válido!\n");
        verificaModo();
    }
}

int pedeNomesJxJ()
{
    printf("Insira o nome do Jogador B: ");
    scanf("%s", nome1);
    printf("Insira o nome do Jogador P: ");
    scanf("%s", nome2);
};

int pedeNomeJxPC()
{
    printf("Insira o nome do Jogador: ");
    scanf("%s", nome1);
}

int estabeleceModoDeJogo()
{
    printf("Escolha o modo do jogo:\n 1 - Jogador x Jogador\n 2 - Jogador x Computador\n");
    modo = verificaModo();    
}

int main()
{
    estabeleceModoDeJogo();
    if (modo == 1)
    {
        pedeNomesJxJ();
        //jogadorxjogador();
    }
    else if (modo == 2)
    {
        pedeNomeJxPC();
        //jogadorxpc();
    }
    printf("\n");
}