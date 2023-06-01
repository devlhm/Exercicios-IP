/*********************************************************************/
/**   ACH2001 - Introducao a Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2022                          **/
/**   Turma 02 - Prof. Marcos Lordello Chaim                        **/
/**                                                                 **/
/**   Primeiro Exercicio-Programa                                   **/
/**                                                                 **/
/**   Luis Henrique Moraes                   14615590               **/
/**                                                                 **/
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MESES_POR_ANO 12
#define DIAS_POR_ANO 365

int calculaMDC(int x, int y)
{
    int mdc = -1;
    int min = x;

    if (y < min)
    {
        min = x;
    }

    for (int i = 1; i <= min; i++)
    {
        if ((x % i) == 0 && (y % i) == 0)
            mdc = i;
    }

    return(mdc);
}

int calculaMMC(int x, int y)
{
    int mdc = calculaMDC(x,y);

    if(mdc == -1) {
        return -1;
    }

    return (x*y)/mdc;
}

int calculaIntervaloEmComum(int* intervalosEncontros) {
    int mmc = intervalosEncontros[0];
    for(int i = 1; i < 5; i++) {
        mmc = calculaMMC(mmc, intervalosEncontros[i]);
    }

    return mmc;
}

int converterParaDiaAbs(int dia, int mes, int* diasDosMeses)
{
    int diaAbs = dia;

    for (int i = 0; i < mes - 1; i++)
    {
        diaAbs += diasDosMeses[i];
    }

    return diaAbs;
}

void converterDeDiaAbs(int diaAbs, int* dataResultado, int* diasDosMeses)
{
    int dia = diaAbs;

    int i = 0;
    while (dia > diasDosMeses[i])
    {
        dia -= diasDosMeses[i];
        i++;
    }

    dataResultado[0] = dia;
    dataResultado[1] = i + 1;
}

// Adicione funções auxiliares se for necessário
int verificaAnoBissexto(int ano)
{
    if (ano % 4 == 0)
    {
        if (ano % 100 == 0)
        {
            if (ano % 400 == 0)
                return 1;
        }
        else
            return 1;
    }

    return 0;
}

int verificaDataValida(int d, int m, int a, int* diasDosMeses)
{
    if (d > 0 && m > 0 && m <= MESES_POR_ANO)
    {
        int ultimoDiaMes = diasDosMeses[m - 1];

        if (d <= ultimoDiaMes)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int intervalosEncontros[5] = {2, 3, 4, 5, 6};
    int diasDosMeses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int dia, mes, ano;

    printf("Entre com a data de inicio do ano letivo:\n");
    printf("Entre com o dia: ");
    scanf("%d", &dia);
    printf("Entre com o mes: ");
    scanf("%d", &mes);
    printf("Entre com o ano: ");
    scanf("%d", &ano);

    clock_t begin = clock();

    if (verificaAnoBissexto(ano) && mes == 2)
        diasDosMeses[1] = 29;

    if (!verificaDataValida(dia, mes, ano, diasDosMeses))
    {
        printf("Dados incorretos\n");
        exit(1); // Esta função aborta a execução do programa.
    }

    int diaInicialAbs = converterParaDiaAbs(dia, mes, diasDosMeses);

    int existeEncontroEmComum = 0;
    int intervaloEmComum = calculaIntervaloEmComum(intervalosEncontros);
    printf("Proximos dias de encontro de todos os clubes:\n");
    for (int i = diaInicialAbs + intervaloEmComum; i <= DIAS_POR_ANO; i += intervaloEmComum)
    {
        existeEncontroEmComum = 1;

        int data[2] = {0, 0};
        converterDeDiaAbs(i + 1, data, diasDosMeses);

        printf("%d/%d/%d\n", data[0], data[1], ano);
    }

    clock_t end = clock();
    double timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\n", timeSpent);

    if (!existeEncontroEmComum)
        printf("Não há encontro em comum entre os clubes!\n");
}