#include <stdio.h>
char nome[10];
int resposta;
int pedeNome()
{
    printf("Qual seu nome? ");
    scanf("%s", nome);
}

int verifica()
{
    printf("Deseja exibir o nome?(1 = S, 2 = N) ");
    scanf("%d", &resposta);
}

int retornaNome()
{
    if (resposta == 1)
    {
        printf("Seu nome é: %s!", nome);
    }else(printf("Seu nome é: informação não exibida."));
}

int main()
{
    pedeNome();
    verifica();
    retornaNome();
    printf("\n");
}