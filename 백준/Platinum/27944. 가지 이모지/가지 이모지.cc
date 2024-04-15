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
using int128 = __int128_t;\

int N; 
vector<int> primes;
vector<ll> values;

bool isPrime[1'000'000];
void getPrimes() {
    fill(isPrime+2, isPrime+1'000'000, true);
    for(int i = 2; i < 1'000'000; i++) {
        if(isPrime[i]) {
            primes.pb(i);
            for(int j = i*2; j < 1'000'000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

vector<pll> factorization(ll v) {
    vector<pll> ret;
    for(auto &p: primes) {
        int cnt = 0;
        while(v%p == 0) {
            cnt++;
            v /= p;
        }
        
        if(cnt) {
            ret.pb({p, cnt});
        }
    }
    
    if(v > 1) {
        ret.pb({v, 1});
    }
    
    return ret;
}

ll solve(ll v) {
    unordered_map<string, ll> mp;
    
    vector<pll> factors = factorization(v);
    for(auto &[p, cnt]: factors) {
        string s = "";
        
        bool flag = true;
        for(int j = 0; j < N-1 && flag; j++) {
            if(values[j]%p && (values[j]+1)%p) {
                flag = false;
            }
            else {
                if(values[j]%p == 0) s += '0';
                else s += '1';
            }
        }
        
        if(flag) {
            ll q = 1;
            for(int i = 1; i <= cnt; i++) {
                bool flag = true;
                q *= p;
                for(int j = 0; j < N-1 && flag; j++) {
                    if((values[j]+(s[j]-'0'))%q) {
                        flag = false;
                    }
                }
                
                if(!flag) {
                    q /= p;
                    break;
                }
            }
            
            auto t = mp.find(s);
            if(t == mp.end()) {
                mp.insert({s, q});
            }
            else {
                t->se *= q;
            }
        }
    }
    
    ll ret = 1;
    for(auto &[s, v]: mp) {
        ret = max(ret, v);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        ll v; cin >> v;
        values.pb(v);
    }
    
    getPrimes();
    
    ll case1 = solve(values[N-1]);
    ll case2 = solve(values[N-1]+1);
    
    cout << max(case1, case2);
    
    return 0;
}