#include <stdio.h>

char map[20][21];
int visited[26] = {0, }; int len = 0; int max = 0;

int DFS(int x, int y, int R, int C) {
    int i = map[x][y] - 'A';
    
    if(visited[i] == 0) {
        visited[i] = 1;
        len++;
    
        if(y-1 >= 0) {
            DFS(x, y-1, R, C);
        }//좌
        
        if(y+1 < C) {
            DFS(x, y+1, R, C);
        }//우
        
        if(x-1 >= 0) {
            DFS(x-1, y, R, C);
        }//상
        
        if(x+1 < R) {
            DFS(x+1, y, R, C);
        }//하
        
        visited[i] = 0;
        if(len > max)
            max = len;
        len--;
    }
}

int main()
{
    int R, C;
    scanf("%d %d", &R, &C);
    
    for(int i = 0; i < R; i++) {
        scanf("%s", &map[i]);
    }
    
    DFS(0, 0, R, C);
    
    printf("%d", max);
}