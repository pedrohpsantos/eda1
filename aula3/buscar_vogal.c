#include <stdio.h>

int LinearSearch(char vect[], int size, char target)
{
    for (int i = 0; i < size; i++)
    {
        if (vect[i] == target)
            return i;
    }
    return -1;
}

int main()
{

    char vowel[5] = {'A', 'E', 'I', 'O', 'U'};
    char letter;
    int position;
    printf("Digite uma vogal para buscar no vetor: ");
    scanf(" %c", &letter);
    position = LinearSearch(vowel, 5, letter);
    if (position != -1)
    {
        printf("Encontrado na posição: %d", position);
    }
    else
    {
        printf("Elemento não encontrado");
    }

    return 0;
}