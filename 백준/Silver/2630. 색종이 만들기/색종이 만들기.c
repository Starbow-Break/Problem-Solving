#include <stdio.h>

int Paper[128][128] = {0, };
int White = 0; int Blue = 0;

void Cut(int N, int x, int y) {
    int i, j;
    int num_0 = 0; int num_1 = 0;
    int cut = 0;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            if(Paper[x+i][y+j] == 0)
                num_0++;
            else
                num_1++;
        }
        if(num_0 != 0 && num_1!= 0) {
            cut = 1;
            break;
        }
    }
    
    if(cut == 1) {
        Cut(N/2, x, y);
        Cut(N/2, x+N/2, y);
        Cut(N/2, x, y+N/2);
        Cut(N/2, x+N/2, y+N/2);
    }
    
    else
        if(num_0 != 0)
            White++;
        else
            Blue++;
    
    
}

int main()
{
    int N;
    scanf("%d", &N);
    int i, j;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            scanf("%d", &Paper[j][i]);
        }
    }
    
    Cut(N, 0, 0);
    
    printf("%d\n", White);
    printf("%d\n", Blue);
}