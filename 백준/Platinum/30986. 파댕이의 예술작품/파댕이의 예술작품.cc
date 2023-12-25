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

int red[8] = {1, 6, 7, 8, 9, 10, 11, 16};
int blue[8] = {2, 3, 4, 5, 12, 13, 14, 15};

bool edges[17][17];

bool visited[17] = {false, };
int conn[17] = {0, };
bool dfs(int cur) {
    for(auto &v: blue) {
        if(edges[cur][v]) {
            if(visited[v]) continue;
            visited[v] = true;
            if(conn[v] == 0 || dfs(conn[v])) {
                conn[v] = cur;
                return true;
            }
        }
    }
    
    return false;
}

int biparate_matching() {
    int ret = 0;
    for(auto &v: red) {
        fill(visited, visited+17, false);
        ret += dfs(v);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // Tesseract 생성
    // 간선은 red -> blue로
    edges[1][2] = edges[1][3] = edges[1][4] = edges[1][5] = true;
    edges[6][2] = edges[6][3] = edges[6][12] = edges[6][13] = true;
    edges[7][2] = edges[7][4] = edges[7][12] = edges[7][14] = true;
    edges[8][2] = edges[8][5] = edges[8][13] = edges[8][14] = true;
    edges[9][3] = edges[9][4] = edges[9][12] = edges[9][15] = true;
    edges[10][3] = edges[10][5] = edges[10][13] = edges[10][15] = true;
    edges[11][4] = edges[11][5] = edges[11][14] = edges[11][15] = true;
    edges[16][12] = edges[16][13] = edges[16][14] = edges[16][15] = true;
    
    int N; cin >> N;
    while(N--) {
        int a, b; cin >> a >> b;
        if((2 <= a && a <= 5) || (12 <= a && a <= 15)) edges[b][a] = false;
        else edges[a][b] = false;
    }
    
    cout << 16-biparate_matching();
    
    return 0;
}