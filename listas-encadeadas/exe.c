#include <stdio.h>

int soma(int n){
    if (n == 1) return 1;
    return n + soma (n -1);
}

int main (){
    int x = soma(5);
    printf ("%d ", x );
    return 0;
}