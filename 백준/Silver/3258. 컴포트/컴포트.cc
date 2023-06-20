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
    
    int N, Z, M; cin >> N >> Z >> M;
    bool obstacle[1001] = {false, };
    while(M--) {
        int v; cin >> v;
        obstacle[v] = true;
    }
    
    for(int i = 1; i < N; i++) {
        bool visited[1001] = {false, };
        int cur = 1;
        while(cur != Z) {
            if(visited[cur]) break;
            visited[cur] = true;
            if(obstacle[cur]) break;
            cur = (cur-1+i)%N+1;
        }
        
        if(cur == Z) {
            cout << i; break;
        }
    }

    return 0;
}