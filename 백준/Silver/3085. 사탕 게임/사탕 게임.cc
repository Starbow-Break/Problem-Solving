#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#define MOD 1000000000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int ans = 0; int N;
char arr[50][51];

void change(int r1, int c1, int r2, int c2) {
    char temp = arr[r1][c1];
    arr[r1][c1] = arr[r2][c2];
    arr[r2][c2] = temp;
}

int process() {
    int ret = 0;
    
    for(int r = 0; r < N; r++) {
        char cur = 'X'; int cnt = 0;
        for(int c = 0; c < N; c++) {
            if(cur == arr[r][c]) cnt++;
            else {
                ret = max(ret, cnt);
                cnt = 1; cur = arr[r][c];
            }
        }
        
        ret = max(ret, cnt);
    }
    
    for(int c = 0; c < N; c++) {
        char cur = 'X'; int cnt = 0;
        for(int r = 0; r < N; r++) {
            if(cur == arr[r][c]) cnt++;
            else {
                ret = max(ret, cnt);
                cnt = 1; cur = arr[r][c];
            }
        }
        
        ret = max(ret, cnt);
    }
    
    return ret;
}

int solve() {
    int ret = 0;
    
    ret = max(ret, process());
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N-1; c++) {
            change(r, c, r, c+1);
            ret = max(ret, process());
            change(r, c, r, c+1);
        }
    }
    
    for(int r = 0; r < N-1; r++) {
        for(int c = 0; c < N; c++) {
            change(r, c, r+1, c);
            ret = max(ret, process());
            change(r, c, r+1, c);
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++) { cin >> arr[i]; }
    cout << solve();

    return 0;
}