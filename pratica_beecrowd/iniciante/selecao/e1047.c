#include <stdio.h>

int main()
{
    int horaInicio, horaFinal, minutoInicio, minutoFinal, totalHoras, totalMinutos, duracaoMinutos;
    scanf("%d %d %d %d", &horaInicio, &minutoInicio, &horaFinal, &minutoFinal);

    int inicioMinutos = (horaInicio * 60) + minutoInicio;
    int finalMinutos = (horaFinal * 60) + minutoFinal;

    if (inicioMinutos < finalMinutos)
    {
        duracaoMinutos = finalMinutos - inicioMinutos;
    }
    else
    {
        duracaoMinutos = (24 * 60 - inicioMinutos) + finalMinutos;
    }

    totalHoras = duracaoMinutos / 60;
    totalMinutos = duracaoMinutos % 60;

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", totalHoras, totalMinutos);
    return 0;
}