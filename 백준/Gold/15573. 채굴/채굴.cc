#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int arr[1000][1000];
bool visited[1000][1000];

int bfs(int r, int c, int N, int M, int d) {
    queue<pii> q; q.push({r, c});
    visited[r][c] = true; int ret = 0;
    
    while(!q.empty()) {
        pii cur = q.front(); q.pop(); ret++;
        
        int r = cur.first, c = cur.second;
        if(r > 0 && !visited[r-1][c] && arr[r-1][c] <= d) {
            q.push({r-1, c}); visited[r-1][c] = true;
        }
        if(r < N-1 && !visited[r+1][c] && arr[r+1][c] <= d) {
            q.push({r+1, c}); visited[r+1][c] = true;
        }
        if(c > 0 && !visited[r][c-1] && arr[r][c-1] <= d) {
            q.push({r, c-1}); visited[r][c-1] = true;
        }
        if(c < M-1 && !visited[r][c+1] && arr[r][c+1] <= d) {
            q.push({r, c+1}); visited[r][c+1] = true;
        }
    }
    
    return ret;
}

int solve(int N, int M, int d) {
    int ret = 0;
    
    for(int r = 0; r < N; r++) fill(visited[r], visited[r]+M, false);
    
    for(int c = 0; c < M; c++) {
        if(!visited[0][c] && arr[0][c] <= d) {
            ret += bfs(0, c, N, M, d);
        }
    }
    for(int r = 0; r < N; r++) {
        if(!visited[r][0] && arr[r][0] <= d) {
            ret += bfs(r, 0, N, M, d);
        }
    }
    for(int r = 0; r < N; r++) {
        if(!visited[r][M-1] && arr[r][M-1] <= d) {
            ret += bfs(r, M-1, N, M, d);
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, K; cin >> N >> M >> K;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) cin >> arr[i][j];
    }
    
    int i = 1, j = 1'000'000;
    
    while(i <= j) {
        int mid = (i+j)>>1;
        int k = solve(N, M, mid);
        
        if(k < K) i = mid+1;
        else j = mid-1;
    }
    
    cout << i;

    return 0;
}