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
#define MAX_N 100'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N;
int ant[MAX_N+1];
vector<pii> edges[MAX_N+1];
int p[MAX_N+1][17] = {0, }, w[MAX_N+1][17] = {0, };

bool visited[MAX_N+1] = {false, };
void dfs(int cur = 1) {
    visited[cur] = true;
    for(auto &next: edges[cur]) {
        if(!visited[next.first]) {
            p[next.first][0] = cur; w[next.first][0] = next.second;
            dfs(next.first);
        }
    }
}

void makeTable() {
    dfs();
    
    for(int i = 1; i < 17; i++) {
        for(int v = 1; v <= N; v++) {
            w[v][i] = w[v][i-1]+w[p[v][i-1]][i-1];
            p[v][i] = p[p[v][i-1]][i-1];
        }
    }
}

int solve(int room, int energy) {
    for(int i = 16; i >= 0; i--) {
        if(p[room][i] && energy >= w[room][i]) {
            energy -= w[room][i]; room = p[room][i];
        }
    }
    
    return room;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> ant[i];
    
    for(int i = 1; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    
    makeTable();
    
    for(int i = 1; i <= N; i++) {
        cout << solve(i, ant[i]) << '\n';
    }

    return 0;
}