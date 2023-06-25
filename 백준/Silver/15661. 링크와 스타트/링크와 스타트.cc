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

int S[20][20];
int arr[1 << 20] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) cin >> S[i][j];
    }
    
    for(int state = 0; state < 1<<N; state++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if((state & 1<<i) && (state & 1<<j)) {
                    arr[state] += S[i][j];
                }
            }
        }
    }
    
    int ans = 1'000'000'000;
    for(int i = 0; i < 1<<N; i++) {
        ans = min(ans, abs(arr[i]-arr[(1<<N)-1-i]));
    }
    cout << ans;

    return 0;
}