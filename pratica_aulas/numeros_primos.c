#include <stdio.h>

int main(){

    int n, primo;
    printf("Escreva um numero para verificar se eh primo ou nao: ");
    scanf("%d", &n);

    if (n == 1) primo = 1;
    else {
        for (int i = 2; i <= n; i++){
            if (n % i == 0){
                primo = 0;
                break;
            }
        }
    }

    if (primo == 1) printf("Nao eh primo");
    else printf("Eh primo");

    return 0;
}