#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

struct area {
    int r, c, d;
};

struct node {
    int r, c, len;
};

int N, M, K;
int arr[3001][3001];
vector<area> areas;

void getArea() {
    vector<ii> vec;
    
    for(int i = 1; i <= N; i++) {
        vec.clear();
        
        for(auto &a: areas) {
            if(a.r-a.d <= i && i <= a.r+a.d) {
                vec.push_back({max(1, a.c-(a.d-abs(i-a.r))), 1});
                vec.push_back({a.c+(a.d-abs(i-a.r))+1, 0});
            }
        }
        
        sort(vec.begin(), vec.end());
        
        int cnt = 0; int idx = 0;
        for(int j = 1; j <= M; j++) {
            while(idx < vec.size() && vec[idx].first == j) {
                if(vec[idx].second) { cnt++; }
                else { cnt--; }
                
                idx++;
            }
            
            arr[i][j] = (cnt > 0);
        }
    }
}

int bfs() {
    queue<node> q; q.push({1, 1, 0});
    arr[1][1] = 1;
    
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int len = q.front().len;
        q.pop();
        
        if(r == N && c == M) return len;
        
        if(r > 1 && !arr[r-1][c]) {
            q.push({r-1, c, len+1});
            arr[r-1][c] = 1;
        }
        if(r < N && !arr[r+1][c]) {
            q.push({r+1, c, len+1});
            arr[r+1][c] = 1;
        }
        if(c > 1 && !arr[r][c-1]) {
            q.push({r, c-1, len+1});
            arr[r][c-1] = 1;
        }
        if(c < M && !arr[r][c+1]) {
            q.push({r, c+1, len+1});
            arr[r][c+1] = 1;
        }
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K;
    while(K--) {
        int r, c, d; cin >> r >> c >> d;
        areas.push_back({r, c, d});
    }
    
    getArea();
    
    int ans = bfs();
    if(ans == -1) {cout << "NO";}
    else {cout << "YES" << '\n' << ans;}

    return 0;
}