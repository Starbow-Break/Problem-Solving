#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

void solve(int N) {
    int ans[5] = {0, };
    
    ans[0] += N/60; N %= 60;
    
    if(N <= 35) {
        if(N%10 <= 5) { ans[1] += N/10; ans[3] += N%10; }
        else { ans[1] += N/10+1; ans[4] += 10-N%10; }
    }
    else {
        ans[0]++; N = 60-N;
        
        if(N%10 <= 5) { 
            ans[2] += N/10; ans[4] += N%10;
        }
        else {
            ans[2] += N/10+1; ans[3] += 10-N%10;
        }
    }
    
    for(int i = 0; i < 5; i++) { cout << ans[i] << " "; }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        solve(N); cout << '\n';
    }

    return 0;
}