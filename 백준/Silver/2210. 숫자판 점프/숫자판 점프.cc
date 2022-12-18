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

int arr[5][5];
bool visited[1000000] = {false, }; int ans = 0;

void progress(int r, int c, int cur = 0, int step = 0) {
    if(step == 6) {
        if(!visited[cur]) { visited[cur] = true; ans++; }
        return;
    }
    
    cur *= 10; cur += arr[r][c];
    
    if(r > 0) {
        progress(r-1, c, cur, step+1);
    }
    if(r < 4) {
        progress(r+1, c, cur, step+1);
    }
    if(c > 0) {
        progress(r, c-1, cur, step+1);
    }
    if(c < 4) {
        progress(r, c+1, cur, step+1);
    }
    
    cur /= 10;
}

void solve() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            progress(i, j);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}