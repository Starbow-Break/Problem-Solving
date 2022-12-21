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

ll inverse(int n) {
    ll ret = 1; ll w = n; int e = MOD-2;
    while(e > 0) {
        if(e%2) {
            ret *= w;
            ret %= MOD;
        }
        
        w *= w; w %= MOD;
        e /= 2;
    }
    
    return ret;
}

ll combination(int N, int M) {
    ll ret = 1;
    for(int i = 1; i <= M; i++) {
        ret *= N-i+1; ret %= MOD;
        ret *= inverse(i); ret %= MOD;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    cout << combination(N, M);

    return 0;
}