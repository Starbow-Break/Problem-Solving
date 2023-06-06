#include <stdio.h>

int arr[501][501];

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    int max = 0;
    
    for(int i = 1; i <= N-3; i++) {
        for(int j = 1; j <= M; j++) {
            int value = arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+3][j];
            if(max < value)
                max = value;
        }
    }//ㅣ
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M-3; j++) {
            int value = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i][j+3];
            if(max < value)
                max = value;
        }
    }//ㅡ
    
    for(int i = 1; i <= N-1; i++) {
        for(int j = 1; j <= M-1; j++) {
            int value = arr[i][j]+arr[i+1][j]+arr[i][j+1]+arr[i+1][j+1];
            if(max < value)
                max = value;
        }
    }//ㅁ
    
    for(int i = 1; i <= N-2; i++) {
        for(int j = 1; j <= M-1; j++) {
            int value = arr[i][j]+arr[i+1][j]+arr[i+2][j]+arr[i+2][j+1];
            if(max < value)
                max = value;
        }
    }//L
    
    for(int i = 1; i <= N-1; i++) {
        for(int j = 1; j <= M-2; j++) {
            int value = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j];
            if(max < value)
                max = value;
        }
    }//L + 시계방향 90도
    
    for(int i = 1; i <= N-2; i++) {
        for(int j = 1; j <= M-1; j++) {
            int value = arr[i][j]+arr[i][j+1]+arr[i+1][j+1]+arr[i+2][j+1];
            if(max < value)
                max = value;
        }
    }//ㄱ(3*2)
    
    for(int i = 1; i <= N-1; i++) {
        for(int j = 1; j <= M-2; j++) {
            int value = arr[i][j+2]+arr[i+1][j]+arr[i+1][j+1]+arr[i+1][j+2];
            if(max < value)
                max = value;
        }
    }//ㄱ + 시계방향 90도
    
    for(int i = 1; i <= N-2; i++) {
        for(int j = 1; j <= M-1; j++) {
            int value = arr[i][j+1]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1];
            if(max < value)
                max = value;
        }
    }//L+좌우대칭
    
    for(int i = 1; i <= N-1; i++) {
        for(int j = 1; j <= M-2; j++) {
            int value = arr[i][j]+arr[i+1][j]+arr[i+1][j+1]+arr[i+1][j+2];
            if(max < value)
                max = value;
        }
    }//ㄴ
    
    for(int i = 1; i <= N-2; i++) {
        for(int j = 1; j <= M-1; j++) {
            int value = arr[i][j]+arr[i][j+1]+arr[i+1][j]+arr[i+2][j];
            if(max < value)
                max = value;
        }
    }//ㄴ + 시계방향 90도
    
    for(int i = 1; i <= N-1; i++) {
        for(int j = 1; j <= M-2; j++) {
            int value = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+2];
            if(max < value)
                max = value;
        }
    }//ㄱ(2*3)
    
    for(int i = 1; i <= N-2; i++) {
        for(int j = 1; j <= M-1; j++) {
            int value = arr[i][j]+arr[i+1][j]+arr[i+1][j+1]+arr[i+2][j+1];
            if(max < value)
                max = value;
        }
    }//{{1, 0}, {1, 1}, {0, 1}}
    
    for(int i = 1; i <= N-1; i++) {
        for(int j = 1; j <= M-2; j++) {
            int value = arr[i][j+1]+arr[i][j+2]+arr[i+1][j]+arr[i+1][j+1];
            if(max < value)
                max = value;
        }
    }//{{0, 1, 1}, {1, 1, 0}}
    
    for(int i = 1; i <= N-2; i++) {
        for(int j = 1; j <= M-1; j++) {
            int value = arr[i][j+1]+arr[i+1][j]+arr[i+1][j+1]+arr[i+2][j];
            if(max < value)
                max = value;
        }
    }//{{0, 1}, {1, 1}, {1, 0}}
    
    for(int i = 1; i <= N-1; i++) {
        for(int j = 1; j <= M-2; j++) {
            int value = arr[i][j]+arr[i][j+1]+arr[i+1][j+1]+arr[i+1][j+2];
            if(max < value)
                max = value;
        }
    }//{{1, 1, 0}, {0, 1, 1}}
    
    for(int i = 1; i <= N-1; i++) {
        for(int j = 1; j <= M-2; j++) {
            int value = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1];
            if(max < value)
                max = value;
        }
    }//T
    
    for(int i = 1; i <= N-2; i++) {
        for(int j = 1; j <= M-1; j++) {
            int value = arr[i][j+1]+arr[i+1][j]+arr[i+1][j+1]+arr[i+2][j+1];
            if(max < value)
                max = value;
        }
    }//ㅓ
    
    for(int i = 1; i <= N-1; i++) {
        for(int j = 1; j <= M-2; j++) {
            int value = arr[i][j+1]+arr[i+1][j]+arr[i+1][j+1]+arr[i+1][j+2];
            if(max < value)
                max = value;
        }
    }//ㅗ
    
    for(int i = 1; i <= N-2; i++) {
        for(int j = 1; j <= M-1; j++) {
            int value = arr[i][j]+arr[i+1][j]+arr[i+1][j+1]+arr[i+2][j];
            if(max < value)
                max = value;
        }
    }//ㅏ

    printf("%d", max);
    
    return 0;
}