//Desenvolvido por Mayara Cechinatto e Bruno Paese Pressanto
//mcechinatto@ucs.br / bppressanto@ucs.br
//2018

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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
//variável que define de quem é o turno (ímpar = Preto / par = Branco)
int turno = 1;
//variáveis que recebem o código da cor do jogador do turno e do adversário (B = 66 P = 80)
int cor, corAdv;
//array que recebe a posição das jogadas válidas
int arrayJogadasValidas[60][2];
//variaveis que guardam os pontos dos jogadores
int pontuacaoP, pontuacaoB;
//váriavel que recebe 1 caso o jogador deseje reiniciar o jogo e 0 se não
int reiniciar = 1;

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
    printf("\nJogo de Othello.");
    printf("\n\nEscolha o modo do jogo:\n 1 - 1 Jogador\n 2 - 2 Jogadores \n");
    modo = verificaModo();
}

//método que insere uma jogada, criando o peão na casa pedida e convertendo os do adversário
void insereJogada(int linha, int coluna)
{
    tabuleiro[linha][coluna] = cor;
    int i = coluna - 1;
    if (tabuleiro[linha][i] == corAdv)
    {
        i--;
        while (i > -1)
        {
            if (tabuleiro[linha][i] == corAdv)
            {
                i--;
            }
            else if (tabuleiro[linha][i] == cor)
            {
                for (i; i < coluna; i++)
                {
                    tabuleiro[linha][i] = cor;
                }
                break;
            }
            else
            {
                break;
            }
        }
    }
    i = coluna + 1;
    if (tabuleiro[linha][i] == corAdv)
    {
        i++;
        while (i < 8)
        {
            if (tabuleiro[linha][i] == corAdv)
            {
                i++;
            }
            else if (tabuleiro[linha][i] == cor)
            {
                for (i; i > coluna; i--)
                {
                    tabuleiro[linha][i] = cor;
                }
                break;
            }
            else
            {
                break;
            }
        }
    }
    i = linha + 1;
    if (tabuleiro[i][coluna] == corAdv)
    {
        i++;
        while (i < 8)
        {
            if (tabuleiro[i][coluna] == corAdv)
            {
                i++;
            }
            else if (tabuleiro[i][coluna] == cor)
            {
                for (i; i > linha; i--)
                {
                    tabuleiro[i][coluna] = cor;
                }
                break;
            }
            else
            {
                break;
            }
        }
    }
    i = linha - 1;
    if (tabuleiro[i][coluna] == corAdv)
    {
        i--;
        while (i > -1)
        {
            if (tabuleiro[i][coluna] == corAdv)
            {
                i--;
            }
            else if (tabuleiro[i][coluna] == cor)
            {
                for (i; i < linha; i++)
                {
                    tabuleiro[i][coluna] = cor;
                }
                break;
            }
            else
            {
                break;
            }
        }
    }
    i = linha - 1;
    int k = coluna - 1;
    int cont = 0;
    if (tabuleiro[i][k] == corAdv)
    {
        i--;
        k--;
        cont++;
        while (i > -1 && k > -1)
        {
            if (tabuleiro[i][k] == corAdv)
            {
                i--;
                k--;
                cont++;
            }
            else if (tabuleiro[i][k] == cor)
            {
                cont++;
                while (cont > 0)
                {
                    tabuleiro[i][k] = cor;
                    cont--;
                    k++;
                    i++;
                }
                break;
            }
            else
            {
                break;
            }
        }
    }
    i = linha - 1;
    k = coluna + 1;
    cont = 0;
    if (tabuleiro[i][k] == corAdv)
    {
        i--;
        k++;
        cont++;
        while (i > -1 && k < 8)
        {
            if (tabuleiro[i][k] == corAdv)
            {
                i--;
                k++;
                cont++;
            }
            else if (tabuleiro[i][k] == cor)
            {
                cont++;
                while (cont > 0)
                {
                    tabuleiro[i][k] = cor;
                    i++;
                    k--;
                    cont--;
                }
                break;
            }
            else
            {
                break;
            }
        }
    }
    i = linha + 1;
    k = coluna + 1;
    cont = 0;
    if (tabuleiro[i][k] == corAdv)
    {
        i++;
        k++;
        cont++;
        while (i < 8 && k < 8)
        {
            if (tabuleiro[i][k] == corAdv)
            {
                i++;
                k++;
                cont++;
            }
            else if (tabuleiro[i][k] == cor)
            {
                cont++;
                while (cont > 0)
                {
                    tabuleiro[i][k] = cor;
                    i--;
                    k--;
                    cont--;
                }
                break;
            }
            else
            {
                break;
            }
        }
    }
    i = linha + 1;
    k = coluna - 1;
    cont = 0;
    if (tabuleiro[i][k] == corAdv)
    {
        i++;
        k--;
        cont++;
        while (i < 8 && k > -1)
        {
            if (tabuleiro[i][k] == corAdv)
            {
                i++;
                k--;
                cont++;
            }
            else if (tabuleiro[i][k] == cor)
            {
                cont++;
                while (cont > 0)
                {
                    tabuleiro[i][k] = cor;
                    i--;
                    k++;
                    cont--;
                }
                break;
            }
            else
            {
                break;
            }
        }
    }
    turno++;
}

