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

int dep[100'001] = {0, };
int ord[100'001] = {0, };
vector<int> edges[100'001];

int order = 0;
void dfs(int cur) {
    ord[cur] = ++order;
    for(auto &next: edges[cur]) {
        if(!ord[next]) {
            dep[next] = dep[cur]+1;
            dfs(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, R; cin >> N >> M >> R;
    while(M--) {
        int a, b; cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    for(int i = 1; i <= N; i++) sort(edges[i].begin(), edges[i].end());
    
    dfs(R);
    
    ll ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += 1LL*ord[i]*dep[i];
    }
    
    cout << ans;

    return 0;
}