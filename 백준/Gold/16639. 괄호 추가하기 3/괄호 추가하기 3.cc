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
bool used[10] = {false, };
void getPermutation(int sz, int step = 0) {
    for(int i = 0; i < sz; i++) {
        if(step == sz) {
            permutation.pb(temp);
            return;
        }
        
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
    
    int N; cin >> N;
    string f; cin >> f;
    
    if(N == 1) {
        cout << f;
        return 0;
    }
    
    getPermutation((N-1)/2);
    
    ll maxV = -1e18;
    vector<ll> value; vector<pair<char, int>> op;
    for(int i = 0; i < N; i++) {
        if(i%2) op.pb({f[i], (i-1)/2});
        else value.pb(f[i]-'0');
    }
    
    vector<ll> v; vector<pair<char, int>> o;
    for(auto &p : permutation) {
        v = value, o = op;
        
        for(auto &i : p) {
            vector<ll> tempv; vector<pair<char, int>> tempo;
            tempv.pb(v[0]);
            for(int j = 0; j < o.size(); j++) {
                if(o[j].se != i) {
                    tempv.pb(v[j+1]);
                    tempo.pb(o[j]);
                }
                else {
                    char c = o[j].fi;
                    if(c == '+') tempv[tempv.size()-1] += v[j+1];
                    if(c == '-') tempv[tempv.size()-1] -= v[j+1];
                    if(c == '*') tempv[tempv.size()-1] *= v[j+1];
                }
            }
            v = tempv; o = tempo;
        }
        
        maxV = max(maxV, v[0]);
    }
    
    cout << maxV;
    
    return 0;
}