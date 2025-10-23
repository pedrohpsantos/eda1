#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Q7(const char *nome, char *buffer, int index)
{
   if (*nome == '\0')
   {
      buffer[index] = '\0';
      return;
   }
   char ch = *nome;
   if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
   {
      buffer[index] = ch;
      Q7(nome + 1, buffer, index + 1);
   }
   else
      Q7(nome + 1, buffer, index);
}

int main()
{
   char nome[100];
   char buffer[100];
   printf("Digite seu nome completo em letras minusculas:\n");
   fgets(nome, sizeof(nome), stdin);
   nome[strcspn(nome, "\n")] = 0;

   memset(buffer, 0, sizeof(buffer));

   Q7(nome, buffer, 0);

   printf("Resposta: \"%s\"\n", buffer);

   return 0;
}