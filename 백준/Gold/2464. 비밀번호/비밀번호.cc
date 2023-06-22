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
    
    ll A; cin >> A;
    vector<int> base2;
    
    ll _A = A;
    while(_A > 0) {
        base2.push_back(_A%2); _A /= 2;
    }
    
    ll m, M;
    
    for(int i = 0; i < base2.size(); i++) {
        if(i == base2.size()-1) {
            m = 0; break;
        }
        if(!base2[i] && base2[i+1]) {
            m = 0;
            for(int j = base2.size()-1; j >= i; j--) {
                m += A & (1LL << j);
            }
            m -= (1LL << i);
            
            int idx = i-1;
            for(int j = i-1; j >= 0; j--) {
                if(A & (1LL << j)) { m += 1LL << idx; idx--; }
            }
            break;
        }
    }
   
    base2.push_back(0);
    for(int i = 0; i < base2.size(); i++) {
        if(base2[i] && !base2[i+1]) {
            M = 0;
            for(int j = base2.size()-1; j >= i; j--) {
                M += A & (1LL << j);
            }
            M += (1LL << i);
            
            int idx = 0;
            for(int j = i-1; j >= 0; j--) {
                if(A & (1LL << j)) { M += 1LL << idx; idx++; }
            }
            break;
        }
    }
    
    cout << m << ' ' << M;

    return 0;
}