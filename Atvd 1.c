#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

struct funcionario
{
    char nome[900];
    float salario;
    int diaRegistrado, mesRegistrado, anoRegistrado;
    char cargo[900];
    float folhaDePagamento;
};

// 1 + 2023

int contador = 0;
float somaSalario = 0;

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

    printf("Digite o nome do funcion�rio: \n");
    gets(informacao[contador].nome);

    printf("Digite o dia que o funcion�rio foi admitido na empresa \n");
    scanf("%d", &informacao[contador].diaRegistrado);

    printf("Digite o m�s de admiss�o do funcion�rio \n");
    scanf("%d", &informacao[contador].mesRegistrado);

    printf("Digite o ano em que esse funcion�rio foi admitido: \n");
    scanf("%d", &informacao[contador].anoRegistrado);

    fflush(stdin);

    printf("Digite o cargo desse funcion�rio: \n");
    gets(informacao[contador].cargo);

    fflush(stdin);

    printf("Digite qual � o sal�rio desse funcion�rio \n");
    scanf("%f", &informacao[contador].salario);

    somaSalario += informacao[contador].salario;

    fflush(stdin);

    do
    {

        menuRegistro();

        printf("Digite o que voc� gostaria de fazer\n");
        scanf("%d", &resposta);
        if (resposta == 1)
        {
            fflush(stdin);

            printf("Digite o nome do funcion�rio: \n");
            gets(informacao[contador].nome);

            printf("Digite o dia que o funcion�rio foi admitido na empresa \n");
            scanf("%d", &informacao[contador].diaRegistrado);

            printf("Digite o m�s de admiss�o do funcion�rio \n");
            scanf("%d", &informacao[contador].mesRegistrado);

            printf("Digite o ano em que esse funcion�rio foi admitido: \n");
            scanf("%d", &informacao[contador].anoRegistrado);

            fflush(stdin);

            printf("Digite o cargo desse funcion�rio: \n");
            gets(informacao[contador].cargo);

            fflush(stdin);

            printf("Digite qual � o sal�rio desse funcion�rio \n");
            scanf("%f", &informacao[contador].salario);

            somaSalario += informacao[contador].salario;

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
            sleep(3);
        }
    }

    system("CLS");
}

void consultaControleDeFerias(struct funcionario *informacao, char nomeInformado[900])
{

    int i;

    for (i = 0; i < contador; i++)
    {
        if (strcmp(informacao[i].nome, nomeInformado) == 0)
        {
            printf("O funcion�rio ter� direito a f�rias a partir de %d/%d/2024 \n", informacao[i].diaRegistrado, informacao[i].mesRegistrado);
            sleep(3);
        }
    }

    system("CLS");
}

void consultaCargo(struct funcionario *informacao, char nomeInformado[900])
{

    for (int i = 0; i < contador; i++)
    {

        if (strcmp(informacao[i].nome, nomeInformado) == 0)
        {
            printf("O cargo de %s �: %s", informacao[i].nome, informacao[i].cargo);
            sleep(3);
        }
    }
    system("CLS");
}

void consultaFolhaDePagamento(struct funcionario *informacao, char nomeInformado[900])
{

    for (int i = 0; i < contador; i++)
    {
        if (strcmp(informacao[i].nome, nomeInformado) == 0)
        {
            printf("O sal�rio bruto de %s �: R$%.2f \n", informacao[i].nome, informacao[i].salario);
            printf("O salario l�quido de %s �: R$%.2f (Descontado o INSS) \n", informacao[i].nome, informacao[i].salario * 0.9);
            printf("Total da folha: R$%.2f reais", somaSalario);
            sleep(5);
        }
    }

    system("CLS");
}

int main()
{
    setlocale(LC_ALL, "");

    int resposta;
    char nomeInformado[900];
    struct funcionario informacao[999];

    registroUsuario(informacao);

    do
    {
        menu();
        printf("Digite o que voc� gostaria de fazer");
        scanf("%d", &resposta);

        fflush(stdin);

        switch (resposta)
        {
        case 1:

            printf("Digite o nome do funcion�rio que voc� quer saber o sal�rio: \n");
            gets(nomeInformado);

            Consultasalario(informacao, nomeInformado);

            break;

        case 2:

            printf("Digite o nome do funcion�rio a verificar f�rias: \n");
            gets(nomeInformado);

            consultaControleDeFerias(informacao, nomeInformado);

            break;

        case 3:

            printf("Digite o nome do funcion�rio a verificar f�rias: \n");
            gets(nomeInformado);

            consultaCargo(informacao, nomeInformado);

            break;

        case 4:

            printf("Digite o nome do funcion�rio para ver seu sal�rio liquido e a folha: \n");
            gets(nomeInformado);

            consultaFolhaDePagamento(informacao, nomeInformado);

            break;

        case 5:

            printf("O programa se encerrar� em breve");
            sleep(2);

            break;

        default:
            printf("Op��o inv�lida! Por favor digite novamente.");
            break;
        }
    } while (resposta != 5);

    return 0;
}
