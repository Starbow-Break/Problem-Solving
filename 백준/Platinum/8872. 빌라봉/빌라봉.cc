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

struct treeInfo {
    int diameter; // 트리의 지름
    int weight; // 루트부터 리프까지의 거리의 최댓값의 최솟값
    int root; // 루트부터 리프까지의 거리의 최댓값의 최솟값을 가질때 루트 노드
};

vector<pii> edges[100000]; // 트리
bool visited[100000] = {false, }; // 방문여부
int dp[100000] = {0, };
int leaf[100000] = {0, };
int parent[100000], pw[100000];
pii vertices; int len; int lca;

void dfs(int cur) {
    visited[cur] = true;
    vector<pii> child;
    
    for(auto &[next, w]: edges[cur]) {
        if(!visited[next]) {
            parent[next] = cur;
            pw[next] = w;
            dfs(next);
            child.pb({w+dp[next], next});
        }
    }
    
    if(child.size()) {
        sort(rall(child));
        
        dp[cur] = child[0].fi;
        leaf[cur] = leaf[child[0].se];
        
        if(child.size() == 1) {
            int newlen = child[0].fi;
            if(len < newlen) {
                vertices = {cur, leaf[child[0].se]};
                len = newlen;
                lca = cur;
            }
        }
        else {
            int newlen = child[0].fi+child[1].fi;
            if(len < newlen) {
                vertices = {leaf[child[0].se], leaf[child[1].se]};
                len = newlen;
                lca = cur;
            }
        }
    }
    else {
        dp[cur] = 0;
        leaf[cur] = cur;
    }
}

vector<treeInfo> getTreeInfos(int sz) {
    vector<treeInfo> ret;
    
    for(int i = 0; i < sz; i++) {
        if(!visited[i]) {
            vertices = {i, i}; len = 0; lca = i;
            parent[i] = -1;
            pw[i] = 0;
            dfs(i);
            
            int w = len, root = vertices.fi;
            
            int l = len;
            for(int i = vertices.fi; i != lca; i = parent[i]) {
                l -= pw[i];
                if(w > max(l, len-l)) {
                    w = max(l, len-l); root = parent[i];
                }
            }
            
            l = len;
            for(int i = vertices.se; i != lca; i = parent[i]) {
                l -= pw[i];
                if(w > max(l, len-l)) {
                    w = max(l, len-l); root = parent[i];
                }
            }
            
            ret.pb({len, w, root});
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, M, L; cin >> N >> M >> L;
    repeat(M) {
        int a, b, w; cin >> a >> b >> w;
        edges[a].pb({b, w});
        edges[b].pb({a, w});
    }
    
    // 트리 정보 받아오기
    vector<treeInfo> treeInfos = getTreeInfos(N);
    // for(auto &info: treeInfos) {
    //     cout << info.diameter << ' ' << info.weight << ' ' << info.root << '\n';
    // }
    
    // 받아온 정보를 토대로 답 구하기
    vector<int> weights, diameters;
    for(auto &info: treeInfos) {
        weights.pb(info.weight);
        diameters.pb(info.diameter);
    }
    
    sort(rall(weights));
    sort(rall(diameters));
    
    int case1 = 0;
    if(weights.size() >= 2) {
        case1 = max(case1, weights[0]+weights[1]+L);
    }
    if(weights.size() >= 3) {
        case1 = max(case1, weights[1]+weights[2]+2*L);
    }
    
    int case2 = diameters[0];
    
    cout << max(case1, case2);
    
    return 0;
}