//metódo que verifica se o movimento pedido pelo jogador está presente
//no arrayJogadasValidas e sendo assim é possível
void verificaMovimento(int linha, int coluna, int array[60][2])
{
    int i;
    int movimentoValido = 0;
    for (i = 0; i < 60; i++)
    {
        if (array[i][0] == linha && array[i][1] == coluna)
        {
            movimentoValido++;
        }
    }
    if (movimentoValido > 0)
    {
        insereJogada(linha, coluna);
    }
    else
    {
        printf("\nMovimento Inválido! Tente outra jogada!\n");
    }
}

//método que recebe a jogada do jogador
void pedeJogada()
{
    printf("\n");
    printf("\n");
    if (turno % 2 != 0)
    {
        printf("Jogador P <%s>: ", nome1);
    }
    else
    {
        printf("Jogador B <%s>: ", nome2);
    }
    scanf("%s", jogada);
}

//metódo que verifica a formatação da jogada e a respectiva casa
//chama função que verifica se o movimento é válido
void verificaFormatacaoJogada(char jogada[2])
{
    int i, k, linha, coluna;
    int cont1 = 0;
    int contColuna = 0;
    for (i = 65,k = 97; i < 73, k < 105; i++, k++)
    {
        if (jogada[0] == i || jogada[0] == k) 
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
        printf("Valor inserido inválido!\nVerifique se o valor digitado é composto de uma letra entre A e H e um número entre 1 e 8.\nExemplo de jogada: D6.");
    }
    else
    {
        if (tabuleiro[linha][coluna] != 32)
        {
            printf("Valor inserido inválido!\nA casa selecionada não está vazia!");
        }
        else
        {
            verificaMovimento(linha, coluna, arrayJogadasValidas);
        }
    }
}

