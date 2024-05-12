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
    
    bool check[10000] = {false, };
    
    int N; cin >> N;
    vector<int> D(N);
    for(int i = 0; i < N; i++) cin >> D[i];
    
    int w = 1;
    for(int l = 1; l <= 4; l++) {
        int cur = 0;
        for(int i = 0; i < l; i++) {
            cur = cur * 10 + D[i];
        }
        check[cur] = true;
        
        for(int i = 1; i+l-1 < N; i++) {
            cur -= D[i-1]*w;
            cur = 10*cur+D[i+l-1];
            check[cur] = true;
        }
        
        w *= 10;
    }
    
    for(int i = 0; i < 10000; i++) {
        if(!check[i]) {
            cout << i;
            return 0;
        }
    }
    
    return 0;
}
