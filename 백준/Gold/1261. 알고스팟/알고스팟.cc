#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int N, M;
char arr[100][101];

struct node {
    int r, c, d;
};

int visited[100][100];

void zero_one_bfs() {
    for(int i = 0; i < N; i++) fill(visited[i], visited[i]+M, -1);
    
    deque<node> dq;
    dq.push_back({0, 0, 0});
    visited[0][0] = 0;
    
    while(!dq.empty()) {
        node cur = dq.front(); dq.pop_front();
        
        for(int k = 0; k < 4; k++) {
            if(0 <= cur.r+dr[k] && cur.r+dr[k] < N) {
                if(0 <= cur.c+dc[k] && cur.c+dc[k] < M) {
                    if(visited[cur.r+dr[k]][cur.c+dc[k]] == -1) {
                        if(arr[cur.r+dr[k]][cur.c+dc[k]] == '0') {
                            dq.push_front({cur.r+dr[k], cur.c+dc[k], cur.d});
                            visited[cur.r+dr[k]][cur.c+dc[k]] = cur.d;
                        }
                        if(arr[cur.r+dr[k]][cur.c+dc[k]] == '1') {
                            dq.push_back({cur.r+dr[k], cur.c+dc[k], cur.d+1});
                            visited[cur.r+dr[k]][cur.c+dc[k]] = cur.d+1;
                        }
                    }
                }
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> M >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    zero_one_bfs();
    
    cout << visited[N-1][M-1];
    
    return 0;
}
