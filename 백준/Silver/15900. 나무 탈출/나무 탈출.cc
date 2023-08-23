#include <bits/stdc++.h>

using namespace std;

int turn = 0;
int dep[500001] = {0, };
vector<int> edges[500001];
bool visited[500001] = {false, };

void dfs(int cur) {
    visited[cur] = true;
    bool isLeaf = true;
    for(auto &next: edges[cur]) {
        if(!visited[next]) {
            isLeaf = false;
            dep[next] = dep[cur]+1;
            dfs(next);
        }
    }
    
    if(isLeaf) turn += dep[cur];
}

int main()
{
    int N; cin >> N;
    for(int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    dfs(1);
    
    cout << (turn%2 ? "Yes" : "No");
}