//função que verifica as jogadas válidas par ao jogador da vez
//armazena essas jogadas no arrayJogadasValidas
//retorna o numero de jogadas válidas ou
//se retornar -1 tabuleiro está cheio
//pega a posição da pedra do jogadorda vez
//verifica se ela pode jogar em linha, coluna ou diagonais
int jogadasValidas()
{
    int i, k;
    int casasVazias = 0;
    int contJogadasValidas = 0;
    int preto = 0;
    int branco = 0;
    for (k = 0; k < 8; k++)
    {
        for (i = 0; i < 8; i++)
        {
            if (tabuleiro[k][i] == 32)
            {
                casasVazias++;
            }
            if (tabuleiro[k][i] == 66)
            {
                branco++;
            }
            if (tabuleiro[k][i] == 80)
            {
                preto++;
            }
        }
    }

    if (casasVazias > 0 && branco > 0 && preto > 0)
    {
        for (k = 0; k < 8; k++)
        {
            for (i = 0; i < 8; i++)
            {
                if (tabuleiro[k][i] == cor)
                {
                    int j = i + 1;
                    if (tabuleiro[k][j] == corAdv)
                    {
                        j++;
                        while (j < 8)
                        {
                            if (tabuleiro[k][j] == corAdv)
                            {
                                j++;
                            }
                            else if (tabuleiro[k][j] == 32)
                            {
                                arrayJogadasValidas[contJogadasValidas][0] = k;
                                arrayJogadasValidas[contJogadasValidas][1] = j;
                                contJogadasValidas++;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    j = i - 1;
                    if (tabuleiro[k][j] == corAdv)
                    {
                        j--;
                        while (j > -1)
                        {
                            if (tabuleiro[k][j] == corAdv)
                            {
                                j--;
                            }
                            else if (tabuleiro[k][j] == 32)
                            {
                                arrayJogadasValidas[contJogadasValidas][0] = k;
                                arrayJogadasValidas[contJogadasValidas][1] = j;
                                contJogadasValidas++;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    j = k + 1;
                    if (tabuleiro[j][i] == corAdv)
                    {
                        j++;
                        while (j < 8)
                        {
                            if (tabuleiro[j][i] == corAdv)
                            {
                                j++;
                            }
                            else if (tabuleiro[j][i] == 32)
                            {
                                arrayJogadasValidas[contJogadasValidas][0] = j;
                                arrayJogadasValidas[contJogadasValidas][1] = i;
                                contJogadasValidas++;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    j = k - 1;
                    if (tabuleiro[j][i] == corAdv)
                    {
                        j--;
                        while (j > -1)
                        {
                            if (tabuleiro[j][i] == corAdv)
                            {
                                j--;
                            }
                            else if (tabuleiro[j][i] == 32)
                            {
                                arrayJogadasValidas[contJogadasValidas][0] = j;
                                arrayJogadasValidas[contJogadasValidas][1] = i;
                                contJogadasValidas++;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    j = i + 1;
                    int l = k + 1;
                    if (tabuleiro[l][j] == corAdv)
                    {
                        j++;
                        l++;
                        while (j < 8 && l < 8)
                        {
                            if (tabuleiro[l][j] == corAdv)
                            {
                                j++;
                                l++;
                            }
                            else if (tabuleiro[l][j] == 32)
                            {
                                arrayJogadasValidas[contJogadasValidas][0] = l;
                                arrayJogadasValidas[contJogadasValidas][1] = j;
                                contJogadasValidas++;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }

                    j = i - 1;
                    l = k - 1;
                    if (tabuleiro[l][j] == corAdv)
                    {
                        j--;
                        l--;
                        while (j > -1 && l > -1)
                        {
                            if (tabuleiro[l][j] == corAdv)
                            {
                                j--;
                                l--;
                            }
                            else if (tabuleiro[l][j] == 32)
                            {
                                arrayJogadasValidas[contJogadasValidas][0] = l;
                                arrayJogadasValidas[contJogadasValidas][1] = j;
                                contJogadasValidas++;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }

                    j = i + 1;
                    l = k - 1;
                    if (tabuleiro[l][j] == corAdv)
                    {
                        j++;
                        l--;
                        while (j < 8 && l > -1)
                        {
                            if (tabuleiro[l][j] == corAdv)
                            {
                                j++;
                                l--;
                            }
                            else if (tabuleiro[l][j] == 32)
                            {
                                arrayJogadasValidas[contJogadasValidas][0] = l;
                                arrayJogadasValidas[contJogadasValidas][1] = j;
                                contJogadasValidas++;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    j = i - 1;
                    l = k + 1;
                    if (tabuleiro[l][j] == corAdv)
                    {
                        j--;
                        l++;
                        while (j > -1 && l < 8)
                        {
                            if (tabuleiro[l][j] == corAdv)
                            {
                                j--;
                                l++;
                            }
                            else if (tabuleiro[l][j] == 32)
                            {
                                arrayJogadasValidas[contJogadasValidas][0] = l;
                                arrayJogadasValidas[contJogadasValidas][1] = j;
                                contJogadasValidas++;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        contJogadasValidas = -1;
    }
    return contJogadasValidas;
}

//método que realiza a movimentação do computador
void turnoPC(int cont)
{
    int num = rand() % cont + 1;
    int l = arrayJogadasValidas[num - 1][0];
    int c = arrayJogadasValidas[num - 1][1];
    printf("\n\nJogador B <Computador>: %c%d\n", c + 65, l + 1);
    insereJogada(l, c);
}

//método que verifica se existe jogada válida para aquele jogador apartir do valor retornado pela função jogadasValidas
void verificaJogadaValida()
{
    //Limpa o array com jogadas válidas para que novas sejam inseridas
    memset(arrayJogadasValidas, 0, sizeof(arrayJogadasValidas));
    int numJogadas = jogadasValidas();
    if (numJogadas == -1)
    {
        fimDeJogo = 1;
    }
    else
    {
        if (numJogadas > 0)
        {
            // if (modo == 1 && cor == 66)
            // {
                turnoPC(numJogadas);
            // }
            // else
            // {
            //     pedeJogada();
            //     verificaFormatacaoJogada(jogada);
            // }
        }
        else
        {
            if (modo == 2)
            {
                if (turno % 2 != 0)
                {
                    printf("\n\nNão há jogada válida para o jogador %s, passou a vez.", nome1);
                }
                else
                {
                    printf("\n\nNão há jogada válida para o jogador %s, passou a vez.", nome2);
                }
                turno++;
                jogadasValidas();
                pedeJogada();
                verificaFormatacaoJogada(jogada);
            }
            else
            {
                if (turno % 2 != 0)
                {
                    printf("\n\nNão há jogada válida para o jogador %s, passou a vez.", nome1);
                    turno++;
                    turnoPC(jogadasValidas());
                }
                else
                {
                    printf("\n\nNão há jogada válida para o jogador %s, passou a vez.", nome2);
                    turno ++;
                    jogadasValidas();
                    pedeJogada();
                    verificaFormatacaoJogada(jogada);
                }
            }
        }
    }
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
            printf("|%C", tabuleiro[k][i]);
        }
        printf("|");
    }
}

//método que calcula os pontos e printa quando a partida é finalizada
void finalizaJogo()
{
    int i, k;
    for (k = 0; k < 8; k++)
    {
        for (i = 0; i < 8; i++)
        {
            if (tabuleiro[k][i] == 66)
            {
                pontuacaoB++;
            }
            else
            {
                pontuacaoP++;
            }
        }
    }
    printf("\n");
    if (pontuacaoP > pontuacaoB)
    {
        printf("\nJogador %s Venceu! Sua pontuação: %d\n", nome1, pontuacaoP);
    }
    else if (pontuacaoP == pontuacaoB)
    {
        printf("\nO jogo terminou empatado! Pontuação dos jogadores: %d\n", pontuacaoP);
    }
    else
    {
        printf("\nJogador %s Venceu! Sua pontuação: %d\n", nome2, pontuacaoB);
    }
}

//método que reinicia as váriavéis caso o jogo for reiniciado;
void limpaVariaves()
{
    fimDeJogo = 0;
    turno = 1;
    pontuacaoB = 0;
    pontuacaoP = 0;
}

//método que seta a variável reiniciar de acordo com a escolha do usuário
void reiniciarJogo()
{

    char SouN[1];
    printf("Deseja reiniciar o jogo (s/n)? ");
    scanf("%s", SouN);
    if (SouN[0] == 83 || SouN[0] == 115)
    {
        limpaVariaves();
    }
    else if (SouN[0] == 78 || SouN[0] == 110)
    {
        exit(0);
    }
    else
    {
        printf("Valor inválido! Insira S para sim ou N para não.");
        reiniciarJogo();
    }
}

void main()
{
    while (reiniciar = 1)
    {
        srand(time(NULL));
        setaTabuleiro();
        estabeleceModoDeJogo();
        pedeNomes();
        //enquanto o estado do jogo não é alterado o tabuleiro é mostrado
        //e uma nova jogada é solicitada ao jogador da vez
        int cont = 0;
        while (fimDeJogo != 1)
        {
            cont++;
            if (turno % 2 != 0)
            {
                cor = 80;
                corAdv = 66;
            }
            else
            {
                cor = 66;
                corAdv = 80;
            }
            mostraTabuleiro();
            verificaJogadaValida();
        }
        finalizaJogo();
        int partidas = 0;
        char c;
        FILE *arquivo = fopen("/home/mayara/code/othello/arquivo.txt", "a+");

        if (arquivo == NULL)
        {
            printf("Não foi possível guardar os valores da partida.");
        }
        else
        {
            while ((c = fgetc(arquivo)) != EOF)
            {
                if (c == '\n')
                {
                    partidas++;
                }
            }
            char dataToAppend[50];
            sprintf(dataToAppend, "%d %s %d %s %d\n", partidas + 1, nome1, pontuacaoP, nome2, pontuacaoB);
            fputs(dataToAppend, arquivo);
            fclose(arquivo);
        }
        reiniciarJogo();
    }
}