#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int decrementa(int n)
{
    int subtraendo;
    if(n / 10 == 0){
        if(n % 2 == 0) return 4;
        else return 3;
    }
    else{
        subtraendo = decrementa(n / 10);
    }
    return n - subtraendo;
}
void main()
{
    int n, resultado;
    scanf("%i", &n);
    resultado = decrementa(n);
    printf("%i\n", resultado);
}