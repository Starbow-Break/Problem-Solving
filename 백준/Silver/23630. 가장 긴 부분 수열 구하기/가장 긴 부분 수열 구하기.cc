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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int cnt[19] = {0, };
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        for(int j = 0; j < 20; j++) {
            if(v & 1<<j) cnt[j]++;
        }
    }
    
    int ans = 0;
    for(int i = 0; i < 20; i++) ans = max(ans, cnt[i]);
    cout << ans;

    return 0;
}