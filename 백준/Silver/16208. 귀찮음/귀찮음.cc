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

int arr[1000][1000] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int sum[500001]; sum[0] = 0;
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> sum[i]; sum[i] += sum[i-1];
    }
    
    ll ans = 0;
    for(int i = 1; i < N; i++) {
        ans += 1LL*(sum[i]-sum[i-1])*(sum[N]-sum[i]);
    }
    
    cout << ans;

    return 0;
}