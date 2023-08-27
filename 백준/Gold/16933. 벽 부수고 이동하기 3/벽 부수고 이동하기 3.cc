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
const int INF = 1'000'000'000;

struct node {
    int r, c, k, d;
};

struct cmp {
    bool operator()(node &a, node &b) {
        return a.d > b.d;
    }
};

int N, M, K;
char arr[1000][1001];
int v[1000][1000][11] = {0, };

int bfs() {
    priority_queue<node, vector<node>, cmp> pq;
    pq.push({0, 0, 0, 1}); v[0][0][0] = 1;
    while(!pq.empty()) {
        node cur = pq.top(); pq.pop();
        int r = cur.r, c = cur.c, k = cur.k, d = cur.d;
        
        //cout << r << ' ' << c << ' ' << k << ' ' << d << '\n';
        if(v[r][c][k] != d) continue;
        
        if(r == N-1 && c == M-1) return v[r][c][k];
        
        for(int a = 0; a < 4; a++) {
            if(0 <= r+dr[a] && r+dr[a] < N && 0 <= c+dc[a] && c+dc[a] < M) {
                if(arr[r+dr[a]][c+dc[a]] == '0' && v[r+dr[a]][c+dc[a]][k] > d+1) {
                    pq.push({r+dr[a], c+dc[a], k, d+1});
                    v[r+dr[a]][c+dc[a]][k] = d+1;
                }
                if(arr[r+dr[a]][c+dc[a]] == '1' && k+1 <= K && v[r+dr[a]][c+dc[a]][k+1] > d+2-d%2) {
                    pq.push({r+dr[a], c+dc[a], k+1, d+2-d%2});
                    v[r+dr[a]][c+dc[a]][k+1] = d+2-d%2;
                }
            }
        }
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K;
    for(int r = 0; r < N; r++) {
        cin >> arr[r];
        for(int c = 0; c < M; c++) {
            fill(v[r][c], v[r][c]+11, INF);    
        }
    }
    
    cout << bfs();
    
    return 0;
}
