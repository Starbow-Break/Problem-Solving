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

struct node {
    int level; pii pos;
};

struct cmp {
    bool operator()(node &A, node &B) {
        return A.level > B.level;
    }
};

int N, M;
int arr[100][100];
bool visited[100][100] = {false, };

int L, E, K;

bool progress(int r, int c) {
    queue<pii> q; q.push({r, c});
    visited[r][c] = true;
    priority_queue<node, vector<node>, cmp> pq;
    
    while(!q.empty()) {
        int rr = q.front().first; int cc = q.front().second; q.pop();
        if(arr[rr][cc] == -2) return true;
        
        if(rr > 0 && !visited[rr-1][cc] && arr[rr-1][cc] != -1) {
            visited[rr-1][cc] = true;
            if(arr[rr-1][cc] == -2) {
                pq.push({K-1, {rr-1, cc}});
            }
            else {
                pq.push({arr[rr-1][cc], {rr-1, cc}});
            }
        }
        if(rr < N-1 && !visited[rr+1][cc] && arr[rr+1][cc] != -1) {
            visited[rr+1][cc] = true;
            if(arr[rr+1][cc] == -2) {
                pq.push({K-1, {rr+1, cc}});
            }
            else {
                pq.push({arr[rr+1][cc], {rr+1, cc}});
            }
        }
        if(cc > 0 && !visited[rr][cc-1] && arr[rr][cc-1] != -1) {
            visited[rr][cc-1] = true;
            if(arr[rr][cc-1] == -2) {
                pq.push({K-1, {rr, cc-1}});
            }
            else {
                pq.push({arr[rr][cc-1], {rr, cc-1}});
            }
        }
        if(cc < M-1 && !visited[rr][cc+1] && arr[rr][cc+1] != -1) {
            visited[rr][cc+1] = true;
            if(arr[rr][cc+1] == -2) {
                pq.push({K-1, {rr, cc+1}});
            }
            else {
                pq.push({arr[rr][cc+1], {rr, cc+1}});
            }
        }
        
        while(!pq.empty() && pq.top().level < L) {
            node cur = pq.top(); pq.pop();
            q.push(cur.pos);
            E += cur.level;
            while(E >= L) { E -= L; L++; }
        }
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> L >> E >> K;
    pii start;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == -3) start = {i, j};
        }
    }
    
    cout << (progress(start.first, start.second) ? "O" : "X");

    return 0;
}