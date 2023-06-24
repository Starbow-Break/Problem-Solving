#include <stdio.h>

int main()
{
    int X;
    scanf("%d", &X);

    int T = 1;
    while(X > T) {
        X = X-T;
        T++;
    }
    
    int A = X;
    int B = T-X+1;
    
    if(T%2 == 0)
        printf("%d/%d", A, B);
    else
        printf("%d/%d", B, A);

    return 0;
}