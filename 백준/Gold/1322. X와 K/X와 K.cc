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

ll solve(int X, int K) {
    ll Y = K;
    
    int w = 1;
    for(int i = 0; i < 31; i++) {
        if(X & w) {
            Y = (Y-Y%w)*2+(Y%w);
        }
        
        w *= 2;
    }
    
    return Y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int X, K; cin >> X >> K;
    cout << solve(X, K);

    return 0;
}