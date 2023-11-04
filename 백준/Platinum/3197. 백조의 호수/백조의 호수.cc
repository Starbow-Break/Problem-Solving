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

int R, C;
char arr[1500][1501];
int visited[1500][1500] = {0, };
vector<int> vec[2000];
int swan[2] = {-1, -1};

int parent[2250000];

int findRoot(int v) {
    if(v == parent[v]) return v;
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

void merge(int a, int b) {
    int ra = findRoot(a);
    int rb = findRoot(b);
    if(ra > rb) swap(ra, rb);
    parent[rb] = ra;
}

void bfs() {
    queue<int> q;
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            if(arr[r][c] == '.' || arr[r][c] == 'L') {
                visited[r][c] = 1;
                vec[1].pb(r*C+c);
                q.push(r*C+c);
            }
        }
    }
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int k = 0; k < 4; k++) {
            int nr = cur/C+dr[k];
            int nc = cur%C+dc[k];
            
            if(0 <= nr && nr < R && 0 <= nc && nc < C && !visited[nr][nc]) {
                q.push(nr*C+nc);
                visited[nr][nc] = visited[cur/C][cur%C]+1;
                vec[visited[nr][nc]].pb(nr*C+nc);
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> C;
    for(int r = 0; r < R; r++) cin >> arr[r];
    
    for(int r = 0; r < R; r++) {
        for(int c = 0; c < C; c++) {
            if(arr[r][c] == 'L') {
                if(swan[0] == -1) swan[0] = r*C+c;
                else swan[1] = r*C+c;
            }
        }
    }
    
    bfs();
    
    for(int i = 0; i < R*C; i++) parent[i] = i;
    
    for(int t = 1; t < 2000; t++) {
        for(auto v: vec[t]) {
            for(int k = 0; k < 4; k++) {
                int nr = v/C+dr[k];
                int nc = v%C+dc[k];
                
                if(0 <= nr && nr < R && 0 <= nc && nc < C && visited[nr][nc] <= t) {
                    merge(nr*C+nc, v);
                }
            }
        }
        
        if(findRoot(swan[0]) == findRoot(swan[1])) {
            cout << t-1;
            return 0;
        }
    }
    
    return 0;
}
