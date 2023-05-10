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

int ans[1'000'100] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        int v; cin >> v;
        ans[i] += v;
    }
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int v; cin >> v;
        ans[i] += v;
    }
    
    for(int i = 1'000'096; i >= 1; i--) {
        if(0 <= ans[i] && ans[i] <= 2) {
            if(ans[i+1] == 0 && ans[i+2] == 2 && ans[i+3] == 0) {
                ans[i]++, ans[i+1] = 0, ans[i+2] = 0, ans[i+3] = 1;
            }
            else if(ans[i+1] == 0 && ans[i+2] == 3 && ans[i+3] == 0) {
                ans[i]++, ans[i+1] = 0, ans[i+2] = 1, ans[i+3] = 1;
            }
            else if(ans[i+1] == 1 && ans[i+2] == 2 && ans[i+3] == 0) {
                ans[i+1] = 0, ans[i+2] = 1, ans[i+3] = 1;
            }
            else if(ans[i+1] == 2 && ans[i+2] == 1 && ans[i+3] == 0) {
                ans[i+1] = 1, ans[i+2] = 0, ans[i+3] = 1;
            }
        }
    }
        
    if(ans[1] == 3 && ans[2] == 0) {
        ans[1] = 1, ans[2] = 1;
    }
    if(ans[1] == 2 && ans[2] == 0) {
        ans[1] = 0, ans[2] = 1;
    }
    if(ans[1] == 2 && ans[2] == 1 && ans[3] == 0) {
        ans[1] = 1, ans[2] = 0, ans[3] = 1;
    }
    if(ans[1] == 0 && ans[2] == 3 && ans[3] == 0) {
        ans[1] = 1, ans[2] = 1, ans[3] = 1;
    }
    if(ans[1] == 0 && ans[2] == 2 && ans[3] == 0) {
        ans[1] = 1, ans[2] = 0, ans[3] = 1;
    }
    if(ans[1] == 0 && ans[2] == 2 && ans[3] == 1 && ans[4] == 0) {
        ans[1] = 0, ans[2] = 1, ans[3] = 0, ans[4] = 1;
    }
    
    for(int i = 1; i <= 1'000'097; i++) {
        if(ans[i] == 1 && ans[i+1] == 1 && ans[i+2] == 0) {
            ans[i] = 0, ans[i+1] = 0, ans[i+2] = 1;
        }
    }
        
    for(int i = 1'000'097; i >= 1; i--) {
        if(ans[i] == 1 && ans[i+1] == 1 && ans[i+2] == 0) {
            ans[i] = 0, ans[i+1] = 0, ans[i+2] = 1;
        }
    }
    
    int len = 1'000'097;
    while(len > 1 && !ans[len]) len--;
    
    cout << len << ' ';
    for(int i = 1; i <= len; i++) cout << ans[i] << ' ';

    return 0;
}