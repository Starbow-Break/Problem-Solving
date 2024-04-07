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

const int MOD = 1e9;

int N, M;
vector<int> edges[10'001];
vector<int> revEdges[10'001];
vector<int> sccEdges[10'001];
stack<int> s;
int sccIndex[10'001] = {0, };
int sccSz[10'001] = {0, };
int numScc = 0;

int inOrder[10'001] = {0, };
int dp[10'001] = {0, };
bool isOverFlow[10'001] = {false, };
bool isINF[10'001] = {false, };

bool visited[10'001] = {false, };
void dfs(int cur) {
    visited[cur] = true;
    
    for(auto &next: edges[cur]) {
        if(!visited[next]) {
            dfs(next);
        }
    }
    
    s.push(cur);
}

void dfs1(int cur) {
    sccSz[numScc]++;
    sccIndex[cur] = numScc;
    
    for(auto &next: revEdges[cur]) {
        if(!sccIndex[next]) {
            dfs1(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // input
    cin >> N >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        edges[a].pb(b);
        revEdges[b].pb(a);
    }
    
    // SCC 구해서 주어진 그래프를 DAG로 만들기
    // 코사라주 알고리즘 사용
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    
    while(!s.empty()) {
        int cur = s.top(); s.pop();
        if(!sccIndex[cur]) {
            numScc++;
            dfs1(cur);
        }
    }
    
    // SCC들을 하나의 정점으로 치환한 그래프 만들기
    for(int i = 1; i <= N; i++) {
        for(auto &j: edges[i]) {
            int si = sccIndex[i];
            int sj = sccIndex[j];
            
            if(si != sj) {
                sccEdges[si].pb(sj);
                inOrder[sj]++;
            }
        }
    }
    
    // dp 실시
    int start = sccIndex[1];
    int finish = sccIndex[2];
    
    if(sccSz[start] > 1) {
        isINF[start] = true;
    }
    else {
        dp[start] = 1;
    }
    
    queue<int> q;
    for(int i = 1; i <= numScc; i++) {
        if(!inOrder[i]) q.push(i);
    }
    
    bool flag = false;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        
        if(sccSz[cur] > 1 && (dp[cur] != 0 || isOverFlow[cur])) {
            isINF[cur] = true;
            dp[cur] = 0;
            isOverFlow[cur] = false;
        }
        
        for(auto &next: sccEdges[cur]) {
            if(isINF[cur] || isINF[next]) {
                isINF[next] = true;
                dp[next] = 0;
                isOverFlow[next] = false;
            }
            else {
                dp[next] += dp[cur];
                if(isOverFlow[cur] || dp[next] >= MOD) {
                    dp[next] %= MOD;
                    isOverFlow[next] = true;
                }
            }
            
            inOrder[next]--;
            if(!inOrder[next]) q.push(next);
        }
    }
    
    if(isINF[finish]) {
        cout << "inf";
    }
    else {
        if(isOverFlow[finish]) {
            for(int i = 1e8; i >= 1; i /= 10) {
                cout << dp[finish]%(i*10)/i;
            }
        }
        else cout << dp[finish];
    }
    
    return 0;
}