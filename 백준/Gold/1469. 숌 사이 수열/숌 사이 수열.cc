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

vector<vector<int>> permutation;
vector<int> temp;
bool used[8] = {false, };
void getPermutation(int sz, int step = 0) {
    if(sz == step) {
        permutation.pb(temp);
        return;
    }
    
    for(int i = 0; i < sz; i++) {
        if(used[i]) continue;
        temp.pb(i);
        used[i] = true;
        getPermutation(sz, step+1);
        used[i] = false;
        temp.erase(temp.end()-1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<int> X(N);
    
    FOR(i, 0, N) cin >> X[i];
    sort(all(X));
    
    getPermutation(N);
    
    vector<int> ans(2*N);
    int idx = 0;
    for(auto &p: permutation) {
        fill(all(ans), -1);
        idx = 0;
        bool check = true;
        for(int i = 0; i < N && check; i++) {
            while(idx < 2*N && ans[idx] != -1) idx++;
            if(idx+X[p[i]]+1 >= 2*N || ans[idx+X[p[i]]+1] != -1) check = false;
            else {
                ans[idx] = X[p[i]], ans[idx+X[p[i]]+1] = X[p[i]];
            }
        }
        
        if(check) {
            for(auto &a: ans) cout << a << ' ';
            return 0;
        }
    }
    
    cout << -1;
    
    return 0;
}
