//Desenvolvido por Mayara Cechinatto e Bruno Paese Pressanto
//mcechinatto@ucs.br / bppressanto@ucs.br
//Outubro de 2018

//@TODOS:
//fazer IA
//contagem de pontos
//criar armazenagem de highscores
//fazer contagem da partida
//Criar menu: Novo Jogo / Ver highscores
//pedir se deseja reiniciar o jogo
//fazer fim do jogo

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
//variável que define de quem é o turno (ímpar = Preto / par = Branco)
int turno = 1;
//variáveis que recebem o código da cor do jogador do turno e do adversário
int cor, corAdv;
//array que recebe a posição das jogadas válidas
int arrayJogadasValidas[60][2];

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
    printf("Escolha o modo do jogo:\n 1 - 1 Jogador\n 2 - 2 Jogadores \n");
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
            while (cont>0)
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
        printf("Valor inserido inválido!\nVerifique se o valor digitado é composto de uma letra maiúscula entre A e H e um número entre 1 e 8.\nExemplo de jogada: D6.");
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
    int i, k, j;
    int casasVazias = 0;
    int contJogadasValidas = 0;
    for (k = 0; k < 8; k++)
    {
        for (i = 0; i < 8; i++)
        {
            if (tabuleiro[k][i] == 32)
            {
                casasVazias++;
            }
            if (casasVazias > 0)
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
            else
            {
                contJogadasValidas = -1;
            }
        }
    }
    return contJogadasValidas;
}

//método que verifica se existe jogada válida para aquele jogador apartir do valor retornado pela função jogadasValidas
void verificaJogadaValida()
{
    //Limpa o array com jogadas válidas para que novas sejam inseridas
    memset(arrayJogadasValidas, 0, sizeof(arrayJogadasValidas));
    if (jogadasValidas() == -1)
    {
        printf("Tabuleiro Cheio");
        fimDeJogo = 1;
    }
    else
    {
        if (jogadasValidas() > 0)
        {
            pedeJogada();
            verificaFormatacaoJogada(jogada);
        }
        else
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
            pedeJogada();
            verificaFormatacaoJogada(jogada);
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
}