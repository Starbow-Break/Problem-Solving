#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORIter(value, vec) for(auto &value: vec)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define fill(vec, value) fill(all(vec), value);
#define fill2d(vec, value) FOR(subVec, vec) { fill(subVec, value) }
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

bool check[1001][1000] = {false, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    FOR(i, 1, 1001) {
        int n = 1e6;
        FOR(k, 0, i) {
            int v = n*k/i/1e3;
            check[i][v] = true;
        }
    }
    
    int N; cin >> N;
    vector<int> data;
    repeat(N) {
        string s; cin >> s;
        bool flag = false;
        int v = 0;
        FORIter(c, s) {
            if(c == '.') flag = true;
            else {
                if(flag) v = v*10+(c-'0'); 
            }
        }
        data.pb(v);
    }
    
    FOR(i, 1, 1001) {
        bool flag = true;
        FORIter(d, data) {
            if(!check[i][d]) {
                flag = false;
                break;
            }
        }
        
        if(flag) {
            cout << i;
            break;
        }
    }
    
    return 0;
}