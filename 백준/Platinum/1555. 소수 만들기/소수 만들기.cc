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

int N; 
vector<vector<int>> per;
vector<vector<int>> vec;
vector<ll> value;
set<ll> results;

vector<int> tempVec;
bool used[6] = {false, };
void getPermutation(int sz, int step = 0) {
    if(step == sz) {
        per.pb(tempVec);
        return;
    }
    
    for(int i = 0; i < sz; i++) {
        if(!used[i]) {
            tempVec.pb(i);
            used[i] = true;
            getPermutation(sz, step+1);
            used[i] = false;
            tempVec.erase(tempVec.end()-1);
        }
    }
}

vector<int> tempVec1;
void buildVec(int sz, int num0 = 0, int num1 = 0) {
    if(num0 == sz && num1 == sz) {
        vec.pb(tempVec1);
        return;
    }
    
    for(int i = 0; i <= 1; i++) {
        if(i) {
            if(num1+1 <= sz && num0 >= num1+1) {
                tempVec1.pb(1);
                buildVec(sz, num0, num1+1);
                tempVec1.erase(tempVec1.end()-1);
            }
        }
        else {
            if(num0+1 <= sz) {
                tempVec1.pb(0);
                buildVec(sz, num0+1, num1);
                tempVec1.erase(tempVec1.end()-1);
            }
        }
    }
}

vector<int> primes;
bool isPrime[27'000];
void getPrimes() {
    fill(isPrime+2, isPrime+27000, true);
    
    for(int i = 2; i < 27000; i++) {
        if(isPrime[i]) {
            primes.pb(i);
            for(int j = i*2; j < 27000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

bool checkPrime(ll v) {
    if(v == 1) return false;
    
    for(auto &p: primes) {
        if(1LL*p*p > v) {
            return true;
        }
        
        if(v%p == 0) return false;
    }
    return true;
}

int l[6] = {-1, 0, 1, 2, 3, 4};
int r[6] = {1, 2, 3, 4, 5, 6};
void calc(vector<int> &p, vector<int> &v, int pidx = 0, int idx = 0) {
    if(idx == v.size()) {
        ll res = value[p[N-1]];
        if(res > 1) results.insert(res);
        return;
    }
    
    int bef = pidx;
    while(idx < v.size() && v[idx] == 0) {
        idx++; pidx++;
    }
    
    for(int i = 0; i < 4; i++) {
        int a = l[pidx-1], b = pidx-1;
        ll va = value[p[a]], vb = value[p[b]];
        
        switch(i) {
            case 0:
                value[p[b]] = va+vb;
                if(a < N-1) l[r[a]] = l[a];
                if(a > 0) r[l[a]] = r[a];
                calc(p, v, pidx, idx+1);
                break;
            case 1:
                value[p[b]] = va-vb;
                if(a < N-1) l[r[a]] = l[a];
                if(a > 0) r[l[a]] = r[a];
                calc(p, v, pidx, idx+1);
                break;
            case 2:
                value[p[b]] = va*vb;
                if(a < N-1) l[r[a]] = l[a];
                if(a > 0) r[l[a]] = r[a];
                calc(p, v, pidx, idx+1);
                break;
            case 3:
                if(vb != 0) {
                    value[p[b]] = va/vb;
                    if(a < N-1) l[r[a]] = l[a];
                    if(a > 0) r[l[a]] = r[a];
                    calc(p, v, pidx, idx+1);
                }
        }
        
        value[p[a]] = va; value[p[b]] = vb;
        if(a < N-1) l[r[a]] = a;
        if(a > 0) r[l[a]] = a;
    }
    
    pidx = bef;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        value.pb(v);
    }
    
    if(N == 1) {
        if(checkPrime(value[0])) {
            cout << value[0] << '\n' << value[0];
        }
        else cout << -1;
        
        return 0;
    }
    
    getPermutation(N);
    tempVec1.pb(0);
    buildVec(N-1);
    
    for(auto &p: per) {
        for(auto &v: vec) {
            calc(p, v);
        }
    }
    
    ll minPrime = 1e18, maxPrime = 0;
    for(auto &v: results) {
        if(checkPrime(v)) {
            minPrime = min(v, minPrime);
            maxPrime = max(v, maxPrime);
        }
    }
    
    if(maxPrime) {
        cout << minPrime << '\n' << maxPrime;
    }
    else cout << -1;
    
    return 0;
}