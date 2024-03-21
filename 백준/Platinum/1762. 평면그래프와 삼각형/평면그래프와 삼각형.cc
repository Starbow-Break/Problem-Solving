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

int order[100'001] = {0, };
set<int> edges[100'001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    int N, M; cin >> N >> M;
    while(M--) {
        int a, b; cin >> a >> b;
        edges[a].insert(b); edges[b].insert(a);
        order[a]++; order[b]++;
    }
    
    // 평면 그래프는 차수가 5 이하인 정점이 적어도 하나 존재한다.
    // 그 정점 들을 큐에 추가
    queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(order[i] <= 5) {
            q.push(i);
        }
    }
    
    // 답 계산
    int ans = 0;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        vector<int> vec;
        for(auto &t: edges[cur]) {
            vec.pb(t);
        }
        
        // cur-vec[i] && cur-vec[j]는 만족하므로
        // vec[i]-vec[j]가 있는지를 확인, 있으면 +1
        for(int i = 0; i < vec.size(); i++) {
            for(int j = i+1; j < vec.size(); j++) {
                auto t1 = edges[vec[i]].find(vec[j]);
                if(t1 != edges[vec[i]].end()) {
                    ans++;
                }
            }
        }
        
        // 방금 확인한 정점 제거
        // 정점 하나가 제거된 이후에도 평면 그래프는 유지된다.
        // 제거하면서 차수가 5 이하인 정점이 새롭게 나타나면 큐에 추가
        for(auto &v: vec) {
            edges[v].erase(edges[v].find(cur));
            order[v]--; order[cur]--;
            if(order[v] <= 5) {
                q.push(v);
            }
        }
        
        edges[cur].clear();
    }
    
    cout << ans;
    
    return 0;
}