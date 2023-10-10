#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; ll K; cin >> N >> K;
    vector<int> arr(N);
    
    int idx = N-1;
    for(int i = N; i >= 1; i--) {
        if(K >= i-1 && K > 0) {
            arr[N-i] = i;
            K -= i-1;
        }
        else if(K > 0) {
            arr[N-1-K] = i;
            K = 0;
        }
        else {
            while(idx >= 0) {
                if(!arr[idx]) break;
                idx--;
            }
            arr[idx] = i;
        }
    }
    
    for(auto &a: arr) cout << a << ' '; 
    
    return 0;
}
