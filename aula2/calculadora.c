#include <stdio.h>

int main()
{
    char esc;
    do
    {
        int opc, n;
        printf("Selecione quantos numeros ira utilizar: ");
        scanf("%d", &n);
        double vect[n];
        printf("Escolha uma opção de 1 (Adição), 2 (Subtração), 3 (Multiplicação) ou 4 (Divisão): ");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            double soma = 0;
            for (int i = 0; i < n; i++)
            {
                printf("Digite o %d numero: ", i + 1);
                scanf("%lf", &vect[i]);
                if (soma == 0)
                    soma = vect[i];
                else
                    soma += vect[i];
            }
            printf("SOMA = %.1lf\n", soma);
            break;

        case 2:
            double sub = 0;
            for (int i = 0; i < n; i++)
            {
                printf("Digite o %d numero: ", i + 1);
                scanf("%lf", &vect[i]);
                if (sub == 0)
                    sub = vect[i];
                else
                    sub -= vect[i];
            }
            printf("SUBTRAÇÃO = %.1lf\n", sub);
            break;

        case 3:
            double mul = 0;
            for (int i = 0; i < n; i++)
            {
                printf("Digite o %d numero: ", i + 1);
                scanf("%lf", &vect[i]);
                if (mul == 0)
                    mul = vect[i];
                else
                    mul *= vect[i];
            }
            printf("MULTIPLICAÇÃO = %.1lf\n", mul);
            break;

        case 4:
            double div = 0;
            for (int i = 0; i < n; i++)
            {
                printf("Digite o %d numero: ", i + 1);
                scanf("%lf", &vect[i]);
                if (div == 0)
                    div = vect[i];
                else
                    div /= vect[i];
            }
            printf("DIVISÃO = %.1lf\n", div);
            break;

        default:
            printf("Opção Invalida!");
            break;
        }
        printf("Quer continuar? (s/n) ");
        scanf(" %c", &esc);
    } while (esc == 's');
}