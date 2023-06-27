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
    
    int T; cin >> T;
    while(T--) {
        int P, Q, A, B, C, D; cin >> P >> Q >> A >> B >> C >> D;
        int bit = P, coin = 0, bitcoin = 0;
        coin += Q/C*D;
        int b = min(bit, coin);
        bitcoin += b; bit -= b; coin -= b;
        
        if(bit == 0) {
            bitcoin += max(coin/(A+B)*A, coin-coin/(A+B)*B-B);
        }
        else if(coin == 0) {
            bitcoin += max(bit/(A+B)*B, bit-bit/(A+B)*A-A);
        }
        
        cout << bitcoin << '\n';
    }

    return 0;
}