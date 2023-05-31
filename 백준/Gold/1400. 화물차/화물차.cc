#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int INF = 1'000'000'000;

struct tl {
    int initD, t[2];
};

struct cmp {
    bool operator()(pii &a, pii &b) {
        return a.y > b.y;
    }
};

char arr[20][21];
tl tls[10];

int d[400];
void dijkstra(int n, int m, int s, int f) {
    fill(d, d+400, INF);
    priority_queue<pii, vector<pii>, cmp> pq;
    pq.push({s, 0}); d[s] = 0;
    
    while(!pq.empty()) {
        int cur = pq.top().x; int dist = pq.top().y; pq.pop();
        if(cur == f) return;
        if(d[cur] < dist) continue;
        
        int r = cur/m, c = cur%m;
        if(r > 0 && arr[r-1][c] != '.') {
            int newD, dir;
            if('0' <= arr[r-1][c] && arr[r-1][c] <= '9') {
                int num = arr[r-1][c]-'0';
                int t0 = tls[num].t[0];
                int t1 = tls[num].t[1];
                int rd = dist%(t0+t1);
                
                if(tls[num].initD) {
                    if(0 <= rd && rd < t1) dir = 1;
                    else dir = 0;
                }
                else {
                    if(0 <= rd && rd < t0) dir = 0;
                    else dir = 1;
                }
                
                if(dir) newD = dist+1;
                else {
                    if(tls[num].initD) {
                        newD = dist+t0+t1-dist%(t0+t1)+1;
                    }
                    else {
                        newD = dist+t0-dist%(t0+t1)+1;
                    }
                }
            }
            else newD = dist+1;
            
            if(d[cur-m] > newD) {
                d[cur-m] = newD; pq.push({cur-m, newD});
            } 
        }
        if(r < n-1 && arr[r+1][c] != '.') {
            int newD, dir;
            if('0' <= arr[r+1][c] && arr[r+1][c] <= '9') {
                int num = arr[r+1][c]-'0';
                int t0 = tls[num].t[0];
                int t1 = tls[num].t[1];
                int rd = dist%(t0+t1);
                
                if(tls[num].initD) {
                    if(0 <= rd && rd < t1) dir = 1;
                    else dir = 0;
                }
                else {
                    if(0 <= rd && rd < t0) dir = 0;
                    else dir = 1;
                }
                
                if(dir) newD = dist+1;
                else {
                    if(tls[num].initD) {
                        newD = dist+t0+t1-dist%(t0+t1)+1;
                    }
                    else {
                        newD = dist+t0-dist%(t0+t1)+1;
                    }
                }
            }
            else newD = dist+1;
            
            if(d[cur+m] > newD) {
                d[cur+m] = newD;
                pq.push({cur+m, newD});
            }
        }
        if(c > 0 && arr[r][c-1] != '.') {
            int newD, dir;
            if('0' <= arr[r][c-1] && arr[r][c-1] <= '9') {
                int num = arr[r][c-1]-'0';
                int t0 = tls[num].t[0];
                int t1 = tls[num].t[1];
                int rd = dist%(t0+t1);
                
                if(tls[num].initD) {
                    if(0 <= rd && rd < t1) dir = 1;
                    else dir = 0;
                }
                else {
                    if(0 <= rd && rd < t0) dir = 0;
                    else dir = 1;
                }
                
                if(!dir) newD = dist+1;
                else {
                    if(tls[num].initD) {
                        newD = dist+t1-dist%(t0+t1)+1;
                    }
                    else {
                        newD = dist+t0+t1-dist%(t0+t1)+1;
                    }
                }
            }
            else newD = dist+1;
            
            if(d[cur-1] > newD) {
                d[cur-1] = newD;
                pq.push({cur-1, newD});
            }
        }
        if(c < m-1 && arr[r][c+1] != '.') {
            int newD, dir;
            if('0' <= arr[r][c+1] && arr[r][c+1] <= '9') {
                int num = arr[r][c+1]-'0';
                int t0 = tls[num].t[0];
                int t1 = tls[num].t[1];
                int rd = dist%(t0+t1);
                
                if(tls[num].initD) {
                    if(0 <= rd && rd < t1) dir = 1;
                    else dir = 0;
                }
                else {
                    if(0 <= rd && rd < t0) dir = 0;
                    else dir = 1;
                }
                
                if(!dir) newD = dist+1;
                else {
                    if(tls[num].initD) {
                        newD = dist+t1-dist%(t0+t1)+1;
                    }
                    else {
                        newD = dist+t0+t1-dist%(t0+t1)+1;
                    }
                }
            }
            else newD = dist+1;
            
            if(d[cur+1] > newD) {
                d[cur+1] = newD;
                pq.push({cur+1, newD});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    while(cin >> n >> m) {
        if(!n && !m) break;
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        int numT = 0; //신호등 갯수
        pii start, finish; //출발 지점, 도착 지점
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                if('0' <= arr[r][c] && arr[r][c] <= '9') {
                    numT = max(numT, arr[r][c]-'0'+1);
                }
                if(arr[r][c] == 'A') start = {r, c};
                if(arr[r][c] == 'B') finish = {r, c};
            }
        }
        
        //신호등 정보 받기
        for(int i = 0; i < numT; i++) {
            int num, a, b; char c;
            cin >> num >> c >> a >> b;
            tls[num] = {c == '|', {a, b}};
        }
        
        //다익스트라
        dijkstra(n, m, m*start.x+start.y, m*finish.x+finish.y);
        
        if(d[m*finish.x+finish.y] == INF) cout << "impossible" << '\n';
        else cout << d[m*finish.x+finish.y] << '\n';
    }
    
    return 0;
}