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

vector<vector<int>> per;

vector<int> temp;
bool used[10] = {false, };
void getPermutation(int sz, int step = 0) {
    if(sz == step) {
        per.pb(temp);
        return;
    }
    
    for(int i = 0; i < sz; i++) {
        if(!used[i]) {
            temp.pb(i);
            used[i] = true;
            getPermutation(sz, step+1);
            used[i] = false;
            temp.erase(temp.end()-1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K; cin >> N >> K;
    vector<int> A(N), B(N), C(N);
    
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++) cin >> C[i];
    
    getPermutation(N);
    
    int ans = -1;
    for(auto &p: per) {
        bool check = true;
        int cur = 0;
        for(int i = 1; i < N; i++) {
            cur += A[p[i-1]]*B[p[i]];
            if(K < C[p[i-1]]*C[p[i]]) {
                check = false;
            }
        }
        
        if(check) {
            ans = max(ans, cur);
        }
    }
    
    cout << ans;
    
    return 0;
}
