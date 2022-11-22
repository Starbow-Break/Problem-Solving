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

struct wood {
    int x1, x2, num;
    
    bool operator<(wood &W) {
        return x1 < W.x1;
    }
};

struct comp {
    bool operator()(ii &A, ii &B) {
        return A.first > B.first;
    }
};

int N, Q;
vector<wood> vec;
priority_queue<ii, vector<ii>, comp> pq;

int parent[MAX+1];

int findRoot(int v) {
    if(v == parent[v]) return v;
    
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

void unionSet(int v1, int v2) {
    int r1 = findRoot(v1);
    int r2 = findRoot(v2);
    
    if(r1 > r2) parent[r1] = r2;
    else parent[r2] = r1;
}

bool sameSet(int v1, int v2) {
    int r1 = findRoot(v1);
    int r2 = findRoot(v2);
    
    return r1 == r2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> Q;
    for(int i = 1; i <= N; i++) {
        int x1, x2, y; cin >> x1 >> x2 >> y;
        vec.push_back({x1, x2, i});
        parent[i] = i;
    }
    
    sort(vec.begin(), vec.end());
    
    int idx = 0;
    while(idx < vec.size()) {
        int t1 = vec[idx].x1; int t2 = 2000000000;
        if(!pq.empty()) t2 = pq.top().first;
        int x = min(t1, t2);
        
        while(!pq.empty() && pq.top().first == x) pq.pop();
        
        while(idx < vec.size() && vec[idx].x1 == x) {
            if(!pq.empty()) {
                int v = pq.top().second;
                unionSet(v, vec[idx].num);
            }
            
            pq.push({vec[idx].x2+1, vec[idx].num});
            idx++;
        }
    }
    
    while(Q--) {
        int a, b; cin >> a >> b;
        cout << sameSet(a, b) << '\n';
    }

    return 0;
}