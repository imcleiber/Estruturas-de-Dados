#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int raiz_digital(int posicao, int valor)
{
    if(posicao == 1) return valor;
    else{
        return raiz_digital(posicao - 1, valor + 9);
    }

}
void main()
{
    int n;
    scanf("%i", &n);
    while(n > 0){
        int posicao, valor, resultado;
        scanf("%i %i", &posicao, &valor);
        resultado = raiz_digital(posicao, valor);
        printf("%i\n", resultado);
        n--;
    }
}