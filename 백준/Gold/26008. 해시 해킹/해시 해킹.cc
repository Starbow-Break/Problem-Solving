#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N, M, A, H;

ll solve() {
    int e = N-1; ll ret = 1, w = M;
    
    while(e > 0) {
        if(e%2) {
            ret *= w;
            ret %= MOD;
        }
        
        w *= w;
        w %= MOD;
        e /= 2;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> A >> H;
    cout << solve();

    return 0;
}