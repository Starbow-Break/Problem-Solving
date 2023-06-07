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
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

int n, m;
int ans[1000][1000];
int arr[1000][1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    pii start;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 2) start = {i, j};
        }
    }
    
    for(int i = 0; i < n; i++) {
        fill(ans[i], ans[i]+m, -1);
    }
    ans[start.first][start.second] = 0;
    
    queue<pii> q; q.push(start);
    while(!q.empty()) {
        int r = q.front().first, c = q.front().second; q.pop();
        if(r > 0 && ans[r-1][c] == -1 && arr[r-1][c]) {
            ans[r-1][c] = ans[r][c]+1;
            q.push({r-1, c});
        }
        if(r < n-1 && ans[r+1][c] == -1 && arr[r+1][c]) {
            ans[r+1][c] = ans[r][c]+1;
            q.push({r+1, c});
        }
        if(c > 0 && ans[r][c-1] == -1 && arr[r][c-1]) {
            ans[r][c-1] = ans[r][c]+1;
            q.push({r, c-1});
        }
        if(c < m-1 && ans[r][c+1] == -1 && arr[r][c+1]) {
            ans[r][c+1] = ans[r][c]+1;
            q.push({r, c+1});
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0) cout << 0;
            else cout << ans[i][j];
            cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}