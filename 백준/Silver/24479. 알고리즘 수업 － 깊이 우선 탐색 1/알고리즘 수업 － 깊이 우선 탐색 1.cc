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
#define MAX_V 100'000 //입력으로 주어지는 정점의 최대 갯수

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

//탐색하고자 하는 그래프
vector<int> graph[MAX_V+1];

//DFS
int visited[MAX_V+1] = {false, };
int idx[MAX_V+1] = {0, };
stack<int> s;

int ord = 0;
void dfs(int start) {
    s.push(start);
    
    while(!s.empty()) {
        int cur = s.top();
        if(!visited[cur]) visited[cur] = ++ord;
        
        while(idx[cur] < graph[cur].size()) {
            int next = graph[cur][idx[cur]];
            
            if(!visited[next]) {
                //다음 노드 탐색 전 수행 내용
                s.push(next); break;
            }
            
            idx[cur]++;
        }
        
        if(idx[cur] == graph[cur].size()) s.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int V, M, R; cin >> V >> M >> R;
    while(M--) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b); graph[b].push_back(a);
    }
    
    for(int i = 1; i <= V; i++) sort(graph[i].begin(), graph[i].end());
    
    dfs(R);
    
    for(int i = 1; i <= V; i++) cout << visited[i] << '\n';
    
    return 0;
}