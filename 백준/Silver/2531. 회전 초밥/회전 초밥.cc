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
#define MOD 987'654'321

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
    
    int n, d, k, c; cin >> n >> d >> k >> c;
    vector<int> vec;
    for(int i = 0; i < n; i++) {
        int v; cin >> v;
        vec.push_back(v);
    }
    
    bool eat[3001]; int ans = 0;
    for(int i = 0; i < n; i++) {
        fill(eat, eat+d+1, false);
        eat[c] = true;
        for(int j = 0; j < k; j++) {
            eat[vec[(i+j)%n]] = true;
        }
        
        int cur = 0;
        for(int j = 1; j <= d; j++) {
            cur += eat[j];
        }
        
        ans = max(ans, cur);
    }
    
    cout << ans;

    return 0;
}