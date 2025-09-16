#include <stdio.h>

int main(){

    FILE *fOriginal, *fCopia;
    char ch;
    fOriginal = fopen("lorem.txt", "r");
    fCopia = fopen("lorem1.txt", "w");
    while((ch = fgetc(fOriginal)) != EOF){
        fputc(ch, fCopia);
    }
    fclose(fOriginal);
    fclose(fCopia);
    printf("Copiado!\nVerifique o Arquivo Copia.\n");
    return 0;
}