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
#define MOD 1'000'000'009

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

int t[20], p[20];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    for(int i = 0; i < M; i++) {
        cin >> t[i] >> p[i];
    }
    
    int ans = 0;
    for(int state; state < 1<<M; state++) {
        int T = 0, P = 0;
        for(int j = 0; j < M; j++) {
            if(state & (1<<j)) {
                T += t[j]; P += p[j];
            }
        }
        if(T <= N) ans = max(ans, P);
    }
    
    cout << ans;

    return 0;
}