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

int arr[128][128] = {0, };

int cnt = 0;
void solve(int x1, int y1, int x2, int y2, int xx, int yy) {
    int len = (x2-x1)+1;
    
    if(len == 2) {
        cnt++;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                if(i+x1 == xx && j+y1 == yy) continue;
                arr[i+x1][j+y1] = cnt;
            }
        }
        return;
    }
    
    if(xx < x1+len/2 && yy < y1+len/2) {
        cnt++;
        arr[x1+len/2][y1+len/2-1] = cnt;
        arr[x1+len/2-1][y1+len/2] = cnt;
        arr[x1+len/2][y1+len/2] = cnt;
        
        solve(x1, y1, x1+len/2-1, y1+len/2-1, xx, yy);
        solve(x1+len/2, y1, x2, y1+len/2-1, x1+len/2, y1+len/2-1);
        solve(x1, y1+len/2, x1+len/2-1, y2, x1+len/2-1, y1+len/2);
        solve(x1+len/2, y1+len/2, x2, y2, x1+len/2, y1+len/2);
    }
    if(xx >= x1+len/2 && yy < y1+len/2) {
        cnt++;
        arr[x1+len/2-1][y1+len/2-1] = cnt;
        arr[x1+len/2-1][y1+len/2] = cnt;
        arr[x1+len/2][y1+len/2] = cnt;
        
        solve(x1, y1, x1+len/2-1, y1+len/2-1, x1+len/2-1, y1+len/2-1);
        solve(x1+len/2, y1, x2, y1+len/2-1, xx, yy);
        solve(x1, y1+len/2, x1+len/2-1, y2, x1+len/2-1, y1+len/2);
        solve(x1+len/2, y1+len/2, x2, y2, x1+len/2, y1+len/2);
    }
    if(xx < x1+len/2 && yy >= y1+len/2) {
        cnt++;
        arr[x1+len/2-1][y1+len/2-1] = cnt;
        arr[x1+len/2][y1+len/2-1] = cnt;
        arr[x1+len/2][y1+len/2] = cnt;
        
        solve(x1, y1, x1+len/2-1, y1+len/2-1, x1+len/2-1, y1+len/2-1);
        solve(x1+len/2, y1, x2, y1+len/2-1, x1+len/2, y1+len/2-1);
        solve(x1, y1+len/2, x1+len/2-1, y2, xx, yy);
        solve(x1+len/2, y1+len/2, x2, y2, x1+len/2, y1+len/2);
    }
    if(xx >= x1+len/2 && yy >= y1+len/2) {
        cnt++;
        arr[x1+len/2-1][y1+len/2-1] = cnt;
        arr[x1+len/2][y1+len/2-1] = cnt;
        arr[x1+len/2-1][y1+len/2] = cnt;
        
        solve(x1, y1, x1+len/2-1, y1+len/2-1, x1+len/2-1, y1+len/2-1);
        solve(x1+len/2, y1, x2, y1+len/2-1, x1+len/2, y1+len/2-1);
        solve(x1, y1+len/2, x1+len/2-1, y2, x1+len/2-1, y1+len/2);
        solve(x1+len/2, y1+len/2, x2, y2, xx, yy);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int K, x, y; cin >> K >> x >> y;
    arr[x-1][y-1] = -1;
    
    int len = pow(2, K);
    solve(0, 0, len-1, len-1, x-1, y-1);
    
    for(int j = len-1; j >= 0; j--) {
        for(int i = 0; i < len; i++) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}