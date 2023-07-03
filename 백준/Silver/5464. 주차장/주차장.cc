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

int cost[101];
int w[2001];
int used[101] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> cost[i];
    for(int i = 1; i <= M; i++) cin >> w[i];
    
    queue<int> q; ll ans = 0;
    for(int i = 1; i <= 2*M; i++) {
        int v; cin >> v;
        if(v > 0) {
            q.push(v);
        }
        else {
            for(int i = 1; i <= N; i++) {
                if(used[i] == -v) {
                    ans += cost[i]*w[-v];
                    used[i] = 0;
                    break;
                }
            }
        }
        
        while(!q.empty()) {
            bool flag = false;
            for(int i = 1; i <= N; i++) {
                if(!used[i]) {
                    used[i] = q.front(); q.pop();
                    flag = true;
                    break;
                }
            }
            
            if(!flag) break;
        }
    }
    
    cout << ans;

    return 0;
}