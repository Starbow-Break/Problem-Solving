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
    int next[10001], visited[10001];
    while(T--) {
        int N; cin >> N;
        fill(visited, visited+N+1, false);
        for(int i = 1; i <= N; i++) cin >> next[i];
        
        int ans = 0; int cur = 1;
        while(cur != N) {
            if(visited[cur]) {
                ans = 0; break;
            }
            visited[cur] = true;
            ans++; cur = next[cur];
        }
        
        cout << ans << '\n';
    }

    return 0;
}