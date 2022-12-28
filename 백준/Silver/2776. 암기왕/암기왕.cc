#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

map<int, int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        mp.clear();
        
        int N; cin >> N;
        while(N--) {
            int v; cin >> v;
            mp.insert({v, 1});
        }
        
        int M; cin >> M;
        while(M--) {
            int v; cin >> v;
            auto t = mp.find(v);
            cout << (t != mp.end()) << '\n';
        }
    }

    return 0;
}