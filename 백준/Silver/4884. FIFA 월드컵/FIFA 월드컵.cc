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

ll pow2[60];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    pow2[0] = 1;
    for(int i = 1; i < 60; i++) pow2[i] = pow2[i-1]*2;
    
    int G, T, A, D;
    while(cin >> G >> T >> A >> D) {
        if(G == -1) break;
        cout << G << '*' << A << '/' << T << '+' << D << '=';
        
        ll X = 1LL*T*(T-1)/2*G+1LL*A*G+D-1;
        ll t = 1LL*A*G+D, Y = 0;
        
        for(int i = 0; i < 60; i++) {
            if(pow2[i] >= t) {
                Y = pow2[i]-t;
                X += Y;
                break;
            }
        }
        
        cout << X << '+' << Y << '\n';
    }

    return 0;
}