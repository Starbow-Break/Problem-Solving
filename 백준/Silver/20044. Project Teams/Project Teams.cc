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
    
    int N; cin >> N;
    vector<int> vec;
    for(int i = 0; i < 2*N; i++) {
        int v; cin >> v;
        vec.push_back(v);
    }
    
    sort(vec.begin(), vec.end());
    
    int ans = 1'000'000'000;
    for(int i = 0; i < N; i++) {
        ans = min(ans, vec[i]+vec[2*N-1-i]);
    }
    cout << ans;

    return 0;
}