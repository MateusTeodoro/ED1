#include <stdio.h>
#define MAX_S 5

struct Conta
{
    int a, b, soma;

    void lerSoma()
    {
        scanf("%d %d", &a, &b);
        soma = a + b;
    }

    void imprimir()
    {
        printf("%d", soma);
    }

};

int main()
{
    int op = 1, tamanho = 0;
    struct Conta conta[MAX_S];

    while (op == 1 || op == 2)
    {
        printf("Escolha a opcao:\n");
        printf("1. Numeros da soma\n");
        printf("2. Mostrar somas\n");
        scanf("%d", &op);

        if(op == 1)
        {
            if (tamanho >= MAX_S)
            {
                return 0;
            }

            else
            {
                conta[tamanho].lerSoma();
                tamanho++;
            }
        }

        else if (op == 2)
        {
            for (int i = 0; i < tamanho; i++)
            {
                conta[i].imprimir();
                printf("\n");
            }
        }
    }
}
