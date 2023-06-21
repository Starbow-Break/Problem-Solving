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

int pow2[31], pow3[20];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    pow2[0] = pow3[0] = 1;
    for(int i = 1; i <= 30; i++) pow2[i] = pow2[i-1]*2;
    for(int i = 1; i <= 19; i++) pow3[i] = pow3[i-1]*3;
    
    int T; cin >> T;
    vector<pii> vec;
    while(T--) {
        vec.clear();
        int N; cin >> N;
        int i = 30, j = 0;
        while(N > 0) {
            while(!(N%3)) { j++; N /= 3; }
            while(pow2[i] > N || (N-pow2[i])%3) i--;
            vec.push_back({i, j});
            N -= pow2[i];
        }
        cout << vec.size() << '\n';
        for(auto &v: vec) cout << v << '\n';
    }
    

    return 0;
}