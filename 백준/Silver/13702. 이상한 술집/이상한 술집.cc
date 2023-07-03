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
    
    int N, K;
    cin >> N >> K;
    ll arr[1'000'000];
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    ll i = 1, j = 2'147'483'647;
    while(i <= j) {
        ll mid = (1LL+i+j)/2;
        ll cnt = 0;
        for(int i = 0; i < N; i++) {
            cnt += arr[i]/mid;
        }
        if(cnt >= K) i = mid+1;
        else j = mid-1;
    }
    
    cout << j;

    return 0;
}