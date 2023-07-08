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

bool visited[1 << 20] = {false, };

int solve(int v) {
    int ret = 0;
    int cur = v;
    while(cur > 0) {
        if(visited[cur]) ret = cur;
        cur /= 2;
    }
    
    if(!ret) visited[v] = true;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, Q; cin >> N >> Q;
    while(Q--) {
        int v; cin >> v;
        cout << solve(v) << '\n';
    }

    return 0;
}