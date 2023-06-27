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
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N; cin >> N;
    ll a = 0, b = N/5;
    while(5*b+3*a < N) a++;
    
    while(a >= 0 && b >= 0) {
        if(5*b+3*a != N) {
            b--;
            while(5*b+3*a < N) a++;
        }
        
        if(5*b+3*a == N) break;
    }
    
    if(b < 0) cout << -1;
    else cout << a+b;
    
    return 0;
}