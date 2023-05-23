#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>
#define MOD 998'244'353

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

int N; 
bool isRed[300'001] = {false, }, isBlue[300'001] = {false, };
int sz[300'001]; //서브트리의 크기
bool visited[300'001] = {false, }; //Centroid로 사용 여부
vector<int> edges[300'001];

//서브트리의 사이즈 얻기
int getSize(int cur, int prev = -1) {
    sz[cur] = 1;
    for(auto &next: edges[cur]) {
        if(next != prev && !visited[next]) sz[cur] += getSize(next, cur);
    }
    
    return sz[cur];
}

//Centroid 얻기
int getCent(int cur, int prev, int size) {
    for(auto &next: edges[cur]) {
        //크기가 size/2를 넘는 서브 트리가 있으면 그쪽으로 이동
        if(next != prev && !visited[next] && sz[next] > size/2) return getCent(next, cur, size);
    }
    
    //없으면 현재 정점이 Centroid가 된다.
    return cur;
}

ll a0 = 0, a1 = 0, a2 = 0, b0 = 0, b1 = 0, b2 = 0, ans = 0;
ll _a0 = 0, _a1 = 0, _a2 = 0, _b0 = 0, _b1 = 0, _b2 = 0;
void dfs(int cur, int prev = -1, int dep = 1) {
    if(isRed[cur]) {
        ans += b2; ans %= MOD;
        ans += 2LL*dep%MOD*b1%MOD; ans %= MOD;
        ans += 1LL*dep*dep%MOD*b0%MOD; ans %= MOD;
        
        _a0 = (_a0+1)%MOD; _a1 = (_a1+dep)%MOD; _a2 = (_a2+1LL*dep*dep)%MOD;
    }
    if(isBlue[cur]) {
        ans += a2; ans %= MOD;
        ans += 2LL*dep%MOD*a1%MOD; ans %= MOD;
        ans += 1LL*dep*dep%MOD*a0%MOD; ans %= MOD;
        
        _b0 = (_b0+1)%MOD; _b1 = (_b1+dep)%MOD; _b2 = (_b2+1LL*dep*dep)%MOD;
    }
    
    for(auto &next: edges[cur]) {
        if(next != prev && !visited[next]) {
            dfs(next, cur, dep+1);
        }
    }
}

//Centroid를 중심으로 Divide and Conquer
void dnc(int cur) {
    int cent = getCent(cur, -1, getSize(cur)); //Centroid를 얻는다.
    visited[cent] = true; //해당 정점이 Centroid로 사용됐음을 표시
    
    if(isRed[cent]) a0 = (a0+1)%MOD;
    if(isBlue[cent]) b0 = (b0+1)%MOD;
    
    for(auto &next: edges[cent]) {
        if(!visited[next]) dfs(next); //서브트리 탐색
        a0 += _a0; a1 += _a1; a2 += _a2;
        b0 += _b0; b1 += _b1; b2 += _b2;
        a0 %= MOD; a1 %= MOD; a2 %= MOD;
        b0 %= MOD; b1 %= MOD; b2 %= MOD;
        _a0 = _a1 = _a2 = _b0 = _b1 = _b2 = 0;
    }
    
    a0 = a1 = a2 = b0 = b1 = b2 = 0;
    for(auto &next: edges[cent]) {
        if(!visited[next]) dnc(next);
    }
}

void solve() {
    dnc(1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    int M, K;
    cin >> M;
    while(M--) { int v; cin >> v; isRed[v] = true; }
    cin >> K;
    while(K--) { int v; cin >> v; isBlue[v] = true; }
    
    solve(); cout << ans;

    return 0;
}