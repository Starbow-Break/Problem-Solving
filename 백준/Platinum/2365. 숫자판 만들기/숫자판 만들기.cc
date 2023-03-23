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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const int INF = 1'000'000'000;

int N; 
int START, FINISH;
int target = 0;

int capacity[2602][2602] = {0, };
int flow[2602][2602] = {0, };
int previous[2602];

vector<int> edge[2602];

void init(int _capacity) {
    for(int i = 0; i <= 2601; i++) fill(flow[i], flow[i]+2602, 0);
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            capacity[(N+1)*(r+1)-1][r*(N+1)+c] = _capacity;
            capacity[r*(N+1)+c][(N+1)*N+c] = _capacity;
        }
    }
}

bool bfs(int start) {
    fill(previous, previous+2602, -1);
    
    queue<int> q;
    q.push(start); previous[start] = -2;
    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        
        if(cur == FINISH) return true;
        
        for(auto &next: edge[cur]) {
            if(previous[next] == -1 && flow[cur][next] < capacity[cur][next]) {
                previous[next] = cur;
                q.push(next);
            }
        }
    }
    
    return false;
}

int maximumFlow(int _capacity) {
    init(_capacity);
    
    int cnt = 0;
    while(bfs(START)) {
        int curFlow = INF;
        
        int i = FINISH;
        while(i != START) {
            curFlow = min(curFlow, capacity[previous[i]][i]-flow[previous[i]][i]);
            i = previous[i];
        }
        
        i = FINISH;
        while(i != START) {
            flow[previous[i]][i] += curFlow;
            flow[i][previous[i]] -= curFlow;
            i = previous[i];
        }
    }
    
    int ret = 0;
    for(int c = 0; c < N; c++) {
        ret += flow[(N+1)*N+c][FINISH];
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    START = (N+1)*(N+1)-1; FINISH = (N+1)*(N+1);
    
    for(int r = 0; r < N; r++) {
        int v; cin >> v;
        capacity[START][(N+1)*(r+1)-1] = v;
        edge[START].push_back((N+1)*(r+1)-1);
        edge[(N+1)*(r+1)-1].push_back(START);
    }
    
    for(int c = 0; c < N; c++) {
        int v; cin >> v;
        capacity[(N+1)*N+c][FINISH] = v;
        edge[(N+1)*N+c].push_back(FINISH);
        edge[FINISH].push_back((N+1)*N+c);
        target += v;
    }
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            edge[(N+1)*(r+1)-1].push_back(r*(N+1)+c);
            edge[r*(N+1)+c].push_back((N+1)*N+c);
            edge[r*(N+1)+c].push_back((N+1)*(r+1)-1);
            edge[(N+1)*N+c].push_back(r*(N+1)+c);
        }
    }
    
    int i = 0; int j = 10000;
    while(i <= j) {
        int mid = (i+j) >> 1;
        int mxFlow = maximumFlow(mid);
        
        if(mxFlow == target) j = mid-1;
        else i = mid+1;
    }
    
    cout << i << '\n';
    maximumFlow(i);
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            cout << flow[(N+1)*(r+1)-1][r*(N+1)+c] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}