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

int N, M;
int arr[1000][1000];
int brr[1000][1000] = {0, };
int sz[1000001] = {0, };

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int ord = 0;
void bfs(int r, int c) {
    ord++;
    queue<pii> q;
    q.push({r, c}); brr[r][c] = ord;
    
    int ret = 0;
    while(!q.empty()) {
        ret++;
        pii cur = q.front(); q.pop();
        int r = cur.fi;
        int c = cur.se;
        
        for(int l = 0; l < 4; l++) {
            if(0 <= r+dr[l] && r+dr[l] < N && 0 <= c+dc[l] && c+dc[l] < M) {
                if(arr[r+dr[l]][c+dc[l]] && !brr[r+dr[l]][c+dc[l]]) {
                    q.push({r+dr[l], c+dc[l]});
                    brr[r+dr[l]][c+dc[l]] = ord;
                }
            }
        }
    }
    
    sz[ord] = ret;
}

int calc(int r, int c) {
    int ret = 1;
    set<int> s;
    for(int l = 0; l < 4; l++) {
        if(0 <= r+dr[l] && r+dr[l] < N && 0 <= c+dc[l] && c+dc[l] < M) {
            if(brr[r+dr[l]][c+dc[l]])
                s.insert(brr[r+dr[l]][c+dc[l]]);
        }
    }
    
    for(auto &v: s) {
        ret += sz[v];
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) cin >> arr[r][c];
    }
    
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(arr[r][c] && !brr[r][c]) bfs(r, c);
        }
    }
    
    int ret = 0;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(!arr[r][c]) {
                ret = max(ret, calc(r, c));
            }
        }
    }
    cout << ret;
    
    return 0;
}
