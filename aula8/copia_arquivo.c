#include <stdio.h>

int main(){

    FILE *fOriginal, *fCopia;
    char ch;
    fOriginal = fopen("lorem.txt", "r");
    fCopia = fopen("lorem1.txt", "w");
    while(1){
        ch = fgetc(fOriginal);
        if (ch == EOF)
            break;
        fputc(ch, fCopia);
    }
    fclose(fOriginal);
    fclose(fCopia);
    printf("Copiado!\nVerifique o Arquivo Copia.\n");
    return 0;
}