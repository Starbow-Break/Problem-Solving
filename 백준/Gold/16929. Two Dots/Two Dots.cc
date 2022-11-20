#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N, M;
char arr[50][51];

bool visited[50][50] = {false, };

bool dfs(int r, int c, int br, int bc) {
    visited[r][c] = true;
    
    if(r > 0 && arr[r-1][c] == arr[r][c]) {
        if(!visited[r-1][c]) { if(dfs(r-1, c, r, c)) return true; }
        else { if(!(r-1 == br && c == bc)) return true; }
    }
    if(r < N-1  && arr[r+1][c] == arr[r][c]) {
        if(!visited[r+1][c]) { if(dfs(r+1, c, r, c)) return true; }
        else { if(!(r+1 == br && c == bc)) return true; }
    }
    if(c > 0 && arr[r][c-1] == arr[r][c]) {
        if(!visited[r][c-1]) { if(dfs(r, c-1, r, c)) return true; }
        else { if(!(r == br && c-1 == bc)) return true; }
    }
    if(c < M-1 && arr[r][c+1] == arr[r][c]) {
        if(!visited[r][c+1]) { if(dfs(r, c+1, r, c)) return true; }
        else { if(!(r == br && c+1 == bc)) return true; }
    }
    
    return false;
}

bool haveCycle() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(!visited[i][j]) {
                if(dfs(i, j, -1, -1)) return true;
            }
        }
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) { cin >> arr[i]; }
    
    cout << (haveCycle() ? "Yes" : "No");

    return 0;
}
