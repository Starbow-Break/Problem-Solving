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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

map<int, int> mp; ll c = 0;
int cnt[300002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    mp.insert({0, -1}); mp.insert({N+1, -1});
    
    for(int i = 1; i <= N; i++) {
        int v; cin >> v;
        mp.insert({v, -1});
        auto t = mp.find(v);
        
        auto l = t, r = t; l--; r++;
        t->second = max(l->second, r->second)+1;
        c += t->second;
        cout << c << '\n';
    }

    return 0;
}