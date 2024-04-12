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

bool check[1 << 12] = {false, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K; cin >> N >> K;
    
    stack<int> s;
    int sz = K;
    int w;
    for(w = (1<<N); w >= 1; w >>= 1) {
        if(sz == w) {
            for(int i = 0; i < sz; i++) {
                check[i] = true;
            }
            break;
        }
        
        if(sz > w/2) {
            sz = w-sz;
            s.push(1);
        }
        else {
            s.push(0);
        }
    }
    
    for(w <<= 1; w <= (1<<N); w <<= 1) {
        int v = s.top(); s.pop();
        if(v) {
            for(int i = 0; i < w; i++) {
                check[i] = !check[i];
            }
        }
    }
    
    cout << "YES" << '\n';
    for(int i = 0; i < (1<<N); i++) {
        if(check[i]) {
            cout << i << ' ';
        }
    }
    
    return 0;
}