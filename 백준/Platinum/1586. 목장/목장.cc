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

const ll INF = 1e18;

struct pasture {
    int x1, y1, x2, y2;
    
    ll getArea() {
        return 1LL*(x2-x1)*(y2-y1);
    }
};

int N;
vector<pasture> pastures;

vector<int> edges[5'001];
bool isArticulation[5'001] = {false, };
ll defect[5'001];
int parent[5'001];

int findRoot(int v) {
    if(v == parent[v]) return v;
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

void merge(int i, int j) {
    int ri = findRoot(i);
    int rj = findRoot(j);
    
    if(ri > rj) swap(ri, rj);
    parent[rj] = ri;
}

bool check(int i, int j) {
    if(
        pastures[i].x1 == pastures[j].x2
        && pastures[i].y1 == pastures[j].y2
    ) {
        return false;
    }
    if(
        pastures[i].x2 == pastures[j].x1
        && pastures[i].y1 == pastures[j].y2
    ) {
        return false;
    }
    if(
        pastures[i].x1 == pastures[j].x2
        && pastures[i].y2 == pastures[j].y1
    ) {
        return false;
    }
    if(
        pastures[i].x2 == pastures[j].x1
        && pastures[i].y2 == pastures[j].y1
    ) {
        return false;
    }
    if(
        pastures[i].x1 <= pastures[j].x1
        && pastures[j].x1 <= pastures[i].x2
        && !(
            pastures[i].y2 < pastures[j].y1
            || pastures[i].y1 > pastures[j].y2
        ) 
    ) {
        return true;
    }
    if(
        pastures[i].x1 <= pastures[j].x2
        && pastures[j].x2 <= pastures[i].x2
        && !(
            pastures[i].y2 < pastures[j].y1
            || pastures[i].y1 > pastures[j].y2
        )
    ) {
        return true;
    }
    if(
        pastures[i].y1 <= pastures[j].y1
        && pastures[j].y1 <= pastures[i].y2
        && !(
            pastures[i].x2 < pastures[j].x1
            || pastures[i].x1 > pastures[j].x2
        )
    ) {
        return true;
    }
    if(
        pastures[i].y1 <= pastures[j].y2
        && pastures[j].y2 <= pastures[i].y2
        && !(
            pastures[i].x2 < pastures[j].x1
            || pastures[i].x1 > pastures[j].x2
        )
    ) {
        return true;
    }
    
    return false;
}

// DFS
int order[5'001] = {0, };
int low[5'001] = {0, };
int curOrd;
int tx1, tx2, ty1, ty2;
void dfs(int cur, int bef = -1) {
    order[cur] = ++curOrd;
    low[cur] = curOrd;
    int child = 0;
    
    tx1 = min(tx1, pastures[cur].x1);
    tx2 = max(tx2, pastures[cur].x2);
    ty1 = min(ty1, pastures[cur].y1);
    ty2 = max(ty2, pastures[cur].y2);
    
    for(auto &next: edges[cur]) {
        // 아직 방문한 정점이 아니면
        if(!order[next]) {
            child++;
            merge(cur, next);
            dfs(next, cur);
            
            // 루트 노드면
            if(bef == -1 && child > 1) {
                isArticulation[cur] = true;
            }
            // 루트 노드가 아니면
            else if(bef != -1 && low[next] >= order[cur]) {
                isArticulation[cur] = true;
            }
            
            low[cur] = min(low[cur], low[next]);
        }
        else {
            if(next != bef) low[cur] = min(low[cur], low[next]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    pastures.pb({-1, -1, -1, -1});
    fill(defect+1, defect+N+1, -1);
    
    // 입력
    cin >> N;
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
        int a, b, c, d; cin >> a >> b >> c >> d;
        pastures.pb({a, c, b, d});
    }
    
    // 목장 상태를 그래프화
    for(int i = 1; i <= N; i++) {
        for(int j = i+1; j <= N; j++) {
            if(check(i, j)) {
                edges[i].pb(j); edges[j].pb(i);
            }
        }
    }
    
    // for(int i = 1; i <= N; i++) {
    //     for(auto &next: edges[i]) {
    //         cout << next << ' ';
    //     }
    //     cout << '\n';
    // }
    
    // DFS
    // 돌면서 단절점과 각 슈퍼목장을 감싸는 직사각형의 최소 넓이를 구해준다.
    for(int i = 1; i <= N; i++) {
        if(!order[i]) {
            // DFS 돌기 전 초기화
            tx1 = 1e9, tx2 = -1e9, ty1 = 1e9, ty2 = -1e9;
            curOrd = 0;
            
            // DFS
            dfs(i);
            
            // 결과 반영
            defect[i] = 1LL*(tx2-tx1)*(ty2-ty1);
        }
    }
    
    // 불량도 계산
    for(int i = 1; i <= N; i++) {
        int r = findRoot(i);
        defect[r] -= pastures[i].getArea();
    }
    
    // 최대 불량도 계산
    ll maxDefect = 0;
    for(int i = 1; i <= N; i++) {
        maxDefect = max(maxDefect, defect[i]);
    }
    
    // 답 구하고 출력
    int ans = -1;
    for(int i = 1; i <= N; i++) {
        int r = findRoot(i);
        if(!isArticulation[i] && defect[r] == maxDefect) {
            if(ans == -1) ans = i;
            else {
                if(pastures[ans].getArea() > pastures[i].getArea()) {
                    ans = i;
                }
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
