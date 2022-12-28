#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

bool visited[1001][1001] = {false, };

pii solve(int C, int R, int K) {
    int c = 1; int r = 1; int cur = 1;
    while(1) {
        while(r < R) {
            visited[c][r] = true;
            if(cur == K) return {c, r}; 
            
            if(visited[c][r+1]) break;
            r++; cur++;
        }
        while(c < C) {
            visited[c][r] = true;
            if(cur == K) return {c, r};
            
            if(visited[c+1][r]) break;
            c++; cur++;
        }
        while(r > 1) {
            visited[c][r] = true;
            if(cur == K) return {c, r};
            
            if(visited[c][r-1]) break;
            r--; cur++;
        }
        while(c > 1) {
            visited[c][r] = true;
            if(cur == K) return {c, r};
            
            if(visited[c-1][r]) break;
            c--; cur++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int C, R, K; cin >> C >> R >> K;
    
    if(R*C < K) cout << 0;
    else {
        pii ans = solve(C, R, K);
        cout << ans.first << " " << ans.second;
    }

    return 0;
}