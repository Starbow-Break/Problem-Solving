#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#define MAX 100000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N, M, X;
vector<int> lower[MAX+1];
vector<int> higher[MAX+1];

bool visited[MAX+1];
int bfsLower(int start) {
    fill(visited+1, visited+N+1, false);
    queue<int> q; q.push(start);
    visited[start] = true;
    
    int ret = -1;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        ret++;
        
        for(auto &next: lower[cur]) {
            if(!visited[next]) {
                q.push(next); visited[next] = true;
            }
        }
    }
    
    return ret;
}

int bfsHigher(int start) {
    fill(visited+1, visited+N+1, false);
    queue<int> q; q.push(start);
    visited[start] = true;
    
    int ret = -1;
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        ret++;
        
        for(auto &next: higher[cur]) {
            if(!visited[next]) {
                q.push(next); visited[next] = true;
            }
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> X;
    while(M--) {
        int s, f; cin >> s >> f;
        lower[s].push_back(f);
        higher[f].push_back(s);
    }
    
    int l = bfsLower(X);
    int h = bfsHigher(X);
    
    cout << h+1 << " " << N-l;

    return 0;
}