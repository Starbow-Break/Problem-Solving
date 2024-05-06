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

const int INF = 1e9;

struct path {
    int v1, v2, w; bool done;
    
    bool operator<(path &p) {
        return w < p.w;
    }
};

struct edge {
    int v1, v2, w;
};

int N, M;
int shortest[101][101]; // 주어진 최단거리
int curShortest[101][101]; // 현재 제작중인 그래프에서 최단 거리들

vector<path> paths;
vector<edge> edges;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    if(N == 1) {
        cout << 0;
        return 0;
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            curShortest[i][j] = (i == j ? 0 : INF);
        }
    }
   
    for(int i = 1; i <= N; i++) {
        shortest[i][i] = 0;
        for(int j = i+1; j <= N; j++) {
            cin >> shortest[i][j];
            paths.pb({i, j, shortest[i][j], false});
            shortest[j][i] = shortest[i][j];
        }
    }
    
    sort(all(paths));
    
    for(auto &p: paths) {
        if(curShortest[p.v1][p.v2] < p.w) {
            cout << 0;
            return 0;
        }
        else if(curShortest[p.v1][p.v2] > p.w) {
            p.done = true;
            edges.pb({p.v1, p.v2, p.w});
            
            int temp[101][101];
            for(int i = 1; i <= N; i++) {
                for(int j = 1; j <= N; j++) {
                    temp[i][j] = min({
                        curShortest[i][j],
                        curShortest[i][p.v1]+p.w+curShortest[p.v2][j],
                        curShortest[i][p.v2]+p.w+curShortest[p.v1][j]
                    });
                }
            }
            
            for(int i = 1; i <= N; i++) {
                for(int j = 1; j <= N; j++) {
                    curShortest[i][j] = temp[i][j];
                }
            }
        }
    }
    
    if(edges.size() > M) {
        cout << 0;
        return 0;
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(curShortest[i][j] != shortest[i][j]) {
                cout << 0;
                return 0;
            }
        }
    }
    
    int remain = M-edges.size();
    for(auto &p: paths) {
        if(remain == 0) break;
        if(!p.done) {
            edges.pb({p.v1, p.v2, p.w});
            remain--;
        }
    }
    
    if(remain == 0) {
        cout << 1 << '\n';
        for(auto &e: edges) {
            cout << e.v1 << ' ' << e.v2 << ' ' << e.w << '\n';
        }
    }
    else {
        cout << 0;
    }
    
    return 0;
}