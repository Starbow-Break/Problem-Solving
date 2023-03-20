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
#define MAX_N 400

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const int INF = 1'000'000'000;

int capacity[2*MAX_N+1][2*MAX_N+1] = {0, }; //최대 유량
int flow[2*MAX_N+1][2*MAX_N+1] = {0, }; //현재 유량
int previous[2*MAX_N+1] = {0, };

bool bfs(int start) {
    queue<int> q; 
    previous[start] = -1; q.push(start);
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        
        if(cur == 3) return true;
        
        for(int next = 1; next <= 2*MAX_N; next++) {
            if(previous[next] == 0 && flow[cur][next] < capacity[cur][next]) {
                q.push(next); previous[next] = cur;
            }
        }
    }
    
    return false;
}

//최대유량
int maximumFlow() {
    int ret = 0;
    
    while(bfs(2)) {
        int curFlow = INF;
        
        int i = 3;
        while(i != 2) {
            curFlow = min(curFlow, capacity[previous[i]][i]-flow[previous[i]][i]);
            i = previous[i];
        }
        
        i = 3;
        while(i != 2) {
            flow[previous[i]][i] += curFlow;
            flow[i][previous[i]] -= curFlow;
            i = previous[i];
        }
        
        fill(previous+1, previous+2*MAX_N+1, 0);
    }
    
    for(int i = 2; i <= 2*MAX_N; i += 2) ret += flow[i][3];
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, P; cin >> N >> P;
    for(int i = 1; i <= N; i++) {
        capacity[2*i-1][2*i] = 1; //2*i-1 : i-in, 2*i : i-out
    }
    
    while(P--) {
        int a, b; cin >> a >> b;
        capacity[2*a][2*b-1] = INF; capacity[2*b][2*a-1] = INF;
    }
    
    cout << maximumFlow();

    return 0;
}