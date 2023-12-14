#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct funcionario
{
    char nome[900];
    float salario;
    int ferias;
    char cargo[900];
    float folhaDePagamento;
};

char diaRegistrado[900];
int contador = 0;

void menu()
{

    printf("1 - Para ver o sal�rio \n");
    printf("2 - Para consultar o controle de f�rias \n");
    printf("3 - Para verificar o cargo \n");
    printf("4 - Para observar a folha de pagamento \n");
    printf("5 - Para sair do programa \n");
}

void menuRegistro()
{

    printf("1 - Para registrar um novo Funcionario \n");
    printf("2 - Para consultar os dados \n");
}

void registroUsuario(struct funcionario *informacao)
{

    int resposta;

    do
    {

        menuRegistro();

        printf("Digite o que voc� gostaria de fazer");
        scanf("%d", &resposta);
        if (resposta == 1)
        {
            fflush(stdin);

            printf("Digite o nome do funcion�rio: \n");
            gets(informacao[contador].nome);

            printf("Digite quando esse funcion�rio foi registrado na empresa");
            gets(diaRegistrado);

            printf("Digite o cargo desse funcion�rio: \n");
            gets(informacao[contador].cargo);

            fflush(stdin);

            printf("Digite qual � o sal�rio desse funcion�rio \n");
            scanf("%f", &informacao[contador].salario);
            fflush(stdin);
        }

        contador++;

    } while (resposta != 2);

    system("CLS");
}

void Consultasalario(struct funcionario *informacao, char nomeInformado[900])
{
    int i;

    for (i = 0; i < contador; i++)
    {

        if (strcmp(informacao[i].nome, nomeInformado) == 0)
        {

            printf("O sal�rio de %s �: R$%.2f reais", informacao[i].nome, informacao[i].salario);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");
    char nome[900];
    int resposta;
    char nomeInformado[900];
    struct funcionario informacao[999];

    registroUsuario(informacao);

    do
    {

        printf("Digite o nome do funci�nario que voc� deseja receber as informa��es: \n");
        gets(nome);

        menu();

        printf("Digite o que voc� gostaria de fazer");
        scanf("%d", &resposta);

        switch (resposta)
        {
        case 1:

            printf("Digite o nome do funcion�rio que voc� quer saber o sal�rio: \n");
            gets(nomeInformado);

            Consultasalario(informacao, nomeInformado);

            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        default:
            printf("Op��o inv�lida! POr favor digite novamente.");
            break;
        }
    } while (resposta != 5);

    return 0;
}

// for(i = 0; i < count; i++)
