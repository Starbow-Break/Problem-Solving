#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int R, C;
char arr[10000][501];
int d[3] = {-1, 0, 1};

bool dfs(int r, int c = 0) {
    if(c == C-1) return true;
    
    for(auto &w: d) {
        if(0 <= r+w && r+w < R && arr[r+w][c+1] == '.') {
            arr[r+w][c+1] = 'x';
            if(dfs(r+w, c+1)) return true;
        }
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> C;
    for(int i = 0; i < R; i++) { cin >> arr[i]; }
    
    for(int r = 0; r < R; r++) { dfs(r); }
    
    int ans = 0;
    for(int r = 0; r < R; r++) { ans += (arr[r][C-1] == 'x'); }
    
    cout << ans;

    return 0;
}