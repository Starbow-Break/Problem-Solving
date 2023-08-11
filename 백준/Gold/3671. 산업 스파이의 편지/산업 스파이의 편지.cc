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

bool isPrime[10000000];
vector<vector<int>> permutation;

void getPrimes() {
    isPrime[1] = false;
    fill(isPrime+2, isPrime+10000000, true);
    for(int i = 2; i < 10000000; i++) {
        if(isPrime[i]) {
            for(int j = i*2; j < 10000000; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int numOne(int state) {
    int ret = 0;
    for(int i = 0; i < 7; i++) {
        if(state & 1<<i) {
            ret++;
        }
    }
    
    return ret;
}

vector<int> temp;
bool used[8] = {false, };
void getPermutation(int state, int n, int step = 0) {
    if(step == n) {
        permutation.pb(temp);
        return;
    }
    
    for(int i = 1; i <= 7; i++) {
        if((state & 1<<(i-1)) && !used[i]) {
            temp.pb(i);
            used[i] = true;
            getPermutation(state, n, step+1);
            used[i] = false;
            temp.erase(temp.end()-1);
        }
    }
}

int solve(string s) {
    set<int> st;
    
    for(auto &p: permutation) {
        int t = 0;
        for(auto &v: p) {
            if(v > s.length()) {
                t = -1;
                break;
            }
            t = t*10+(s[v-1]-'0');
        }
        if(t != -1 && isPrime[t]) {
            
            st.insert(t);
        }
    }
    
    return st.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    for(int s = 1; s < 1<<7; s++) {
        getPermutation(s, numOne(s));
    }
    
    int T; cin >> T;
    while(T--) {
        string s; cin >> s;
        cout << solve(s) << '\n';
    }
    
    return 0;
}