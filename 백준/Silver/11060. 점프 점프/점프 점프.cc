#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <list>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N; int A[1001];

bool visited[1001] = {false, };
int solve(int start) {
    queue<pii> q; q.push({start, 0});
    visited[start] = true;
    
    while(!q.empty()) {
        int cur = q.front().first; int step = q.front().second; q.pop();
        if(cur == N) return step;
        
        for(int i = 1; i <= A[cur]; i++) {
            if(!visited[cur+i]) {
                q.push({cur+i, step+1});
                visited[cur+i] = true;
            }
        }
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) { cin >> A[i]; }
    
    cout << solve(1);
    
    return 0;
}