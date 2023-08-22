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

const int INF = 1'000'000'000;

struct brick {
    int area, height, weight;
};

vector<brick> bricks;
vector<pii> edges[101];
int d[101];
int bef[101] = {0, };

void bellmanFord(int start, int numV) {
    fill(d+1, d+numV+1, INF);
    d[0] = 0;
    for(int i = 1; i <= numV; i++) {
        for(int v = 0; v <= numV; v++) {
            for(auto &[next, w]: edges[v]) {
                if(d[next] > d[v]+w) {
                    d[next] = d[v]+w;
                    bef[next] = v;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    bricks.pb({INF, 0, INF});
    
    int N; cin >> N;
    repeat(N) {
        int area, height, weight; cin >> area >> height >> weight;
        bricks.pb({area, height, weight});
    }
    
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            if(i == j) continue;
            if(bricks[j].area <= bricks[i].area && bricks[j].weight <= bricks[i].weight) {
                edges[i].pb({j, -bricks[j].height});
            }
        }
    }
    
    bellmanFord(0, N);
    
    vector<int> ans;
    int top = 0;
    for(int i = 1; i <= N; i++) {
        if(d[i] < d[top]) top = i;
    }
    
    while(top != 0) {
        ans.pb(top);
        top = bef[top];
    }
    
    cout << ans.size() << '\n';
    for(auto &a: ans) cout << a << '\n';
    
    return 0;
}