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
#define INF 1'000'000'000

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

int num[100'001];
int sz[100'001]; //서브트리의 크기
bool visited[100'001] = {false, }; //Centroid로 사용 여부
vector<int> edges[100'001];

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

vector<pii> temp; vector<int> visit;
int minDep[100'001];

void dfs(int cur, int prev = -1, int dep = 1) {
    temp.push_back({num[cur], dep});
    visit.push_back(num[cur]);
    
    for(auto &next: edges[cur]) {
        if(next != prev && !visited[next]) {
            dfs(next, cur, dep+1);
        }
    }
}

//Centroid를 중심으로 Divide and Conquer
int dnc(int cur) {
    int ret = INF;
    
    int cent = getCent(cur, -1, getSize(cur)); //Centroid를 얻는다.
    visited[cent] = true; //해당 정점이 Centroid로 사용됐음을 표시
    minDep[num[cent]] = 0; visit.push_back(num[cent]);
    
    for(auto &next: edges[cent]) {
        if(!visited[next]) dfs(next); //서브트리 탐색
        for(auto &p: temp) {
            ret = min(ret, minDep[p.first]+p.second);
        }
        for(auto &p: temp) {
            minDep[p.first] = min(minDep[p.first], p.second);
        }
        
        temp.clear();
    }
    
    for(auto &v: visit) minDep[v] = INF;
    visit.clear();
    
    for(auto &next: edges[cent]) {
        if(!visited[next]) ret = min(ret, dnc(next));
    }
    
    return ret;
}

int solve() { return dnc(1); }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    fill(minDep+1, minDep+100'001, INF);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> num[i];
    for(int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    cout << solve();

    return 0;
}