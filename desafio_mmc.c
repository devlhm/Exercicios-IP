#include <stdio.h>

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

    printf("MDC: %d\n", mdc);

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

int main()
{
    int a, b, mmc;
    printf("Entre com dois valores separados por espaço, enter ou tab:\n");
    scanf("%d %d", &a, &b);

    mmc = calculaMMC(a, b);

    if (mmc == -1)
    {
        printf("O MMC entre %d e %d não existe!\n", a, b);
    }
    else
    {
        printf("O MMC entre %d e %d é: %d\n", a, b, mmc);
    }

    return 0;
}
