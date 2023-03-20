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

__int128 modPow(int a, int e, ll mod) {
    __int128 ret = 1; __int128 w = a;
    
    while(e > 0) {
        if(e%2) {
            ret *= w;
            ret %= mod;
        }
        
        e /= 2; w *= w; w %= mod;
    }
    
    return ret;
}

double S(int d, int j) {
    double ret = 0;
    for(int i = 0; i <= d+4; i++) {
        if(i <= d) {
            __int128 w = modPow(16, d-i, 1LL*(8*i+j)*(8*i+j));
            ret += (double)w/(1LL*(8*i+j)*(8*i+j));
        }
        else {
            ll w = pow(16, i-d);
            ret += (double)1/(1LL*(8*i+j)*(8*i+j)*w);
        }
    }
    
    return ret-floor(ret);
}

double floatPart(int N) {
    double ret = 16*S(N-1, 1)-16*S(N-1, 2)-8*S(N-1, 3)-16*S(N-1, 4)
        -4*S(N-1, 5)-4*S(N-1, 6)+2*S(N-1, 7);
        
    while(ret < 0) ret += 1;
    
    return ret-floor(ret);
}

int main()
{
    int N; cin >> N;
    
    double f = floatPart(N);
    int v = floor(f*16);
    
    if(v < 10) cout << v;
    else cout << (char)('A'+v-10);
    
    return 0;
}