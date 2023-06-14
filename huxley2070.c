#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int ehpar(int n){
    if(n % 2 == 0)
    return 2;
    else
    return 3;
}
int function(int n, int contador){
    if(n == 0){
        return 0;
    }
    else{
        int algarismo;
        algarismo = n % 10;
        n /= 10;
        return (algarismo * ehpar(algarismo) * contador) + function(n, contador + 1);
    }
}
void main()
{
    int n;
    scanf("%i", &n);
    while(n != 0){
        int resultado;
        resultado = function(n, 1);
        printf("%d\n", resultado);
        scanf("%i", &n);
    }
    return;
}