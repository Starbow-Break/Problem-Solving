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

const int START = 301, FINISH = 302, INF = 1'000'000'000;

vector<pii> wall, hole, mouse;
int capacity[303][303] = {0, };
int flow[303][303] = {0, };
vector<int> edges[303];

//----------------------Line-segment intersection----------------------
ll ccw(pii a, pii b) {
    return 1LL*a.first*b.second-1LL*a.second*b.first;
}

//교차 판정 (겹치는 부분이 h 뿐일때는 교차하지 않는걸로 판정)
bool intersect(pii m, pii h, pii w1, pii w2) {
    ll ch = ccw({w1.first-h.first, w1.second-h.second}, {w2.first-h.first, w2.second-h.second});
    ll cm = ccw({w1.first-m.first, w1.second-m.second}, {w2.first-m.first, w2.second-m.second});
    ll cw1 = ccw({h.first-w1.first, h.second-w1.second}, {m.first-w1.first, m.second-w1.second});
    ll cw2 = ccw({h.first-w2.first, h.second-w2.second}, {m.first-w2.first, m.second-w2.second});
    
    ch = (ch == 0 ? 0 : ch/abs(ch)); cm = (cm == 0 ? 0 : cm/abs(cm));
    cw1 = (cw1 == 0 ? 0 : cw1/abs(cw1)); cw2 = (cw2 == 0 ? 0 : cw2/abs(cw2));
    
    if(ch*cm != 0 && cw1*cw2 != 0) return (ch*cm < 0 && cw1*cw2 < 0);
    
    if(ch*cm == 0 && cw1*cw2 == 0) {  
        if(w1.first == w2.first) {
            return !((max(w1.second, w2.second) < h.second && max(w1.second, w2.second) < m.second) ||
                (min(w1.second, w2.second) > h.second && min(w1.second, w2.second) > m.second));
        }
        return !((max(w1.first, w2.first) < h.first && max(w1.first, w2.first) < m.first) ||
                (min(w1.first, w2.first) > h.first && min(w1.first, w2.first) > m.first));
    }

    if(cw1*cw2 == 0) {
        if(cw1 == 0) {
            if(h.first == m.first) {
                return min(h.second, m.second) < w1.second && w1.second < max(h.second, m.second);
            }
            return min(h.first, m.first) < w1.first && w1.first < max(h.first, m.first);
        }
        if(cw2 == 0) {
            if(h.first == m.first) {
                return min(h.second, m.second) < w2.second && w2.second < max(h.second, m.second);
            }
            return min(h.first, m.first) < w2.first && w2.first < max(h.first, m.first);
        }
    }

    return false;
}
//----------------------Line-segment intersection----------------------

//-----------------------------maximum Flow----------------------------
int previous[303];
bool bfs() {
    fill(previous, previous+303, 0);
    
    queue<int> q; q.push(START); previous[START] = -1;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        
        if(cur == FINISH) return true;
        
        for(auto &next: edges[cur]) {
            if(previous[next] == 0 && flow[cur][next] < capacity[cur][next]) {
                previous[next] = cur;
                q.push(next);
            }
        }
    }
    
    return false;
}

int maxFlow() {
    while(bfs()) {
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
    for(auto &v: edges[FINISH]) {
        ret += flow[v][FINISH];
    }
    
    return ret;
}
//-----------------------------maximum Flow----------------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k, h, m; cin >> n >> k >> h >> m;
    
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        wall.push_back({x, y});
    }
    wall.push_back(wall.front());
    
    for(int i = 0; i < h; i++) {
        int x, y; cin >> x >> y;
        hole.push_back({x, y});
    }
    
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        mouse.push_back({x, y});
    }
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= h; j++) {
            bool check = true;
            for(int k = 0; k < n && check; k++) {
                if(wall[k] == hole[j-1] || wall[k+1] == hole[j-1]) continue;
                check = check && !intersect(mouse[i-1], hole[j-1], wall[k], wall[k+1]);
            }
            
            if(check) {
                capacity[i][250+j] = 1;
                edges[i].push_back(250+j); edges[250+j].push_back(i);
            }
        }
    }
    
    for(int i = 1; i <= m; i++) {
        capacity[START][i] = 1;
        edges[START].push_back(i); edges[i].push_back(START);
    }
    for(int i = 1; i <= h; i++) {
        capacity[250+i][FINISH] = k;
        edges[250+i].push_back(FINISH); edges[FINISH].push_back(250+i);
    }
    
    cout << (maxFlow() == m ? "Possible" : "Impossible");

    return 0;
}