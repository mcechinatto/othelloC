//verificar se o jogador da vez possui jogada valida
//solicitar jogada
//exemplo de input de jogada: D6

#include <stdio.h>
#include <string.h>

char nome1[10], nome2[15], tabuleiro[8][8], jogada[2];
int modo; 
int fimDeJogo = 0;
int turno = 1;

void setaTabuleiro()
{
    int i, k;
    for (k = 0; k < 8; k++)
    {
        for (i = 0; i < 8; i++)
        {
            if (k == 3 && i == 3 || k == 4 && i == 4)
            {
                tabuleiro[k][i] = 66;
            }
            else if (k == 4 && i == 3 || k == 3 && i == 4)
            {
                tabuleiro[k][i] = 80;
            }
            else
            {
                tabuleiro[k][i] = 32;
            }
        }
    }
}

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

void estabeleceModoDeJogo()
{
    printf("Escolha o modo do jogo:\n 1 - 1 Jogador\n 2 - 2 Jogadores \n");
    modo = verificaModo();
}

void pedeJogada()
{
    printf("\n");
    printf("\n");
    char entrada[2];
    if (turno%2 != 0)
    {
        printf("Jogador B <%s>: ", nome1);
        scanf("%s", entrada);
        strcpy(jogada, entrada);
    }else{
        printf("Jogador P <%s>: ", nome2);
        scanf("%s", entrada);
        strcpy(jogada, entrada);
    }
    turno++;
}

void pedeNomesJxJ()
{
    printf("Insira o nome do Jogador B: ");
    scanf("%s", nome1);
    printf("Insira o nome do Jogador P: ");
    scanf("%s", nome2);
}

void pedeNomeJxPC()
{
    printf("Insira o nome do Jogador: ");
    scanf("%s", nome1);
    strcpy(nome2, "Computador");
}

void mostraTabuleiro()
{
    printf("\n");
    printf("Jogador B: %s\n", nome1);
    printf("Jogador P: %s\n", nome2);
    while(fimDeJogo != 1){
    printf("\n");
    int i, k, colunas[8];
    k = 65;
    printf(" ");
    for (i = 0; i < 8; i++)
    {
        colunas[i] = k;
        printf(" %c", colunas[i]);
        k++;
    }

    for (k = 0; k < 8; k++)
    {
        printf("\n%d", k + 1);
        for (i = 0; i < 8; i++)
        {
            printf("|%c", tabuleiro[k][i]);
        }
        printf("|");
    }
    pedeJogada();
    }
}

void jogadorxjogador()
{
    pedeNomesJxJ();
    
    mostraTabuleiro();
    
}

void jogadorxpc()
{
    pedeNomeJxPC();
    mostraTabuleiro();
}

void main()
{
    setaTabuleiro();
    estabeleceModoDeJogo();
    if (modo == 1)
    {
        jogadorxpc();
    }
    else if (modo == 2)
    {
        jogadorxjogador();
    }
    printf("\n");
}