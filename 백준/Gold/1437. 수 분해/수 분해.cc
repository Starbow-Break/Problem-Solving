#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#define MOD 10007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int modPow(int a, int e) {
    int ret = 1; int w = a;
    while(e > 0) {
        if(e%2) {
            ret *= w; ret %= MOD;
        }
        
        w *= w; w %= MOD;
        e /= 2;
    }
    
    return ret;
}

int solve(int N) {
    if(N <= 4) return N;
    if(N == 5) return 6;
    if(N == 6) return 9;
    
    if(N%3 == 1) return (modPow(3, (N-4)/3)*4)%MOD;
    if(N%3 == 2) return (modPow(3, (N-2)/3)*2)%MOD;
    return modPow(3, N/3);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    cout << solve(N);

    return 0;
}
