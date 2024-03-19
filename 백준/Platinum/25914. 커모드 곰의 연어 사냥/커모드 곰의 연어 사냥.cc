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

int N, M, K, c; 
vector<pii> edges[200'001]; // 그래프
bool salmon[200'001] = {false, }; // 연여 존재 여부
bool isArticulation[200'001] = {false, }; // 단절선 여부
vector<int> sz; // 각 집합의 크기 (연어가 있는 정점은 제외한 크기)

// 단절선을 구하기 위한 DFS
int order[200'001] = {0, };
int low[200'001] = {0, };
int curOrd = 0;
void dfs(int cur, int bef = -1) {
    order[cur] = ++curOrd;
    low[cur] = curOrd;
    
    for(auto &[next, num]: edges[cur]) {
        if(!order[next]) {
            dfs(next, cur);
            
            if(low[next] > order[cur]) {
                isArticulation[num] = true;
            }
            
            low[cur] = min(low[cur], low[next]);
        }
        else {
            if(next != bef) low[cur] = min(low[cur], low[next]);
        }
    }
}

// 각 집합의 사이즈 구하기
int curSize = 0;
bool visited[200'001] = {false, };
bool hasSalmon;
void dfs1(int cur) {
    visited[cur] = true;
    curSize += !salmon[cur];
    
    if(salmon[cur]) hasSalmon = true;
    
    for(auto &[next, num]: edges[cur]) {
        // 이미 배정이 끝난 정점이거나 단절선이 아니면 넘긴다.
        if(visited[next]) continue;
        if(!isArticulation[num]) continue;
        
        dfs1(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K;
    for(int i = 1; i <= M; i++) {
        int a, b; cin >> a >> b;
        edges[a].pb({b, i}); edges[b].pb({a, i});
    }
    
    while(K--) {
        int v; cin >> v;
        salmon[v] = true;
    }
    
    cin >> c;
    
    // 단절선 구하기
    for(int i = 1; i <= N; i++) {
        if(!order[i]) {
            curOrd = 0;
            dfs(i);
        }
    }
    
    // DFS를 한번 더 돌아서 님 게임으로 치환해준다.
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            curSize = 0;
            hasSalmon = false;
            
            dfs1(i);
            
            if(hasSalmon) sz.pb(curSize);
        }
    }
    
    // 스프라그-그런디로 답 구하기
    int grundy = 0;
    for(auto &v: sz) { grundy ^= v; }
    cout << (grundy ? c : !c);
    
    return 0;
}