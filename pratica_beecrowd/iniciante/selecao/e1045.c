#include <stdio.h>
#include <math.h>

int main(){

    double a, b, c, temp;
    scanf("%lf %lf %lf", &a, &b, &c);

    if (b > a) { temp = a; a = b; b = temp; }
    if (c > a) { temp = a; a = c; c = temp; }
    if (c > b) { temp = b; b = c; c = temp; }

    if(a > 0 && b > 0 && c > 0){
        if(a >= (b + c)) printf("NAO FORMA TRIANGULO\n");
        else 
            if(pow(a, 2) == (pow(b, 2) + pow(c, 2))) printf("TRIANGULO RETANGULO\n");
            else if(pow(a, 2) > (pow(b, 2) + pow(c, 2))) printf("TRIANGULO OBTUSANGULO\n");
            else printf("TRIANGULO ACUTANGULO\n");
        if(a==b && b==c) printf("TRIANGULO EQUILATERO\n");
        else if (a==b || a==c || b==c) printf("TRIANGULO ISOSCELES\n");
    }
    return 0;
}