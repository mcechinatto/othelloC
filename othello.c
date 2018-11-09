//Desenvolvido por Mayara Cechinatto e Bruno Paese Pressanto
//mcechinatto@ucs.br / bppressanto@ucs.br
//Outubro de 2018

//@TODOS:
//verificar se o movimento é permitido
//verificar se há jogadas válidas para o determinado jogador
//fazer "comer" as peças
//fazer IA
//contagem de pontos
//criar armazenagem de highscores
//fazer contagem da partida
//Criar menu: Novo Jogo / Ver highscores
//pedir se deseja reiniciar o jogo

#include <stdio.h>
#include <string.h>

//variáveis que recebem os nomes dos jogadores
char nome1[15], nome2[15];
//variável que recebe os valores das casas do tabuleuiro
char tabuleiro[8][8];
//variável que recebe a ultima jogada efetuada
char jogada[2];
//variável que recebe o modo do jogo (JxPC = 1 / JxJ = 2)
int modo;
//variável que guarda o estado do jogo (em execução = 0 / finalizado = 1)
int fimDeJogo = 0;
//variável que define de quem é o turno (ímpar = Branco / par = Preto)
int turno = 1;

//método que seta o tabuleiro na sua forma inicial
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

//método que insere um valor no tabuleiro
void insereValorTabuleiro(int linha, int coluna)
{
    if (turno % 2 != 0)
    {
        tabuleiro[linha][coluna] = 80;
    }
    else
    {
        tabuleiro[linha][coluna] = 66;
    }
}

//método que pergunta ao jogador o modo do jogo (JxJ/JxPC)
int verificaModo()
{
    char estilo;
    scanf("%s", &estilo);
    if (estilo == 49)
    {
        return 1;
    }
    else if (estilo == 50)
    {
        return 2;
    }
    else
    {
        printf("Insira um valor válido!\n");
        verificaModo();
    }
}

//método que dá as opções do modo de jogo e chama a função verificaModo
void estabeleceModoDeJogo()
{
    printf("Escolha o modo do jogo:\n 1 - 1 Jogador\n 2 - 2 Jogadores \n");
    modo = verificaModo();
}

//metódo que verifica se o movimento pedido pelo jogador é válido
void verificaMovimento(int linha, int coluna){

    insereValorTabuleiro(linha, coluna);
    turno++;
}

//método que recebe a jogada do jogador
void pedeJogada()
{
    printf("\n");
    printf("\n");
    if (turno % 2 != 0)
    {
        printf("Jogador P <%s>: ", nome1);
        scanf("%s", jogada);
    }
    else
    {
        printf("Jogador B <%s>: ", nome2);
        scanf("%s", jogada);
    }
}

//metódo que verifica a formatação da jogada e a respectiva casa
//chama função que verifica se o movimento é válido
void verificaJogada(char jogada[2])
{
    int i, linha, coluna;
    int cont1 = 0;
    int contColuna = 0;
    for (i = 65; i < 73; i++)
    {
        if (jogada[0] == i)
        {
            coluna = cont1;
            contColuna++;
        }
        cont1++;
    }

    int cont2 = 0;
    int contLinha = 0;
    for (i = 49; i < 57; i++)
    {
        if (jogada[1] == i)
        {
            linha = cont2;
            contLinha++;
        }
        cont2++;
    }

    if (contLinha == 0 || contColuna == 0)
    {
        printf("Valor inserido inválido!\nExemplo de jogada: D6.");
        pedeJogada();
        verificaJogada(jogada);
    }
    else
    {
        verificaMovimento(linha, coluna);        
    }
}

//@TODO: método que verifica se existe jogada válida para aquele jogador
void verificaJogadaValida(){
    pedeJogada();
    verificaJogada(jogada);
}

//método que pede e instancia o nome dos jogadores
void pedeNomes()
{
    if (modo == 1)
    {
        printf("Insira o nome do Jogador: ");
        scanf("%s", nome1);
        strcpy(nome2, "Computador");
    }
    else
    {
        printf("Insira o nome do Jogador P: ");
        scanf("%s", nome1);
        printf("Insira o nome do Jogador B: ");
        scanf("%s", nome2);
    }
}

//método que instancia o tabuleiro com seus valores mais recentes
void mostraTabuleiro()
{
    printf("\n");
    printf("Jogador P: %s\n", nome1);
    printf("Jogador B: %s\n", nome2);
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
}

void main()
{
    setaTabuleiro();
    estabeleceModoDeJogo();
    pedeNomes();
    //enquanto o estado do jogo não é alterado o tabuleiro é mostrado
    //e uma nova jogada é solicitada ao jogador da vez
    while (fimDeJogo != 1)
    {
        mostraTabuleiro();
        verificaJogadaValida();        
    }
}